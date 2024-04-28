// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H




// MY CUSTOM CODE //////////////////////////////////////////////////////////////////////////////////////////
#define COMBO_VARIABLE_LEN
#define PERMISSIVE_HOLD // applies the "hold" mechanic if another key is pressed and released before the hold key is released, even if this all takes place within the tapping term


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
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_7)), // Alt+0197 → Å
    },
    {
		    SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_6)SS_TAP(X_KP_5)),   // Alt+0165 → ¥
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_6)),  // Alt+0196 → Ä
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
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
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

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    NULL
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // CCY SHORTCUTS
    if (record->event.pressed) {
        switch (keycode) {
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

                    return false;
                }
        }
    }

    return true;
}




// Add the combos
#include "keyboards/gboards/g/keymap_combo.h"


// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
// controls the COMBO timing, to have a more relax timing for the thumb keys
uint16_t get_combo_term(uint16_t index, combo_t *combo) {

    if (index - thum_base_right <= 5) {
        return 300;
    }

    return 50; //COMBO_TERM; 
}