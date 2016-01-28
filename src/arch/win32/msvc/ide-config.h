#ifndef VICE_CONFIG_H_
#define VICE_CONFIG_H_

#define UNSTABLE

/* FIXME: Doesn't work with the rewrite. #define FEATURE_CPUMEMHISTORY 1*/
#define HAVE_WORKING_VSNPRINTF

#if defined _MSC_VER && _MSC_VER < 1400 
# define vsnprintf _vsnprintf
#endif

#if defined _MSC_VER
#pragma warning(disable:4996)
#endif

#define HAVE_ALLOCA             1
#define RETSIGTYPE              void
#define HAVE_RESID              1
#define HAVE_RESID_FP           1
#define HAVE_RESID_DTV          1
#define HAS_JOYSTICK            1
#define HAVE_MOUSE              1
#ifdef __ANDROID__
#	undef HAVE_CATWEASELMKIII
#	undef HAVE_HARDSID
#else //__ANDROID__
#	define HAVE_CATWEASELMKIII  1
#	define HAVE_HARDSID         1
#endif //__ANDROID__
#define HAVE_RS232              1
#define HAVE_DYNLIB_SUPPORT     1

#ifndef WINIA64
#define HAVE_PARSID             1
#endif

#define HAS_LONGLONG_INTEGER    1
#define HAS_UNLOCKRESOURCE      1
#define SIZEOF_UNSIGNED_INT     4
#define SIZEOF_UNSIGNED_LONG    4
#define SIZEOF_UNSIGNED_SHORT   2
#define HAVE_ATEXIT             1
#define HAVE_MEMMOVE            1
#define HAVE_STRERROR           1
#define HAVE_FCNTL_H            1
#define HAVE_LIMITS_H           1
#define HAVE_COMMCTRL_H         1
#define HAVE_SHLOBJ_H           1
#ifdef __ANDROID__
#	undef HAVE_DIRECT_H
#else
#	define HAVE_DIRECT_H        1
#endif
#define HAVE_DIRENT_H           1
#define HAVE_ERRNO_H            1
#ifdef __ANDROID__
#	undef HAVE_IO_H
#else
#	define HAVE_IO_H            1
#endif
#define HAVE_PROCESS_H          1
#define HAVE_SYS_TYPES_H        1
#define HAVE_SYS_STAT_H         1
#define HAVE_SIGNAL_H           1
#define HAVE_WINIOCTL_H         1

#define DWORD_IS_LONG           1
#ifdef __ANDROID__
#	undef HAVE_TFE
#else //__ANDROID__
#	define HAVE_TFE             1
#endif //__ANDROID__
#define HAVE_FFMPEG             1
#define HAVE_FFMPEG_SWSCALE     1
#define HAVE_FFMPEG_HEADER_SUBDIRS 1

#ifndef _WIN64
#define FFMPEG_ALIGNMENT_HACK   1
#endif

#define HAVE_OPENCBM            1
#define HAVE_MIDI               1
#define HAVE_CRTDBG             1
#define HAS_TRANSLATION         1
#define HAVE_HTONL              1
#define HAVE_HTONS              1
#ifdef __ANDROID__
#	undef HAVE_NETWORK
#else
#	define HAVE_NETWORK            1
#endif
#define HAVE_GETCWD             1

#ifndef NODIRECTX
#	ifdef __ANDROID__
//...
#	else //__ANDROID__
#		define HAVE_DINPUT      1
#		define USE_DXSOUND      1
#		define HAVE_DSOUND_LIB  1
#	endif //__ANDROID__
#	ifndef WINIA64
#		define HAVE_GUIDLIB     1
#	endif
#endif

#if !defined(_M_AMD64) && !defined(WINIA64)
#define __i386__                1
#endif

#ifdef _M_AMD64
#define __amd64__               1
#endif

#define inline                  _inline

#define _ANONYMOUS_UNION

#ifndef __ANDROID__
#	define S_ISDIR(m)              ((m) & _S_IFDIR)
#endif

#define MSVC_RC                 1

#define strcasecmp(s1, s2)      _stricmp(s1, s2)
#define HAVE_STRCASECMP         1

//#define snprintf _snprintf

/* begin: for FFMPEG: common.h */
#define CONFIG_WIN32

#define int64_t_C(c)     (c ## i64)
#define uint64_t_C(c)    (c ## ui64)
/* end: for FFMPEG: common.h */

#ifdef __ANDROID__
#	define PLATFORM "android armv7a armv8a x86 x64 gcc"
#	define PLATFORM_OS "android"
#	define PLATFORM_CPU "armv7a, armv8a, x86, x64"
#	define PLATFORM_COMPILER "gcc"
#elif defined(WINIA64)
#	define PLATFORM "win64 ia64 msvc"
#	define PLATFORM_OS "win64"
#	define PLATFORM_CPU "ia64"
#	define PLATFORM_COMPILER "msvc"
#else
#  ifdef _WIN64
#    define PLATFORM "win64 x64 msvc"
#    define PLATFORM_OS "win64"
#    define PLATFORM_CPU "x64"
#    define PLATFORM_COMPILER "msvc"
#  else
#    define PLATFORM "win32 x86 msvc"
#    define PLATFORM_OS "win32"
#    define PLATFORM_CPU "x86"
#    define PLATFORM_COMPILER "msvc"
#  endif
#endif

#endif
