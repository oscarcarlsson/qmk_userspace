/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "oscarcarlsson.h"

// Layer shorthand
#define _DV 0
#define _LW 1
#define _RS 2
#define _FN 3

#define CT_CAD LALT(LCTL(KC_DEL))
#define CT_MEL LGUI(KC_L)

// Left control when held, ESC when tapped
#define CT_LCES LCTL_T(KC_ESC)

// Fillers to make layering more clear
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

#define CT_LW QK_TRI_LAYER_LOWER
#define CT_RS QK_TRI_LAYER_UPPER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DV] = LAYOUT_monotux(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    CT_CAD,  CT_MEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_MINS, \
    KC_TAB,  SE_ARNG, SE_ADIA, SE_ODIA, KC_P,    KC_Y,    KC_INS,  KC_DEL,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_COMM, \
    CT_LCES, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_HOME, KC_PGUP, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,  \
    KC_LSFT, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_END,  KC_PGDN, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
    XXXXXXX, KC_LGUI, KC_LALT, KC_LALT, CT_RS,      KC_BSPC,           KC_SPC,       CT_LW,   KC_LALT, KC_RALT, KC_RGUI, XXXXXXX  \
  ),

  [_LW] = LAYOUT_monotux(
    KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  \
    ___T___, SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_DLR,  XXXXXXX, XXXXXXX, SE_DQUO, SE_QUES, SE_AMPR, SE_LABK, SE_RABK, SE_MINS, \
    ___T___, SE_SCLN, SE_SLSH, SE_LPRN, SE_RPRN, SE_PIPE, XXXXXXX, XXXXXXX, SE_HASH, SE_CIRC, SE_EURO, SE_QUOT, SE_GRV,  XXXXXXX, \
    ___T___, SE_COLN, SE_EQL,  SE_AT,   KC_EXLM, SE_BSLS, KC_COPY, KC_PSTE, KC_PERC, SE_TILD, XXXXXXX, XXXXXXX, SE_ACUT, XXXXXXX, \
    ___T___, KC_APP,  ___T___, ___T___, ___T___,      ___T___,          ___T___,     ___T___, ___T___, ___T___, ___T___, ___T___  \
  ),

  [_RS] = LAYOUT_monotux(
    CT_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM,  KC_P7,   KC_P8,   KC_P9,   SE_ASTR, KC_INS,  \
    ___T___, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   SE_PLUS, ___T___, \
    ___T___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   SE_MINS, ___T___, \
    ___T___, ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, KC_COMM, KC_P0,   KC_DOT,  SE_EQL,  ___T___, \
    ___T___, ___T___, ___T___, ___T___, ___T___,     ___T___,      ___T___,          ___T___, ___T___, ___T___, ___T___, ___T___  \
  ),

  [_FN] = LAYOUT_monotux(
    QK_BOOT, UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, _______, _______, _______, _______, _______, _______, _______, CT_JIGG,  \
    _______, KC_MPLY, KC_VOLU, KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, CT_CAD,  \
    _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,       _______,       _______,       _______, _______, _______, KC_APP,  _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
