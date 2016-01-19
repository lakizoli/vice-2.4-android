#############################
# libgfxoutputdrv.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := gfxoutputdrv

LOCAL_C_INCLUDES := 			\
	../src/arch/win32/msvc		\
	../src/arch/win32			\
	../src						\
	../src/lib/libffmpeg

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	bmpdrv.c                    \
	doodledrv.c                 \
	ffmpegdrv.c                 \
	ffmpeglib.c                 \
	gfxoutput.c                 \
	iffdrv.c                    \
	pcxdrv.c                    \
	ppmdrv.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

LOCAL_C_FLAGS += -DDONT_USE_UNISTD_H
LOCAL_CPP_FLAGS += -DDONT_USE_UNISTD_H

include $(BUILD_STATIC_LIBRARY)
