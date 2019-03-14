#
# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from pme device
$(call inherit-product, device/htc/pme/device.mk)

$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_m.mk)

# Inherit some common Resurrection Remix stuff.
$(call inherit-product, vendor/rr/config/common_full_phone.mk)
export RR_BUILDTYPE=Official

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := pme
PRODUCT_NAME := rr_pme
PRODUCT_BRAND := HTC
PRODUCT_MODEL := HTC 10
PRODUCT_MANUFACTURER := HTC
PRODUCT_RELEASE_NAME := pme

$(call inherit-product-if-exists, vendor/htc/pme/pme-vendor.mk)

# Device Fingerprint
BUILD_FINGERPRINT := htc/pmeuhl_00401/htc_pmeuhl:8.0.0/OPR1.170623.027/1012001.2:user/release-keys
