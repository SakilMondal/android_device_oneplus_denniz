/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"

static const variant_info_t global_info = {
    .prjname_value = "20831",

    .model = "DN2103",
    .name = "DN2103EEA",
    .build_fingerprint = "OnePlus/DN2103EEA/OP515BL1:11/RP1A.200720.011/1629889893415:user/release-keys",
    .hw = "20831",
};

static const variant_info_t india_info = {
    .prjname_value = "20827",

    .model = "DN2101",
    .name = "DN2101IND",
    .build_fingerprint = "OnePlus/DN2101IND/OP515BL1:11/RP1A.200720.011/1627567766349:user/release-keys",
    .hw = "20827",
};

static const std::vector<variant_info_t> variants = {
    global_info,
    india_info,
};

void vendor_load_properties() {
    search_variant(variants);
    set_dalvik_heap();
}
