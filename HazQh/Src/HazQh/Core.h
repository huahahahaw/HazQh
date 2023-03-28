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