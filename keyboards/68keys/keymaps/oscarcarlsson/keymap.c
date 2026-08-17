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

#include "68keys.h"
#include "keymap_swedish.h"
#include "oscarcarlsson.h"

#define _QWERTY 0
#define _FN1 1
#define XXXXXXX KC_NO
#define ___T___ KC_TRNS
#define KC_FN MO(_FN1)
#define KC_FS LT(_FN1, KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_68_ansi(
       KC_ESC,  KC_1,   KC_2,  KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   SE_MINS,SE_EQL, KC_BSPC,KC_HOME,KC_PGUP,
       KC_TAB,  KC_Q,   KC_W,  KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   SE_ARNG,SE_DIAE,SE_QUOT,KC_END, KC_PGDN,
       KC_LCTL, KC_A,   KC_S,  KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   SE_ODIA,SE_ADIA,KC_ENT,
       KC_LSFT, KC_Z,   KC_X,  KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,        KC_UP ,
       KC_LCTL, KC_LGUI,KC_LALT,            KC_FS,                     KC_RALT,KC_FN,  KC_RCTL,        KC_LEFT,KC_DOWN,KC_RGHT
  ),

  [_FN1] = LAYOUT_68_ansi(
       KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS, KC_VOLU,
       ___T___,___T___,KC_HOME,KC_UP,  KC_END, ___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,KC_DEL, KC_VOLD,
       KC_CAPS,___T___,KC_LEFT,KC_DOWN,KC_RGHT,___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,
       ___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,___T___,        KC_MUTE,
       ___T___,___T___,___T___,             ___T___,                   ___T___,___T___,___T___,        KC_MPRV,KC_MPLY,KC_MNXT
  ),
};
