// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H




// MY CUSTOM CODE //////////////////////////////////////////////////////////////////////////////////////////

enum custom_keycodes {
    CCY_POUND = SAFE_RANGE, // Alt Codes start here.
    CCY_EURO,                 // € 0128
    CCY_YEN,
    FR_A_GRAVE,
    FR_A_CIRC,
    FR_C_CEDILLE,
    FR_E_GRAVE,
    FR_E_AIGU,
    FR_E_CIRC,
    FR_U_CIRC,
    JIGGLE,
};

// £ 0163
// € 0128
// ¥ 0165

// à 0244
// â 0226
// ç 0231
// è 0232
// é 0233
// ê 0234
// û 0251 

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_6)SS_TAP(X_KP_3)), // Alt+0163 → £
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_6)SS_TAP(X_KP_3)), // Alt+0163 → £
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0128 → €
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0128 → €
    },
    {
		SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_6)SS_TAP(X_KP_5)),  // Alt+0165 → ¥
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_6)SS_TAP(X_KP_5)),  // Alt+0165 → ¥
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+0246 → ö
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_4)), // Alt+0214 → Ö
    },
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
















#include "manna-harbour_miryoku.h"


// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  // if (state->count == 2) { // activate this if you want to only trigger on a double-tap
    reset_keyboard();  // Reset to bootloader
  // }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
    switch (state->count) { \
        case 1: \
            default_layer_set((layer_state_t)1 << U_BASE); \
            break; \
        case 2: \
            default_layer_set((layer_state_t)1 << U_##LAYER); \
            break; \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS); //  replaces Shift+CWTOGGLE with Capslock
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL); // replaces Shift+Backspace with Del
// const key_override_t ctrl_down = ko_make_basic(MOD_MASK_CTRL, KC_DOWN, KC_DOWN); // replaces Ctrl+Down with Down
// const key_override_t ctrl_up = ko_make_basic(MOD_MASK_CTRL, KC_UP, KC_UP); // replaces Ctrl+Up with Up

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    &delete_key_override,
    // &ctrl_down, // actually there are sone shortcuts that need Ctrl+Down in VSCode
    // &ctrl_up,
    NULL // Null terminate the array of overrides!
};

// // thumb combos
// // #define MIRYOKU_KLUDGE_THUMBCOMBOS

// #if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
// const uint16_t PROGMEM thumbcombos_base_right[] = { LT(U_SYM, KC_BSPC), LT(U_NUM, KC_ENT),    COMBO_END};
// const uint16_t PROGMEM thumbcombos_base_left[] =  { LT(U_NAV, KC_TAB),  LT(U_MOUSE, KC_SPC),  COMBO_END};
// const uint16_t PROGMEM thumbcombos_nav[] =        { KC_BSPC,            KC_ENT,               COMBO_END};
// const uint16_t PROGMEM thumbcombos_mouse[] =      { KC_BTN2,            KC_BTN1,              COMBO_END};
// const uint16_t PROGMEM thumbcombos_media[] =      { KC_MSTP,            KC_MPLY,              COMBO_END};
// const uint16_t PROGMEM thumbcombos_num[] =        { KC_0,               KC_MINS,              COMBO_END};
// //   #if defined (MIRYOKU_LAYERS_FLIP)
// // const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
// //   #else
// const uint16_t PROGMEM thumbcombos_sym[] =        { KC_RPRN,            KC_UNDS,              COMBO_END};
//   // #endif
// const uint16_t PROGMEM thumbcombos_fun[] =        { KC_TAB,             KC_SPC,               COMBO_END};

// // combo_t key_combos[COMBO_COUNT] = {
// combo_t key_combos_mir[] = {
//     COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
//     COMBO(thumbcombos_base_left,  LT(U_MEDIA, KC_ESC)),
//     COMBO(thumbcombos_nav,        KC_DEL),
//     COMBO(thumbcombos_mouse,      KC_BTN3),
//     COMBO(thumbcombos_media,      KC_MUTE),
//     COMBO(thumbcombos_num,        KC_DOT),
//     // #if defined (MIRYOKU_LAYERS_FLIP)
//     //   COMBO(thumbcombos_sym, KC_RPRN),
//     // #else
//     COMBO(thumbcombos_sym,        KC_LPRN),
//     // #endif
//     COMBO(thumbcombos_fun,        KC_APP)
// };

// #endif



















// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
// If these functions return true QMK will process the keycodes as usual. That can be handy for extending the functionality of a key rather than replacing it. If these functions return false QMK will skip the normal key handling, and it will be up to you to send any key up or down events that are required.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        switch (keycode) {

                // CCY SHORTCUTS
                case CCY_POUND: 
                case CCY_EURO: 
                case CCY_YEN: {
                    uint16_t index = keycode - CCY_POUND; // MAKES A REFERENCE TO THE FIRST CCYCODE
                    uint8_t shift = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

                    unregister_code(KC_LSFT);
                    unregister_code(KC_RSFT);

                    send_string(alt_codes[index][(bool)shift]);

                    if (shift & MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
                    if (shift & MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

                    return false; // Skip all further processing of this key
                }

        }
    }



    // JIGGLE 
    if (record->event.pressed) {
        static deferred_token token = INVALID_DEFERRED_TOKEN;
        static report_mouse_t report = {0};
        if (token) {
            // If jiggler is currently running, stop when any key is pressed.
            cancel_deferred_exec(token);
            token = INVALID_DEFERRED_TOKEN;
            report = (report_mouse_t){};  // Clear the mouse.
            host_mouse_send(&report);
        } else if (keycode == JIGGLE) {

            uint32_t jiggler_callback(uint32_t trigger_time, void* cb_arg) {
            // Deltas to move in a circle of radius 20 pixels over 32 frames.
            static const int8_t deltas[32] = {
                0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
                0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
            static uint8_t phase = 0;
            // Get x delta from table and y delta by rotating a quarter cycle.
            report.x = deltas[phase];
            report.y = deltas[(phase + 8) & 31];
            phase = (phase + 1) & 31;
            host_mouse_send(&report);
            return 16;  // Call the callback every 16 ms.
            }

            token = defer_exec(1, jiggler_callback, NULL);  // Schedule callback.
        }
    }

    return true; // Process all other keycodes normally
}




// Add the combos
#include "keymap_combo.h" // originally from keyboards/gboards/g/
// #include "keyboards/gboards/g/keymap_combo.h"


// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
// controls the COMBO timing, to have a more relax timing for the thumb keys
uint16_t get_combo_term(uint16_t index, combo_t *combo) {

    // if (index  <= 5) { // - &thum_base_right
    //     return 300;
    // }

    return 50; //COMBO_TERM; 
}

// https://docs.qmk.fm/#/tap_hold?id=tap-hold-configuration-optionszt
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A): // windows key
        case LGUI_T(KC_O): // windows key
            return 400;

        case LALT_T(KC_R):
        case LCTL_T(KC_S):
        case LSFT_T(KC_T):
        case LSFT_T(KC_N):
        case LCTL_T(KC_E):
        case LALT_T(KC_I):
            return 200;

        default:
            return 200; // TAPPING_TERM;
    }
}