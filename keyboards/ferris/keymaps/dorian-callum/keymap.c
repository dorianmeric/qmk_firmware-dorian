// https://mattstenback.com/journal/my-34-key-keyboard-layout/
// Forked/inspired by: https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum

#include QMK_KEYBOARD_H





// #include "keyboards/gboards/g/keymap_combo.h"
#include "g/keymap_combo.h"
#include "oneshot.h"
#include "swapper.h"

// Keymap helpers
#define LA_SYM MO(RIGHTTHUMB_SYM)
#define LA_NAV MO(LEFTTHUMB_NAV)
#define xxxx KC_NO

// MacOS macros
// #define SPOTL LGUI(KC_SPC)
// #define ONEPW LGUI(KC_BSLS)
// #define SC_SHOT SGUI(KC_4)

// Browser navigation

// #define TAB_L LAG(KC_LEFT)
// #define BR_BACK LGUI(KC_LEFT)


// Delete words
// #define BSPC_WORD RCTL(KC_BSPC)
// #define BSPC_LINE RSFT(KC_HOME)
// #define DEL_WORD RCTL(KC_DEL)
// #define DEL_LINE RSFT(KC_END)


enum layers {
    QWERTY = 0,
    COLEMAKVANILLA,
    LEFTTHUMB_NAV,
    RIGHTTHUMB_SYM,
    BOTHTHUMBS_NUM,
};

enum custom_keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_WIN,

    CCY_POUND, // Alt Codes start here.
    CCY_EURO,                 // € 0128
    CCY_YEN,
    FR_A_GRAVE,
    FR_A_CIRC,
    FR_C_CEDILLE,
    FR_E_GRAVE,
    FR_E_AIGU,
    FR_E_CIRC,
    FR_U_CIRC,

    // SW_WIN,  // Switch to next window (cmd-tab)
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
		SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0228 → ä
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_6)), // Alt+0196 → Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+0246 → ö
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_4)), // Alt+0214 → Ö
    },
};


///////////////////////////////////////// TAP DANCE ////////////////////////////////////////////////////
enum tap_dance_keys { // list the tap dances that are user-defined
    ENTER_AND_F12,
    LAYOUT_TOGGLE,
    TEST_TAP_HOLD
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

void tapdancekey1_finished(tap_dance_state_t *state, void *user_data);
void tapdancekey1_reset(tap_dance_state_t *state, void *user_data);
void tapdancekey2_finished(tap_dance_state_t *state, void *user_data);
void tapdancekey2_reset(tap_dance_state_t *state, void *user_data);
void tapdancekey3_finished(tap_dance_state_t *state, void *user_data);
void tapdancekey3_reset(tap_dance_state_t *state, void *user_data);
///////////////////////////////////////////////////////////////////////////////////////////////////////////





// http://www.keyboard-layout-editor.com/#/gists/0b9ac350eca3458847c790123362cbc5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,      KC_U,    KC_I,    KC_O,    KC_QUOTE, // KC_QUOTE = ' and ""
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,      KC_J,    KC_K,    KC_L,    KC_P,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,      KC_M,    KC_COMMA, KC_DOT,  KC_MINUS,  // COMMA = "," and <, and KC_MINUS = dash + underscore 
                     LA_NAV,  MT(MOD_RGUI,KC_SPACE),          KC_LSFT,   LA_SYM
    ),

    [COLEMAKVANILLA] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,           KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,          KC_K,    KC_M,    KC_COMMA, KC_DOT,  KC_SEMICOLON,
                    LA_NAV,  MT(MOD_RGUI,KC_SPACE),           KC_LSFT,   LA_SYM
    ),

    [LEFTTHUMB_NAV] = LAYOUT_split_3x5_2(
        KC_HOME, LCTL(KC_W), LCTL(KC_T), KC_WWW_REFRESH, KC_PGUP,   TD(LAYOUT_TOGGLE), xxxx, xxxx, xxxx,  KC_F24,  // F24 is used to cancel the one-shot mods loaded
        OS_WIN, OS_SHFT, OS_ALT, OS_CTRL, KC_PGDN,                  KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT,  xxxx,
        KC_END, xxxx, xxxx, xxxx, xxxx,                             xxxx,  DM_PLY2, DM_REC2, DM_PLY1, DM_REC1,
                        _______,  KC_MEDIA_PLAY_PAUSE,              xxxx, _______
    ),
    
    [RIGHTTHUMB_SYM] = LAYOUT_split_3x5_2(
        KC_GRAVE,KC_LPRN, KC_LCBR, KC_LBRC, KC_LT,          KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN, xxxx, // GRV = grave + tilde
        KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC,        xxxx, OS_CTRL, OS_ALT, OS_SHFT, OS_WIN,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_EQUAL,      KC_SLASH, KC_BACKSLASH,  xxxx, xxxx, xxxx,  // SLASH = / + ?   Backslash = \ + |
                                    _______, CCY_EURO,      CCY_POUND, _______
    ),

    [BOTHTHUMBS_NUM] = LAYOUT_split_3x5_2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F11,  KC_CIRC, KC_E,   KC_DOT,   KC_EQUAL,       KC_KP_SLASH, KC_KP_ASTERISK,  KC_KP_MINUS, KC_KP_PLUS, TD(ENTER_AND_F12),  // ENTER_AND_F12 = Enter if quick tapped, and F12 if held
                                    _______, KC_LPRN,       KC_RPRN, _______
    ),

};


bool is_oneshot_cancel_key(uint16_t keycode) { //  Defines keys to cancel oneshot mods.
    switch (keycode) {
        case KC_F24:
        // case LA_NAV:
        // case LA_NAV:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) { //  Defines keys to ignore when determining whether a oneshot mod has been used.
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:

        case KC_LCTL:
        case KC_LALT:
        case KC_LSFT:
        case KC_LGUI:

        case KC_RCTL:
        case KC_RALT:
        case KC_RSFT:
        case KC_RGUI:
        
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_WIN:
            return true;
        default:
            return false;
    }
}

// bool sw_win_active = false

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_win_state = os_up_unqueued;


// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 // If these functions return true QMK will process the keycodes as usual. That can be handy for extending the functionality of a key rather than replacing it. If these functions return false QMK will skip the normal key handling, and it will be up to you to send any key up or down events that are required.

    // update_swapper(
    //     &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
    //     keycode, record
    // );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_win_state, KC_LGUI, OS_WIN,
        keycode, record
    );


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


    // TAP DANCE SHORTCUTS
    // tap_dance_action_t *action;

    // switch (keycode) {
    //     case TD(LAYOUT_TOGGLE):  // list all tap dance keycodes with tap-hold configurations
    //         action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
    //         if (!record->event.pressed && action->state.count && !action->state.finished) {
    //             tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
    //             tap_code16(tap_hold->tap);
    //         }
    // }



    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, RIGHTTHUMB_SYM, LEFTTHUMB_NAV, BOTHTHUMBS_NUM);
}










//////////////////// TAP DANCE ///////////////////////////////////////////////////////////////////////////////////////

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void tapdancekey1_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ENTER); break;
        case TD_SINGLE_HOLD: register_code(KC_F12); break;
        // case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // // Last case is for fast typing. Assuming your key is `f`:
        // // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        default: break;
    }
}
void tapdancekey1_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ENTER); break;
        case TD_SINGLE_HOLD: unregister_code(KC_F12); break;
        // case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void tapdancekey2_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    // layer_off(get_highest_layer(layer_state));
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: layer_move(QWERTY); break;   // layer_on():Turns specified layer on, leaves all other layers in existing state.       layer_move():Turns specified layer on, and all other layers off.
        case TD_SINGLE_HOLD: layer_move(COLEMAKVANILLA); break; // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
        default: layer_move(QWERTY);
    }
}
void tapdancekey2_reset(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = TD_NONE;
}

void tapdancekey3_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ENTER); break;
        case TD_SINGLE_HOLD: register_code(KC_F12); break;
        default: break;
    }
}
void tapdancekey3_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ENTER); break;
        case TD_SINGLE_HOLD: unregister_code(KC_F12); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [ENTER_AND_F12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tapdancekey1_finished, tapdancekey1_reset),
    [LAYOUT_TOGGLE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tapdancekey2_finished, tapdancekey2_reset),
    [TEST_TAP_HOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tapdancekey3_finished, tapdancekey3_reset),
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////