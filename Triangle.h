#pragma once
#include "utils.h"

class Triangle
{
public:
	Triangle(Microsoft::WRL::ComPtr<ID3D11Device1> dev, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> ctx);
	void update();
	void render();

	struct Vertex {
		float x, y, z;
	};

	struct ConstantBuffer {
		float r, g, b, a;
	};

private:
	Microsoft::WRL::ComPtr<ID3D11Device1> dev;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1> ctx;

	Microsoft::WRL::ComPtr<ID3D11Buffer> vb;
	Microsoft::WRL::ComPtr<ID3D11Buffer> cb;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> vs;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> ps;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> il;

	UINT offset;
	UINT stride;

	float r;
	float g;
	float b;
	float a;
};

