#############################
# libc64cart.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := c64cart

LOCAL_C_INCLUDES := 			\
	../src/arch/win32/msvc		\
	../src/arch/win32			\
	../src						\
	../src/c64					\
	../src/vicii				\
	../src/rtc					\
	../src/sid					\
	../src/drive				\
	../src/lib/p64				\
	../src/monitor				\
	../src/core

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=			\
	actionreplay.c 			\
	actionreplay2.c 		\
	actionreplay3.c 		\
	actionreplay4.c 		\
	atomicpower.c 			\
	c64-generic.c 			\
	c64-midi.c 				\
	c64tpi.c 				\
	capture.c 				\
	comal80.c 				\
	delaep256.c 			\
	delaep64.c 				\
	delaep7x8.c 			\
	diashowmaker.c 			\
	dinamic.c 				\
	dqbb.c 					\
	easyflash.c 			\
	epyxfastload.c 			\
	exos.c                  \
	expert.c                \
	final.c                 \
	final3.c                \
	finalplus.c             \
	formel64.c              \
	freezeframe.c           \
	freezemachine.c         \
	funplay.c               \
	gamekiller.c            \
	gs.c                    \
	ide64.c                 \
	isepic.c                \
	kcs.c                   \
	kingsoft.c              \
	mach5.c                 \
	magicdesk.c             \
	magicformel.c           \
	magicvoice.c            \
	mikroass.c              \
	mmc64.c                 \
	mmcreplay.c             \
	ocean.c                 \
	pagefox.c               \
	prophet64.c             \
	ramcart.c               \
	retroreplay.c           \
	reu.c                   \
	rexep256.c              \
	rexutility.c            \
	ross.c                  \
	silverrock128.c         \
	simonsbasic.c           \
	snapshot64.c            \
	stardos.c               \
	stb.c                   \
	superexplode5.c         \
	supergames.c            \
	supersnapshot.c         \
	supersnapshot4.c        \
	warpspeed.c             \
	westermann.c            \
	zaxxon.c				\
	c64cart.c				\
	c64carthooks.c 			\
	c64cartmem.c 			\
	crt.c 					\
	c64acia1.c 				\
	digimax.c 				\
	ds12c887rtc.c 			\
	georam.c 				\
	sfx_soundexpander.c 	\
	sfx_soundsampler.c 		\
	tfe.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
