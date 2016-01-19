#############################
# libc64emu.so (main module)
#############################

TOP_PATH := $(abspath $(call my-dir))

include $(TOP_PATH)/../src/Android.mk
include $(TOP_PATH)/../src/c64/Android.mk
include $(TOP_PATH)/../src/c64/cart/Android.mk
include $(TOP_PATH)/../src/core/Android.mk
include $(TOP_PATH)/../src/drive/Android.mk
include $(TOP_PATH)/../src/drive/iec/c64exp/Android.mk
include $(TOP_PATH)/../src/diskimage/Android.mk
include $(TOP_PATH)/../src/fileio/Android.mk
include $(TOP_PATH)/../src/fsdevice/Android.mk
include $(TOP_PATH)/../src/lib/p64/Android.mk
include $(TOP_PATH)/../src/parallel/Android.mk
include $(TOP_PATH)/../src/tape/Android.mk
include $(TOP_PATH)/../src/vdrive/Android.mk

# libc64emu.so
include $(CLEAR_VARS)

LOCAL_MODULE    := c64emu

LOCAL_C_INCLUDES := 			\
	../src/arch/win32/msvc 		\
	../src/arch/win32 			\
	../src						\
	../src/vdrive               \
	../src/drive               	\
	../src/lib/p64

#LOCAL_DISABLE_FORMAT_STRING_CHECKS := true
ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

#LOCAL_SRC_FILES +=

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base c64 c64cart c64exp core diskimage drive fileio fsdevice p64 parallel tape vdrive

include $(BUILD_SHARED_LIBRARY)

