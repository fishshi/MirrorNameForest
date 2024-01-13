#include "Light.hlsli"

// ¶¥µã×ÅÉ«Æ÷
VertexOut VS(VertexIn vIn)
{
    VertexOut vOut;
    matrix viewProj = mul(g_View, g_Proj);
    float4 posW = mul(float4(vIn.PosL, 1.0f), g_World);
    vOut.PosW = posW.xyz;
    vOut.NormalW = mul(vIn.NormalL, (float3x3) g_WorldInvTranspose);
    vOut.Color = vIn.Color;
    if (VSisMirror == 1.0f)
    {
        vOut.NormalW.x = -vOut.NormalW.x;
        vOut.PosW.x = 200.0f - vOut.PosW.x;
    }
    vOut.PosH = mul(float4(vOut.PosW, 1.0f), viewProj);
    return vOut;
}