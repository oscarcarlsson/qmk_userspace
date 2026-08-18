/* Copyright 2017 Oscar Carlsson
 *
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

// Fillers to make layering more clear
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _SV 0
#define _LW 1
#define _RS 2
#define _MD 3

// Magic keys
#define KC_LSHM SFT_T(SE_MINS) // shift when held, minus when tapped
#define KC_RSHC SFT_T(KC_COMM) // shift when held, comma when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_SV] = { /* SVORAK */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    SE_SLSH, SE_ASTR, SE_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_TAB,  SE_ARNG, SE_ADIA, SE_ODIA, KC_P,    KC_Y,    KC_PGUP, KC_INS,  KC_HOME, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    SE_QUOT },
  { KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_PGDN, KC_UP,   KC_END,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT  },
  { KC_LSHM, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_LEFT, KC_DOWN, KC_RGHT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSHC },
  { SE_QUOT, KC_DEL,  KC_SPC,  KC_LGUI, TL_UPPR, KC_BSPC, KC_LALT, MO(_MD), KC_RALT, KC_SPC,  TL_LOWR, KC_RALT, KC_RGUI, KC_COMM, SE_MINS },
 },

 [_LW] = { /* LOWERED */
  { CT_MAKE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_DEL  },
  { ___T___, SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, SE_DQUO, SE_QUES, SE_AMPR, SE_LABK, SE_RABK, ___T___ },
  { ___T___, SE_SCLN, SE_SLSH, SE_LPRN, SE_RPRN, SE_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, SE_HASH, SE_CIRC, SE_EURO, SE_QUOT, SE_GRV,  ___T___ },
  { ___T___, SE_COLN, SE_EQL,  SE_AT,   KC_EXLM, SE_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, SE_TILD, XXXXXXX, XXXXXXX, SE_ACUT, ___T___ },
  { ___T___, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, KC_DEL,  ___T___, XXXXXXX, ___T___, ___T___, ___T___, XXXXXXX, XXXXXXX, ___T___ },
 },

 [_RS] = { /* LOWERED */
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    SE_ASTR, KC_DEL  },
  { ___T___, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    SE_PLUS, ___T___ },
  { ___T___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    SE_BSLS, ___T___ },
  { ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_0,    KC_COMM, SE_EQL,  ___T___ },
  { XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, ___T___, XXXXXXX, XXXXXXX, ___T___ },
 },

 [_MD] = { /* some media buttons */
   { QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
   { XXXXXXX, KC_MPLY, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
   { KC_CAPS, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CT_JIGG },
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
   { XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }
 },
};
