#pragma once


#if defined(_WIN64) || defined(_WIN32)
	#define CR_PLATFORM_WINDOWS
	#if defined (_WIN64)
		#include <Windows.h>
		#include <wincodec.h>
		// Interface Files Depending Platform
		#include "Interface/Window.h"
		// Rendering API
		#include <d3d12.h>
		#include <dxgi1_6.h>
	#elif defined(_WIN32)
		#error x86 Systems Not yet Supported!
	#endif
#elif defined(__linux__) || defined(__FreeBSD__)
	#define CR_PLATFORM_LINUX
	#error Linux not Supported!
#elif defined (__APPLE__)
	#define CR_PLATFORM_X
	#error Platform not Supported!
#else
	#define CR_PLATFORM_FAILED
	#error Platform not Supported!
#endif