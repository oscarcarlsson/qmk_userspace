#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "oscarcarlsson.h"

enum {
    TD_LSFT_CAPS,
};

enum custom_keycodes {
  CT_ODCL = NEW_SAFE_RANGE,
  CT_ARRC,
  CT_DIRC,
  CT_ADQT,
  CT_DTCL
};

#define BASE 0
#define HHKB 1
#define LOWR 2
#define GAME 3
#define GMFN 4

#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

#define CT_FSPC LT(HHKB, KC_SPC)
#define CT_HHKB MO(HHKB)
#define CT_LOWR MO(LOWR)
#define CT_GMFM MO(GMFN)
#define CT_GAME DF(GAME)
#define CT_NORM DF(BASE)

#define CT_CTLE CTL_T(KC_ESC)
#define CT_DTCL TD(TD_LSFT_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, SE_ACUT, SE_QUOT, SE_SECT,
		          KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, KC_BSPC,
		          KC_LCTL, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ADIA, KC_ENT,
		          CT_DTCL, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, CT_DTCL, CT_HHKB,
						            KC_LGUI, KC_LALT, CT_FSPC, KC_RALT, CT_LOWR),

  [HHKB] = LAYOUT(SE_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
		          KC_CAPS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS, SE_LBRC, SE_RBRC, KC_BSPC,
		          ___T___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_SCLN, XXXXXXX, KC_ENT,
		          ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_LABK, SE_RABK, SE_PIPE, XXXXXXX, ___T___,
						            ___T___, ___T___, ___T___, ___T___, ___T___),

  [LOWR] = LAYOUT(QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_RSWP, AG_RNRM, KC_PSCR, CT_JIGG,
        		  KC_CAPS, KC_MPLY, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_LCBR, SE_RCBR, XXXXXXX,
        		  CL_SWAP, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, CT_GAME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_COLN, XXXXXXX, XXXXXXX,
        		  XXXXXXX, DM_REC1, DM_RSTP, DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___,
         						    GU_TOGG, AG_LSWP, ___T___, AG_LNRM, ___T___),

  [GAME] = LAYOUT(KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, SE_ACUT, SE_QUOT, CT_NORM,
		          KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, KC_BSPC,
		          KC_LCTL, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ADIA, KC_ENT,
		          KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, KC_RSFT, CT_GMFM,
					                KC_LGUI, KC_LALT, KC_SPC,  KC_RALT, CT_GMFM),

  [GMFN] = LAYOUT(SE_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
            	  KC_CAPS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS, SE_LBRC, SE_RBRC, KC_BSPC,
            	  ___T___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_SCLN, XXXXXXX, KC_ENT,
            	  ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_LABK, SE_RABK, SE_PIPE, XXXXXXX, ___T___,
                                    ___T___, ___T___, ___T___, ___T___, ___T___),
};

#if defined(TAP_DANCE_ENABLE)
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
#endif
