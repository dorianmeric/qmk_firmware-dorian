// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// #include "custom_config.h"

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 300 // 200ms originally

// // Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0  // allows to spam the tap output by doing a quick 'tap-hold'

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64


#define COMBO_ONLY_FROM_LAYER 0 // makes the Combos letters assume that you are always on layer 0 (useful to trigger keys even if using a Colemak layout for example. But it means the text Combo also triggers while in the NAV / MOUSE layers)
#define COMBO_TERM 50        // how quickly all combo keys must be pressed in succession to trigger
// #define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
// #define COMBO_HOLD_TERM 200  // how long at least one of the combo keys must be held to trigger
#define EXTRA_SHORT_COMBOS // limits combos to 6 keys max

#define COMBO_TERM_PER_COMBO


#define DYNAMIC_KEYMAP_LAYER_COUNT 8


#define FORCE_NKRO // needed for quicker macros
#define DYNAMIC_MACRO_NO_NESTING  // disables recursive macros

#define TAP_CODE_DELAY 10 // default 0 