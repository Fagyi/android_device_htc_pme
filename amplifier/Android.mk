LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
	liblog libutils libcutils libtinyalsa

LOCAL_C_INCLUDES := \
       external/tinyalsa/include \
       hardware/libhardware/include \
       $(call project-path-for,qcom-audio)/hal

LOCAL_SRC_FILES := \
	audio_amplifier.c tfa.c

LOCAL_ADDITIONAL_DEPENDENCIES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include

LOCAL_MODULE := audio_amplifier.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
