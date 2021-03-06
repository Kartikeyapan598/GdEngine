#pragma once
#include "Cndrpch.h"
#include "Core.h"
#include "Platform/Platform.h"

#ifdef CR_PLATFORM_WINDOWS

extern Cndr::Application* Cndr::CreateApp();

int main(int argc, char** argv)
{

	Cndr::Log::Init();
	CR_CORE_WARN("Core Initialized");
	CR_TRACE("Editor Log");

	auto app = Cndr::CreateApp();
	app->Run();
	delete app;

}


#endif