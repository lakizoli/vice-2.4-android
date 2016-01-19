@ECHO OFF

REM Rename windows specific platform headers
rename ..\src\arch\win32\msvc\inttypes.h __inttypes.h
rename ..\src\arch\win32\msvc\stdint.h __stdint.h
rename ..\src\arch\win32\msvc\dirent.h __dirent.h
rename ..\src\arch\win32\msvc\msvc_ver.h __msvc_ver.h

REM All abi settings
REM	"APP_ABI=x86 armeabi armeabi-v7a"

REM Run build (debug)
ndk-build ^
	-j1 ^
	NDK_PROJECT_PATH=. ^
	NDK_LIBS_OUT=jniLibs ^
	APP_BUILD_SCRIPT=Android.mk ^
	NDK_APPLICATION_MK=Application.mk ^
	"APP_ABI=armeabi-v7a" ^
	NDK_DEBUG=1 ^
	"VICE_CFLAGS=-DIDE_COMPILE -D_DEBUG -g -ggdb -O0" ^
	"VICE_CPPFLAGS=-DIDE_COMPILE -D_DEBUG -g -ggdb -O0"
	
REM Run build (release)
REM ndk-build ^
REM		-j1 ^
REM		NDK_PROJECT_PATH=. ^
REM		NDK_LIBS_OUT=jniLibs ^
REM		APP_BUILD_SCRIPT=Android.mk ^
REM		NDK_APPLICATION_MK=Application.mk ^
REM		"APP_ABI=x86 armeabi armeabi-v7a" ^
REM		NDK_DEBUG=0 ^
REM		"VICE_CFLAGS=-DIDE_COMPILE -DNDEBUG -O2" ^
REM		"VICE_CPPFLAGS=-DIDE_COMPILE -DNDEBUG -O2"

REM Rename back windows specific platform headers
rename ..\src\arch\win32\msvc\__inttypes.h inttypes.h
rename ..\src\arch\win32\msvc\__stdint.h stdint.h
rename ..\src\arch\win32\msvc\__dirent.h dirent.h
rename ..\src\arch\win32\msvc\__msvc_ver.h msvc_ver.h
