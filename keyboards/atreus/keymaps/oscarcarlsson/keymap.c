#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define _DEFT 0
#define _NAVI 1
#define _SYMB 2
#define _DUAL 3

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Each new keycode requires an unique number, the SAFE_RANGE macro
// helps us with this. These keys are added to our keymaps and handled
// in process_record_user.
enum custom_keycodes {
  DEFT = SAFE_RANGE,
  SYMB,
  NAVI
};

#define KC_LSHD SFT_T(KC_DOT)
#define KC_RSDT SFT_T(KC_Z)
#define KC_RGMS RGUI_T(SE_MINS)

// Home row mods
#define MT_LGA MT(MOD_LGUI, KC_A)
#define MT_LAO MT(MOD_LALT, KC_O)
#define MT_LSE MT(MOD_LSFT, KC_E)
#define MT_LCU MT(MOD_LCTL, KC_U)

#define MT_RCH MT(MOD_RCTL, KC_H)
#define MT_RST MT(MOD_LSFT, KC_T)
#define MT_RAN MT(MOD_LALT, KC_N)
#define MT_RGS MT(MOD_LGUI, KC_S)

#define MT_LCB MT(MOD_LCTL, KC_BSPC)
#define MT_LAS MT(MOD_LALT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFT] = {
    { SE_ARNG, SE_ADIA, SE_ODIA, KC_P,    KC_Y,    _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L    },
    { MT_LGA,  MT_LAO,  MT_LSE,  MT_LCU,  KC_I,    _______, KC_D,    MT_RCH,  MT_RST,  MT_RAN,  MT_RGS  },
    { KC_LSHD, KC_Q,    KC_J,    KC_K,    KC_X,    MT_LCB,  KC_B,    KC_M,    KC_W,    KC_V,    KC_RSDT },
    { KC_TAB,  KC_COMM, KC_LGUI, NAVI,    NAVI,    MT_LAS,  SYMB,    KC_RGUI, KC_RGMS, KC_RALT, KC_ENT  }
  },

  [_NAVI] = {
    { KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______, KC_PGUP, KC_7,    KC_8,    KC_9,    SE_ASTR },
    { KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, _______, KC_PGDN, KC_4,    KC_5,    KC_6,    SE_PLUS },
    { _______, DM_REC1, DM_RSTP, DM_PLY1, KC_MPLY, _______, SE_SLSH, KC_1,    KC_2,    KC_3,    _______ },
    { KC_ESC,  _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______ }
  },

  [_SYMB] = {
    { SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_DLR,  _______, SE_DQUO, SE_QUES, SE_AMPR, SE_LABK, SE_RABK },
    { SE_SCLN, SE_SLSH, SE_LPRN, SE_RPRN, SE_PIPE, _______, SE_HASH, SE_CIRC, SE_TILD, SE_QUOT, SE_GRV  },
    { _______, SE_EQL,  SE_AT,   SE_EXLM, SE_BSLS, _______, SE_PERC, SE_EURO, SE_MINS, XXXXXXX, SE_ACUT },
    { KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, KC_APP,  _______ }
  },

  [_DUAL] = {
    { MS_ACL0, MS_BTN1, MS_UP,   MS_BTN2, MS_WHLU, _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10  },
    { MS_ACL1, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, _______, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11  },
    { MS_ACL2, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12  },
    { QK_BOOT, XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX, _______, KC_PSCR, KC_SCRL, KC_PAUS }
  }
};

#if defined(CONSOLE_ENABLE)
void keyboard_post_init_user(void) {
  debug_enable = true;
}
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Return true makes QMK deal with the key as usual, false means that
// we have the responsibility and enables us to do our magic
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case DEFT:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL<<_DEFT);
    }
    return false;
    break;
  case SYMB:
    if (record->event.pressed) {
      layer_on(_SYMB);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    } else {
      layer_off(_SYMB);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    }
    return false;
    break;
  case NAVI:
    if (record->event.pressed) {
      layer_on(_NAVI);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    } else {
      layer_off(_NAVI);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    }
    return false;
    break;
  }
  return true;
}
