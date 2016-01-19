APP_PLATFORM := android-10
NDK_TOOLCHAIN_VERSION := 4.8
APP_MODULES := c64emu
APP_STL := c++_shared
APP_CFLAGS := -Wno-error=format-security -Wno-multichar -Wno-deprecated-register $(VICE_CFLAGS)
APP_CPPFLAGS := -Wno-error=format-security -Wno-format-security --rtti -fexceptions $(VICE_CPPFLAGS)
