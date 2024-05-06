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

INTROSPECTION_KEYMAP_C = manna-harbour_miryoku.c # keymaps

include users/dorian-mir/custom_rules.mk

include users/dorian-mir/post_rules.mk
