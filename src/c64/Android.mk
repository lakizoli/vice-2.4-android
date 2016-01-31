#############################
# libc64.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := c64

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/core					\
	$(C64_LIB_BASE_PATH)../src/drive 				\
	$(C64_LIB_BASE_PATH)../src/drive/iec/c64exp 	\
	$(C64_LIB_BASE_PATH)../src/userport 			\
	$(C64_LIB_BASE_PATH)../src/video 				\
	$(C64_LIB_BASE_PATH)../src/c64/cart 			\
	$(C64_LIB_BASE_PATH)../src/tape 				\
	$(C64_LIB_BASE_PATH)../src/rtc					\
	$(C64_LIB_BASE_PATH)../src/sid 					\
	$(C64_LIB_BASE_PATH)../src/vicii 				\
	$(C64_LIB_BASE_PATH)../src/raster 				\
	$(C64_LIB_BASE_PATH)../src/monitor 				\
	$(C64_LIB_BASE_PATH)../src/lib/p64 				\
	$(C64_LIB_BASE_PATH)../src/rs232drv
	
ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

#c64 files
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

#c64cart files
LOCAL_SRC_FILES +=				\
	cart/actionreplay.c 		\
	cart/actionreplay2.c 		\
	cart/actionreplay3.c 		\
	cart/actionreplay4.c 		\
	cart/atomicpower.c 			\
	cart/c64-generic.c 			\
	cart/c64-midi.c 			\
	cart/c64tpi.c 				\
	cart/capture.c 				\
	cart/comal80.c 				\
	cart/delaep256.c 			\
	cart/delaep64.c 			\
	cart/delaep7x8.c 			\
	cart/diashowmaker.c 		\
	cart/dinamic.c 				\
	cart/dqbb.c 				\
	cart/easyflash.c 			\
	cart/epyxfastload.c 		\
	cart/exos.c                 \
	cart/expert.c               \
	cart/final.c                \
	cart/final3.c               \
	cart/finalplus.c            \
	cart/formel64.c             \
	cart/freezeframe.c          \
	cart/freezemachine.c        \
	cart/funplay.c              \
	cart/gamekiller.c           \
	cart/gs.c                   \
	cart/ide64.c                \
	cart/isepic.c               \
	cart/kcs.c                  \
	cart/kingsoft.c             \
	cart/mach5.c                \
	cart/magicdesk.c            \
	cart/magicformel.c          \
	cart/magicvoice.c           \
	cart/mikroass.c             \
	cart/mmc64.c                \
	cart/mmcreplay.c            \
	cart/ocean.c                \
	cart/pagefox.c              \
	cart/prophet64.c            \
	cart/ramcart.c              \
	cart/retroreplay.c          \
	cart/reu.c                  \
	cart/rexep256.c             \
	cart/rexutility.c           \
	cart/ross.c                 \
	cart/silverrock128.c        \
	cart/simonsbasic.c          \
	cart/snapshot64.c           \
	cart/stardos.c              \
	cart/stb.c                  \
	cart/superexplode5.c        \
	cart/supergames.c           \
	cart/supersnapshot.c        \
	cart/supersnapshot4.c       \
	cart/warpspeed.c            \
	cart/westermann.c           \
	cart/zaxxon.c				\
	cart/c64cart.c				\
	cart/c64carthooks.c 		\
	cart/c64cartmem.c 			\
	cart/crt.c 					\
	cart/c64acia1.c 			\
	cart/digimax.c 				\
	cart/ds12c887rtc.c 			\
	cart/georam.c 				\
	cart/sfx_soundexpander.c 	\
	cart/sfx_soundsampler.c 	\
	cart/tfe.c
	
LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
