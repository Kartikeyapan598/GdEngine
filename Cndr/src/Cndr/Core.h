#pragma once


// ----- Basic Macros Defined Here ----- //


#ifdef CR_PLATFORM_WINDOWS
	#ifdef CR_BUILD_API
		#define CR_API __declspec(dllexport)
	#else
		#define CR_API __declspec(dllimport)
	#endif // CR_BUILD_API
#else	
	 #error CNDR Supports Windows x64 Only
#endif // CR_PLATFORM_WINDOWS

#ifdef CR_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) {if(!(x)) {CR_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) {if(!(x)) {CR_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CR_ASSERT(x, ...)
	#define CR_CORE_ASSERT(x, ...)
#endif
