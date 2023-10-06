
#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

#if defined(RGB_MATRIX_ENABLE)
#    include "rgb.h"
#endif

#if defined(OLED_ENABLE)
#    include "oled.h"
#endif

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _NUMPAD
};

enum custom_keycodes {
    BSP_DEL = SAFE_RANGE,
#if defined(RGB_MATRIX_ENABLE)
    RGB_RST, // Reset RGB
    RGB_UND, // Toggle RGB underglow as layer indicator
    RGB_ATG, // Toggle active RGB mode
    RGB_PST, // Toggle simple passive RGB mode
    RGB_PCT, // Toggle colorful passive RGB mode
    RGB_IDL, // RGB Idling animations,
    RGB_UHI, // RGB Underglow HUE increase
    RGB_UHD, // RGB Underglow HUE decrease
#endif
    TYPING, // Switch to Colemak layer
    GAMING, // Switch to gaming Colemak layer
    WASD    // Switch to gaming with WASD positions
};
