/*
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

#define XXXXXXX KC_NO
#define ___T___ KC_TRNS

#define CT_FSPC LT(TL_UPPR, KC_SPC)
#define CT_GAME TG(LGAME)
#define CT_GRAI MO(LRAIS)
#define CT_GLWR MO(LLOWR)

#define LBASE 0
#define LLOWR 1
#define LRAIS 2
#define LDUAL 3
#define LGAME 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LBASE] = LAYOUT_all(
            QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, SE_ACUT, KC_BSLS, KC_BSPC,
            KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, KC_BSLS,
            KC_LCTL, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ADIA, SE_QUOT, KC_ENT,
            KC_LSFT, SE_LABK, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, KC_NO,   KC_RSFT, TL_UPPR,
            XXXXXXX, KC_LGUI, XXXXXXX, KC_LALT, CT_FSPC, CT_FSPC, CT_FSPC,                   KC_RALT, KC_RALT, KC_RALT, TL_LOWR, XXXXXXX),

[LLOWR] = LAYOUT_all(
            XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,
            XXXXXXX, KC_MPLY, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, SE_LCBR, SE_RCBR, XXXXXXX,
            KC_CAPS, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___, ___T___, ___T___,                   XXXXXXX, XXXXXXX, XXXXXXX, ___T___, XXXXXXX),

[LRAIS] = LAYOUT_all(
            SE_SECT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, CT_MAKE,
            XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, ___T___, SE_LBRC, SE_RBRC, ___T___,
            ___T___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, ___T___,
            ___T___, XXXXXXX, XXXXXXX, ___T___, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, KC_MAIL, SE_LABK, SE_RABK, SE_PIPE, ___T___, ___T___, ___T___,
            ___T___, KC_LGUI, XXXXXXX, ___T___, ___T___, ___T___, ___T___,                   ___T___, ___T___, ___T___, ___T___, XXXXXXX),

[LDUAL] = LAYOUT_all(
            DM_RSTP, DM_REC1, DM_REC2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            CL_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CT_GAME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CT_JIGG,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___,
            XXXXXXX, AG_TOGG, XXXXXXX, XXXXXXX, ___T___, ___T___, ___T___,                   XXXXXXX, XXXXXXX, XXXXXXX, ___T___, XXXXXXX),

[LGAME] = LAYOUT_all(
            QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, SE_ACUT, KC_BSLS, KC_BSPC,
            KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, KC_BSLS,
            KC_LCTL, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ODIA, SE_ADIA, KC_ENT,
            KC_LSFT, SE_LABK, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, KC_RSFT, KC_RSFT, ___T___,
            XXXXXXX, TL_UPPR, XXXXXXX, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,                    KC_RALT, KC_RALT, KC_RALT, TL_LOWR, XXXXXXX),
};
