RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
DEFERRED_EXEC_ENABLE = yes
MOUSE_ENABLE = yes
CONSOLE_ENABLE = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

DEBOUNCE_TYPE = sym_eager_pk
