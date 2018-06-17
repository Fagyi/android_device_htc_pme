/*
 * Copyright (C) 2016, The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "audio_amplifier::tfa"
#define LOG_NDEBUG 0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>

#include <cutils/log.h>
#include <tinyalsa/asoundlib.h>
#include "tfa.h"

#define TRACE_REGISTERS 0

#define UNUSED __attribute__ ((unused))

#include <linux/ioctl.h>
#include <sound/htc_audio_ioctl.h>

struct tfaS {
    struct mixer *mixer;
};

#define SND_CARD        0
#define AMP_PCM_DEV     47
#define AMP_MIXER_CTL   "QUAT_MI2S_RX_DL_HL Switch"

tfa_t *tfa_new(void)
{
    struct mixer *mixer;
    tfa_t *t;

    if ((mixer = mixer_open(SND_CARD)) == NULL) {
        ALOGE("failed to open mixer");
        return NULL;
    }

    if ((t = malloc(sizeof(*t))) == NULL) {
        ALOGE("out of memory");
        mixer_close(mixer);
        return NULL;
    }

    t->mixer = mixer;

    return t;
}

void tfa_destroy(tfa_t *t)
{
    mixer_close(0);
    free(t);
}

static struct pcm_config amp_pcm_config = {
    .channels = 1,
    .rate = 48000,
    .period_size = 0,
    .period_count = 4,
    .format = 0,
    .start_threshold = 0,
    .stop_threshold = INT_MAX,
    .avail_min = 0,
};

struct pcm *tfa_clocks_on(tfa_t *t)
{
    struct mixer_ctl *ctl;
    struct pcm *pcm;
    struct pcm_params *pcm_params;

    ctl = mixer_get_ctl_by_name(t->mixer, AMP_MIXER_CTL);
    if (ctl == NULL) {
        ALOGE("%s: Could not find %s", __func__, AMP_MIXER_CTL);
        return NULL;
    }

    pcm_params = pcm_params_get(SND_CARD, AMP_PCM_DEV, PCM_OUT);
    if (pcm_params == NULL) {
        ALOGE("Could not get the pcm_params");
        return NULL;
    }

    amp_pcm_config.period_count = pcm_params_get_max(pcm_params, PCM_PARAM_PERIODS);
    pcm_params_free(pcm_params);

    mixer_ctl_set_value(ctl, 0, 1);
    pcm = pcm_open(SND_CARD, AMP_PCM_DEV, PCM_OUT, &amp_pcm_config);
    if (!pcm) {
        ALOGE("failed to open pcm at all??");
        return NULL;
    }
    if (!pcm_is_ready(pcm)) {
        ALOGE("failed to open pcm device: %s", pcm_get_error(pcm));
        pcm_close(pcm);
        return NULL;
    }
    if (pcm_prepare(pcm) < 0) {
        ALOGE("failed to pcm_prepare: %s", pcm_get_error(pcm));
        pcm_close(pcm);
        return NULL;
    }

    ALOGV("clocks: ON");
    return pcm;
}

int tfa_clocks_off(tfa_t *t, struct pcm *pcm)
{
    struct mixer_ctl *ctl;

    pcm_close(pcm);

    ctl = mixer_get_ctl_by_name(t->mixer, AMP_MIXER_CTL);
    if (ctl == NULL) {
        ALOGE("%s: Could not find %s", __func__, AMP_MIXER_CTL);
        return -ENODEV;
    } else {
        mixer_ctl_set_value(ctl, 0, 0);
    }

    ALOGV("clocks: OFF");
    return 0;
}

bool tfa_wait_for_init(tfa_t *t)
{
    struct mixer_ctl *ctl;
    int retries = 0;

    ctl = mixer_get_ctl_by_name(t->mixer, "NXP MANSTATE");
    if (ctl == NULL) {
        ALOGE("%s: Could not find %s", __func__, "NXP MANSTATE");
        return false;
    }

    while (mixer_ctl_get_value(ctl, 0) != 9) {
        if (retries++ > 100) {
           ALOGI("%s: failed to get stable state", __func__);
           return false;
        }
        usleep(50000);
    }

    return true;
}

void tfa_apply_profile(tfa_t *t, int profile)
{
    struct mixer_ctl *ctl;
    int retries = 0;

    ctl = mixer_get_ctl_by_name(t->mixer, "PME Profile");
    if (ctl == NULL) {
        ALOGE("%s: Could not find %s", __func__, "PME Profile");
        return;
    }

    if (mixer_ctl_set_value(ctl, 0, profile)) {
        ALOGI("%s: failed to set profile %d", __func__, profile);
    }
}
