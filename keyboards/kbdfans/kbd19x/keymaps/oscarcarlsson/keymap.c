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
#include "os_detection.h"

enum custom_keycodes {
  MACOS_SWITCH_LANGUAGE = SAFE_RANGE,
  JIGGLE
};

#define BASE 0
#define LOWR 1

#define CT_LOWR MO(LOWR)
#define CT_JIGG JIGGLE
#define CT_CAD LALT(LCTL(KC_DEL))
#define CT_MCL MACOS_SWITCH_LANGUAGE

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

#if defined(OS_DETECTION_ENABLE)
uint32_t custom_os_settings(uint32_t trigger_time, void *cb_arg) {
  os_variant_t host = detected_host_os();
  uint16_t retry_ms = 500;

  if (host == OS_MACOS || host == OS_IOS) {
    keymap_config.swap_lalt_lgui = true;
    keymap_config.swap_ralt_rgui = true;
    retry_ms = 0;
  } else if (host == OS_LINUX) {
    keymap_config.swap_control_capslock = true;
    retry_ms = 0;
  }

  return retry_ms;
}

void keyboard_post_init_user(void) {
  defer_exec(100, custom_os_settings, NULL);
}
#endif

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

  case MACOS_SWITCH_LANGUAGE:
    if (!record->event.pressed) {
      SEND_STRING(SS_LOPT(" "));
      return false;
    }
    break;

  default:
    break;
  }
  return true;
}
