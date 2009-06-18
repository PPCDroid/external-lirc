# This file is the top android makefile for all sub-modules.

LOCAL_PATH := $(call my-dir)

LIRC_TOP := $(LOCAL_PATH)

include $(CLEAR_VARS)

include $(LIRC_TOP)/daemons/libhw_module.mk
include $(LIRC_TOP)/daemons/lircd.mk
include $(LIRC_TOP)/tools/irw.mk
