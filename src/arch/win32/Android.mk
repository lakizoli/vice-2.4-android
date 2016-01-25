#############################
# libarch.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := arch

LOCAL_C_INCLUDES := 									\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc			\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc/wpcap	\
	$(C64_LIB_BASE_PATH)../src/arch/win32				\
	$(C64_LIB_BASE_PATH)../src							\
	$(C64_LIB_BASE_PATH)../src/platform             	\
	$(C64_LIB_BASE_PATH)../src/drive                	\
	$(C64_LIB_BASE_PATH)../src/vdrive               	\
	$(C64_LIB_BASE_PATH)../src/userport             	\
	$(C64_LIB_BASE_PATH)../src/c64                  	\
	$(C64_LIB_BASE_PATH)../src/c64/cart             	\
	$(C64_LIB_BASE_PATH)../src/c64dtv               	\
	$(C64_LIB_BASE_PATH)../src/c128                 	\
	$(C64_LIB_BASE_PATH)../src/vic20                	\
	$(C64_LIB_BASE_PATH)../src/pet                  	\
	$(C64_LIB_BASE_PATH)../src/cbm2                 	\
	$(C64_LIB_BASE_PATH)../src/raster               	\
	$(C64_LIB_BASE_PATH)../src/monitor              	\
	$(C64_LIB_BASE_PATH)../src/lib/p64              	\
	$(C64_LIB_BASE_PATH)../src/lib/libffmpeg        	\
	$(C64_LIB_BASE_PATH)../src/plus4                	\
	$(C64_LIB_BASE_PATH)../src/rs232drv             	\
	$(C64_LIB_BASE_PATH)../src/sid                  	\
	$(C64_LIB_BASE_PATH)../src/imagecontents

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	archdep.c                   \
	blockdev.c                  \
	c64ui.c                     \
	catweaselmkiii.c            \
	console.c                   \
	dinput_handle.c             \
	dirent.c                    \
	dynlib.c                    \
	gifdrv.c                    \
	hardsid.c                   \
	intl.c                      \
	joy.c                       \
	kbd.c                       \
	lightpendrv.c               \
	mididrv.c                   \
	mousedrv.c                  \
	parsid.c                    \
	rawnetarch.c                \
	rs232.c                     \
	rs232dev.c                  \
	rs232net.c                  \
	signals.c                   \
	statusbar.c                 \
	system.c                    \
	ui.c                        \
	uimon.c                     \
	video-ddraw.c               \
	video-dx9.c                 \
	video.c                     \
	vsyncarch.c                 \
	winmain.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
