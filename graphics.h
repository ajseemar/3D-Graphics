#pragma once
#include "Triangle.h"
//#include "utils.h"

class Graphics
{
public:
	void initialize();
	void update();
	void render();

private:
	void draw_triangle();
	void draw_triangle_official();

private:
	Microsoft::WRL::ComPtr<ID3D11Device1> dev;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1> ctx;
	Microsoft::WRL::ComPtr<IDXGISwapChain1> swapchain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> rtv;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> dsv;
	//Microsoft::WRL::ComPtr<ID3D11DepthStencilState> dss;
	D3D11_VIEWPORT vp = { 0 };

	std::unique_ptr<Triangle> t;
};

