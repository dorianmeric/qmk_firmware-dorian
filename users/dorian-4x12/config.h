// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// #include "custom_config.h"

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 300 // 200ms originally
#define TAPPING_TERM_PER_KEY

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

// Thumb Combos
// #if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
//   // #define COMBO_COUNT 8
//   #define COMBO_TERM 300 // 200 originally
// #endif

#define COMBO_ONLY_FROM_LAYER 0 // makes the Combos letters assume that you are always on layer 0 (useful to trigger keys even if using a Colemak layout for example. But it means the text Combo also triggers while in the NAV / MOUSE layers)
#define COMBO_TERM 50        // how quickly all combo keys must be pressed in succession to trigger
// #define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
// #define COMBO_HOLD_TERM 200  // how long at least one of the combo keys must be held to trigger
#define EXTRA_SHORT_COMBOS // limits combos to 6 keys max

#define COMBO_TERM_PER_COMBO


#define FORCE_NKRO // needed for quicker macros
#define DYNAMIC_MACRO_NO_NESTING  // disables recursive macros

#define TAP_CODE_DELAY 10 // default 0 



/*
* `#define TAPPING_TERM 200`
  * how long before a key press becomes a hold
* `#define TAPPING_TERM_PER_KEY`
  * enables handling for per key `TAPPING_TERM` settings
* `#define TAPPING_TOGGLE 2`
  * how many taps before triggering the toggle
* `#define PERMISSIVE_HOLD`
  * makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the `TAPPING_TERM`
  * See [Permissive Hold](tap_hold.md#permissive-hold) for details
* `#define PERMISSIVE_HOLD_PER_KEY`
  * enabled handling for per key `PERMISSIVE_HOLD` settings
* `#define QUICK_TAP_TERM 100`
  * tap-then-hold timing to use a dual role key to repeat keycode
  * See [Quick Tap Term](tap_hold.md#quick-tap-term)
  * Changes the timing of Tap Toggle functionality (`TT` or the One Shot Tap Toggle)
  * Defaults to `TAPPING_TERM` if not defined
* `#define QUICK_TAP_TERM_PER_KEY`
  * enables handling for per key `QUICK_TAP_TERM` settings
* `#define HOLD_ON_OTHER_KEY_PRESS`
  * selects the hold action of a dual-role key as soon as the tap of the dual-role key is interrupted by the press of another key.
  * See "[hold on other key press](tap_hold.md#hold-on-other-key-press)" for details
* `#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY`
  * enables handling for per key `HOLD_ON_OTHER_KEY_PRESS` settings
* `#define LEADER_TIMEOUT 300`
  * how long before the leader key times out
    * If you're having issues finishing the sequence before it times out, you may need to increase the timeout setting. Or you may want to enable the `LEADER_PER_KEY_TIMING` option, which resets the timeout after each key is tapped.
* `#define LEADER_PER_KEY_TIMING`
  * sets the timer for leader key chords to run on each key press rather than overall
* `#define LEADER_KEY_STRICT_KEY_PROCESSING`
  * Disables keycode filtering for Mod-Tap and Layer-Tap keycodes. Eg, if you enable this, you would need to specify `MT(MOD_CTL, KC_A)` if you want to use `KC_A`.
* `#define ONESHOT_TIMEOUT 300`
  * how long before oneshot times out
* `#define ONESHOT_TAP_TOGGLE 2`
  * how many taps before oneshot toggle is triggered
  * 
* `#define COMBO_TERM 200`
  * how long for the Combo keys to be detected. Defaults to `TAPPING_TERM` if not defined.
* `#define COMBO_MUST_HOLD_MODS`
  * Flag for enabling extending timeout on Combos containing modifiers
* `#define COMBO_MOD_TERM 200`
  * Allows for extending COMBO_TERM for mod keys while mid-combo.
* `#define COMBO_MUST_HOLD_PER_COMBO`
  * Flag to enable per-combo COMBO_TERM extension and `get_combo_must_hold()` function
* `#define COMBO_TERM_PER_COMBO`
  * Flag to enable per-combo COMBO_TERM extension and `get_combo_term()` function
* `#define COMBO_STRICT_TIMER`
  * Only start the combo timer on the first key press instead of on all key presses.
* `#define COMBO_NO_TIMER`
  * Disable the combo timer completely for relaxed combos.
* `#define TAP_CODE_DELAY 100`
  * Sets the delay between `register_code` and `unregister_code`, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds and defaults to `0`.
* `#define TAP_HOLD_CAPS_DELAY 80`
  * Sets the delay for Tap Hold keys (`LT`, `MT`) when using `KC_CAPS_LOCK` keycode, as this has some special handling on MacOS.  The value is in milliseconds, and defaults to 80 ms if not defined. For macOS, you may want to set this to 200 or higher.
  * 
  * */