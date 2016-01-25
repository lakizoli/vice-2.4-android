#############################
# libbase.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := base

LOCAL_C_INCLUDES := 							\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc	\
	$(C64_LIB_BASE_PATH)../src/arch/win32		\
	$(C64_LIB_BASE_PATH)../src/drive 			\
	$(C64_LIB_BASE_PATH)../src/userport			\
	$(C64_LIB_BASE_PATH)../src/monitor			\
	$(C64_LIB_BASE_PATH)../src/lib/p64			\
	$(C64_LIB_BASE_PATH)../src/vdrive			\
	$(C64_LIB_BASE_PATH)../src/rs232drv			\
	$(C64_LIB_BASE_PATH)../src/imagecontents	\
	$(C64_LIB_BASE_PATH)../src/rtc				\
	$(C64_LIB_BASE_PATH)../src/platform

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=			\
	alarm.c 				\
	attach.c 				\
	autostart-prg.c 		\
	autostart.c 			\
	cbmdos.c 				\
	cbmimage.c 				\
	charset.c 				\
	clipboard.c 			\
	clkguard.c 				\
	cmdline.c 				\
	color.c 				\
	crc32.c 				\
	datasette.c 			\
	debug.c 				\
	dma.c 					\
	event.c 				\
	findpath.c 				\
	fliplist.c 				\
	gcr.c 					\
	info.c 					\
	init.c 					\
	initcmdline.c 			\
	interrupt.c 			\
	ioutil.c 				\
	joystick.c 				\
	kbdbuf.c 				\
	keyboard.c 				\
	lib.c 					\
	lightpen.c 				\
	log.c 					\
	machine-bus.c 			\
	machine.c 				\
	midi.c 					\
	mouse.c 				\
	network.c 				\
	opencbmlib.c 			\
	palette.c 				\
	ram.c 					\
	rawfile.c 				\
	rawnet.c 				\
	resources.c 			\
	romset.c 				\
	screenshot.c 			\
	snapshot.c 				\
	socket.c 				\
	sound.c 				\
	sysfile.c 				\
	translate.c 			\
	traps.c 				\
	util.c 					\
	vsync.c 				\
	zfile.c 				\
	zipcode.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
