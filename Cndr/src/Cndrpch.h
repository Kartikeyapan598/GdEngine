#pragma once

// Macros Start

#if defined(DEBUG) || defined(_DEBUG)
	#if defined(_MSC_VER)
		#define _CRT_SECURE_NO_WARNINGS
	#endif

	#define _CRTDGB_MAP_ALLOC
	#include <dxgidebug.h>
	#include <crtdbg.h>

#endif


#include <memory>
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
#include <thread>
#include <exception>
#include <chrono>

#include <fcntl.h>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <wrl.h>			//FAILED macro defined here;


// Cndr Includes

#include "Cndr/Core/Core.h"
#include "Platform/Platform.h"
#include "Cndr/Core/Log.h"

// Cndr Instrumentor
#include "Cndr/Profiler/Instrumentor.h"

#ifndef ReleaseCom
#define ReleaseCom(x) { if(x){ x->Release(); x = 0; } }
#endif

namespace Cndr
{
	inline void ThrowIfFailed(HRESULT hr)
	{
		if (FAILED(hr))
		{
			// Sets Break point on this line to catch DirectX API errors
			throw std::exception();
		}
	}
}