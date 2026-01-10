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

// Fillers to make layering more clear
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  RAISE,
  DUAL,
  JIGGLE,
};


// Layer shorthand
#define _SV 0
#define _LW 1
#define _RS 2
#define _MD 3

// Magic keys
#define KC_LSHM SFT_T(SE_MINS) // shift when held, minus when tapped
#define KC_RSHC SFT_T(KC_COMM) // shift when held, comma when tapped

#define CT_JIGG JIGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_SV] = { /* SVORAK */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    SE_SLSH, SE_ASTR, SE_PLUS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_TAB,  SE_ARNG, SE_ADIA, SE_ODIA, KC_P,    KC_Y,    KC_PGUP, KC_INS,  KC_HOME, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_COMM },
  { KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_PGDN, KC_UP,   KC_END,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT  },
  { KC_LSHM, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_LEFT, KC_DOWN, KC_RGHT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT },
  { SE_QUOT, KC_DEL,  KC_SPC,  KC_LGUI, TL_UPPR, KC_BSPC, KC_LALT, MO(_MD), KC_RALT, KC_SPC,  TL_LOWR, KC_RALT, KC_RGUI, KC_COMM, SE_MINS },
 },

 [_LW] = { /* LOWERED */
  { KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_DEL  },
  { ___T___, SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, SE_DQUO, SE_QUES, SE_AMPR, SE_LABK, SE_RABK, ___T___ },
  { XXXXXXX, SE_SCLN, SE_SLSH, SE_LPRN, SE_RPRN, SE_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, SE_HASH, SE_CIRC, SE_EURO, SE_QUOT, SE_GRV,  XXXXXXX },
  { ___T___, SE_COLN, SE_EQL,  SE_AT,   KC_EXLM, SE_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, SE_TILD, XXXXXXX, XXXXXXX, SE_ACUT, XXXXXXX },
  { QK_BOOT, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, KC_DEL,  ___T___, XXXXXXX, ___T___, ___T___, ___T___, XXXXXXX, XXXXXXX, XXXXXXX },
 },

 [_RS] = { /* LOWERED */
  { XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    SE_ASTR, KC_DEL  },
  { ___T___, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    SE_PLUS, ___T___ },
  { ___T___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    SE_BSLS, XXXXXXX },
  { ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_0,    KC_COMM, SE_EQL,  XXXXXXX },
  { XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, ___T___, XXXXXXX, XXXXXXX, XXXXXXX },
 },

 [_MD] = { /* some media buttons */
   { DM_RSTP, DM_REC1, DM_REC2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
   { XXXXXXX, KC_MPLY, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
   { KC_CAPS, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CT_JIGG },
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
   { XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, XXXXXXX, ___T___, XXXXXXX, ___T___, ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }
 },
};

#if defined(OS_DETECTION_ENABLE)
uint32_t custom_os_settings(uint32_t trigger_time, void *cb_arg) {
  os_variant_t host = detected_host_os();
  uint16_t retry_ms = 500;

  if (host == OS_MACOS || host == OS_IOS) {
    keymap_config.swap_lalt_lgui = true;
    keymap_config.swap_ralt_rgui = true;
    retry_ms = 0;
  }

  return retry_ms;
}

void keyboard_post_init_user(void) {
  defer_exec(100, custom_os_settings, NULL);
}
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    static deferred_token token = INVALID_DEFERRED_TOKEN;
    static report_mouse_t report = {0};
    if (token) {
      // If jiggler is currently running, stop when any key is pressed.
      cancel_deferred_exec(token);
      token = INVALID_DEFERRED_TOKEN;
      report = (report_mouse_t){};  // Clear the mouse.
      host_mouse_send(&report);
    } else if (keycode == JIGGLE) {

      uint32_t jiggler_callback(uint32_t trigger_time, void* cb_arg) {
        // Deltas to move in a circle of radius 20 pixels over 32 frames.
        static const int8_t deltas[32] = {
          0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
          0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
        static uint8_t phase = 0;
        // Get x delta from table and y delta by rotating a quarter cycle.
        report.x = deltas[phase];
        report.y = deltas[(phase + 8) & 31];
        phase = (phase + 1) & 31;
        host_mouse_send(&report);
        return 16;  // Call the callback every 16 ms.
      }

      token = defer_exec(1, jiggler_callback, NULL);  // Schedule callback.
    }
  }

  switch (keycode) {
  case DEFAULT:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL << _SV);
    }
    return false;
    break;

  case KC_BSPC: {
    // https://getreuer.info/posts/keyboards/macros3/index.html
    static uint16_t registered_key = KC_NO;
    if (record->event.pressed) {  // On key press.
      const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
      uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
      uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
      if (shift_mods) {  // At least one shift key is held.
        registered_key = KC_DEL;
        // If one shift is held, clear it from the mods. But if both
        // shifts are held, leave as is to send Shift + Del.
        if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
          del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
          unregister_mods(MOD_MASK_SHIFT);
        }
      } else {
        registered_key = KC_BSPC;
      }

      register_code(registered_key);
      set_mods(mods);
    } else {  // On key release.
      unregister_code(registered_key);
    }
  } return false;
  }
  return true;
}
