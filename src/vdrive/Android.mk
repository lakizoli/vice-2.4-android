#############################
# libvdrive.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := vdrive

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/drive				\
	$(C64_LIB_BASE_PATH)../src/lib/p64

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=			\
	vdrive-bam.c \
	vdrive-command.c \
	vdrive-dir.c \
	vdrive-iec.c \
	vdrive-internal.c \
	vdrive-rel.c \
	vdrive-snapshot.c \
	vdrive.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
