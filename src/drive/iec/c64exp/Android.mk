#############################
# libc64exp.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := c64exp

LOCAL_C_INCLUDES := 			\
	../src/arch/win32/msvc		\
	../src/arch/win32			\
	../src						\
	../src/core					\
	../src/drive				\
	../src/lib/p64

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	c64exp-cmdline-options.c    \
	c64exp-resources.c          \
	dolphindos3.c               \
	iec-c64exp.c                \
	profdos.c                   \
	supercard.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
