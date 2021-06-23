/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/properties.h>
#include <libinit_utils.h>

#include <libinit_variant.h>

using android::base::GetProperty;

#define PRJNAME_PROP "ro.boot.prjname"

void search_variant(const std::vector<variant_info_t> variants) {
    std::string prjname_value = GetProperty(PRJNAME_PROP, "");

    for (const auto& variant : variants) {
        if ((variant.prjname_value == "" || variant.prjname_value == prjname_value)) {
            set_variant_props(variant);
            break;
        }
    }
}

void set_variant_props(const variant_info_t variant) {
    set_ro_build_prop("model", variant.model, true);
    set_ro_build_prop("name", variant.name, true);

    set_ro_build_prop("fingerprint", variant.build_fingerprint);
    property_override("ro.bootimage.build.fingerprint", variant.build_fingerprint);

    property_override("ro.build.description", fingerprint_to_description(variant.build_fingerprint));

    property_override("ro.product.hw", variant.hw);
}
