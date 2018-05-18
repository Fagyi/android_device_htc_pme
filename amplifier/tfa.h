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

#ifndef __TFA_H__
#define __TFA_H__

#include <tinyalsa/asoundlib.h>
#include <stdbool.h>

typedef struct tfaS tfa_t;

tfa_t *tfa_new(void);

struct pcm *tfa_clocks_on(tfa_t *);
int tfa_clocks_off(tfa_t *, struct pcm *pcm);

bool tfa_wait_for_init(tfa_t *tfa);
void tfa_apply_profile(tfa_t *tfa, int profile);

void tfa_destroy(tfa_t *);

typedef enum {
    PROFILE_MUSIC = 0,
    PROFILE_RINGTONE,
    PROFILE_FM,
    PROFILE_VIDEO_RECORD,
    PROFILE_HANDSFREE_NB,
    PROFILE_HANDSFREE_WB,
    PROFILE_HANDSFREE_SWB,
    PROFILE_HANDSET,
    PROFILE_VOIP,
    PROFILE_MFG,
    PROFILE_AUDIO_EVALUATION,
    PROFILE_CALIBRATION,
    PROFILE_MAX
} tfa_profile_t;

#endif
