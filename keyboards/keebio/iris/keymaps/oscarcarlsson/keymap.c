#include QMK_KEYBOARD_H

#include "keymap_swedish.h"

#define _DEFT 0
#define _LOWR 1
#define _NAVI 2
#define _DUAL 3

// Silly comment

// I should try to understand QMK better
enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  NAVI,
  DUAL,
  JIGGLE
};

#define KC_CAD LALT(LCTL(KC_DEL))

// For TT(layer)
// For future Oscar:
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md#example-6-using-tap-dance-for-momentary-layer-switch-and-layer-toggle-keys-idexample-6
// https://getreuer.info/posts/keyboards/layer-lock/index.html
#define CT_NAVI NAVI
#define CT_LOWR LOWER

// PaperWM ftw
#define CT_GCOM LGUI(SE_COMM)
#define CT_GDOT LGUI(SE_DOT)

// Shift on hold, comma / dash upon tap
#define KC_SHMN MT(MOD_LSFT, SE_MINS)
#define KC_SHCM MT(MOD_RSFT, KC_COMM)

// Home row mods
#define MT_LGA MT(MOD_LGUI, KC_A)
#define MT_LAO MT(MOD_LALT, KC_O)
#define MT_LSE MT(MOD_LSFT, KC_E)
#define MT_LCU MT(MOD_LCTL, KC_U)

#define MT_RCH MT(MOD_RCTL, KC_H)
#define MT_RST MT(MOD_LSFT, KC_T)
#define MT_RAN MT(MOD_LALT, KC_N)
#define MT_RGS MT(MOD_LGUI, KC_S)

#define CT_JIG JIGGLE

// LCTL/TAB
#define KC_LCTT LCTL_T(KC_TAB)

// TODO: Make these tap toggleable
#define KC_LOWR LOWER
#define KC_NAVI NAVI
#define KC_DUAL DUAL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFT] = LAYOUT(KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,                      SE_6,    SE_7,    SE_8,    SE_9,     SE_0,    SE_MINS,
                   SE_COMM, SE_ARNG, SE_ADIA, SE_ODIA, SE_P,    SE_Y,                      SE_F,    SE_G,    SE_C,    SE_R,     SE_L,    SE_DOT,
                   KC_LCTT, MT_LGA,  MT_LAO,  MT_LSE,  MT_LCU,  SE_I,                      SE_D,    MT_RCH,  MT_RST,  MT_RAN,   MT_RGS,  KC_ENT,
                   KC_LSFT, SE_DOT,  SE_Q,    SE_J,    SE_K,    SE_X,    KC_BSPC, KC_SPC,  SE_B,    SE_M,    SE_W,    SE_V,     SE_Z,    KC_RSFT,
                                                       KC_LGUI, CT_NAVI, KC_BSPC, KC_SPC,  CT_LOWR, KC_LALT),

  [_LOWR] = LAYOUT(KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
                   CT_GCOM, SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_DLR,                    SE_DQUO, SE_QUES, SE_AMPR,  SE_LABK, SE_RABK, CT_GDOT,
                   _______, SE_SCLN, SE_SLSH, SE_LPRN, SE_RPRN, SE_PIPE,                   SE_HASH, SE_CIRC, SE_EURO,  SE_QUOT, SE_TILD, _______,
                   _______, SE_COLN, SE_EQL,  SE_AT,   KC_EXLM, SE_BSLS, KC_WBAK, _______, KC_PERC, SE_MICR, SE_PND,   SE_ACUT, SE_GRV,  _______,
                                                       _______, _______, KC_WBAK, _______, _______, _______),

  [_NAVI] = LAYOUT(CT_JIG,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_NUM,  SE_7,    SE_8,    SE_9,    SE_ASTR, KC_INS,
                   CT_GCOM, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,                   XXXXXXX, SE_4,    SE_5,    SE_6,    SE_PLUS, CT_GDOT,
                   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,                   XXXXXXX, SE_1,    SE_2,    SE_3,    SE_SLSH, _______,
                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, SE_MINS, SE_0,    SE_COMM, SE_EQL,  _______,
                                                       _______, _______, _______, _______, _______, _______),

  [_DUAL] = LAYOUT(DM_RSTP, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                   DM_REC1, KC_MPLY, KC_VOLU, KC_MSTP, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   DM_REC2, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAD,
                   _______, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                       _______, _______, _______, _______, _______, _______)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// I should really understand what this does at some point
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
        persistent_default_layer_set(1UL<<_DEFT);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWR);
        update_tri_layer(_LOWR, _NAVI, _DUAL);
      } else {
        layer_off(_LOWR);
        update_tri_layer(_LOWR, _NAVI, _DUAL);
      }
      return false;
      break;

    case NAVI:
      if (record->event.pressed) {
        layer_on(_NAVI);
        update_tri_layer(_LOWR, _NAVI, _DUAL);
      } else {
        layer_off(_NAVI);
        update_tri_layer(_LOWR, _NAVI, _DUAL);
      }
      return false;
      break;

    case DUAL:
      if (record->event.pressed) {
        layer_on(_DUAL);
        update_tri_layer(_LOWR, _NAVI, _DUAL);
      } else {
        layer_off(_DUAL);
        update_tri_layer(_LOWR, _NAVI, _DUAL);
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

#if defined(CONSOLE_ENABLE)
void keyboard_post_init_user(void) {
  debug_enable = true;
}
#endif
