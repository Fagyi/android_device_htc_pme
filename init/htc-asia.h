/* props/asia-1.21: hTC Asia AUS: HTC__039 OPTUS001 VODAP021 TELNZ001 */
static bool is_variant_asia(std::string bootcid) {
    if (bootcid == "HTC__039") return true;
    if (bootcid == "OPTUS001") return true;
    if (bootcid == "VODAP021") return true;
    if (bootcid == "TELNZ001") return true;
    return false;
}

static const char *htc_asia_properties =
    "ro.telephony.ipv6_capability=1\n"
    "ro.ril.vmail.505029=+61411000212\n"
    "ro.ril.vmail.50506=+61430005333\n"
    "ro.ril.vmail.53005=+6483083210\n"
    "ro.ril.vmail.50502=+61411000321\n"
    "ro.ril.vmail.50503=121\n"
    "ro.ril.vmail.53024=202\n"
    "ro.ril.oem.ecclist=000,111,112\n"
    "ro.ril.oem.nosim.ecclist=000,111,112\n"
    "ro.ril.enable.a52=0\n"
    "ro.ril.enable.amr.wideband=0\n"
    "ro.ril.enable.sdr=1\n"
    "ro.ril.emc.mode=1\n"
    "ro.ril.enable.pre_r8fd=1\n"
    "ro.ril.fd.pre_r8_tout.scr_off=0\n"
    "ro.ril.fd.pre_r8_tout.scr_on=0\n"
    "ro.ril.enable.r8fd=1\n"
    "ro.ril.fd.r8_tout.scr_off=2\n"
    "ro.ril.fd.r8_tout.scr_on=3\n"
    "ro.ril.hsxpa=5\n"
    "ro.ril.hsdpa.category=24\n"
    "ro.ril.hsupa.category=6\n"
    "ro.ril.disable.cpc=0\n"
    "ro.ril.radio.svn=1\n"
    "ro.ril.ltefgi.rel10=1076232192\n"
    "persist.radio.NETWORK_SWITCH=1\n"
    "persist.rild.nitz_plmn=\n"
    "persist.rild.nitz_long_ons_0=\n"
    "persist.rild.nitz_long_ons_1=\n"
    "persist.rild.nitz_long_ons_2=\n"
    "persist.rild.nitz_long_ons_3=\n"
    "persist.rild.nitz_short_ons_0=\n"
    "persist.rild.nitz_short_ons_1=\n"
    "persist.rild.nitz_short_ons_2=\n"
    "persist.rild.nitz_short_ons_3=\n"
    "ril.subscription.types=NV,RUIM\n"
    "telephony.lteOnCdmaDevice=1\n"
    "telephony.lteOnCdmaDevice=0\n"
    "persist.radio.fill_eons=1\n"
    "persist.igps.sensor=on\n"
    "persist.radio.custom_ecc=1\n"
    "persist.radio.apm_sim_not_pwdn=0\n"
    "persist.radio.apm_mdm_not_pwdn=1\n"
    "ro.telephony.default_network=9\n"
    "persist.radio.sap_silent_pin=1\n"
    "ro.gps.agps_provider=1\n"
;
