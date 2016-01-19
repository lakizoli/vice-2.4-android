# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(abspath $(call my-dir))

# libparallel
include $(CLEAR_VARS)

LOCAL_MODULE    := c64					# ez lesz majd, ha static lib lesz: parallel

LOCAL_C_INCLUDES := 			\
	..\src\arch\win32\msvc 		\
	..\src\arch\win32 			\
	..\src						\
	..\src\vdrive               \
	..\src\drive               	\
	..\src\lib\p64

#LOCAL_DISABLE_FORMAT_STRING_CHECKS := true
ifeq ($(TARGET_ARCH),x86) #gcc 4.8 need this because of a configuration bug in NDK (https://code.google.com/p/android/issues/detail?id=73843)
	LOCAL_CFLAGS += -DUSE_SSE4=0 -mtune=atom -m32 -mno-sse4.1 -mno-sse4.2 -mno-popcnt -mno-movbe
endif
LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES +=						\
	..\src\parallel\parallel-trap.c		\
	..\src\parallel\parallel.c

LOCAL_SHARED_LIBRARIES :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_EXPORT_LDLIBS := -lz -ldl

include $(BUILD_SHARED_LIBRARY) 		#		$(BUILD_STATIC_LIBRARY)
