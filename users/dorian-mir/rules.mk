# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes # https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md
KEY_OVERRIDE_ENABLE = yes

MOUSE_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

DYNAMIC_MACRO_ENABLE = yes # to be able to record macros
NKRO_ENABLE = yes
COMBO_ENABLE = yes


# VIA_ENABLE = yes

INTROSPECTION_KEYMAP_C = dorian-ferris.c # keymaps

include users/dorian-mir/custom_rules.mk

include users/dorian-mir/post_rules.mk
