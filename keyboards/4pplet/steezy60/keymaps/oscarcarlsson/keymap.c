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

// silly
#define XXXXXXX KC_NO
#define ___T___ KC_TRNS

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  RAISE,
  DUAL,
  MACOS_SWITCH_LANGUAGE,
  JIGGLE,
  GAME
};

// Testing CI again

#define CT_LOWR LOWER
#define CT_RAIS RAISE
#define CT_FSPC LT(LRAIS, KC_SPC)
#define CT_MCL MACOS_SWITCH_LANGUAGE
#define CT_JIG JIGGLE
#define CT_GAME TG(LGAME)
#define CT_GRAI MO(LRAIS)
#define CT_GLWR MO(LLOWR)

#define LBASE 0
#define LRAIS 1
#define LLOWR 2
#define LDUAL 3
#define LGAME 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LBASE] = LAYOUT_all(
            QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, SE_ACUT, KC_BSLS, KC_BSPC,
            KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, KC_BSLS,
            KC_LCTL, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ADIA, SE_QUOT, KC_ENT,
            KC_LSFT, SE_LABK, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, KC_NO,   KC_RSFT, CT_RAIS,
            XXXXXXX, KC_LGUI, XXXXXXX, KC_LALT, CT_FSPC, CT_FSPC, CT_FSPC,                   KC_RALT, KC_RALT, KC_RALT, CT_LOWR, XXXXXXX),

[LRAIS] = LAYOUT_all(
            SE_SECT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, CT_MCL,
            XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, ___T___, SE_LBRC, SE_RBRC, ___T___,
            ___T___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, ___T___,
            ___T___, XXXXXXX, XXXXXXX, ___T___, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, KC_MAIL, SE_LABK, SE_RABK, SE_PIPE, ___T___, ___T___, ___T___,
            ___T___, KC_LGUI, XXXXXXX, ___T___, ___T___, ___T___, ___T___,                   ___T___, ___T___, ___T___, ___T___, XXXXXXX),

[LLOWR] = LAYOUT_all(
            XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,
            XXXXXXX, KC_MPLY, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, SE_LCBR, SE_RCBR, XXXXXXX,
            KC_CAPS, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___, ___T___, ___T___,                   XXXXXXX, XXXXXXX, XXXXXXX, ___T___, XXXXXXX),

[LDUAL] = LAYOUT_all(
            DM_RSTP, DM_REC1, DM_REC2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
            XXXXXXX, RGB_TOG, RGB_MOD, RGB_M_P, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            CL_TOGG, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CT_JIG,
            XXXXXXX, RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___,
            XXXXXXX, AG_TOGG, XXXXXXX, XXXXXXX, ___T___, ___T___, ___T___,                   XXXXXXX, XXXXXXX, XXXXXXX, ___T___, XXXXXXX),

[LGAME] = LAYOUT_all(
            QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, SE_ACUT, KC_BSLS, KC_BSPC,
            KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, KC_BSLS,
            KC_LCTL, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ODIA, SE_ADIA, KC_ENT,
            KC_LSFT, SE_LABK, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, KC_RSFT, KC_RSFT, ___T___,
            XXXXXXX, CT_RAIS, XXXXXXX, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,                    KC_RALT, KC_RALT, KC_RALT, CT_LOWR, XXXXXXX),
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
      persistent_default_layer_set(1UL << LBASE);
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

  case LOWER:
    if (record->event.pressed) {
      layer_on(LLOWR);
      update_tri_layer(LLOWR, LRAIS, LDUAL);
    } else {
      layer_off(LLOWR);
      update_tri_layer(LLOWR, LRAIS, LDUAL);
    }
    return false;
    break;

  case RAISE:
    if (record->event.pressed) {
      layer_on(LRAIS);
      update_tri_layer(LLOWR, LRAIS, LDUAL);
    } else {
      layer_off(LRAIS);
      update_tri_layer(LLOWR, LRAIS, LDUAL);
    }
    return false;
    break;

  case DUAL:
    if (record->event.pressed) {
      layer_on(LDUAL);
      update_tri_layer(LLOWR, LRAIS, LDUAL);
    } else {
      layer_off(LDUAL);
      update_tri_layer(LLOWR, LRAIS, LDUAL);
    }
    return false;
    break;

  case MACOS_SWITCH_LANGUAGE:
    if (!record->event.pressed) {
      SEND_STRING(SS_LOPT(" "));
      return false;
    }
    break;
  }
  return true;
}
