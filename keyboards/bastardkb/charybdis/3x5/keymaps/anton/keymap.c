/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
};

// Automatically enable sniping-mode on the pointer layer.
// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define ESC_NAV LT(LAYER_NAVIGATION, KC_ESC)
#define SPC_NUM LT(LAYER_NUMERAL, KC_SPC)
#define TAB_FUN LT(LAYER_FUNCTION, KC_TAB)
#define BSP_SYM LT(LAYER_SYMBOLS, KC_BSPC)
// #define _L_PTR(KC) LT(LAYER_POINTER, KC)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, CW_TOGG, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      ESC_NAV, SPC_NUM, TAB_FUN,  KC_ENT, BSP_SYM

/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_GASC_L______________ KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX
#define ______________HOME_ROW_GASC_R______________ XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI


#define LAYOUT_LAYER_FUNCTION                                                                  \
    _______________DEAD_HALF_ROW_______________, KC_PSCR,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    ______________HOME_ROW_GASC_L______________, KC_SCRL,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  \
    _______________DEAD_HALF_ROW_______________, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  \
                      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX

#define LAYOUT_LAYER_POINTER                                                                  \
    _______________DEAD_HALF_ROW_______________, S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, \
    ______________HOME_ROW_GASC_L______________, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, SNIPING, \
    _______________DEAD_HALF_ROW_______________, XXXXXXX, DRGSCRL, XXXXXXX, XXXXXXX, XXXXXXX, \
                      _______, _______, _______, _______, _______

#define LAYOUT_LAYER_NAVIGATION                                                              \
    XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX, _______________DEAD_HALF_ROW_______________, \
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______________DEAD_HALF_ROW_______________, \
    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______________DEAD_HALF_ROW_______________, \
                      _______, _______, _______,  KC_ENT, KC_BSPC

#define LAYOUT_LAYER_NUMERAL                                                                  \
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, \
    ______________HOME_ROW_GASC_L______________, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, \
       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, \
                      _______, _______, _______,  KC_ENT, KC_BSPC

#define LAYOUT_LAYER_SYMBOLS                                                                 \
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______________DEAD_HALF_ROW_______________, \
    KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, ______________HOME_ROW_GASC_R______________, \
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE, _______________DEAD_HALF_ROW_______________, \
                      KC_LPRN, KC_RPRN, KC_UNDS, _______, XXXXXXX


#define _HOME_ROW_MOD_GASC(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
      LGUI_T(L10), LALT_T(L11), LSFT_T(L12), LCTL_T(L13),        L14,  \
             R15,  RCTL_T(R16), RSFT_T(R17), LALT_T(R18), RGUI_T(R19), \
      __VA_ARGS__
#define HOME_ROW_MOD_GASC(...) _HOME_ROW_MOD_GASC(__VA_ARGS__)



#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
    HOME_ROW_MOD_GASC(LAYOUT_LAYER_BASE)
  ),
  [LAYER_FUNCTION] = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_NUMERAL] = LAYOUT_wrapper(
    HOME_ROW_MOD_GASC(LAYOUT_LAYER_NUMERAL)
  ),
  [LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
  [LAYER_SYMBOLS] = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    return IS_RETRO(keycode);
}
// TODO: retro-shift seems to affect even non-alpha tap-hold keys like backspace and so on. Not great since that makes it so I cant actually hold backspace.
// Also, caps word is not working.