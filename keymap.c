#include QMK_KEYBOARD_H

#include "common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RBRC,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,                 KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
            KC_LCTL, KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,                       KC_ENT, MO(_RAISE), TT(_NUMPAD), KC_LALT, KC_APP
    ),
	[_LOWER] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,                                  KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
        KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                   S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_BSPC,
        KC_TRNS, KC_VOLU, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MPRV, KC_MNXT, KC_LBRC, KC_RBRC, KC_EQL, KC_MINS, KC_BSLS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_RAISE] = LAYOUT(
        KC_TRNS, G(KC_P), KC_NO, RGB_PST, RGB_PCT, RGB_ATG,                  KC_PSCR, KC_SCRL, KC_PAUSE, KC_NO, KC_NO, KC_BSPC,
        KC_CAPS, KC_NO, KC_NO, KC_NO, RGB_UND, RGB_IDL,                    KC_NO, C(KC_LEFT), KC_UP, C(KC_RGHT), KC_PGUP, KC_BSPC,
        KC_TRNS, KC_NO, KC_NO, KC_NO, RGB_SPD, RGB_TOG,                    KC_INS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_HOME,
        KC_TRNS, KC_NO, KC_NO, KC_NO, RGB_RST,   RGB_MOD,  KC_MPRV, KC_MNXT, KC_DEL, KC_NO, KC_PPLS, KC_PMNS, KC_NO, KC_END,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS
    ),
	[_NUMPAD] = LAYOUT(
        EE_CLR, KC_NO, KC_MS_BTN3, KC_NO, KC_SLEP, KC_WAKE,                        KC_CALC, KC_NUM, KC_NO, KC_PSLS, KC_PAST, KC_MINS,
        KC_TRNS, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_NO, KC_NO,                S(KC_6), KC_P7, KC_P8, KC_P9, S(KC_8), KC_PPLS,
        KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_NO, KC_NO,             KC_INS, KC_P4, KC_P5, KC_P6, KC_EQL, KC_BSPC,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,           KC_TRNS, KC_DEL, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_ENT,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT
    )
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_LOWER] = { ENCODER_CCW_CW(RGB_UHD, RGB_UHI), ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_RAISE] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_NUMPAD] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


void suspend_power_down_keymap(void) {
#ifdef OLED_ENABLE
    oled_off();
#endif
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(true);
#endif
}

void suspend_wakeup_init_keymap(void) {
#ifdef OLED_ENABLE
    oled_on();
#endif
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(false);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGB_MATRIX_ENABLE
    process_record_user_rgb_matrix(keycode, record);
#endif
    return true;
}

// Override functions to save memory
// https://docs.qmk.fm/#/squeezing_avr?id=magic-keycodes
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
