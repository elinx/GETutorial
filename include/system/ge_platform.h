#ifndef GE_PLATEFORM_H
#define GE_PLATEFORM_H

//
// NOTE:
//	Define pre-precess macros for DLL export import, and system macros
//
//

#ifdef _WIN32
	#define GE_SYS_WINDOWS
	//defined to disalbe <windows.h> from defining the min and max macros
	#ifndef NOMINMAX
	#define NOMINMAX
	#endif

#elif defined (__linux__)
#define GE_SYS_LINUX
#elif defined (__APPLE__)
#define GE_SYS_MACOS
#endif

#ifndef GE_STATIC_BUILD
	#ifdef GE_SYS_WINDOWS

		#ifdef GE_NONCLIENT_BUILD
			#define GE_API __declspec(dllexport)
		#else
			#define GE_API __declspec(dllimport)
		#endif

		// Visual C++ compiler warning C4251 disalbe
		#ifdef _MSC_VER
		#pragma warning(disable : 4251)
		#endif
#else
		#ifdef __GNUC__ >= 4
		#define GE_API __attribute__((__visiblitity__("default")))
		#else
		#define GE_API GE_API
		#endif
	#endif
#endif

#endif