#############################
# libiec.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := iec

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/drive				\
	$(C64_LIB_BASE_PATH)../src/vdrive				\
	$(C64_LIB_BASE_PATH)../src/lib/p64

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=					\
	cia1571d.c                  	\
	cia1581d.c                  	\
	fdd.c                       	\
	glue1571.c                  	\
	iec-cmdline-options.c       	\
	iec-resources.c             	\
	iec.c                       	\
	iecrom.c                    	\
	memiec.c                    	\
	pc8477.c                   		\
	via1d1541.c                		\
	via4000.c                   	\
	wd1770.c                        \
	../iecieee/iecieee.c            \
	../iecieee/via2d.c              \
	../ieee/fdc.c                   \
	../ieee/ieee-cmdline-options.c  \
	../ieee/ieee-resources.c        \
	../ieee/ieee.c                  \
	../ieee/ieeerom.c               \
	../ieee/memieee.c               \
	../ieee/riot1d.c                \
	../ieee/riot2d.c                \
	../ieee/via1d2031.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES := base
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
