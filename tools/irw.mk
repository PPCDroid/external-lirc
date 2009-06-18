LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    irw.c

LOCAL_CFLAGS = -DHAVE_CONFIG_H

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    external/lirc

LOCAL_MODULE:= irw

include $(BUILD_EXECUTABLE)
