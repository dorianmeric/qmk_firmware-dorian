# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

MOUSE_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

DYNAMIC_MACRO_ENABLE = yes # to be able to record macros
NKRO_ENABLE = yes
COMBO_ENABLE = yes

# VIA_ENABLE = yes

INTROSPECTION_KEYMAP_C = dorian-4x12.c # keymaps

include users/dorian-4x12/custom_rules.mk

include users/dorian-4x12/post_rules.mk
