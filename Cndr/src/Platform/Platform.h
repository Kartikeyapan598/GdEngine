#pragma once


#if defined(_WIN64)
	#include <Windows.h>
	#include <WindowsX.h>
	//#include interface for basic windows
	#include "Cndr/Interface/Window.h"
#elif defined(_WIN32)
	// include Windows.h file
	#include <Windows.h>
	#include <WindowsX.h>
	#include "Interface/Window.h"
#elif defined(__linux__)
	#error Linux not Supported!
	// include Windows.h file
#else 
	#error Platform not Supported!
#endif
