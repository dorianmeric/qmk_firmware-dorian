




// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define xxxx  KC_NO // present but not available for use
#define Y_KEY MT(MOD_RCTL | MOD_RALT | MOD_RSFT,KC_Y)
#define J_KEY MT(MOD_RCTL | MOD_RALT | MOD_RSFT,KC_J)


#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                 KC_PGUP, KC_PGDN,         J_KEY,              KC_L,              KC_U,             KC_Y,              KC_SLSH,           \
LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,             KC_KP_PLUS,  KC_KP_MINUS,     KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
KC_Z,               ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,        KC_KP_ASTERISK,  KC_KP_SLASH,         KC_K,              KC_H,              KC_COMM,          ALGR_T(KC_DOT),    KC_QUOT,             \
xxxx,              xxxx,              LT(U_MEDIA,KC_ESC),   LT(U_MOUSE,KC_TAB),  LT(U_NAV,KC_SPC),  xxxx,   xxxx,        LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT), LT(U_FUN,KC_DEL),    xxxx,              xxxx


#define MIRYOKU_ALTERNATIVES_BASE_QWERTY \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                   xxxx,   xxxx,         Y_KEY,             KC_U,              KC_I,              KC_O,              KC_P,              \
LWIN_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,                   xxxx,   xxxx,         KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LWIN_T(KC_QUOT),   \
KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,                   xxxx,   xxxx,         KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,            \
xxxx,              xxxx,              LT(U_MEDIA,KC_ESC),   LT(U_MOUSE,KC_TAB),  LT(U_NAV,KC_SPC),  xxxx,   xxxx,        LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT), LT(U_FUN,KC_DEL),    xxxx,              xxxx


// added Capslock to (NAV) Left-hand top right, and Insert just below
// Redo = Ctrl+Y
// Undo = Ctrl+Z    
#define MIRYOKU_ALTERNATIVES_NAV \
KC_HOME,           LCTL(KC_W),        LCTL(KC_T),        KC_WWW_REFRESH,    KC_PGUP,                xxxx,   xxxx,         KC_WWW_BACK,       KC_WWW_FORWARD,    xxxx,              xxxx,              xxxx,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_PGDN,                xxxx,   xxxx,         xxxx,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
KC_END,            KC_ALGR,           TD(U_TD_U_NAV),    KC_INS,            CW_TOGG,                xxxx,   xxxx,         xxxx,              KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
xxxx,              xxxx,              xxxx,              xxxx,              xxxx,                   xxxx,   xxxx,         KC_BSPC,           KC_ENT,           KC_DEL,              xxxx,          xxxx

#define MIRYOKU_ALTERNATIVES_MOUSE \
DM_REC1,           DM_PLY1,           DM_REC2,           DM_PLY2,           DM_RSTP,                xxxx,   xxxx,         KC_WWW_BACK,       KC_WWW_FORWARD,    xxxx,              xxxx,              JIGGLE,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           C(KC_S),           LSFT(KC_F9),            xxxx,   xxxx,         xxxx,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
TD(U_TD_U_MOUSE),  RSFT(KC_HOME),     RCTL(KC_BSPC),     RCTL(KC_DEL),      RSFT(KC_END),           xxxx,   xxxx,         xxxx,               KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
xxxx,              xxxx,              xxxx,              xxxx,              xxxx,                   xxxx,   xxxx,         KC_BTN1,           KC_BTN2,           KC_BTN3,       xxxx,          xxxx      


#define MIRYOKU_ALTERNATIVES_MEDIA \
xxxx,              xxxx,              xxxx,              xxxx,              KC_MEDIA_PLAY_PAUSE,    xxxx,   xxxx,         RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           xxxx,                   xxxx,   xxxx,         xxxx,          KC_MEDIA_PREV_TRACK,   KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,   KC_MEDIA_NEXT_TRACK,           \
TD(U_TD_U_MEDIA),  KC_ALGR,           xxxx,              xxxx,              xxxx,                   xxxx,   xxxx,         OU_AUTO,           xxxx,              xxxx,              xxxx,              xxxx,              \
xxxx,              xxxx,              xxxx,              xxxx,              xxxx,                   xxxx,   xxxx,         KC_MUTE,      KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_STOP,       xxxx,             xxxx




// RIGHTMOST RIGHT THUMB
// Needs to be an "Excel" layer:
// parentheses (open and close), e, dot, +, -, *, /, circ, =, comma(?), f4, f2(maybe)
#define MIRYOKU_ALTERNATIVES_NUM \
KC_LPRN,           KC_7,              KC_8,              KC_9,              KC_RPRN,                xxxx,   xxxx,         KC_CIRC,           KC_KP_PLUS,        KC_KP_MINUS,       KC_KP_ASTERISK,    KC_KP_SLASH,              \
KC_COMM,           KC_4,              KC_5,              KC_6,              KC_EQL,                 xxxx,   xxxx,         KC_E,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_DOT,            KC_1,              KC_2,              KC_3,              KC_BSLS,                xxxx,   xxxx,         KC_F4,             KC_DOT,            xxxx,              KC_ALGR,           TD(U_TD_U_NUM),              \
xxxx,              xxxx,              KC_0,              KC_0,              KC_MINS,                xxxx,   xxxx,         KC_BSPC,           xxxx,              xxxx,              xxxx,               xxxx        

// layers for symbols. LEFTMOST RIGHT THUMB
// remove:  equal/+,  parentheses(?)
#define MIRYOKU_ALTERNATIVES_SYM \
KC_GRAVE,          KC_AMPR,           KC_LCBR,           KC_LBRC,           KC_LPRN,                xxxx,   xxxx,         KC_RPRN,           KC_RBRC,           KC_RCBR,           KC_KP_ASTERISK,    xxxx,               \
KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,                xxxx,   xxxx,         KC_DLR,            KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,                xxxx,   xxxx,         CCY_POUND,         CCY_EURO,          CCY_YEN,           KC_ALGR,           TD(U_TD_U_SYM),              \
xxxx,              xxxx,              xxxx,              KC_RPRN,           KC_UNDS,                xxxx,   xxxx,         KC_BSPC,           xxxx,              xxxx,             xxxx,               xxxx          

// BOTH RIGHT
#define MIRYOKU_ALTERNATIVES_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                xxxx,   xxxx,         xxxx,              DF(U_TAP),         DF(U_BASE),       DF(U_EXTRA),       TD(U_TD_BOOT),            \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                xxxx,   xxxx,         xxxx,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,                xxxx,   xxxx,         xxxx,              xxxx,              xxxx,              KC_ALGR,           TD(U_TD_U_FUN),              \
xxxx,               xxxx,              xxxx,             KC_TAB,             KC_SPC,                xxxx,  xxxx,          xxxx,               xxxx,              xxxx,              xxxx,              xxxx 




#define MIRYOKU_ALTERNATIVES_TAP_QWERTY \
KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,                   KC_1,   xxxx,         KC_T,               KC_Y,              KC_U,              KC_I,              KC_O,                         \
KC_LSFT,           KC_A,              KC_S,              KC_D,              KC_F,                   KC_2,   xxxx,         KC_G,               KC_H,              KC_J,              KC_K,              KC_L,                       \
KC_LCTL,           KC_Z,              KC_X,              KC_C,              KC_V,                   KC_3,   xxxx,         KC_B,               KC_N,              KC_M,              A(KC_TAB),         DF(U_BASE),           \
KC_LALT,           CW_TOGG,           KC_ESC,     LT(U_NUM,KC_LALT),        KC_SPC,                 KC_4,   xxxx,         KC_BSPC,            KC_ENT,           KC_DEL,             xxxx,               xxxx


    