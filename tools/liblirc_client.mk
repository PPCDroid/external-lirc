LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LIRC_MAJORMINOR:= cvs

LOCAL_SRC_FILES:= \
    lirc_client.c

LOCAL_CFLAGS = -DHAVE_CONFIG_H

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    external/lirc
     
LOCAL_MODULE:= liblirc_client-$(LIRC_MAJORMINOR)

include $(BUILD_SHARED_LIBRARY)
