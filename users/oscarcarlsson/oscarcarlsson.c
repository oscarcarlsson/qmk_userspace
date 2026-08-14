#include "oscarcarlsson.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef MOUSE_JIGGLER
  if (record->event.pressed) {
    static deferred_token token = INVALID_DEFERRED_TOKEN;
    static report_mouse_t report = {0};

    if (token) {
      // If jiggler is currently running, stop when any key is pressed.
      cancel_deferred_exec(token);
      token = INVALID_DEFERRED_TOKEN;
      report = (report_mouse_t){};  // Clear the mouse.
      host_mouse_send(&report);
    } else if (keycode == CT_JIGG) {

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
#endif

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
  }
    break;

  case CT_MAKE: {  // Compiles the firmware, and adds the flash command based on keyboard bootloader
    if (!record->event.pressed) {
      uint8_t temp_mod = get_mods();
      uint8_t temp_osm = get_oneshot_mods();
      clear_mods(); clear_oneshot_mods();
      SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
#ifndef FLASH_BOOTLOADER
      if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
#endif
        {
          SEND_STRING(":flash");
        }
      if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
        SEND_STRING(" -j8 --output-sync");
      }
      tap_code(KC_ENT);
      set_mods(temp_mod);
    }
  }
    break;
  }
  return process_record_keymap(keycode, record);
}

#if defined(OS_DETECTION_ENABLE)
uint32_t custom_os_settings(uint32_t trigger_time, void *cb_arg) {
  os_variant_t host = detected_host_os();
  uint16_t retry_ms = 500;

  if (host == OS_MACOS || host == OS_IOS) {
    keymap_config.swap_lalt_lgui = true;
    keymap_config.swap_ralt_rgui = false;
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
