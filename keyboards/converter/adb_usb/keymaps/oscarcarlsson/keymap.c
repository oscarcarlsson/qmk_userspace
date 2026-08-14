#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "oscarcarlsson.h"

#define CT_CAD LCA(KC_DEL)
#define CT_EXCL HYPR(KC_X)
#define CT_TEMS HYPR(KC_T)
#define CT_WORD HYPR(KC_W)
#define CT_OUTL HYPR(KC_O)

#define CT_CCPY LCTL(KC_C)
#define CT_CUND LCTL(KC_Z)
#define CT_CCUT LCTL(KC_X)
#define CT_CPST LCTL(KC_V)

#define CT_LT1 MO(1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ext_ansi(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR,KC_SCRL, KC_PAUS,                           CT_CAD,
    SE_LABK, SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    SE_PLUS, SE_ACUT, KC_BSPC, CT_LT1, KC_HOME, KC_PGUP, KC_NUM,  KC_EQL, KC_PSLS, KC_PAST,
    KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, SE_QUOT, KC_DEL, KC_END,  KC_PGDN, KC_P7,   KC_P8,  KC_P9,   KC_PMNS,
    KC_LCAP, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ADIA,          KC_ENT,                            KC_P4,   KC_P5,  KC_P6,   KC_PPLS,
    KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS,                   KC_RSFT,          KC_UP,           KC_P1,   KC_P2,  KC_P3,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT, KC_RALT,                   KC_LEFT, KC_DOWN, KC_RGHT,KC_P0,           KC_PDOT, KC_PENT
    ),

  [1] = LAYOUT_ext_ansi(
    CT_MAKE, CT_CUND, CT_CCUT, CT_CCPY, CT_CPST, DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_F13,  KC_F14,  KC_F15,                           CT_JIGG,
    SE_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, _______, KC_HOME, KC_PGUP, KC_NUM, KC_EQL, KC_PSLS, KC_PAST,
    _______, XXXXXXX, CT_WORD, XXXXXXX, XXXXXXX, CT_TEMS, XXXXXXX, XXXXXXX, XXXXXXX, CT_OUTL, XXXXXXX, SE_LBRC, SE_RBRC, SE_BSLS, KC_INS,  KC_END,  KC_PGDN, KC_P7,  KC_P8,  KC_P9,   KC_PMNS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_LCBR, SE_RCBR,          _______,                            KC_P4,  KC_P5,  KC_P6,   KC_PPLS,
    _______, XXXXXXX, CT_EXCL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_LABK, SE_RABK, SE_PIPE,                   _______,          KC_VOLU,          KC_P1,  KC_P2,  KC_P3,
    _______, _______, AG_TOGG,                   _______,                                     _______, _______,                   KC_MUTE, KC_VOLD, KC_MPLY, KC_P0,          KC_PDOT, KC_PENT
  )
};
