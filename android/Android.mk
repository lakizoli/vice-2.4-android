#############################
# libc64emu.so (main module)
#############################

TOP_PATH := $(abspath $(call my-dir))

include $(TOP_PATH)/../src/Android.mk
#include $(TOP_PATH)/../src/arch/win32/Android.mk
include $(TOP_PATH)/../src/c64/Android.mk
include $(TOP_PATH)/../src/c64/cart/Android.mk
include $(TOP_PATH)/../src/core/Android.mk
include $(TOP_PATH)/../src/drive/Android.mk
include $(TOP_PATH)/../src/drive/iec/c64exp/Android.mk
include $(TOP_PATH)/../src/drive/iec/Android.mk
include $(TOP_PATH)/../src/diskimage/Android.mk
include $(TOP_PATH)/../src/fileio/Android.mk
include $(TOP_PATH)/../src/fsdevice/Android.mk
include $(TOP_PATH)/../src/gfxoutputdrv/Android.mk
include $(TOP_PATH)/../src/iecbus/Android.mk
include $(TOP_PATH)/../src/imagecontents/Android.mk
include $(TOP_PATH)/../src/lib/p64/Android.mk
include $(TOP_PATH)/../src/monitor/Android.mk
include $(TOP_PATH)/../src/parallel/Android.mk
include $(TOP_PATH)/../src/printerdrv/Android.mk
#include $(TOP_PATH)/../src/raster/Android.mk
include $(TOP_PATH)/../src/resid/Android.mk
include $(TOP_PATH)/../src/resid-fp/Android.mk
include $(TOP_PATH)/../src/rs232drv/Android.mk
include $(TOP_PATH)/../src/rtc/Android.mk
include $(TOP_PATH)/../src/serial/Android.mk
include $(TOP_PATH)/../src/sid/Android.mk
include $(TOP_PATH)/../src/sounddrv/Android.mk
include $(TOP_PATH)/../src/tape/Android.mk
include $(TOP_PATH)/../src/userport/Android.mk
include $(TOP_PATH)/../src/vdrive/Android.mk
include $(TOP_PATH)/../src/vicii/Android.mk
include $(TOP_PATH)/../src/video/Android.mk

# libc64emu.so
include $(CLEAR_VARS)

LOCAL_MODULE    := c64emu

LOCAL_C_INCLUDES :=		 					\
	$(TOP_PATH)/../src/arch/win32/msvc 		\
	$(TOP_PATH)/../src/arch/win32 			\
	$(TOP_PATH)/../src						\
	$(TOP_PATH)/../src/drive                \
	$(TOP_PATH)/../src/vdrive               \
	$(TOP_PATH)/../src/lib/p64              \
	$(TOP_PATH)/../src/monitor

#LOCAL_DISABLE_FORMAT_STRING_CHECKS := true
ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=					\
	$(TOP_PATH)/../src/main.c		\
	$(TOP_PATH)/../src/maincpu.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := 		\
	base                        \
	c64                         \
	c64cart                     \
	c64exp                      \
	core                        \
	diskimage                   \
	drive                       \
	fileio                      \
	fsdevice                    \
	gfxoutputdrv                \
	iec                         \
	iecbus                      \
	imagecontents               \
	monitor                     \
	p64                         \
	parallel                    \
	printerdrv                  \
	resid						\
	residfp						\
	rs232drv                    \
	rtc                         \
	serial                      \
	sid                         \
	sounddrv					\
	tape                        \
	userport                    \
	vdrive						\
	vicii
	
# Egyelore kiszedett libek: arch raster video

include $(BUILD_SHARED_LIBRARY)

