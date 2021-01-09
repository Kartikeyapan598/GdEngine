#include "Renderer.h"

void Cndr::Renderer::Init()
{
	HRESULT res ;

	unsigned int createDeviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

	// if debug mode mode enabled create device with debug layer

#ifndef NDEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // !NDEBUG

	D3D_DRIVER_TYPE driver_types[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT num_driver_types = ARRAYSIZE(driver_types);

	//D3D_FEATURE_LEVEL feature_levels[] =
	//{
	//	D3D_FEATURE_LEVEL_11_0
	//};
	//UINT num_feature_levels = ARRAYSIZE(feature_levels);

	// Device Creation using D3D11CreateDevice

	res = D3D11CreateDevice(NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		0,
		createDeviceFlags,
		NULL,
		0,
		D3D11_SDK_VERSION,
		&m_d3d_device,
		&m_feature_level,
		&m_imm_context);

	if (SUCCEEDED(res))
	{
		CR_CORE_INFO("Successfully Created D3D11 Device ");
	}
		
	if (FAILED(res))
	{
		CR_CORE_CRITICAL("D3D11 device creation failed!");
	}

}

void Cndr::Renderer::Clear()
{
	if (m_imm_context && m_d3d_device)
	{
		m_imm_context->Release();
		m_d3d_device->Release();
		CR_CORE_INFO("D3D11 device and context successfully released \n Shut Down successful");
	}
	else  
	{ 
		CR_CORE_CRITICAL("Device Release Failed \n Shut Down Failed");
	}

}

//Cndr::Renderer* Cndr::Renderer::GetRenderer()
//{
//	static Renderer render_api;
//	return &render_api;
//}
