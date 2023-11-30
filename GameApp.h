#ifndef GAMEAPP_H
#define GAMEAPP_H

#include "d3dApp.h"
#include "LightHelper.h"

class NameVertices;// 声明类， 避免头文件与类之间的相互依赖

class GameApp : public D3DApp
{
public:
	struct VertexPosNormalColor
	{
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT3 normal;
		DirectX::XMFLOAT4 color;
		static const D3D11_INPUT_ELEMENT_DESC inputLayout[3];
	};

	struct VSConstantBuffer
	{
		DirectX::XMMATRIX world;
		DirectX::XMMATRIX view;
		DirectX::XMMATRIX proj;
		DirectX::XMMATRIX worldInvTranspose;
		float angle;
		float isMirror;
		float pad[2];
	};

	struct PSConstantBuffer
	{
		LightData dirLights;
		//DirectionalLight dirLight;
		PointLight pointLight;
		SpotLight spotLight;
		Material material;
		DirectX::XMFLOAT4 eyePos;
		float isMirror;
		float pad[3];
	};


public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();


private:
	bool InitEffect();
	bool InitResource();
	void InitDSS();
	void DrawNameYu();
	void DrawPlane();
	void DrawMirror();


private:
	ComPtr<ID3D11InputLayout> m_pVertexLayout;	    // 顶点输入布局
	ComPtr<ID3D11Buffer> m_pVertexBuffer;			// 顶点缓冲区
	ComPtr<ID3D11Buffer> m_pIndexBuffer;			// 索引缓冲区
	ComPtr<ID3D11Buffer> m_pConstantBuffers[2];	    // 常量缓冲区

	ComPtr<ID3D11VertexShader> m_pVertexShader;	    // 顶点着色器
	ComPtr<ID3D11VertexShader> plane_pVertexShader;	    // 顶点着色器
	ComPtr<ID3D11PixelShader> m_pPixelShader;		// 像素着色器
	ComPtr<ID3D11PixelShader> plane_pPixelShader;	// plane像素着色器
	ComPtr<ID3D11GeometryShader> m_pGeometryShader;	// 几何着色器
	VSConstantBuffer m_VSConstantBuffer;			// 用于修改用于VS的GPU常量缓冲区的变量
	PSConstantBuffer m_PSConstantBuffer;			// 用于修改用于PS的GPU常量缓冲区的变量

	DirectionalLight m_DirLight;					// 默认环境光
	PointLight m_PointLight;						// 默认点光
	SpotLight m_SpotLight;						    // 默认汇聚光

	ComPtr<ID3D11RasterizerState> m_pRSWireframe;	// 光栅化状态: 线框模式
	bool m_IsWireframeMode;							// 当前是否为线框模式

	ComPtr<ID3D11RasterizerState> RSNoCull;            // 光栅化器状态：无背面裁剪模式
	ComPtr<ID3D11RasterizerState> RSCullClockWise;    // 光栅化器状态：顺时针裁剪模式

	ComPtr<ID3D11ShaderResourceView> planeTexture;	//plane纹理
	ComPtr<ID3D11SamplerState> m_pSamplerState;		//采样器状态

	ComPtr<ID3D11BlendState> BSNoColorWrite;        // 混合状态：不写入颜色
	ComPtr<ID3D11BlendState> BSTransparent;        // 混合状态：透明混合
	ComPtr<ID3D11BlendState> BSAlphaToCoverage;    // 混合状态：Alpha-To-Coverage
	ComPtr<ID3D11DepthStencilState> DSSMarkMirror;       // 深度/模板状态：标记镜面区域
	ComPtr<ID3D11DepthStencilState> DSSDrawReflection;   // 深度/模板状态：绘制反射区域
	ComPtr<ID3D11DepthStencilState> DSSNoDoubleBlend;    // 深度/模板状态：无二次混合区域
	ComPtr<ID3D11DepthStencilState> DSSNoDepthTest;      // 深度/模板状态：关闭深度测试
	ComPtr<ID3D11DepthStencilState> DSSNoDepthWrite;		// 深度/模板状态：仅深度测试，不写入深度值

	NameVertices* name;// 存储绘制名字的顶点、类型
	int nameN;
	float angle;
	DirectX::XMFLOAT3 viewPos;
	DirectX::XMFLOAT3 viewRot;

	bool isPointLight;
	bool isSpotLight;
};


#endif