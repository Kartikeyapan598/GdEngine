#pragma once

#include "Core.h"

#include "Platform/Windows/PltWindows.h"
#include "Core/Main_Thread.h"

class PltWindows;
// class Main_Thread;
#ifdef CR_PLATFORM_WINDOWS

extern Cndr::Application* Cndr::CreateApp();

int main(int argc, char** argv)
{

	Cndr::Log::Init();
	CR_CORE_WARN("Core Initialized");
	CR_TRACE("Editor Log");

	// Cndr::Main_Thread::main_process->Begin();

	auto app = Cndr::CreateApp();
	app->Run();
	delete app;

}


#endif