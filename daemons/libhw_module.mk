LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LIRC_MAJORMINOR:= cvs

LOCAL_SRC_FILES:= \
    hw-types.c \
    ir_remote.c \
    release.c \
    hw_default.c \
    receive.c \
    transmit.c

LOCAL_CFLAGS = -DHAVE_CONFIG_H

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    external/lirc \
    external/lirc/drivers 
     
LOCAL_MODULE:= libhw_module-$(LIRC_MAJORMINOR)

include $(BUILD_STATIC_LIBRARY)
