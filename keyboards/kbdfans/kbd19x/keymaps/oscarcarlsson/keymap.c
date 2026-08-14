/*
  Copyright 2018 Jeff Shufelt <jshuf@puppyfish.com> @jshuf

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "oscarcarlsson.h"

#define BASE 0
#define LOWR 1

#define CT_LOWR MO(LOWR)
#define CT_CAD LALT(LCTL(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_iso( /* Base */
         KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  CT_CAD,           KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  \
         SE_SECT, SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    SE_PLUS, SE_ACUT, KC_BSPC,          KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, \
         KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE,                   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
         KC_CAPS, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ADIA, SE_QUOT, KC_ENT,           KC_P4,   KC_P5,   KC_P6,            \
         KC_LSFT, SE_LABK, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, KC_RSFT,       KC_UP,      KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
         KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, CT_LOWR, KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,   KC_PDOT \
  ),
  [LOWR] = LAYOUT_iso( /* Func */
         KC_MUTE, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,  CT_JIGG,         KC_HOME, KC_END,  KC_SCRL, KC_PSCR, \
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  QK_BOOT,         KC_CALC, _______, _______, _______, \
         _______, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______, _______, _______,  _______,         _______, _______, _______, _______, \
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,          \
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       KC_VOLU,    _______, _______, _______, _______, \
         CL_TOGG, KC_APP,  AG_TOGG,                            _______,                   _______, _______, _______,       KC_BRID, KC_VOLD, KC_BRIU,    _______, _______           \
  ),
};
