#pragma once
#include "HzPch.h"

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace HazQh
{
	class HAZQH_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//core log macros
#define HZ_CORE_TRACE(...) ::HazQh::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::HazQh::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::HazQh::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::HazQh::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::HazQh::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//client log macros
#define HZ_TRACE(...) ::HazQh::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...) ::HazQh::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...) ::HazQh::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...) ::HazQh::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...) ::HazQh::Log::GetClientLogger()->fatal(__VA_ARGS__)
