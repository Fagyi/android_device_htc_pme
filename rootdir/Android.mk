LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# Device init scripts

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.early_boot.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qcom.early_boot.sh
LOCAL_MODULE_PATH  := $(TARGET_OUT_VENDOR_EXECUTABLES)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.post_boot.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qcom.post_boot.sh
LOCAL_MODULE_PATH  := $(TARGET_OUT_VENDOR_EXECUTABLES)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE	   := move_time_data.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/move_time_data.sh
LOCAL_MODULE_PATH  := $(TARGET_OUT_EXECUTABLES)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := charger.fstab.qcom
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/charger.fstab.qcom
LOCAL_VENDOR_MODULE    := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := fstab.qcom
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/fstab.qcom
LOCAL_VENDOR_MODULE    := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE	   := init.target.rc
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.target.rc
LOCAL_VENDOR_MODULE    := true
LOCAL_MODULE_RELATIVE_PATH := init/hw
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.rc
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qcom.rc
LOCAL_VENDOR_MODULE    := true
LOCAL_MODULE_RELATIVE_PATH := init/hw
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE	   := init.qcom.power.rc
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qcom.power.rc
LOCAL_VENDOR_MODULE    := true
LOCAL_MODULE_RELATIVE_PATH := init/hw
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.usb.rc
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qcom.usb.rc
LOCAL_VENDOR_MODULE    := true
LOCAL_MODULE_RELATIVE_PATH := init/hw
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.usb.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qcom.usb.sh
LOCAL_MODULE_PATH  := $(TARGET_OUT_VENDOR_EXECUTABLES)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qti.ims.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qti.ims.sh
LOCAL_MODULE_PATH  := $(TARGET_OUT_VENDOR_EXECUTABLES)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.sensors.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.qcom.sensors.sh
LOCAL_MODULE_PATH  := $(TARGET_OUT_VENDOR_EXECUTABLES)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := ueventd.qcom.rc
LOCAL_MODULE_STEM  := ueventd.rc
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/ueventd.qcom.rc
# this needs to be in /vendor/ueventd.rc
LOCAL_MODULE_PATH  := $(TARGET_OUT_VENDOR)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES    := bin/init.qcom.sh
LOCAL_VENDOR_MODULE    := true
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.qcom.firmware_links.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES    := bin/init.qcom.firmware_links.sh
LOCAL_VENDOR_MODULE    := true
include $(BUILD_PREBUILT)

