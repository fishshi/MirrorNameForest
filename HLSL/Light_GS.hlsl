#include "Light.hlsli"

// ������ɫ��
[maxvertexcount(6)]
void GS(triangle VertexOut gin[3], inout TriangleStream<VertexOut> stream)
{
    // ����ԭʼ���������㣬�����Ǵ��ݵ������
    for (int i = 0; i < 3; ++i)
        stream.Append(gin[i]);
    stream.RestartStrip();
    //��Z���Ͻ��о���Գ�
    for (int j = 2; j >= 0; --j)
    {
        VertexOut mirroredVertex = gin[j];

        mirroredVertex.Color = float4(0.2f, 0.5f, 0.8f, 1.0f);
        
        mirroredVertex.PosW.y = -mirroredVertex.PosW.y + 50.0f;
        
        mirroredVertex.PosH = mul(float4(mirroredVertex.PosW, 1.0f), mul(g_View, g_Proj));
        
        mirroredVertex.NormalW.y = -mirroredVertex.NormalW.y;
        
        stream.Append(mirroredVertex);
    }
    stream.RestartStrip();
}