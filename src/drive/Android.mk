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
	$(C64_LIB_BASE_PATH)../src/core					\
	$(C64_LIB_BASE_PATH)../src/vdrive				\
	$(C64_LIB_BASE_PATH)../src/rtc					\
	$(C64_LIB_BASE_PATH)../src/monitor				\
	$(C64_LIB_BASE_PATH)../src/lib/p64

ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

#drive files
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
	
#iec files
LOCAL_SRC_FILES +=				\
	iec/cia1571d.c              \
	iec/cia1581d.c              \
	iec/fdd.c                   \
	iec/glue1571.c              \
	iec/iec-cmdline-options.c   \
	iec/iec-resources.c         \
	iec/iec.c                   \
	iec/iecrom.c                \
	iec/memiec.c                \
	iec/pc8477.c                \
	iec/via1d1541.c             \
	iec/via4000.c               \
	iec/wd1770.c                \
	iecieee/iecieee.c           \
	iecieee/via2d.c             \
	ieee/fdc.c                  \
	ieee/ieee-cmdline-options.c \
	ieee/ieee-resources.c       \
	ieee/ieee.c                 \
	ieee/ieeerom.c              \
	ieee/memieee.c              \
	ieee/riot1d.c               \
	ieee/riot2d.c               \
	ieee/via1d2031.c
	
#c64exp files
LOCAL_SRC_FILES +=							\
	iec/c64exp/c64exp-cmdline-options.c    	\
	iec/c64exp/c64exp-resources.c          	\
	iec/c64exp/dolphindos3.c               	\
	iec/c64exp/iec-c64exp.c                	\
	iec/c64exp/profdos.c                   	\
	iec/c64exp/supercard.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
