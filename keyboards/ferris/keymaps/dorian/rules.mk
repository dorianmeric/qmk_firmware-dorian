# Bootloader selection



RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

# Enables combos to be defined cleanly in combos.def
COMBO_ENABLE = yes
VPATH += keyboards/gboards  # can now write #include "g/keymap_combo.h"    to include keyboards/gboards/g/keymap_combo.h

SRC += oneshot.c
SRC += swapper.c

TAP_DANCE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

SPLIT_KEYBOARD = yes
BOOTLOADER = rp2040
CONVERT_TO = kb2040
# to compile, run
# 
#  cd /root/qmk_firmware
#  make ferris/sweep:dorian
#
# or
# qmk compile -kb ferris/sweep -km dorian-v1 -e CONVERT_TO=kb2040
# then copy the uf2 file onto each half.

# make ferris/sweep:dorian
# make ferris/sweep:dorian -e CONVERT_TO=promicro_rp2040
