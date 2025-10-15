#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace le {

	class LE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define LE_CORE_TRACE(...)	::le::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LE_CORE_INFO(...)	::le::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LE_CORE_WARN(...)	::le::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LE_CORE_ERROR(...)	::le::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LE_CORE_FATAL(...)	::le::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LE_TRACE(...)		::le::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LE_INFO(...)		::le::Log::GetClientLogger()->info(__VA_ARGS__)
#define LE_WARN(...)		::le::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LE_ERROR(...)		::le::Log::GetClientLogger()->error(__VA_ARGS__)
#define LE_FATAL(...)		::le::Log::GetClientLogger()->fatal(__VA_ARGS__)