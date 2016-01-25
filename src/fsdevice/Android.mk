#############################
# libfsdevice.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := fsdevice

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/fsdevice				\
	$(C64_LIB_BASE_PATH)../src/vdrive

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	fsdevice-close.c            \
	fsdevice-cmdline-options.c  \
	fsdevice-flush.c            \
	fsdevice-open.c             \
	fsdevice-read.c             \
	fsdevice-resources.c        \
	fsdevice-write.c            \
	fsdevice.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
