#pragma once

#include <memory>
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
#include <thread>
#include <exception>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <exception>
#include <wrl.h>			//FAILED macro defined here;


// Cndr Includes

#include "Cndr/Core.h"
#include "Cndr/Interface/Window.h"
//#include "Cndr/Interface/RenderApi.h"
#include "Platform/Platform.h"
#include "Cndr/Log.h"

#if defined(DEBUG) || defined(_DEBUG)
	#include <dxgidebug.h>
	#define _CRTDGB_MAP_ALLOC
	#include <crtdbg.h>
#endif

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