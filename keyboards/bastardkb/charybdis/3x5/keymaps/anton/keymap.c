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

//#include "keymap_swedish.h"
#define SE_SECT KC_GRV  // §
#define SE_1    KC_1    // 1
#define SE_2    KC_2    // 2
#define SE_3    KC_3    // 3
#define SE_4    KC_4    // 4
#define SE_5    KC_5    // 5
#define SE_6    KC_6    // 6
#define SE_7    KC_7    // 7
#define SE_8    KC_8    // 8
#define SE_9    KC_9    // 9
#define SE_0    KC_0    // 0
#define SE_PLUS KC_MINS // +
#define SE_ACUT KC_EQL  // ´ (dead)
#define SE_Q    KC_Q    // Q
#define SE_W    KC_W    // W
#define SE_E    KC_E    // E
#define SE_R    KC_R    // R
#define SE_T    KC_T    // T
#define SE_Y    KC_Y    // Y
#define SE_U    KC_U    // U
#define SE_I    KC_I    // I
#define SE_O    KC_O    // O
#define SE_P    KC_P    // P
#define SE_ARNG KC_LBRC // Å
#define SE_DIAE KC_RBRC // ¨ (dead)
#define SE_A    KC_A    // A
#define SE_S    KC_S    // S
#define SE_D    KC_D    // D
#define SE_F    KC_F    // F
#define SE_G    KC_G    // G
#define SE_H    KC_H    // H
#define SE_J    KC_J    // J
#define SE_K    KC_K    // K
#define SE_L    KC_L    // L
#define SE_ODIA KC_SCLN // Ö
#define SE_ADIA KC_QUOT // Ä
#define SE_QUOT KC_NUHS // '
#define SE_LABK KC_NUBS // <
#define SE_Z    KC_Z    // Z
#define SE_X    KC_X    // X
#define SE_C    KC_C    // C
#define SE_V    KC_V    // V
#define SE_B    KC_B    // B
#define SE_N    KC_N    // N
#define SE_M    KC_M    // M
#define SE_COMM KC_COMM // ,
#define SE_DOT  KC_DOT  // .
#define SE_MINS KC_SLSH // -
#define SE_HALF S(SE_SECT) // ½
#define SE_EXLM S(SE_1)    // !
#define SE_DQUO S(SE_2)    // "
#define SE_HASH S(SE_3)    // #
#define SE_CURR S(SE_4)    // ¤
#define SE_PERC S(SE_5)    // %
#define SE_AMPR S(SE_6)    // &
#define SE_SLSH S(SE_7)    // /
#define SE_LPRN S(SE_8)    // (
#define SE_RPRN S(SE_9)    // )
#define SE_EQL  S(SE_0)    // =
#define SE_QUES S(SE_PLUS) // ?
#define SE_GRV  S(SE_ACUT) // ` (dead)
#define SE_CIRC S(SE_DIAE) // ^ (dead)
#define SE_ASTR S(SE_QUOT) // *
#define SE_RABK S(SE_LABK) // >
#define SE_SCLN S(SE_COMM) // ;
#define SE_COLN S(SE_DOT)  // :
#define SE_UNDS S(SE_MINS) // _
#define SE_AT   ALGR(SE_2)    // @
#define SE_PND  ALGR(SE_3)    // £
#define SE_DLR  ALGR(SE_4)    // $
#define SE_EURO ALGR(SE_5)    // €
#define SE_LCBR ALGR(SE_7)    // {
#define SE_LBRC ALGR(SE_8)    // [
#define SE_RBRC ALGR(SE_9)    // ]
#define SE_RCBR ALGR(SE_0)    // }
#define SE_BSLS ALGR(SE_PLUS) // (backslash)
#define SE_TILD ALGR(SE_DIAE) // ~ (dead)
#define SE_PIPE ALGR(SE_LABK) // |
#define SE_MICR ALGR(SE_M)    // µ

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_GAME,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
};

enum custom_keycodes {
    M_CARET = SAFE_RANGE,
    M_BTICK,
    M_TILDE,
    M_CLEAR,
};

// Automatically enable sniping-mode on the pointer layer.
// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
//static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define TAB_NAV LT(LAYER_NAVIGATION, KC_TAB)
#define SPC_NUM LT(LAYER_NUMERAL, KC_SPC)
#define ESC_FUN LT(LAYER_FUNCTION, KC_ESC)
#define BSP_SYM LT(LAYER_SYMBOLS, KC_BSPC)
#define A_SYM LT(LAYER_SYMBOLS, KC_A)
#define DF_BASE DF(LAYER_BASE)
#define DF_GAME DF(LAYER_GAME)
#define TAB_NUM LT(LAYER_NUMERAL, KC_TAB)
#define ESC_NAV LT(LAYER_NAVIGATION, KC_ESC)
// #define _L_PTR(KC) LT(LAYER_POINTER, KC)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off

/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _______________TRAN_HALF_ROW_______________ _______, _______, _______, _______, _______
#define ______________HOME_ROW_GASC_L______________ XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI
#define ______________HOME_ROW_GASC_R______________ KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX


#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
      A_SYM,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, CW_TOGG, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      TAB_NAV, SPC_NUM, ESC_FUN,  KC_ENT, BSP_SYM

#define LAYOUT_LAYER_GAME                                                                     \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
    KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L, DF_BASE, \
    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      TAB_NUM, KC_SPC, ESC_NAV,  KC_ENT, BSP_SYM

#define LAYOUT_LAYER_FUNCTION                                                                 \
    _______________DEAD_HALF_ROW_______________, KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
    ______________HOME_ROW_GASC_L______________, KC_SCRL,   KC_F5,   KC_F6,   KC_F7,   KC_F8, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_GAME, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4, \
                      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX

#define LAYOUT_LAYER_POINTER                                                                  \
    _______________TRAN_HALF_ROW_______________, S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, \
    ______________HOME_ROW_GASC_L______________, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, \
    _______________TRAN_HALF_ROW_______________, XXXXXXX, KC_BTN1, DRGSCRL, KC_BTN2, SNIPING, \
                      _______, _______, M_CLEAR, _______, _______

#define LAYOUT_LAYER_NAVIGATION                                                               \
    KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_INS, _______________DEAD_HALF_ROW_______________, \
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, ______________HOME_ROW_GASC_R______________, \
    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______________DEAD_HALF_ROW_______________, \
                      _______, _______, _______,  KC_ENT, KC_BSPC

#define LAYOUT_LAYER_NUMERAL                                                                  \
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, \
    ______________HOME_ROW_GASC_L______________, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, \
       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, \
                      _______, _______, _______,  KC_ENT, KC_BSPC

#define LAYOUT_LAYER_SYMBOLS                                                                  \
    SE_PERC, SE_HASH, SE_AMPR,  SE_DLR, M_CARET, SE_ACUT, SE_SLSH, SE_ARNG, SE_ADIA, SE_ODIA, \
    SE_EXLM, SE_DQUO,  SE_EQL, SE_RABK, SE_PLUS, SE_QUOT, SE_LPRN, SE_RPRN, SE_LCBR, SE_RCBR, \
    SE_BSLS, SE_LABK, SE_PIPE,   SE_AT, M_BTICK, M_TILDE, SE_PLUS, SE_QUES, SE_LBRC, SE_RBRC, \
                      _______, _______, _______, _______, _______


#define _HOME_ROW_MOD_GASC(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,  LALT_T(L11), LSFT_T(L12), LCTL_T(L13), LGUI_T(L14), \
             R15,  RCTL_T(R16), RSFT_T(R17), LALT_T(R18),        R19,  \
      __VA_ARGS__
#define HOME_ROW_MOD_GASC(...) _HOME_ROW_MOD_GASC(__VA_ARGS__)



#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
    HOME_ROW_MOD_GASC(LAYOUT_LAYER_BASE)
  ),
  [LAYER_GAME] = LAYOUT_wrapper(LAYOUT_LAYER_GAME),
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
        layer_on(LAYER_POINTER);
//         if (auto_pointer_layer_timer == 0) {
//             layer_on(LAYER_POINTER);
// #        ifdef RGB_MATRIX_ENABLE
//             rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
//             rgb_matrix_sethsv_noeeprom(HSV_GREEN);
// #        endif // RGB_MATRIX_ENABLE
//         }
//         auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

// void matrix_scan_user(void) {
//     if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
//         auto_pointer_layer_timer = 0;
//         layer_off(LAYER_POINTER);
// #        ifdef RGB_MATRIX_ENABLE
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
// #        endif // RGB_MATRIX_ENABLE
//     }
// }
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

// bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LGUI_T(KC_A):
//         case LALT_T(KC_S):
//         case LSFT_T(KC_D):
//         case LCTL_T(KC_F):
//         case LALT_T(KC_L):
//         case RSFT_T(KC_K):
//         case RCTL_T(KC_J):
//             return true;
//     }
//     return false;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_CARET:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_RBRC); // (¨)
                // _delay_ms(10);
                unregister_code(KC_RBRC); // (¨)
                unregister_code(KC_LSFT);
                register_code(KC_SPC);
                //_delay_ms(10);
                unregister_code(KC_SPC);
            }
            break;
        case M_BTICK:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_EQL); // (´)
                //_delay_ms(10);
                unregister_code(KC_EQL); // (´)
                unregister_code(KC_LSFT);
                register_code(KC_SPC);
                //_delay_ms(10);
                unregister_code(KC_SPC);
            }
            break;
        case M_TILDE:
            if (record->event.pressed) {
                register_code(KC_RALT);
                register_code(KC_RBRC); // (¨)
                //_delay_ms(10);
                unregister_code(KC_RBRC); // (¨)
                unregister_code(KC_RALT);
                register_code(KC_SPC);
                //_delay_ms(10);
                unregister_code(KC_SPC);
            }
            break;
        case M_CLEAR:
            if (record->event.pressed) {
                layer_clear();
            }
            break;
        default:
            return true;
    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case SE_MINS:
        case SE_ARNG:
        case SE_ADIA:
        case SE_ODIA:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;
    }
}


const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};
