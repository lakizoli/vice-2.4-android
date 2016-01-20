#############################
# libvideo.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := video

LOCAL_C_INCLUDES := 			\
	../src/arch/win32/msvc		\
	../src/arch/win32			\
	../src						\
	../src/c64                  \
	../src/raster               \
	../src/video

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	render1x1.c                 \
	render1x1ntsc.c             \
	render1x1pal.c              \
	render1x2.c                 \
	render1x2crt.c              \
	render2x2.c                 \
	render2x2crt.c              \
	render2x2ntsc.c             \
	render2x2pal.c              \
	render2x4.c                 \
	render2x4crt.c              \
	renderscale2x.c             \
	renderyuv.c                 \
	video-canvas.c              \
	video-cmdline-options.c     \
	video-color.c               \
	video-render-1x2.c          \
	video-render-2x2.c          \
	video-render-crt.c          \
	video-render-pal.c          \
	video-render.c              \
	video-resources.c           \
	video-sound.c               \
	video-viewport.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
