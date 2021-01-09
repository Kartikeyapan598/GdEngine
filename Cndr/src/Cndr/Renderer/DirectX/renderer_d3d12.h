#pragma once

#include <wrl.h>
#include <D3d12.h>
#include <dxgi.h>

// Link necessary d3d12 libraries.
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")

#include <vector>
#include <string.h>

#include "Cndr/Application.h"

namespace Cndr
{
	
	class D3D12 
	{
	public :
		static D3D12* GetApp();
		bool Get4xMsaaState();
		void Set4xMsaaState(bool Value);
	private : // private methods
		void LogAdapters();
		void LogAdapterOutputs(IDXGIAdapter* adapter);
		void LogOutputDisplayModes(IDXGIOutput* output, DXGI_FORMAT format);

		void calculateFrameStats();
		void Get_Window_Handle() {}
		//HRESULT 

	protected : // protected methods
		inline void ReleaseCOM(IUnknown* pInterface) { pInterface->Release(); }
		D3D12(const D3D12& instance) = delete;
		D3D12& operator=(const D3D12& deep_copy) = delete;

		void CreateSwapChain();

	private : // private objects
		IDXGIFactory* mdxgiFactory;

		static D3D12* m_instance; // static instance of renderer

	protected : // protected Objects

		unsigned int Width;
		unsigned int Height;


		HWND renderer_hwnd;
		bool m_4xMsaaState = 0;
		UINT m_4xMsaaQuality = 0;
		int SwapChainBufferCount = 2;

		Microsoft::WRL::ComPtr<IDXGISwapChain> m_SwapChain;
		DXGI_FORMAT m_BackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;

		friend class Application;

	};
	
}