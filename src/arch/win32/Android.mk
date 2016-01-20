#############################
# libarch.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))
$(warning $(LOCAL_PATH))

include $(CLEAR_VARS)

LOCAL_MODULE    := arch

LOCAL_C_INCLUDES := 				\
	../src/arch/win32/msvc			\
	../src/arch/win32/msvc/wpcap	\
	../src/arch/win32				\
	../src							\
	../src/platform             	\
	../src/drive                	\
	../src/vdrive               	\
	../src/userport             	\
	../src/c64                  	\
	../src/c64/cart             	\
	../src/c64dtv               	\
	../src/c128                 	\
	../src/vic20                	\
	../src/pet                  	\
	../src/cbm2                 	\
	../src/raster               	\
	../src/monitor              	\
	../src/lib/p64              	\
	../src/lib/libffmpeg        	\
	../src/plus4                	\
	../src/rs232drv             	\
	../src/sid                  	\
	../src/imagecontents

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
