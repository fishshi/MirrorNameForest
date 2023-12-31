﻿#include "NameVertices.h"

using namespace DirectX;
NameVertices::NameVertices(D3D11_PRIMITIVE_TOPOLOGY type)
{
	topology = type;

	nameVertices = new GameApp::VertexPosNormalColor[]
	{
		{ XMFLOAT3(-1.9893f, 0.92f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2453f, 0.952f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1867f, 0.728f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9147f, 0.6907f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9893f, 0.92f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9893f, 0.92f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9147f, 0.6907f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9147f, 0.6907f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2453f, 0.952f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2453f, 0.952f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1867f, 0.728f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1867f, 0.728f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2453f, 0.952f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9893f, 0.92f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9147f, 0.6907f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1867f, 0.728f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9893f, 0.92f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2453f, 0.952f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2453f, 0.952f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9893f, 0.92f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9147f, 0.6907f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1867f, 0.728f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1867f, 0.728f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9147f, 0.6907f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.584f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.584f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.584f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.584f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.584f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.584f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.584f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.584f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.584f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.584f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.584f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.584f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.3813f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.3813f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.2373f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.2373f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.2373f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6267f, 0.2373f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.3813f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.3813f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.2373f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.2373f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.3813f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.2373f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.5067f, 0.2373f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.0347f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.0347f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.0347f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.0347f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.0347f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.0347f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.0347f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.0347f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.2373f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.0347f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.0347f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.2347f, 0.0347f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.8987f, 0.0347f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.0773f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.0773f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.0773f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.0773f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.0773f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.0773f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.0773f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.0773f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.0773f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.0773f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.0773f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.0773f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.296f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.968f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.968f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.968f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.968f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.296f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.296f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.968f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.968f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.296f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.968f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.968f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.296f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.296f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.296f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.968f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.968f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6853f, -0.968f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.9733f, -0.968f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.296f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.968f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.296f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.296f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.968f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.968f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.296f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.968f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.296f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.296f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.296f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.968f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.1387f, -0.968f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.7333f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.7333f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7733f, -0.968f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.7333f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.7333f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7733f, -0.968f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7733f, -0.968f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.7333f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.7333f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.7333f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.7333f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7733f, -0.968f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.7333f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.7333f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.7333f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.7333f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7733f, -0.968f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.4107f, -0.968f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7733f, -0.968f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, 0.7333f, -0.15f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, 0.7333f, -0.15f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, -0.4933f, -0.15f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, -0.4933f, -0.15f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, 0.7333f, 0.15f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, 0.7333f, -0.15f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, -0.4933f, -0.15f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, -0.4933f, 0.15f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, 0.7333f, -0.15f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, 0.7333f, 0.15f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, -0.4933f, 0.15f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, -0.4933f, -0.15f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, 0.7333f, 0.15f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, 0.7333f, 0.15f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, -0.4933f, 0.15f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, -0.4933f, 0.15f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, 0.7333f, 0.15f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, 0.7333f, 0.15f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, 0.7333f, -0.15f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, 0.7333f, -0.15f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, -0.4933f, -0.15f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, -0.4933f, -0.15f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.9227f, -0.4933f, 0.15f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.2f, -0.4933f, 0.15f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.632f, -0.4933f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7627f, -0.4667f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6773f, -0.6427f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6f, -0.728f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.632f, -0.4933f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.632f, -0.4933f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6f, -0.728f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6f, -0.728f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7627f, -0.4667f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7627f, -0.4667f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6773f, -0.6427f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6773f, -0.6427f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7627f, -0.4667f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.632f, -0.4933f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6f, -0.728f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6773f, -0.6427f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.632f, -0.4933f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7627f, -0.4667f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.7627f, -0.4667f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.632f, -0.4933f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6f, -0.728f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6773f, -0.6427f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6773f, -0.6427f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-1.6f, -0.728f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.3493f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6347f, -0.264f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.432f, -0.6267f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6453f, -0.712f, -0.2f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.3493f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.3493f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6453f, -0.712f, -0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6453f, -0.712f, 0.2f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6347f, -0.264f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6347f, -0.264f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.432f, -0.6267f, 0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.432f, -0.6267f, -0.2f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6347f, -0.264f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.3493f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6453f, -0.712f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.432f, -0.6267f, 0.2f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.3493f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6347f, -0.264f, 0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6347f, -0.264f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.832f, -0.3493f, -0.2f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6453f, -0.712f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.432f, -0.6267f, -0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.432f, -0.6267f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(-0.6453f, -0.712f, 0.2f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		//plane部分
		{ XMFLOAT3(-40.0f, 24.0f, -40.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		{ XMFLOAT3(40.0f, 24.0f, -40.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		{ XMFLOAT3(40.0f, 24.0f, 40.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		{ XMFLOAT3(-40.0f, 24.0f, 40.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		{ XMFLOAT3(-40.0f, 24.0f, -40.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		{ XMFLOAT3(40.0f, 24.0f, -40.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		{ XMFLOAT3(40.0f, 24.0f, 40.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		{ XMFLOAT3(-40.0f, 24.0f, 40.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 0.5f) },
		//Mirror部分
		{ XMFLOAT3(100.0f, 50.0f, 50.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(100.0f, 50.0f, -50.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(100.0f, -50.0f, -50.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
		{ XMFLOAT3(100.0f, -50.0f, 50.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f) },
	};

	nameIndices = new WORD[]
	{
		0, 1, 2, 2, 3, 0,
		4, 5, 6, 6, 7, 4,
		8, 9, 10, 10, 11, 8,
		12, 13, 14, 14, 15, 12,
		16, 17, 18, 18, 19, 16,
		20, 21, 22, 22, 23, 20,
		24, 25, 26, 26, 27, 24,
		28, 29, 30, 30, 31, 28,
		32, 33, 34, 34, 35, 32,
		36, 37, 38, 38, 39, 36,
		40, 41, 42, 42, 43, 40,
		44, 45, 46, 46, 47, 44,
		48, 49, 50, 50, 51, 48,
		52, 53, 54, 54, 55, 52,
		56, 57, 58, 58, 59, 56,
		60, 61, 62, 62, 63, 60,
		64, 65, 66, 66, 67, 64,
		68, 69, 70, 70, 71, 68,
		72, 73, 74, 74, 75, 72,
		76, 77, 78, 78, 79, 76,
		80, 81, 82, 82, 83, 80,
		84, 85, 86, 86, 87, 84,
		88, 89, 90, 90, 91, 88,
		92, 93, 94, 94, 95, 92,
		96, 97, 98, 98, 99, 96,
		100, 101, 102, 102, 103, 100,
		104, 105, 106, 106, 107, 104,
		108, 109, 110, 110, 111, 108,
		112, 113, 114, 114, 115, 112,
		116, 117, 118, 118, 119, 116,
		120, 121, 122, 122, 123, 120,
		124, 125, 126, 126, 127, 124,
		128, 129, 130, 130, 131, 128,
		132, 133, 134, 134, 135, 132,
		136, 137, 138, 138, 139, 136,
		140, 141, 142, 142, 143, 140,
		144, 145, 146, 146, 147, 144,
		148, 149, 150, 150, 151, 148,
		152, 153, 154, 154, 155, 152,
		156, 157, 158, 158, 159, 156,
		160, 161, 162, 162, 163, 160,
		164, 165, 166, 166, 167, 164,
		168, 169, 170, 170, 171, 168,
		172, 173, 174, 174, 175, 172,
		176, 177, 178, 178, 179, 176,
		180, 181, 182, 182, 183, 180,
		184, 185, 186, 186, 187, 184,
		188, 189, 190, 190, 191, 188,
		192, 193, 194, 194, 195, 192,
		196, 197, 198, 198, 199, 196,
		200, 201, 202, 202, 203, 200,
		204, 205, 206, 206, 207, 204,
		208, 209, 210, 210, 211, 208,
		212, 213, 214, 214, 215, 212,
		216, 217, 218, 218, 219, 216,
		220, 221, 222, 222, 223, 220,
		224, 225, 226, 226, 227, 224,
		228, 229, 230, 230, 231, 228,
		232, 233, 234, 234, 235, 232,
		236, 237, 238, 238, 239, 236,
		240, 241, 242, 242, 243, 240,
		244, 245, 246, 246, 247, 244,
		248, 249, 250, 250, 251, 248,
		252, 253, 254, 254, 255, 252,
		256, 257, 258, 258, 259, 256,
		260, 261, 262, 262, 263, 260,
		264, 265, 266, 266, 267, 264,
		268, 269, 270, 270, 271, 268,
		272, 273, 274, 274, 275, 272,
		276, 277, 278, 278, 279, 276,
		280, 281, 282, 282, 283, 280,
		284, 285, 286, 286, 287, 284,
		//Plane部分
		288, 289, 290, 290, 291, 288,
		295, 294, 293, 293, 292, 295,
		//Mirror部分
		296, 297, 298, 298, 299, 300,
	};
	verticesCount = 288 + 8 + 4;	//顶点总数
	indexCount = 432 + 12 + 6;		//索引总数
}

NameVertices::~NameVertices()
{
	delete nameVertices;
}

GameApp::VertexPosNormalColor* NameVertices::GetNameVertices()
{
	return nameVertices;
}

WORD* NameVertices::GetNameIndices()
{
	return nameIndices;
}

D3D11_PRIMITIVE_TOPOLOGY NameVertices::GetTopology()
{
	return topology;
}

UINT NameVertices::GetVerticesCount()
{
	return verticesCount;
}

UINT NameVertices::GetIndexCount()
{
	return indexCount;
}
