#pragma once
#include "Cndr/Interface/SwapChain.h"

namespace Cndr
{


	class SwapChain_dx12
	{
	public:

		virtual void ChangeSwapChainBufferValue(int value);
		virtual bool GetSwapChainBufferValue();
		virtual void CreateSwapChain();
		virtual bool Get4xMsaaState()const;
		virtual void Set4xMsaaState(bool value);

	private:

	protected:
		static const int SwapChainBufferCount = 2;
		static Microsoft::WRL::ComPtr<IDXGISwapChain> m_SwapChain;
		static Microsoft::WRL::ComPtr<ID3D12Resource> m_SwapChainBuffer[SwapChainBufferCount];
	};


}