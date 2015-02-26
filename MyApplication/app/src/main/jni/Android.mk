# This makefile is only used if the magic string is uncommented in build.gradle
#

LOCAL_PATH := $(call my-dir)

# static library info
LOCAL_MODULE := libXMP
LOCAL_SRC_FILES := ../prebuilt/libXMP.a
include $(PREBUILT_STATIC_LIBRARY)

# wrapper info
include $(CLEAR_VARS)
LOCAL_MODULE    := xmp-jni
LOCAL_SRC_FILES := xmp-jni.cpp
LOCAL_CFLAGS    += -fexceptions
LOCAL_STATIC_LIBRARIES := libXMP
LOCAL_LDLIBS += -lz
include $(BUILD_SHARED_LIBRARY)
