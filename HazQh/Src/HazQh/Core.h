#pragma once

#ifdef HAZQH_PLATFORM_WINDOWS
	#ifdef HAZQH_BUILD_DLL
		#define HAZQH_API _declspec(dllexport)
	#else
		#define HAZQH_API _declspec(dllimport)
	#endif // HazQh_API
#else
	#error HazQh Only Windows!
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x,...) { if(!(x)) {HZ_ERROR("Assertion Failed:{0}",__VA_ARGS__); __debugbreak();} }
	#define HZ_CORE_ASSERT(x,...) { if(!(x)) {HZ_CORE_ERROR("Assertion Core Failed:{0}",__VA_ARGS__); __debugbreak();} }
#else
	#define HZ_ASSERT(x,...)
	#define HZ_CORE_ASSERT(x,...)
#endif


#define BIT(x) (1<<x )