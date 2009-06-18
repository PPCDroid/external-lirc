LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    irexec.c

LOCAL_CFLAGS = -DHAVE_CONFIG_H

LOCAL_SHARED_LIBRARIES:= \
    liblirc_client-cvs

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    external/lirc

LOCAL_MODULE:= irexec

include $(BUILD_EXECUTABLE)
