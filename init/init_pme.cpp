/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>
#include <android-base/logging.h>
#include "vendor_init.h"
#include "property_service.h"

/* Device specific properties */
#include "htc-asia.h"
#include "htc-ee_uk.h"
#include "htc-europe.h"
#include "htc-mexico.h"
#include "htc-o2_uk.h"
#include "htc-sprint.h"
#include "htc-taiwan.h"
#include "htc-tmobile_usa.h"
#include "htc-unlocked.h"
#include "htc-verizon.h"

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[],
    char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

static void load_properties(const char *original_data)
{
    char *data;
    char *key, *value, *eol, *sol, *tmp;

    if ((data = (char *) malloc(strlen(original_data)+1)) == NULL) {
        return;
    }

    strcpy(data, original_data);

    sol = data;
    while ((eol = strchr(sol, '\n'))) {
        key = sol;
        *eol++ = 0;
        sol = eol;

        while (isspace(*key)) key++;
        if (*key == '#') continue;

        tmp = eol - 2;
        while ((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        value = strchr(key, '=');
        if (!value) continue;
        *value++ = 0;

        tmp = value - 2;
        while ((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        while (isspace(*value)) value++;

        property_override(key, value);
    }

    free(data);
}

void vendor_load_properties()
{
    std::string platform;
    std::string bootmid;
    std::string bootcid;

    platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    bootmid = GetProperty("ro.boot.mid", "");
    bootcid = GetProperty("ro.boot.cid", "");

    if (is_variant_asia(bootcid)) {
        load_properties(htc_asia_properties);
    } else if (is_variant_ee_uk(bootcid)) {
        load_properties(htc_ee_uk_properties);
    } else if (is_variant_europe(bootcid)) {
        load_properties(htc_europe_properties);
    } else if (is_variant_mexico(bootcid)) {
        load_properties(htc_mexico_properties);
    } else if (is_variant_o2_uk(bootcid)) {
        load_properties(htc_o2_uk_properties);
    } else if (is_variant_sprint(bootcid)) {
        load_properties(htc_sprint_properties);
    } else if (is_variant_taiwan(bootcid)) {
        load_properties(htc_taiwan_properties);
    } else if (is_variant_tmobile_usa(bootcid)) {
        load_properties(htc_tmobile_usa_properties);
    } else if (is_variant_unlocked(bootcid)) {
        load_properties(htc_unlocked_properties);
    } else if (is_variant_verizon(bootcid)) {
        load_properties(htc_verizon_properties);
    } else {
        property_set("ro.lineage.invalid_bootcid", bootcid.c_str());
        if (bootmid == "2PS620000") {
            load_properties(htc_europe_properties);
        } else {
            load_properties(htc_unlocked_properties);
        }
    }
}
