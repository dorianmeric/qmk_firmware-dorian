// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once


// #include "../spacebarracecar.h"


#define xxxx  KC_NO // present but not available for use
#define ____  KC_TRANSPARENT
#define Y_KEY MT(MOD_RCTL | MOD_RALT | MOD_RSFT, KC_Y)
#define J_KEY MT(MOD_RCTL | MOD_RALT | MOD_RSFT,KC_J)
#define CAPS_KEY MT(MOD_RCTL | MOD_RALT | MOD_RSFT, KC_NO)

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDHFATZ \
KC_ESC,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                      KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                   KC_MINS,           KC_EQL,            KC_BSPC,   \
KC_TAB,              KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                      J_KEY,              KC_L,              KC_U,              KC_Y,              KC_SLSH,                KC_LBRC,           KC_RBRC,           KC_BSLS,    \
CAPS_KEY,          LWIN_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),       KC_G,                       KC_M,               LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),       LWIN_T(KC_O),            KC_SCLN,           KC_ENT,          \
MT(MOD_LSFT,KC_Z),  KC_X,               KC_C,              KC_D,              KC_V,             KC_MINS,                    KC_K,              KC_H,               KC_COMM,             ALGR_T(KC_DOT),       KC_QUOT,                 MT(MOD_RSFT,KC_UP),   \
KC_LCTL,             LT(U_MEDIA,KC_LWIN), LT(U_MOUSE,KC_TAB),          LT(U_NAV,KC_SPC),  xxxx,   LT(U_NUM,KC_BSPC),                LT(U_SYM,KC_ENT),     LT(U_FUN,KC_LEFT),     LT(U_MEDIA, KC_DOWN),                MT(MOD_RCTL, KC_RIGHT)


#define MIRYOKU_ALTERNATIVES_BASE_QWERTY \
KC_ESC,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                      KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                   KC_MINS,           KC_EQL,            KC_BSPC,   \
KC_TAB,              KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                      KC_Y,             KC_U,              KC_I,              KC_O,              KC_P,                   KC_LBRC,           KC_RBRC,           KC_BSLS,     \
CAPS_KEY,            LWIN_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,                      KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LWIN_T(KC_QUOT),        KC_SCLN,           KC_ENT,                         \
KC_LSFT,             KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,                      KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,                MT(MOD_RSFT, KC_UP),                                \
KC_LCTL,             LT(U_MEDIA,KC_LWIN), LT(U_MOUSE,KC_TAB),          LT(U_NAV,KC_SPC),  xxxx,   LT(U_NUM,KC_BSPC),                LT(U_SYM,KC_ENT),     LT(U_FUN,KC_LEFT),     LT(U_MEDIA, KC_DOWN),                MT(MOD_RCTL, KC_RIGHT)


#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
KC_ESC,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                      KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                   KC_MINS,           KC_EQL,            KC_BSPC,   \
KC_TAB,              KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                      KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,                KC_LBRC,           KC_RBRC,           KC_BSLS,    \
CAPS_KEY,          LWIN_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,                        KC_M,               LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),       LWIN_T(KC_O),            KC_SCLN,           KC_ENT,          \
KC_LSFT,           KC_Z,               ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,                       KC_K,              KC_H,            KC_COMM,             ALGR_T(KC_DOT),       KC_SLSH,                 MT(MOD_RSFT,KC_UP),   \
KC_LCTL,             LT(U_MEDIA,KC_LWIN), LT(U_MOUSE,KC_TAB),          LT(U_NAV,KC_SPC),  xxxx,   LT(U_NUM,KC_BSPC),                LT(U_SYM,KC_ENT),     LT(U_FUN,KC_LEFT),     LT(U_MEDIA, KC_DOWN),                MT(MOD_RCTL, KC_RIGHT)




// left spc: Nav arrowsrte
// left alt: media?
// right spc: Symbols. Good
// righalt : Function
// both spaces" FUN?
// Fn button
// added Capslock to (NAV) Left-hand top right, and Insert just below
// Redo = Ctrl+Y
// Undo = Ctrl+Z
#define MIRYOKU_ALTERNATIVES_NAV \
____,            ____,              ____,              ____,              ____,              xxxx,                          ____,              ____,              ____,              ____,              ____,                  ____,              ____,              KC_DEL, \
A(KC_TAB),       KC_HOME,           LCTL(KC_W),        LCTL(KC_T),        KC_WWW_REFRESH,    xxxx,                          RSFT(KC_HOME),     RCTL(KC_BSPC),     KC_BSPC,             ____,             ____,                 ____,              ____,              ____,             \
____,            KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_PGUP,           KC_PGDN,                       xxxx,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,               ____,              ____,         \
A(KC_LSFT),      KC_END,              xxxx,           TD(U_TD_U_NAV),    KC_PGDN,            CW_TOGG,                       RSFT(KC_END),      RCTL(KC_DEL),      KC_DEL,           KC_PGUP,           KC_END,                ____,       \
A(KC_LCTL),       ____,              ____,                           xxxx,      ____,       KC_DEL,                                   ____,              ____,               ____,            ____         

#define MIRYOKU_ALTERNATIVES_MOUSE \
____,              ____,              ____,              ____,              ____,              ____,                        ____,               KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_NEXT_TRACK, KC_MUTE,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,              ____, \
____,              DM_REC1,           DM_PLY1,           DM_REC2,           DM_PLY2,           DM_RSTP,                     KC_WWW_BACK,       KC_WWW_FORWARD,             ____,             ____,             JIGGLE,               ____,              ____,              ____,             \
____,              KC_LGUI,           KC_LALT,           KC_LCTL,           C(KC_S),           LSFT(KC_F9),                 xxxx,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,       ____,              ____,     \
____,              TD(U_TD_U_MOUSE),  RSFT(KC_HOME),     RCTL(KC_BSPC),     RCTL(KC_DEL),      RSFT(KC_END),                xxxx,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,        ____,       \
____,            ____,                 ____,                           ____,      ____,      KC_BTN1,                       KC_BTN2,           KC_BTN3,           ____,              ____

#define MIRYOKU_ALTERNATIVES_MEDIA \
A(KC_F4),         ____,              ____,              ____,                ____,              ____,                         ____,            KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_NEXT_TRACK, KC_MUTE,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,              ____, \
____,              ____,              ____,              ____,               ____,              ____,                       ____,            G(KC_L),                 ____,           ____,           ____,                ____,              ____,              ____,          \
____,              KC_LGUI,           G(KC_R),        G(S(KC_S)),           KC_LSFT,           ____,                        ____,           KC_MEDIA_PREV_TRACK,   G(KC_E), ____,   KC_MEDIA_NEXT_TRACK,     ____,              ____,       \
____,              TD(U_TD_U_MEDIA),  KC_ALGR,           ____,              ____,              ____,                        ____,           ____,              ____,              ____,              ____,           G(KC_UP),       \
____,            ____,              ____,                           ____,      ____,  KC_MUTE,                              KC_MEDIA_PLAY_PAUSE,  G(KC_LEFT),     G(KC_DOWN),              G(KC_RIGHT)





// RIGHTMOST RIGHT THUMB


// Needs to be an "Excel" layer:
// parentheses (open and close), e, dot, +, -, *, /, circ, =, comma(?), f4, f2(maybe)
#define MIRYOKU_ALTERNATIVES_NUM \
KC_GRAVE,          ____,              ____,              ____,              ____,              ____,                        ____,              ____,              ____,              ____,              ____,              ____,              ____,              ____, \
____,              KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,                     KC_CIRC,           KC_KP_PLUS,        KC_KP_MINUS,       KC_KP_ASTERISK,    KC_KP_SLASH,               ____,              ____,              ____,              \
____,              KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,                      KC_E,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,          ____,              ____,  \
____,              KC_DOT,            KC_1,              KC_2,              KC_3,              KC_BSLS,                     KC_F4,             KC_DOT,            xxxx,              KC_ALGR,           TD(U_TD_U_NUM),         ____,         \
____,              KC_DOT,            ____,                          KC_0,      ____,     KC_MINS,                              ____,              ____,              ____,             ____

// layers for symbols. LEFTMOST RIGHT THUMB
// remove:  equal/+,  parentheses(?)
#define MIRYOKU_ALTERNATIVES_SYM \
KC_GRAVE,          ____,              ____,              ____,              ____,              ____,                        ____,              ____,              ____,              ____,              ____,              ____,              ____,              ____, \
____,              KC_GRAVE,          KC_AMPR,           KC_LCBR,           KC_LBRC,           KC_LPRN,                     KC_RPRN,           KC_RBRC,           KC_RCBR,           KC_KP_ASTERISK,    xxxx,                  ____,              ____,              ____,            \
____,              KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,                     KC_DLR,            KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           ____,              ____, \
____,              KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,                     CCY_POUND,         CCY_EURO,          CCY_YEN,           KC_ALGR,           TD(U_TD_U_SYM),       ____,           \
____,              xxxx,              KC_RPRN,                  KC_UNDS,          ____,     ____,                           ____,              ____,              ____,             ____

// BOTH RIGHT
#define MIRYOKU_ALTERNATIVES_FUN \
KC_GRAVE,          KC_F1,             KC_F2,             KC_F3,             KC_F4,             KC_F5,                       KC_F6,             KC_F7,             KC_F8,             KC_F9,             KC_F10,          KC_F11,      KC_F12,              KC_DEL, \
____,              KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                     xxxx,              xxxx,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_BOOT),                RGB_TOG,              RGB_VAI,        RGB_VAD,          \
KC_CAPS_LOCK,      KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                     xxxx,              KC_LSFT,           KC_LCTL,           KC_LALT,           RGB_HUI,         RGB_HUD,     RGB_M_P ,           \
____,              KC_F10,            KC_F1,             KC_F2,             KC_INS,            KC_PAUS,                     xxxx,              xxxx,              RGB_MOD,           RGB_RMOD,         RGB_SAI,                     RGB_SAD,       \
____,              xxxx,              KC_TAB,            KC_SPC,           ____,     ____,                      ____,              ____,              ____,             ____





