#pragma once


namespace Cndr
{
#ifdef CR_PLATFORM_WINDOWS

		#define Microsoft::WRL::ComPtr<IDXGISwapChain> T
		#define Microsoft::WRL::ComPtr<ID3D12Resource> T2

	#else
		#define T
		#define T2
		#error Platform Not Supported for SwapChain Creation in DirectX 12	

#endif // CR_PLATFORM_WINDOWS

	template<typename T,typename T2>
	class SwapChain
	{
	public:

		virtual void ChangeSwapChainBufferValue(int value );
		virtual bool GetSwapChainBufferValue();
		virtual void CreateSwapChain();
		virtual bool Get4xMsaaState()const;
		virtual void Set4xMsaaState(bool value);

	private:

	protected:
		int SwapChainBufferCount = 2;
		T m_SwapChain;
		T2 m_SwapChainBuffer[SwapChainBufferCount];
		DXGI_FORMAT m_BackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
		UINT m_4xMsaaQuality = 0;
	
	};
}