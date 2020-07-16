#include "pch.h"
#include "Triangle.h"
//#include "utils.h"

Triangle::Triangle(Microsoft::WRL::ComPtr<ID3D11Device1> dev, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> ctx) : dev(dev), ctx(ctx), r(1.f), g(0.f), b(0.f), a(1.f)
{
	Vertex verts[] =
	{
		{ -0.5f, -0.5f, 0.f },
		{   0.f,  0.5f, 0.f },
		{  0.5f, -0.5f, 0.f },
	};

	offset = 0u;
	stride = sizeof(Vertex);

	{
		D3D11_BUFFER_DESC vbd = { 0 };
		vbd.ByteWidth = stride * ARRAYSIZE(verts);
		vbd.StructureByteStride = stride;
		vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA vd = { 0 };
		vd.pSysMem = verts;

		dev->CreateBuffer(&vbd, &vd, &vb);
	}

	{
		ConstantBuffer cbuf = { r, g, b, a };
		D3D11_BUFFER_DESC cbd = { 0 };
		cbd.ByteWidth = sizeof(ConstantBuffer);
		cbd.StructureByteStride = sizeof(float);
		cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbd.Usage = D3D11_USAGE_DEFAULT;

		D3D11_SUBRESOURCE_DATA cbdata = { 0 };
		cbdata.pSysMem = &cbuf;
		cbdata.SysMemSlicePitch = 0u;
		cbdata.SysMemPitch = 0u;

		dev->CreateBuffer(&cbd, &cbdata, &cb);
	}

	HRESULT hr;

	{
		auto vsdata = LoadShaderFile("TriangleVertexShader.cso");
		hr = dev->CreateVertexShader(vsdata->Data, vsdata->Length, nullptr, &vs);
		if (FAILED(hr)) {
			OutputDebugString(L"Failed to create vertex shader");
		}

		D3D11_INPUT_ELEMENT_DESC ied[] =
		{
			{ "POSITION", 0u, DXGI_FORMAT_R32G32B32_FLOAT, 0u, 0u, D3D11_INPUT_PER_VERTEX_DATA, 0u }
		};

		dev->CreateInputLayout(ied, ARRAYSIZE(ied), vsdata->Data, vsdata->Length, &il);
	}
	
	{
		auto psdata = LoadShaderFile("TrianglePixelShader.cso");
		hr = dev->CreatePixelShader(psdata->Data, psdata->Length, nullptr, &ps);
		if (FAILED(hr)) {
			OutputDebugString(L"Failed to create pixel shader");
		}
	}
}

void Triangle::update()
{
	ConstantBuffer cbuf = { r, g, b, a };
	ctx->UpdateSubresource(cb.Get(), 0u, nullptr, &cbuf, 0u, 0u);
}

void Triangle::render()
{
	ctx->IASetVertexBuffers(0u, 1u, vb.GetAddressOf(), &stride, &offset);
	ctx->IASetInputLayout(il.Get());
	ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	ctx->VSSetShader(vs.Get(), nullptr, 0u);

	ctx->PSSetShader(ps.Get(), nullptr, 0u);
	ctx->PSSetConstantBuffers(0u, 1u, cb.GetAddressOf());

	ctx->Draw(3u, 0u);
}
