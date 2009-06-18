LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    lircd.c \
    config_file.c

LOCAL_STATIC_LIBRARIES:= \
    libhw_module-cvs

LOCAL_CFLAGS = -DHAVE_CONFIG_H -DDEBUG

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    external/lirc \
    external/lirc/drivers

LOCAL_MODULE:= lircd

include $(BUILD_EXECUTABLE)
