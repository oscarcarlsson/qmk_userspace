#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  JIGGLE,
  MACOS_SWITCH_LANGUAGE
};

#define CT_CAD LCA(KC_DEL)
#define CT_EXCL HYPR(KC_X)
#define CT_TEMS HYPR(KC_T)
#define CT_WORD HYPR(KC_W)
#define CT_OUTL HYPR(KC_O)

#define CT_CCPY LCTL(KC_C)
#define CT_CUND LCTL(KC_Z)
#define CT_CCUT LCTL(KC_X)
#define CT_CPST LCTL(KC_V)

#define CT_JIGG JIGGLE
#define CT_MACL MACOS_SWITCH_LANGUAGE
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
    CT_MACL, CT_CUND, CT_CCUT, CT_CCPY, CT_CPST, DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_F13,  KC_F14,  KC_F15,                          CT_JIGG,
    SE_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, _______,  KC_HOME, KC_PGUP, KC_NUM, KC_EQL, KC_PSLS,KC_PAST,
    _______, XXXXXXX, CT_WORD, XXXXXXX, XXXXXXX, CT_TEMS, XXXXXXX, XXXXXXX, XXXXXXX, CT_OUTL, XXXXXXX, SE_LBRC, SE_RBRC, SE_BSLS, KC_INS,   KC_END,  KC_PGDN, KC_P7,  KC_P8,  KC_P9,  KC_PMNS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_LCBR, SE_RCBR,          _______,                            KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
    _______, XXXXXXX, CT_EXCL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_LABK, SE_RABK, SE_PIPE,                   _______,          KC_VOLU,          KC_P1,  KC_P2,  KC_P3,
    _______, _______, AG_TOGG,                   _______,                                     _______, _______,                   KC_MUTE, KC_VOLD, KC_MPLY, KC_P0,          KC_PDOT,KC_PENT
  )
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

#endif

void keyboard_post_init_user(void) {
#if defined(DEFERRED_EXEC_ENABLE)
  defer_exec(100, custom_os_settings, NULL);
#endif
#if defined(CONSOLE_ENABLE)
  debug_enable = true;
#endif
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
  }
  return true;
}
