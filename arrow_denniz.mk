#
# Copyright (C) 2021 Android Open Source Project
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

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from device makefile
$(call inherit-product, device/oneplus/denniz/device.mk)

# Inherit some common ArrowOS stuff.
$(call inherit-product, vendor/arrow/config/common.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := arrow_denniz
PRODUCT_DEVICE := denniz
PRODUCT_BRAND := OnePlus
PRODUCT_MODEL := DN2101
PRODUCT_MANUFACTURER := OnePlus

TARGET_BOOT_ANIMATION_RES := 1080


PRODUCT_GMS_CLIENTID_BASE := android-oneplus

# Build info
PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_DEVICE=OP515BL1 \
    PRODUCT_NAME=DN2101IND \
    PRIVATE_BUILD_DESC="DN201IND-user 11 RP1A.200720.011 1627567766349 release-keys"

BUILD_FINGERPRINT := OnePlus/DN2101IND/OP515BL1:11/RP1A.200720.011/1627567766349:user/release-keys
