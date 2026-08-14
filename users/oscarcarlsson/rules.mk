SRC += oscarcarlsson.c

ifeq ($(strip $(MOUSE_JIGGLER)), yes)
    OPT_DEFS += -DMOUSE_JIGGLER
endif


