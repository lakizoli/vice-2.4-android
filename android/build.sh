#!/bin/bash

# Rename windows specific platform headers
mv ../src/arch/win32/msvc/inttypes.h ../src/arch/win32/msvc/__inttypes.h
mv ../src/arch/win32/msvc/stdint.h ../src/arch/win32/msvc/__stdint.h
mv ../src/arch/win32/msvc/dirent.h ../src/arch/win32/msvc/__dirent.h
mv ../src/arch/win32/msvc/msvc_ver.h ../src/arch/win32/msvc/__msvc_ver.h

# All abi settings
#	"APP_ABI=x86 armeabi armeabi-v7a" \

# Run build (debug)
ndk-build \
	-j1 \
	NDK_PROJECT_PATH=. \
	NDK_LIBS_OUT=jniLibs \
	APP_BUILD_SCRIPT=Android.mk \
	NDK_APPLICATION_MK=Application.mk \
	"APP_ABI=armeabi-v7a" \
	NDK_DEBUG=1 \
	"VICE_CFLAGS=-DIDE_COMPILE -D_DEBUG -g -ggdb -O0" \
	"VICE_CPPFLAGS=-DIDE_COMPILE -D_DEBUG -g -ggdb -O0"
	
# Run build (release)
#ndk-build \
#	-j1 \
#	NDK_PROJECT_PATH=. \
#	NDK_LIBS_OUT=jniLibs \
#	APP_BUILD_SCRIPT=Android.mk \
#	NDK_APPLICATION_MK=Application.mk \
#	"APP_ABI=x86 armeabi armeabi-v7a" \
#	NDK_DEBUG=0 \
#	"VICE_CFLAGS=-DIDE_COMPILE -DNDEBUG -g -ggdb -O0" \
#	"VICE_CPPFLAGS=-DIDE_COMPILE -DNDEBUG -g -ggdb -O0"

# Rename back windows specific platform headers
mv ../src/arch/win32/msvc/__inttypes.h ../src/arch/win32/msvc/inttypes.h
mv ../src/arch/win32/msvc/__stdint.h ../src/arch/win32/msvc/stdint.h
mv ../src/arch/win32/msvc/__dirent.h ../src/arch/win32/msvc/dirent.h
mv ../src/arch/win32/msvc/__msvc_ver.h ../src/arch/win32/msvc/msvc_ver.h
