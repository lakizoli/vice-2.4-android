#############################
# libvicii.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := vicii

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/c64                  \
	$(C64_LIB_BASE_PATH)../src/c64dtv               \
	$(C64_LIB_BASE_PATH)../src/raster               \
	$(C64_LIB_BASE_PATH)../src/video                \
	$(C64_LIB_BASE_PATH)../src/monitor              \
	$(C64_LIB_BASE_PATH)../src/c64/cart

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	vicii-badline.c             \
	vicii-clock-stretch.c       \
	vicii-cmdline-options.c     \
	vicii-color.c               \
	vicii-draw.c                \
	vicii-fetch.c               \
	vicii-irq.c                 \
	vicii-mem.c                 \
	vicii-phi1.c                \
	vicii-resources.c           \
	vicii-snapshot.c            \
	vicii-sprites.c             \
	vicii-stubs.c               \
	vicii-timing.c              \
	vicii.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
