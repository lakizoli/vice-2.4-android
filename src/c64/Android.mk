#############################
# libc64.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := c64

LOCAL_C_INCLUDES := 			\
	../src/arch/win32/msvc		\
	../src/arch/win32			\
	../src						\
	../src/drive 				\
	../src/drive/iec/c64exp 	\
	../src/userport 			\
	../src/video 				\
	../src/c64/cart 			\
	../src/tape 				\
	../src/sid 					\
	../src/vicii 				\
	../src/raster 				\
	../src/monitor 				\
	../src/lib/p64 				\
	../src/rs232drv

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=			\
	c64-cmdline-options.c 	\
	c64-resources.c 		\
	c64-snapshot.c 			\
	c64.c 					\
	c64bus.c 				\
	c64cia1.c 				\
	c64cia2.c 				\
	c64datasette.c 			\
	c64drive.c 				\
	c64export.c 			\
	c64fastiec.c 			\
	c64gluelogic.c 			\
	c64iec.c 				\
	c64io.c 				\
	c64keyboard.c 			\
	c64mem.c 				\
	c64meminit.c 			\
	c64memlimit.c 			\
	c64memrom.c 			\
	c64memsnapshot.c 		\
	c64model.c 				\
	c64parallel.c 			\
	c64pla.c 				\
	c64printer.c 			\
	c64rom.c 				\
	c64romset.c 			\
	c64rsuser.c 			\
	c64sound.c 				\
	c64video.c 				\
	c64_256k.c 				\
	patchrom.c 				\
	plus256k.c 				\
	plus60k.c 				\
	psid.c 					\
	reloc65.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
