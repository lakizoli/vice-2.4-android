@ECHO OFF

REM 
REM         def ndkABIs = "APP_ABI=x86 armeabi armeabi-v7a";
REM         def ndkDebug = "NDK_DEBUG=1"
REM         def ndkBIMxCFlags = "BIMX_CFLAGS=-DDEBUVERS=1 -DDEBUVERS_=1 -DDEBUVERS_${System.env.GS_DEVELOPER_ID}=1 -DALLOW_SELF_SIGNED_CERTS"
REM         def ndkBIMxCPPFlags = "BIMX_CPPFLAGS=-DDEBUVERS=1 -DDEBUVERS_=1 -DDEBUVERS_${System.env.GS_DEVELOPER_ID}=1 -DALLOW_SELF_SIGNED_CERTS"
REM 
REM         if (abiFilter == "x86") {
REM             ndkABIs = "APP_ABI=x86"
REM         } else if (abiFilter == "arm") {
REM             ndkABIs = "APP_ABI=armeabi"
REM         } else if (abiFilter == "armv7a") {
REM             ndkABIs = "APP_ABI=armeabi-v7a"
REM         } else if (abiFilter == "allPlatform") {
REM             ndkABIs = "APP_ABI=x86 armeabi armeabi-v7a"
REM         }
REM 
REM         if (buildConfig == "debug") {
REM             ndkDebug = "NDK_DEBUG=1"
REM             ndkBIMxCFlags = "BIMX_CFLAGS=-DDEBUVERS=1 -DDEBUVERS_=1 -DDEBUVERS_${System.env.GS_DEVELOPER_ID}=1 -DALLOW_SELF_SIGNED_CERTS -g -ggdb -O0"
REM             ndkBIMxCPPFlags = "BIMX_CPPFLAGS=-DDEBUVERS=1 -DDEBUVERS_=1 -DDEBUVERS_${System.env.GS_DEVELOPER_ID}=1 -DALLOW_SELF_SIGNED_CERTS -g -ggdb -O0"
REM         } else if (buildConfig == "release") {
REM             ndkDebug = "NDK_DEBUG=0"
REM             ndkBIMxCFlags = "BIMX_CFLAGS=-DALLOW_SELF_SIGNED_CERTS -O2"
REM             ndkBIMxCPPFlags = "BIMX_CPPFLAGS=-DALLOW_SELF_SIGNED_CERTS -O2"
REM         }
REM 
REM         this.command = "[\"" + ndkbuild + "\"" +
REM                 ', "-j8"' +
REM                 ', "NDK_PROJECT_PATH=../../build/intermediates/ndk"' +
REM                 ', "NDK_LIBS_OUT=jniLibs"' +
REM                 ', "APP_BUILD_SCRIPT=jni/Android.mk"' +
REM                 ', "NDK_APPLICATION_MK=jni/Application.mk"' +
REM //                ', "V=1"' +
REM                 ", \"${ndkABIs}\"" +
REM                 ", \"${ndkDebug}\"" +
REM                 ", \"${ndkBIMxCFlags}\"" +
REM                 ", \"${ndkBIMxCPPFlags}\"" +
REM                 ', "-C' + basePath + '"' +
REM                 "]"

ndk-build -j1 "NDK_PROJECT_PATH=." "NDK_LIBS_OUT=jniLibs" "APP_BUILD_SCRIPT=Android.mk" "NDK_APPLICATION_MK=Application.mk" "APP_ABI=x86 armeabi armeabi-v7a" "NDK_DEBUG=1" "VICE_CFLAGS=-DIDE_COMPILE -D_DEBUG -g -ggdb -O0" "VICE_CPPFLAGS=-DIDE_COMPILE -D_DEBUG -g -ggdb -O0"