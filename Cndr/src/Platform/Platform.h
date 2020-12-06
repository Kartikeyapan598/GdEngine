#pragma once


#if defined(_WIN64)
	#include <Windows.h>
	//#include interface for basic windows
	#include "Interface/Window.h"
#elif defined(_WIN32)
	// include Windows.h file
	#include <Windows.h>
	#include "Interface/Window.h"
#elif defined(__linux__)
	#error Linux not Supported!
	//#include "IWindow.h"
#else 
	#error Platform not Supported!
#endif
