#############################
# libbase.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := base

LOCAL_C_INCLUDES := 									\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc			\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc/wpcap	\
	$(C64_LIB_BASE_PATH)../src/arch/win32				\
	$(C64_LIB_BASE_PATH)../src/c128                 	\
	$(C64_LIB_BASE_PATH)../src/c64                  	\
	$(C64_LIB_BASE_PATH)../src/c64/cart             	\
	$(C64_LIB_BASE_PATH)../src/c64dtv               	\
	$(C64_LIB_BASE_PATH)../src/cbm2                 	\
	$(C64_LIB_BASE_PATH)../src/drive 					\
	$(C64_LIB_BASE_PATH)../src/imagecontents			\
	$(C64_LIB_BASE_PATH)../src/lib/libffmpeg        	\
	$(C64_LIB_BASE_PATH)../src/lib/p64					\
	$(C64_LIB_BASE_PATH)../src/monitor					\
	$(C64_LIB_BASE_PATH)../src/pet                  	\
	$(C64_LIB_BASE_PATH)../src/platform					\
	$(C64_LIB_BASE_PATH)../src/plus4                	\
	$(C64_LIB_BASE_PATH)../src/raster               	\
	$(C64_LIB_BASE_PATH)../src/rs232drv					\
	$(C64_LIB_BASE_PATH)../src/rtc						\
	$(C64_LIB_BASE_PATH)../src/sid                  	\
	$(C64_LIB_BASE_PATH)../src/userport					\
	$(C64_LIB_BASE_PATH)../src/vdrive					\
	$(C64_LIB_BASE_PATH)../src/vic20
	
ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

#base files
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

#arch files
LOCAL_SRC_FILES +=					\
	arch/win32/archdep.c           	\
	arch/win32/blockdev.c          	\
	arch/win32/c64ui.c             	\
	arch/win32/catweaselmkiii.c    	\
	arch/win32/console.c           	\
	arch/win32/dinput_handle.c     	\
	arch/win32/dirent.c            	\
	arch/win32/dynlib.c            	\
	arch/win32/gifdrv.c            	\
	arch/win32/hardsid.c           	\
	arch/win32/intl.c              	\
	arch/win32/joy.c               	\
	arch/win32/kbd.c               	\
	arch/win32/lightpendrv.c       	\
	arch/win32/mididrv.c           	\
	arch/win32/mousedrv.c          	\
	arch/win32/parsid.c            	\
	arch/win32/rawnetarch.c        	\
	arch/win32/rs232.c             	\
	arch/win32/rs232dev.c          	\
	arch/win32/rs232net.c          	\
	arch/win32/signals.c           	\
	arch/win32/statusbar.c         	\
	arch/win32/system.c            	\
	arch/win32/ui.c                	\
	arch/win32/uimon.c             	\
	arch/win32/video-ddraw.c       	\
	arch/win32/video-dx9.c         	\
	arch/win32/video.c             	\
	arch/win32/vsyncarch.c         	\
	arch/win32/winmain.c
	
#fileio files
LOCAL_SRC_FILES +=					\
	fileio/cbmfile.c 				\
	fileio/fileio.c 				\
	fileio/p00.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := serial
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
