#pragma once
//Device作成に必要なヘッダー
#include <Windows.h>
#include <D3D11.h>
#include <d3dx11.h>
#include <d3dCompiler.h>

typedef class CDeviceCreate
{
public:
	CDeviceCreate() {};
	~CDeviceCreate() {};
	static HRESULT APIENTRY InitDevice(HWND hWnd, int w, int h);
	static void ShutDown();

	static ID3D11Device*			GetDevice() { return m_pDevice; }
	static ID3D11DeviceContext*		GetDeviceContext() { return m_pDeviceContext; }
	static ID3D11RasterizerState*	GetRS() { return m_pRS; }
	static ID3D11RenderTargetView*	GetRTV() { return m_pRTV; }
	static ID3D11RenderTargetView** GetppRTV() { return &m_pRTV; }
	static IDXGISwapChain*			GetSwapChain() { return m_pDXGISwapChain; }


private:
	static ID3D11Device*			m_pDevice;
	static ID3D11DeviceContext*		m_pDeviceContext;
	static ID3D11RasterizerState*	m_pRS;
	static ID3D11RenderTargetView*	m_pRTV;
	static ID3D11BlendState*		m_pBlendState;
	static IDXGIAdapter*			m_pDXGIAdapter;
	static IDXGIFactory*			m_pDXGIFactory;
	static IDXGISwapChain*			m_pDXGISwapChain;
	static IDXGIOutput**			m_ppDXGIOutputArray;
	static UINT						m_nDXGIOutputArraySize;
	static IDXGIDevice1*			m_pDXGIDevice;
	static D3D_FEATURE_LEVEL		m_FeatureLevel;

}Dev;