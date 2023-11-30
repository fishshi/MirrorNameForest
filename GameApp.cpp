#include "GameApp.h"
#include "d3dUtil.h"
#include "DXTrace.h"
#include "NameVertices.h"
using namespace DirectX;

const D3D11_INPUT_ELEMENT_DESC GameApp::VertexPosNormalColor::inputLayout[3] = {
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

GameApp::GameApp(HINSTANCE hInstance)
	: D3DApp(hInstance), 
	m_VSConstantBuffer(),
	m_PSConstantBuffer(),
	m_DirLight(),
	m_PointLight(),
	m_SpotLight(),
	name(nullptr),// 初始化变量，置空
	nameN(40),
	angle(0),
	viewPos(0.0f, 18.0f, -120.0f),
	viewRot(-0.2f, 0.0f, 0.0f),
	isPointLight(false),
	isSpotLight(false)
{
	for (int i = 0; i < 10; ++i)
		m_PSConstantBuffer.dirLights.directionalLights[i] = DirectionalLight();
	m_PSConstantBuffer.dirLights.n = 0;
}

GameApp::~GameApp()
{
	delete name;// 释放内存
}

bool GameApp::Init()
{
	if (!D3DApp::Init())
		return false;

	if (!InitEffect())
		return false;

	if (!InitResource())
		return false;
	
	InitDSS();

	// 初始化鼠标，键盘不需要
	m_pMouse->SetWindow(m_hMainWnd);
	m_pMouse->SetMode(DirectX::Mouse::MODE_ABSOLUTE);

	return true;
}

void GameApp::InitDSS() {
	// ******************
	// 初始化混合状态
	//
	D3D11_BLEND_DESC blendDesc;
	ZeroMemory(&blendDesc, sizeof(blendDesc));
	auto& rtDesc = blendDesc.RenderTarget[0];
	// Alpha-To-Coverage模式
	blendDesc.AlphaToCoverageEnable = true;
	blendDesc.IndependentBlendEnable = false;
	rtDesc.BlendEnable = false;
	rtDesc.RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	HR(m_pd3dDevice->CreateBlendState(&blendDesc, BSAlphaToCoverage.GetAddressOf()));

	// 透明混合模式
	// Color = SrcAlpha * SrcColor + (1 - SrcAlpha) * DestColor 
	// Alpha = SrcAlpha
	blendDesc.AlphaToCoverageEnable = false;
	blendDesc.IndependentBlendEnable = false;
	rtDesc.BlendEnable = true;
	rtDesc.SrcBlend = D3D11_BLEND_SRC_ALPHA;
	rtDesc.DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	rtDesc.BlendOp = D3D11_BLEND_OP_ADD;
	rtDesc.SrcBlendAlpha = D3D11_BLEND_ONE;
	rtDesc.DestBlendAlpha = D3D11_BLEND_ZERO;
	rtDesc.BlendOpAlpha = D3D11_BLEND_OP_ADD;

	HR(m_pd3dDevice->CreateBlendState(&blendDesc, BSTransparent.GetAddressOf()));

	// 无颜色写入混合模式
	// Color = DestColor
	// Alpha = DestAlpha
	rtDesc.BlendEnable = false;
	rtDesc.SrcBlend = D3D11_BLEND_ZERO;
	rtDesc.DestBlend = D3D11_BLEND_ONE;
	rtDesc.BlendOp = D3D11_BLEND_OP_ADD;
	rtDesc.SrcBlendAlpha = D3D11_BLEND_ZERO;
	rtDesc.DestBlendAlpha = D3D11_BLEND_ONE;
	rtDesc.BlendOpAlpha = D3D11_BLEND_OP_ADD;
	rtDesc.RenderTargetWriteMask = 0;
	HR(m_pd3dDevice->CreateBlendState(&blendDesc, BSNoColorWrite.GetAddressOf()));

	// ******************
	// 初始化深度/模板状态
	//
	D3D11_DEPTH_STENCIL_DESC dsDesc;

	// 镜面标记深度/模板状态
	// 这里不写入深度信息
	// 无论是正面还是背面，原来指定的区域的模板值都会被写入StencilRef
	dsDesc.DepthEnable = true;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;

	dsDesc.StencilEnable = true;
	dsDesc.StencilReadMask = D3D11_DEFAULT_STENCIL_READ_MASK;
	dsDesc.StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;

	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	// 对于背面的几何体我们是不进行渲染的，所以这里的设置无关紧要
	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	HR(m_pd3dDevice->CreateDepthStencilState(&dsDesc, DSSMarkMirror.GetAddressOf()));

	// 反射绘制深度/模板状态
	// 由于要绘制反射镜面，需要更新深度
	// 仅当镜面标记模板值和当前设置模板值相等时才会进行绘制
	dsDesc.DepthEnable = true;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;

	dsDesc.StencilEnable = true;
	dsDesc.StencilReadMask = D3D11_DEFAULT_STENCIL_READ_MASK;
	dsDesc.StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;

	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_EQUAL;
	// 对于背面的几何体我们是不进行渲染的，所以这里的设置无关紧要
	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_EQUAL;

	HR(m_pd3dDevice->CreateDepthStencilState(&dsDesc, DSSDrawReflection.GetAddressOf()));

	// 无二次混合深度/模板状态
	// 允许默认深度测试
	// 通过自递增使得原来StencilRef的值只能使用一次，实现仅一次混合
	dsDesc.DepthEnable = true;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;

	dsDesc.StencilEnable = true;
	dsDesc.StencilReadMask = D3D11_DEFAULT_STENCIL_READ_MASK;
	dsDesc.StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;

	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_INCR;
	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_EQUAL;
	// 对于背面的几何体我们是不进行渲染的，所以这里的设置无关紧要
	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_INCR;
	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_EQUAL;

	HR(m_pd3dDevice->CreateDepthStencilState(&dsDesc, DSSNoDoubleBlend.GetAddressOf()));

	// 关闭深度测试的深度/模板状态
	// 若绘制非透明物体，务必严格按照绘制顺序
	// 绘制透明物体则不需要担心绘制顺序
	// 而默认情况下模板测试就是关闭的
	dsDesc.DepthEnable = false;
	dsDesc.StencilEnable = false;

	HR(m_pd3dDevice->CreateDepthStencilState(&dsDesc, DSSNoDepthTest.GetAddressOf()));
	// 进行深度测试，但不写入深度值的状态
	// 若绘制非透明物体时，应使用默认状态
	// 绘制透明物体时，使用该状态可以有效确保混合状态的进行
	// 并且确保较前的非透明物体可以阻挡较后的一切物体
	dsDesc.DepthEnable = true;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;
	dsDesc.StencilEnable = false;

	HR(m_pd3dDevice->CreateDepthStencilState(&dsDesc, DSSNoDepthWrite.GetAddressOf()));
}

void GameApp::OnResize()
{
	D3DApp::OnResize();
}

void GameApp::UpdateScene(float dt)
{
	angle += 1.5f * dt;

	// 获取鼠标状态
	Mouse::State mouseState = m_pMouse->GetState();
	Mouse::State lastMouseState = m_MouseTracker.GetLastState();
	// 获取键盘状态
	Keyboard::State keyState = m_pKeyboard->GetState();
	Keyboard::State lastKeyState = m_KeyboardTracker.GetLastState();

	// 更新鼠标按钮状态跟踪器，仅当鼠标按住的情况下才进行移动
	m_MouseTracker.Update(mouseState);
	m_KeyboardTracker.Update(keyState);

	XMFLOAT3 pos = { 0, 0, 0 };
	float moveSpeed = 40.0f;
	if (keyState.IsKeyDown(Keyboard::LeftShift)) moveSpeed *= 2.0f;
	if (keyState.IsKeyDown(Keyboard::W)) pos.z += moveSpeed * dt;
	if (keyState.IsKeyDown(Keyboard::S)) pos.z -= moveSpeed * dt;
	if (keyState.IsKeyDown(Keyboard::A)) pos.x -= moveSpeed * dt;
	if (keyState.IsKeyDown(Keyboard::D)) pos.x += moveSpeed * dt;
	if (keyState.IsKeyDown(Keyboard::Q)) viewRot.z += 0.6f * dt;
	if (keyState.IsKeyDown(Keyboard::E)) viewRot.z -= 0.6f * dt;

	if (mouseState.leftButton == true && m_MouseTracker.leftButton == m_MouseTracker.HELD) // 这两者似乎只有在鼠标按下的那一帧存在区别(此时左为true，右为false)?
	{
		viewRot.y += (mouseState.x - lastMouseState.x) * 0.5f * dt;
		viewRot.x += (mouseState.y - lastMouseState.y) * 0.5f * dt;
	}
	
	if (viewRot.x > 1.5f) viewRot.x = 1.5f;
	else if (viewRot.x < -1.5f) viewRot.x = -1.5f;
	/*
	if (viewRot.z > 0.7f) viewRot.z = 0.7f;
	else if (viewRot.z < -0.7f) viewRot.z = -0.7f;
	*/
	XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos),  XMMatrixRotationX(viewRot.x) * XMMatrixRotationZ(viewRot.z) * XMMatrixRotationY(viewRot.y)));
	viewPos.x += pos.x;
	viewPos.y += pos.y;
	viewPos.z += pos.z;
	m_VSConstantBuffer.view = XMMatrixTranspose(XMMatrixTranslation(-viewPos.x, -viewPos.y, -viewPos.z) * XMMatrixRotationY(-viewRot.y) * XMMatrixRotationZ(-viewRot.z) * XMMatrixRotationX(-viewRot.x));
	m_PSConstantBuffer.eyePos = { viewPos.x, viewPos.y, viewPos.z, 0.0f };

	if (m_KeyboardTracker.IsKeyPressed(Keyboard::D0))
	{
		m_PSConstantBuffer.dirLights.directionalLights[0] = m_DirLight;
		m_PSConstantBuffer.dirLights.n = 1;
		m_PSConstantBuffer.pointLight = PointLight();
		isPointLight = false;
		m_PSConstantBuffer.spotLight = SpotLight();
		isSpotLight = false;
	}
	else if (m_KeyboardTracker.IsKeyPressed(Keyboard::D1))
	{
		if (isPointLight) {
			m_PSConstantBuffer.pointLight = PointLight();
			isPointLight = false;
		}
		else {
			m_PSConstantBuffer.pointLight = m_PointLight;
			isPointLight = true;
		}
	}
	else if (m_KeyboardTracker.IsKeyPressed(Keyboard::D2))
	{
		if (isSpotLight) {
			m_PSConstantBuffer.spotLight = SpotLight();
			isSpotLight = false;
		}
		else {
			m_PSConstantBuffer.spotLight = m_SpotLight;
			isSpotLight = true;
		}
	}
	else if (m_KeyboardTracker.IsKeyPressed(Keyboard::F))
	{
		m_IsWireframeMode = !m_IsWireframeMode;
		m_pd3dImmediateContext->RSSetState(m_IsWireframeMode ? m_pRSWireframe.Get() : nullptr);
	}
	else if (m_KeyboardTracker.IsKeyPressed(Keyboard::OemPlus))
	{
		if (m_PSConstantBuffer.dirLights.n < 10) {
			DirectionalLight tempDirLight;
			tempDirLight.lightIntensity = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
			tempDirLight.direction = XMFLOAT3(-viewPos.x, -viewPos.y, -viewPos.z);
			m_PSConstantBuffer.dirLights.directionalLights[m_PSConstantBuffer.dirLights.n] = tempDirLight;
			++m_PSConstantBuffer.dirLights.n;
		}
	}
	else if (m_KeyboardTracker.IsKeyPressed(Keyboard::OemMinus))
	{
		if (m_PSConstantBuffer.dirLights.n > 0)
			--m_PSConstantBuffer.dirLights.n;
	}

	m_PSConstantBuffer.pointLight.position.x = sinf(angle * 0.2f) * 20.0f;
	m_PSConstantBuffer.pointLight.position.z = sinf(angle * 0.5f) * 20.0f;

	m_PSConstantBuffer.spotLight.position = viewPos;
	XMFLOAT3 dir = { 0, 0, 1.0f };
	XMStoreFloat3(&m_PSConstantBuffer.spotLight.direction, XMVector3Transform(XMLoadFloat3(&dir), XMMatrixRotationX(viewRot.x) * XMMatrixRotationZ(viewRot.z) * XMMatrixRotationY(viewRot.y)));

}

void GameApp::DrawScene()
{
	assert(m_pd3dImmediateContext);
	assert(m_pSwapChain);

	m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(), reinterpret_cast<const float*>(&Colors::LightGreen));
	m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	// 将顶点着色器绑定到渲染管线
	m_pd3dImmediateContext->VSSetShader(m_pVertexShader.Get(), nullptr, 0);
	//将几何着色器绑定到渲染管线
	m_pd3dImmediateContext->GSSetShader(m_pGeometryShader.Get(), nullptr, 0);
	//将像素着色器绑定到渲染管线
	m_pd3dImmediateContext->PSSetShader(m_pPixelShader.Get(), nullptr, 0);

	m_PSConstantBuffer.material.ambient = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	m_PSConstantBuffer.material.diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	m_PSConstantBuffer.material.specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 5.0f);
	D3D11_MAPPED_SUBRESOURCE mappedData;
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);

	m_VSConstantBuffer.world = XMMatrixTranspose(XMMatrixScaling(5.0f, 5.0f, 5.0f) * XMMatrixTranslation(0.0f, 5.0f, 2.0f));
	m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));
	DrawNameYu();

	m_PSConstantBuffer.material.ambient = XMFLOAT4(0.5f, 0.1f, 0.1f, 1.0f);
	m_PSConstantBuffer.material.diffuse = XMFLOAT4(1.0f, 0.2f, 0.1f, 1.0f);
	m_PSConstantBuffer.material.specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 10.0f);
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);
	for (int i = 1; i <= nameN; i++)
	{
		for (int j = 1; j <= nameN; j++)
		{
			float scale = (sinf(angle * 3.0f + i * j * 0.2f) + 1.3f) * 0.35f;
			DirectX::XMMATRIX mScale = XMMatrixScaling(scale, scale, scale);
			DirectX::XMMATRIX mRotate = XMMatrixRotationX(angle) * XMMatrixRotationY(angle);
			DirectX::XMMATRIX mTranslate = XMMatrixTranslation((i - (nameN + 1) / 2.0f) * 4.5f, 0, (j - (nameN + 1) / 2.0f) * 4.5f);
			m_VSConstantBuffer.world = XMMatrixTranspose(mScale * mRotate * mTranslate); // mul(vec, mat) 中为行向量，矩阵右乘，顺序SRT, 参考https://www.cnblogs.com/X-Jun/p/9808727.html#_lab2_1_1
			m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));

			DrawNameYu();

			srand(i * j + 1);
			DirectX::XMMATRIX mScaleChild = XMMatrixScaling(0.3f, 0.3f, 0.3f);
			DirectX::XMMATRIX mTranslateChild = XMMatrixTranslation(2.5f, 0, 0);
			for (int k = 1; k <= 1 + rand() % 3; k++)
			{
				DirectX::XMMATRIX mRotateChild = XMMatrixRotationX(rand() + angle) * XMMatrixRotationY(rand() + angle) * XMMatrixRotationY(rand() + angle);
				m_VSConstantBuffer.world = XMMatrixTranspose(mScaleChild * mTranslateChild * mScale * mRotateChild * mTranslate);
				m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));

				DrawNameYu();
			}
		}
	}
	//将顶点着色器解绑
	m_pd3dImmediateContext->VSSetShader(nullptr, nullptr, 0);
	//将几何着色器解绑
	m_pd3dImmediateContext->GSSetShader(nullptr, nullptr, 0);
	//将像素着色器解绑
	m_pd3dImmediateContext->PSSetShader(nullptr, nullptr, 0);
	//将顶点着色器绑定到渲染管线
	m_pd3dImmediateContext->VSSetShader(plane_pVertexShader.Get(), nullptr, 0);
	//将像素着色器绑定到渲染管线
	m_pd3dImmediateContext->PSSetShader(plane_pPixelShader.Get(), nullptr, 0);
	//透明混合
	m_pd3dImmediateContext->OMSetBlendState(BSTransparent.Get(), nullptr, 0xFFFFFFFF);

	m_PSConstantBuffer.material.ambient = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	m_PSConstantBuffer.material.diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	m_PSConstantBuffer.material.specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 5.0f);
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);
	m_VSConstantBuffer.world = XMMatrixTranspose(XMMatrixScaling(2.0f, 1.0f, 2.0f) * XMMatrixTranslation(0.0f, 0.0f, 0.0f));
	m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));
	m_VSConstantBuffer.angle += 0.005f;
	DrawPlane();

	//将顶点着色器解绑
	m_pd3dImmediateContext->VSSetShader(nullptr, nullptr, 0);
	//将像素着色器解绑
	m_pd3dImmediateContext->PSSetShader(nullptr, nullptr, 0);
	m_pd3dImmediateContext->OMSetBlendState(nullptr, nullptr, 0xFFFFFFFF);
	
	DrawMirror();//绘制镜子和镜像空间

	HR(m_pSwapChain->Present(0, 0));
}

void GameApp::DrawNameYu()//绘制禹字
{
	D3D11_MAPPED_SUBRESOURCE mappedData;
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[0].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(VSConstantBuffer), &m_VSConstantBuffer, sizeof(VSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[0].Get(), 0);
	m_pd3dImmediateContext->DrawIndexed(432, 0, 0);
}

void GameApp::DrawPlane()//绘制平面
{
	D3D11_MAPPED_SUBRESOURCE mappedData;
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[0].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(VSConstantBuffer), &m_VSConstantBuffer, sizeof(VSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[0].Get(), 0);
	m_pd3dImmediateContext->DrawIndexed(12, 432, 0);
}

void GameApp::DrawMirror()//绘制镜子和镜像区域
{
	D3D11_MAPPED_SUBRESOURCE mappedData;

	// 将顶点着色器绑定到渲染管线
	m_pd3dImmediateContext->VSSetShader(m_pVertexShader.Get(), nullptr, 0);
	//将像素着色器绑定到渲染管线
	m_pd3dImmediateContext->PSSetShader(m_pPixelShader.Get(), nullptr, 0);
	

	// *********************
	// 1. 给镜面反射区域写入值1到模板缓冲区

	m_pd3dImmediateContext->RSSetState(nullptr);
	m_pd3dImmediateContext->OMSetDepthStencilState(DSSMarkMirror.Get(), 1);
	m_pd3dImmediateContext->OMSetBlendState(BSNoColorWrite.Get(), nullptr, 0xFFFFFFFF);

	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);

	m_VSConstantBuffer.world = XMMatrixTranspose(XMMatrixScaling(1.0f, 1.0f, 1.0f) * XMMatrixTranslation(0.0f, 0.0f, 0.0f));
	m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));

	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[0].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(VSConstantBuffer), &m_VSConstantBuffer, sizeof(VSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[0].Get(), 0);

	m_pd3dImmediateContext->DrawIndexed(6, 432 + 12, 0);

	// ***********************
	// 2. 绘制不透明的反射物体
	// 开启反射绘制
	m_VSConstantBuffer.isMirror = 1.0f;
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[0].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(VSConstantBuffer), &m_VSConstantBuffer, sizeof(VSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[0].Get(), 0);
	m_PSConstantBuffer.isMirror = 1.0f;
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);

	// 绘制不透明物体，需要顺时针裁剪
	// 仅对模板值为1的镜面区域绘制
	m_pd3dImmediateContext->RSSetState(RSCullClockWise.Get());
	m_pd3dImmediateContext->OMSetDepthStencilState(DSSDrawReflection.Get(), 1);
	m_pd3dImmediateContext->OMSetBlendState(nullptr, nullptr, 0xFFFFFFFF);

	// 将顶点着色器绑定到渲染管线
	m_pd3dImmediateContext->VSSetShader(m_pVertexShader.Get(), nullptr, 0);
	//将几何着色器绑定到渲染管线
	m_pd3dImmediateContext->GSSetShader(m_pGeometryShader.Get(), nullptr, 0);
	//将像素着色器绑定到渲染管线
	m_pd3dImmediateContext->PSSetShader(m_pPixelShader.Get(), nullptr, 0);

	m_PSConstantBuffer.material.ambient = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	m_PSConstantBuffer.material.diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	m_PSConstantBuffer.material.specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 5.0f);
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);

	m_VSConstantBuffer.world = XMMatrixTranspose(XMMatrixScaling(5.0f, 5.0f, 5.0f) * XMMatrixTranslation(0.0f, 5.0f, 2.0f));
	m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));
	DrawNameYu();

	m_PSConstantBuffer.material.ambient = XMFLOAT4(0.5f, 0.1f, 0.1f, 1.0f);
	m_PSConstantBuffer.material.diffuse = XMFLOAT4(1.0f, 0.2f, 0.1f, 1.0f);
	m_PSConstantBuffer.material.specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 10.0f);
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);
	for (int i = 1; i <= nameN; i++)
	{
		for (int j = 1; j <= nameN; j++)
		{
			float scale = (sinf(angle * 3.0f + i * j * 0.2f) + 1.3f) * 0.35f;
			DirectX::XMMATRIX mScale = XMMatrixScaling(scale, scale, scale);
			DirectX::XMMATRIX mRotate = XMMatrixRotationX(angle) * XMMatrixRotationY(angle);
			DirectX::XMMATRIX mTranslate = XMMatrixTranslation((i - (nameN + 1) / 2.0f) * 4.5f, 0, (j - (nameN + 1) / 2.0f) * 4.5f);
			m_VSConstantBuffer.world = XMMatrixTranspose(mScale * mRotate * mTranslate); // mul(vec, mat) 中为行向量，矩阵右乘，顺序SRT, 参考https://www.cnblogs.com/X-Jun/p/9808727.html#_lab2_1_1
			m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));

			DrawNameYu();

			srand(i * j + 1);
			DirectX::XMMATRIX mScaleChild = XMMatrixScaling(0.3f, 0.3f, 0.3f);
			DirectX::XMMATRIX mTranslateChild = XMMatrixTranslation(2.5f, 0, 0);
			for (int k = 1; k <= 1 + rand() % 3; k++)
			{
				DirectX::XMMATRIX mRotateChild = XMMatrixRotationX(rand() + angle) * XMMatrixRotationY(rand() + angle) * XMMatrixRotationY(rand() + angle);
				m_VSConstantBuffer.world = XMMatrixTranspose(mScaleChild * mTranslateChild * mScale * mRotateChild * mTranslate);
				m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));

				DrawNameYu();
			}
		}
	}
	//将顶点着色器解绑
	m_pd3dImmediateContext->VSSetShader(nullptr, nullptr, 0);
	//将几何着色器解绑
	m_pd3dImmediateContext->GSSetShader(nullptr, nullptr, 0);
	//将像素着色器解绑
	m_pd3dImmediateContext->PSSetShader(nullptr, nullptr, 0);
	//将顶点着色器绑定到渲染管线
	m_pd3dImmediateContext->VSSetShader(plane_pVertexShader.Get(), nullptr, 0);
	//将像素着色器绑定到渲染管线
	m_pd3dImmediateContext->PSSetShader(plane_pPixelShader.Get(), nullptr, 0);
	//透明混合
	m_pd3dImmediateContext->OMSetBlendState(BSTransparent.Get(), nullptr, 0xFFFFFFFF);
	m_PSConstantBuffer.material.ambient = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	m_PSConstantBuffer.material.diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	m_PSConstantBuffer.material.specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 5.0f);
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);
	m_VSConstantBuffer.world = XMMatrixTranspose(XMMatrixScaling(2.0f, 1.0f, 2.0f) * XMMatrixTranslation(0.0f, 0.0f, 0.0f));
	m_VSConstantBuffer.worldInvTranspose = XMMatrixInverse(nullptr, XMMatrixTranspose(m_VSConstantBuffer.world));
	m_VSConstantBuffer.angle += 0.005f;
	DrawPlane();

	//将顶点着色器解绑
	m_pd3dImmediateContext->VSSetShader(nullptr, nullptr, 0);
	//将像素着色器解绑
	m_pd3dImmediateContext->PSSetShader(nullptr, nullptr, 0);

	// 关闭反射绘制
	m_VSConstantBuffer.isMirror = 0.0f;
	m_PSConstantBuffer.isMirror = 0.0f;
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[0].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(VSConstantBuffer), &m_VSConstantBuffer, sizeof(VSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[0].Get(), 0);
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_PSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);

	m_pd3dImmediateContext->RSSetState(nullptr);
	m_pd3dImmediateContext->OMSetDepthStencilState(nullptr, 0);
	m_pd3dImmediateContext->OMSetBlendState(nullptr, nullptr, 0xFFFFFFFF);

}

bool GameApp::InitEffect()
{
	ComPtr<ID3DBlob> blob;

	// 创建顶点着色器
	HR(CreateShaderFromFile(L"HLSL\\Light_VS.cso", L"HLSL\\Light_VS.hlsl", "VS", "vs_5_0", blob.ReleaseAndGetAddressOf()));
	HR(m_pd3dDevice->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, m_pVertexShader.GetAddressOf()));
	// 创建并绑定顶点布局
	HR(m_pd3dDevice->CreateInputLayout(VertexPosNormalColor::inputLayout, ARRAYSIZE(VertexPosNormalColor::inputLayout),
		blob->GetBufferPointer(), blob->GetBufferSize(), m_pVertexLayout.GetAddressOf()));

	//创建几何着色器
	HR(CreateShaderFromFile(L"HLSL\\Light_GS.cso", L"HLSL\\Light_GS.hlsl", "GS", "gs_5_0", blob.ReleaseAndGetAddressOf()));
	HR(m_pd3dDevice->CreateGeometryShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, m_pGeometryShader.GetAddressOf()));

	// 创建像素着色器
	HR(CreateShaderFromFile(L"HLSL\\Light_PS.cso", L"HLSL\\Light_PS.hlsl", "PS", "ps_5_0", blob.ReleaseAndGetAddressOf()));
	HR(m_pd3dDevice->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, m_pPixelShader.GetAddressOf()));

	// 创建plane顶点着色器
	HR(CreateShaderFromFile(L"HLSL\\Plane_VS.cso", L"HLSL\\Plane_VS.hlsl", "VS", "vs_5_0", blob.ReleaseAndGetAddressOf()));
	HR(m_pd3dDevice->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, plane_pVertexShader.GetAddressOf()));
	// 创建并绑定顶点布局
	HR(m_pd3dDevice->CreateInputLayout(VertexPosNormalColor::inputLayout, ARRAYSIZE(VertexPosNormalColor::inputLayout),
		blob->GetBufferPointer(), blob->GetBufferSize(), m_pVertexLayout.GetAddressOf()));

	// 创建plane像素着色器
	HR(CreateShaderFromFile(L"HLSL\\Plane_PS.cso", L"HLSL\\Plane_PS.hlsl", "PS", "ps_5_0", blob.ReleaseAndGetAddressOf()));
	HR(m_pd3dDevice->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, plane_pPixelShader.GetAddressOf()));

	return true;
}

bool GameApp::InitResource()
{
	// 创建对象，绘制类型为0
	name = new NameVertices(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// 设置三角形顶点
	VertexPosNormalColor* vertices = name->GetNameVertices(); // 通过对象获取顶点
	// 设置顶点缓冲区描述
	D3D11_BUFFER_DESC vbd;
	ZeroMemory(&vbd, sizeof(vbd));
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = (sizeof * vertices) * name->GetVerticesCount(); // 计算位宽
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbd.CPUAccessFlags = 0;
	// 新建顶点缓冲区
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	HR(m_pd3dDevice->CreateBuffer(&vbd, &InitData, m_pVertexBuffer.GetAddressOf()));

	// ******************
	// 索引数组

	WORD* indices = name->GetNameIndices(); // 通过对象获取索引
	// 设置索引缓冲区描述
	D3D11_BUFFER_DESC ibd;
	ZeroMemory(&ibd, sizeof(ibd));
	ibd.Usage = D3D11_USAGE_IMMUTABLE;
	ibd.ByteWidth = (sizeof * indices) * name->GetIndexCount(); // 计算位宽
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibd.CPUAccessFlags = 0;
	// 新建索引缓冲区
	InitData.pSysMem = indices;
	HR(m_pd3dDevice->CreateBuffer(&ibd, &InitData, m_pIndexBuffer.GetAddressOf()));
	// 输入装配阶段的索引缓冲区设置
	m_pd3dImmediateContext->IASetIndexBuffer(m_pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0);

	// ******************
	// 设置常量缓冲区描述
	//
	D3D11_BUFFER_DESC cbd;
	ZeroMemory(&cbd, sizeof(cbd));
	cbd.Usage = D3D11_USAGE_DYNAMIC;
	cbd.ByteWidth = sizeof(VSConstantBuffer);
	cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	// 新建用于VS和PS的常量缓冲区
	HR(m_pd3dDevice->CreateBuffer(&cbd, nullptr, m_pConstantBuffers[0].GetAddressOf()));
	cbd.ByteWidth = sizeof(PSConstantBuffer);
	HR(m_pd3dDevice->CreateBuffer(&cbd, nullptr, m_pConstantBuffers[1].GetAddressOf()));


	// ******************
	// 初始化默认光照
	// 方向光
	m_DirLight.lightIntensity = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	m_DirLight.direction = XMFLOAT3(-0.577f, -0.577f, 0.577f);
	// 点光
	m_PointLight.position = XMFLOAT3(0.0f, 0.0f, -10.0f);
	m_PointLight.lightIntensity = XMFLOAT4(0.4f, 0.8f, 0.4f, 1.0f);
	m_PointLight.att = XMFLOAT3(0.0f, 0.1f, 0.0f);
	m_PointLight.range = 25.0f;
	// 聚光灯
	m_SpotLight.position = XMFLOAT3(0.0f, 0.0f, -5.0f);
	m_SpotLight.direction = XMFLOAT3(0.0f, 0.0f, 1.0f);
	m_SpotLight.lightIntensity = XMFLOAT4(0.4f, 0.4f, 0.8f, 1.0f);
	m_SpotLight.att = XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_SpotLight.spot = 12.0f;
	m_SpotLight.range = 10000.0f;
	// 初始化用于VS的常量缓冲区的值
	m_VSConstantBuffer.world = XMMatrixIdentity();
	m_VSConstantBuffer.view = XMMatrixTranspose(XMMatrixTranslation(-viewPos.x, -viewPos.y, -viewPos.z) * XMMatrixRotationY(-viewRot.y) * XMMatrixRotationZ(-viewRot.z) * XMMatrixRotationX(-viewRot.x));
	m_VSConstantBuffer.proj = XMMatrixTranspose(XMMatrixPerspectiveFovLH(XM_PIDIV2, AspectRatio(), 1.0f, 1000.0f));
	m_VSConstantBuffer.worldInvTranspose = XMMatrixIdentity();
	m_VSConstantBuffer.angle = 0.0f;
	m_VSConstantBuffer.isMirror = 0.0f;
	// 初始化用于PS的常量缓冲区的值
	m_PSConstantBuffer.material.ambient = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	m_PSConstantBuffer.material.diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	m_PSConstantBuffer.material.specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 5.0f);
	m_PSConstantBuffer.isMirror = 0.0f;
	// 使用默认平行光
	m_PSConstantBuffer.dirLights.directionalLights[0] = m_DirLight;
	m_PSConstantBuffer.dirLights.n = 1;
	// 注意不要忘记设置此处的观察位置，否则高亮部分会有问题
	m_PSConstantBuffer.eyePos = { viewPos.x, viewPos.y, viewPos.z, 0.0f };

	// 更新PS常量缓冲区资源
	D3D11_MAPPED_SUBRESOURCE mappedData;
	HR(m_pd3dImmediateContext->Map(m_pConstantBuffers[1].Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedData));
	memcpy_s(mappedData.pData, sizeof(PSConstantBuffer), &m_VSConstantBuffer, sizeof(PSConstantBuffer));
	m_pd3dImmediateContext->Unmap(m_pConstantBuffers[1].Get(), 0);

	// ******************
	// 初始化光栅化状态
	//
	D3D11_RASTERIZER_DESC rasterizerDesc;
	ZeroMemory(&rasterizerDesc, sizeof(rasterizerDesc));
	rasterizerDesc.FillMode = D3D11_FILL_WIREFRAME;
	rasterizerDesc.CullMode = D3D11_CULL_NONE;
	rasterizerDesc.FrontCounterClockwise = false;
	rasterizerDesc.DepthClipEnable = true;
	HR(m_pd3dDevice->CreateRasterizerState(&rasterizerDesc, m_pRSWireframe.GetAddressOf()));

	// 无背面剔除模式
	rasterizerDesc.FillMode = D3D11_FILL_SOLID;
	rasterizerDesc.CullMode = D3D11_CULL_NONE;
	rasterizerDesc.FrontCounterClockwise = false;
	rasterizerDesc.DepthClipEnable = true;
	HR(m_pd3dDevice->CreateRasterizerState(&rasterizerDesc, RSNoCull.GetAddressOf()));

	// 顺时针剔除模式
	rasterizerDesc.FillMode = D3D11_FILL_SOLID;
	rasterizerDesc.CullMode = D3D11_CULL_BACK;
	rasterizerDesc.FrontCounterClockwise = true;
	rasterizerDesc.DepthClipEnable = true;
	HR(m_pd3dDevice->CreateRasterizerState(&rasterizerDesc, RSCullClockWise.GetAddressOf()));

	// ******************
	// 给渲染管线各个阶段绑定好所需资源
	//

	// 输入装配阶段的顶点缓冲区设置
	UINT stride = sizeof(VertexPosNormalColor);	// 跨越字节数
	UINT offset = 0;						// 起始偏移量
	
	m_pd3dImmediateContext->IASetInputLayout(m_pVertexLayout.Get());
	m_pd3dImmediateContext->IASetVertexBuffers(0, 1, m_pVertexBuffer.GetAddressOf(), &stride, &offset);
	// 设置图元类型，设定输入布局
	m_pd3dImmediateContext->IASetPrimitiveTopology(name->GetTopology());// 通过对象设置图元类型
	// VS常量缓冲区对应HLSL寄存于b0的常量缓冲区
	m_pd3dImmediateContext->VSSetConstantBuffers(0, 1, m_pConstantBuffers[0].GetAddressOf());
	// GS常量缓冲区对应HLSL寄存于b0的常量缓冲区
	m_pd3dImmediateContext->GSSetConstantBuffers(0, 1, m_pConstantBuffers[0].GetAddressOf());
	// PS常量缓冲区对应HLSL寄存于b1的常量缓冲区
	m_pd3dImmediateContext->PSSetConstantBuffers(1, 1, m_pConstantBuffers[1].GetAddressOf());

	// ******************
	// 设置调试对象名
	//
	D3D11SetDebugObjectName(m_pVertexBuffer.Get(), "VertexBuffer");
	D3D11SetDebugObjectName(m_pIndexBuffer.Get(), "IndexBuffer");
	D3D11SetDebugObjectName(m_pVertexLayout.Get(), "VertexPosNormalTexLayout");
	D3D11SetDebugObjectName(m_pConstantBuffers[0].Get(), "VSConstantBuffer");
	D3D11SetDebugObjectName(m_pConstantBuffers[1].Get(), "PSConstantBuffer");
	D3D11SetDebugObjectName(m_pVertexShader.Get(), "Light_VS");
	D3D11SetDebugObjectName(m_pPixelShader.Get(), "Light_PS");

	//初始化图片纹理
	CreateDDSTextureFromFile(
		m_pd3dDevice.Get(),								// [In]D3D设备
		L"images\\planeTexture.dds",					// [In]dds图片文件名
		nullptr,					// [Out]输出一个指向资源接口类的指针，也可以填nullptr
		planeTexture.GetAddressOf());		// [Out]输出一个指向着色器资源视图的指针，也可以填nullptr
	//设置着色器资源
	m_pd3dImmediateContext->PSSetShaderResources(0, 1, planeTexture.GetAddressOf());
	// 初始化采样器状态描述
	D3D11_SAMPLER_DESC sampDesc;
	ZeroMemory(&sampDesc, sizeof(sampDesc));
	sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sampDesc.MinLOD = 0;
	sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
	HR(m_pd3dDevice->CreateSamplerState(&sampDesc, m_pSamplerState.GetAddressOf()));
	m_pd3dImmediateContext->PSSetSamplers(0, 1, m_pSamplerState.GetAddressOf());

	return true;
}
