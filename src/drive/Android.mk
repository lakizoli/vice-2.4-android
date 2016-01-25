#############################
# libdrive.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := drive

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/vdrive				\
	$(C64_LIB_BASE_PATH)../src/rtc					\
	$(C64_LIB_BASE_PATH)../src/monitor				\
	$(C64_LIB_BASE_PATH)../src/lib/p64

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=			\
	drive-check.c           \
	drive-cmdline-options.c \
	drive-overflow.c        \
	drive-resources.c       \
	drive-snapshot.c        \
	drive-sound.c           \
	drive-writeprotect.c    \
	drive.c                 \
	drivecpu.c              \
	drivecpu65c02.c         \
	driveimage.c            \
	drivemem.c              \
	driverom.c              \
	drivesync.c             \
	rotation.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
