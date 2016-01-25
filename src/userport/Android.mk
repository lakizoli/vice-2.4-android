#############################
# libuserport.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := userport

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/c64/cart				\
	$(C64_LIB_BASE_PATH)../src/rtc

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	userport_dac.c              \
	userport_digimax.c          \
	userport_joystick.c         \
	userport_rtc.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
