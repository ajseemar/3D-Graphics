#pragma once
class Graphics
{
public:
	void initialize();
	void update();
	void render();

private:
	Microsoft::WRL::ComPtr<ID3D11Device1> dev;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1> ctx;
	Microsoft::WRL::ComPtr<IDXGISwapChain1> swapchain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> rtv;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> dsv;
	//Microsoft::WRL::ComPtr<ID3D11DepthStencilState> dss;
};

