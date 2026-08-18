#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "oscarcarlsson.h"

#define _DEFT 0
#define _LOWR 1
#define _NAVI 2
#define _DUAL 3

#define KC_CAD LALT(LCTL(KC_DEL))

// For TT(layer)
// For future Oscar:
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md#example-6-using-tap-dance-for-momentary-layer-switch-and-layer-toggle-keys-idexample-6
// https://getreuer.info/posts/keyboards/layer-lock/index.html

// PaperWM ftw
#define CT_GCOM LGUI(SE_COMM)
#define CT_GDOT LGUI(SE_DOT)

// Shift on hold, comma / dash upon tap
#define KC_SHMN MT(MOD_LSFT, SE_MINS)
#define KC_SHCM MT(MOD_RSFT, KC_COMM)

// Home row mods
#define MT_LGA MT(MOD_LGUI, KC_A)
#define MT_LAO MT(MOD_LALT, KC_O)
#define MT_LSE MT(MOD_LSFT, KC_E)
#define MT_LCU MT(MOD_LCTL, KC_U)

#define MT_RCH MT(MOD_RCTL, KC_H)
#define MT_RST MT(MOD_LSFT, KC_T)
#define MT_RAN MT(MOD_LALT, KC_N)
#define MT_RGS MT(MOD_LGUI, KC_S)

#define CT_UPPR LT(_NAVI, KC_BSPC)
#define CT_LOWR LT(_LOWR, KC_SPC)

// LCTL/TAB
#define KC_LCTT LCTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFT] = LAYOUT(KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,                      SE_6,    SE_7,    SE_8,    SE_9,     SE_0,    SE_MINS,
                   KC_TAB,  SE_ARNG, SE_ADIA, SE_ODIA, SE_P,    SE_Y,                      SE_F,    SE_G,    SE_C,    SE_R,     SE_L,    SE_DOT,
                   KC_LCTL, MT_LGA,  MT_LAO,  MT_LSE,  MT_LCU,  SE_I,                      SE_D,    MT_RCH,  MT_RST,  MT_RAN,   MT_RGS,  KC_ENT,
                   KC_SHMN, SE_DOT,  SE_Q,    SE_J,    SE_K,    SE_X,    CT_UPPR, CT_LOWR, SE_B,    SE_M,    SE_W,    SE_V,     SE_Z,    KC_SHCM,
                                                       KC_LGUI, TL_UPPR, CT_UPPR, CT_LOWR, TL_LOWR, KC_LALT),

  [_LOWR] = LAYOUT(KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
                   CT_GCOM, SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_DLR,                    SE_DQUO, SE_QUES, SE_AMPR,  SE_LABK, SE_RABK, CT_GDOT,
                   _______, SE_SCLN, SE_SLSH, SE_LPRN, SE_RPRN, SE_PIPE,                   SE_HASH, SE_CIRC, SE_EURO,  SE_QUOT, SE_TILD, _______,
                   _______, SE_COLN, SE_EQL,  SE_AT,   KC_EXLM, SE_BSLS, KC_WBAK, _______, KC_PERC, SE_MICR, SE_PND,   SE_ACUT, SE_GRV,  _______,
                                                       _______, _______, KC_WBAK, _______, _______, _______),

  [_NAVI] = LAYOUT(CT_JIGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_NUM,  SE_7,    SE_8,    SE_9,    SE_ASTR, KC_INS,
                   CT_GCOM, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,                   XXXXXXX, SE_4,    SE_5,    SE_6,    SE_PLUS, CT_GDOT,
                   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,                   XXXXXXX, SE_1,    SE_2,    SE_3,    SE_SLSH, _______,
                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, SE_MINS, SE_0,    SE_COMM, SE_EQL,  _______,
                                                       _______, _______, _______, _______, _______, _______),

  [_DUAL] = LAYOUT(DM_RSTP, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                   DM_REC1, KC_MPLY, KC_VOLU, KC_MSTP, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   DM_REC2, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAD,
                   _______, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                       _______, _______, _______, _______, _______, _______)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWR, _NAVI, _DUAL);
}
