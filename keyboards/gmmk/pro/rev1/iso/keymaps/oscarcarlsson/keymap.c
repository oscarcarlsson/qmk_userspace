/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#include "oscarcarlsson.h"

enum layers {
  _LAYER_BASE,
  _LAYER_GAME,
  _LAYER_FN,
};

#define KC_CAD LALT(LCTL(KC_DEL))

#define CT_LGM TG(_LAYER_GAME)
#define CT_LFN MO(_LAYER_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER_BASE] = LAYOUT(
	KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CAD,           KC_MUTE,
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_END,
	KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
	KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
	KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, CT_LFN,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAYER_GAME] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, KC_T,    _______, _______, _______, _______, _______, _______, _______,                   _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, KC_C,    KC_V,    _______, _______, _______, _______, _______, _______,          _______, _______, _______,
	XXXXXXX, XXXXXXX, KC_LALT,                            _______,                            KC_RALT, _______, _______, _______, _______, _______
    ),

    [_LAYER_FN] = LAYOUT(
	QK_BOOT, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, CT_JIGG,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           KC_INS,
	_______, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,                   _______,
	CL_TOGG, _______, _______, _______, _______, CT_LGM,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, _______, _______,
	_______, AG_TOGG, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
