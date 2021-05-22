#include "Cndrpch.h"
#include "Log.h"

namespace Cndr
{
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("Cndr");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Edtr");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}