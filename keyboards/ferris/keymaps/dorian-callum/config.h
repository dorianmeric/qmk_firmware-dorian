#pragma once

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 40 // The default is 20. Since we made the mouse about 3 times faster with the previous setting,  give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_DELAY 100 // The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_WHEEL_DELAY 100 // It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_INTERVAL 50 // The default is 100
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100 // The default is 40

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 50 // was originally 50ms, which is way too strict


#define TAPPING_TERM 200 // used by MOD TAP. 200ms is actually quite quick.  test here: https://jsfiddle.net/EeXVX/1/show/
#define PERMISSIVE_HOLD // applies the "hold" mechanic if another key is pressed and released before the hold key is released, even if this all takes place within the tapping term
// #define QUICK_TAP_TERM 120 // allows to spam the tap output by doing a quick 'tap-hold'