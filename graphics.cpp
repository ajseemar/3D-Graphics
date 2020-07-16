#include "pch.h"
#include "Graphics.h"
#include "colors.h"
//#include "utils.h"

using Microsoft::WRL::ComPtr;

void Graphics::initialize()
{
	Windows::UI::Core::CoreWindow^ win = Windows::UI::Core::CoreWindow::GetForCurrentThread();

	{
		ComPtr<ID3D11Device> _dev;
		ComPtr<ID3D11DeviceContext> _ctx;

		D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			D3D11_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_DEBUG,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&_dev,
			nullptr,
			&_ctx
		);

		_dev.As(&dev);
		_ctx.As(&ctx);
	}

	{
		DXGI_SWAP_CHAIN_DESC1 scd = { 0 };
		scd.Width = static_cast<UINT>(win->Bounds.Width);
		scd.Height = static_cast<UINT>(win->Bounds.Height);
		scd.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		scd.BufferCount = 2;
		scd.SampleDesc.Count = 1;
		scd.SampleDesc.Quality = 0;
		scd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
		scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

		ComPtr<IDXGIDevice1> dxgi;
		dev.As(&dxgi);

		ComPtr<IDXGIAdapter> adapter;
		dxgi->GetAdapter(&adapter);

		ComPtr<IDXGIFactory2> dxgiFactory;
		adapter->GetParent(__uuidof(IDXGIFactory2), &dxgiFactory);

		dxgiFactory->CreateSwapChainForCoreWindow(
			dev.Get(),
			reinterpret_cast<IUnknown*>(win),
			&scd,
			nullptr,
			&swapchain
		);
	}

	{
		ComPtr<ID3D11Texture2D> backbuffer;
		swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backbuffer);

		dev->CreateRenderTargetView(backbuffer.Get(), nullptr, &rtv);
	}

	vp.TopLeftX = 0.f;
	vp.TopLeftY = 0.f;
	vp.Width = win->Bounds.Width;
	vp.Height = win->Bounds.Height;
	vp.MinDepth = 0.f;
	vp.MaxDepth = 1.f;

	t = std::make_unique<Triangle>(dev, ctx);
}

void Graphics::update()
{
	t->update();
}

void Graphics::render()
{
	ctx->RSSetViewports(1u, &vp);
	
	ctx->OMSetRenderTargets(1u, rtv.GetAddressOf(), nullptr);

	ctx->ClearRenderTargetView(rtv.Get(), colors::sea_green.data());

	t->render();

	swapchain->Present(1u, 0u);
}
