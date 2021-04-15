#pragma once
#include "Cndrpch.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Cndr/Core.h"

namespace Cndr
{

	class CR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr < spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr < spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private :
		static std::shared_ptr<spdlog::logger> s_CoreLogger ;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log Macros

#define CR_CORE_ERROR(...)			::Cndr::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CR_CORE_WARN(...)			::Cndr::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_INFO(...)			::Cndr::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_TRACE(...)			::Cndr::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_CRITICAL(...)		::Cndr::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros

#define CR_ERROR(...)				::Cndr::Log::GetClientLogger()->error(__VA_ARGS__)
#define CR_WARN(...)				::Cndr::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CR_INFO(...)				::Cndr::Log::GetClientLogger()->info(__VA_ARGS__)
#define CR_TRACE(...)				::Cndr::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CR_CRITICAL(...)			::Cndr::Log::GetClientLogger()->critical(__VA_ARGS__)
