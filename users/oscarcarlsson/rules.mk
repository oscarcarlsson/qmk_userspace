ifeq ($(strip $(MOUSE_JIGGLER)), yes)
    OPT_DEFS += -DMOUSE_JIGGLER
endif

ifeq ($(strip $(OS_DETECTION)), yes)
    OPT_DEFS += -DOS_DETECTION
endif
