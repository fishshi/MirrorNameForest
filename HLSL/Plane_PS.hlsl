#include "Light.hlsli"

// 像素着色器
float4 PS(VertexOut pIn) : SV_Target
{
    // 标准化法向量
    pIn.NormalW = normalize(pIn.NormalW);

    // 顶点指向眼睛的向量
    float3 toEyeW = normalize(g_EyePosW - pIn.PosW);

    // 初始化为0
    float4 ambient, diffuse, spec;
    float4 A, D, S;
    ambient = diffuse = spec = A = D = S = float4(0.0f, 0.0f, 0.0f, 0.0f);
    
    DirectionalLight nowLight;
    for (int i = 0; i < g_DirLights.n; ++i)
    {
        nowLight = g_DirLights.directionalLights[i];
        if (PSisMirror == 1.0f)
        {
            nowLight.Direction.x = -nowLight.Direction.x;
        }
        ComputeDirectionalLight(g_Material, nowLight, pIn.NormalW, toEyeW, A, D, S);
        ambient += A;
        diffuse += D;
        spec += S;
    }
    
    PointLight pointLight = g_PointLight;
    if (PSisMirror == 1.0f)
    {
        pointLight.Position.x = 200.0f - pointLight.Position.x;
    }
    ComputePointLight(g_Material, pointLight, pIn.PosW, pIn.NormalW, toEyeW, A, D, S);
    ambient += A;
    diffuse += D;
    spec += S;

    SpotLight spotLight = g_SpotLight;
    if (PSisMirror == 1.0f)
    {
        spotLight.Position.x = 200.0f - spotLight.Position.x;
        spotLight.Direction.x = -spotLight.Direction.x;
    }
    ComputeSpotLight(g_Material, spotLight, pIn.PosW, pIn.NormalW, toEyeW, A, D, S);
    ambient += A;
    diffuse += D;
    spec += S;
    
    float4 texColor = g_Tex.Sample(g_SamLinear, (float2)pIn.Color);
    float4 litColor = texColor * (ambient + diffuse) + spec;
    litColor.a = 0.6f;
    
    return litColor;
}