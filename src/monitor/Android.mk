#############################
# libmonitor.a
#############################

LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE    := monitor

LOCAL_C_INCLUDES := 								\
	$(C64_LIB_BASE_PATH)../src/arch/win32/msvc		\
	$(C64_LIB_BASE_PATH)../src/arch/win32			\
	$(C64_LIB_BASE_PATH)../src						\
	$(C64_LIB_BASE_PATH)../src/vdrive               \
	$(C64_LIB_BASE_PATH)../src/monitor              \
	$(C64_LIB_BASE_PATH)../src/lib/p64              \
	$(C64_LIB_BASE_PATH)../src/drive                \
	$(C64_LIB_BASE_PATH)../src/imagecontents
	
ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=				\
	asm6502.c                   \
	asm6502dtv.c                \
	asm6809.c                   \
	asmR65C02.c                 \
	asmz80.c                    \
	monitor.c                   \
	monitor_network.c           \
	mon_assemble6502.c          \
	mon_assemble6809.c          \
	mon_assembleR65C02.c        \
	mon_assemblez80.c           \
	mon_breakpoint.c            \
	mon_command.c               \
	mon_disassemble.c           \
	mon_drive.c                 \
	mon_file.c                  \
	mon_lex.c                   \
	mon_memory.c                \
	mon_parse.c                 \
	mon_register6502.c          \
	mon_register6502dtv.c       \
	mon_register6809.c          \
	mon_registerR65C02.c        \
	mon_registerz80.c           \
	mon_ui.c                    \
	mon_util.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)
