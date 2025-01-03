#pragma once

/* Select hand configuration */
#define EE_HANDS

#define NO_ACTION_ONESHOT
#define NO_USB_STARTUP_CHECK

// #define LAYER_STATE_8BIT // 8 layer limit

#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
// #define MASTER_LEFT
#define ENCODER_DIRECTION_FLIP
#define TAPPING_TOGGLE 2

#define TOTAL_LEDS 72

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    /* ws2812 RGB LED */
    // #define RGB_DI_PIN D3
    #define WS2812_DI_PIN D3
#endif



#ifdef RGB_MATRIX_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM TOTAL_LEDS
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_LED_COUNT RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.


    #define RGB_MATRIX_SPLIT {36,36}
    #define SPLIT_TRANSPORT_MIRROR
    #define SPLIT_LAYER_STATE_ENABLE

    #define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
    #define RGB_DISABLE_TIMEOUT 600000 // (10min) number of milliseconds to wait until rgb automatically turns off

#    undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_VAL
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_HUE_BREATHING
#    undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    undef ENABLE_RGB_MATRIX_SPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_SPLASH


#    define SPLIT_TRANSACTION_IDS_USER USER_CONFIG_SYNC

#    define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#    define IDLE_TIMEOUT 60000 * 4
#    define GAMING_IDLE_TIMEOUT 10000
#    define RGB_MATRIX_TYPING_ACTIVE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define RGB_MATRIX_TYPING_PASSIVE RGB_MATRIX_DIGITAL_RAIN //RGB_MATRIX_RAINBOW_PINWHEELS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

#    define RGB_MATRIX_HUE_STEP 6
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 10
#    define RGB_MATRIX_SPD_STEP 10

#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS

#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses

#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

#    define RGB_MATRIX_ANIMATION_SPEED_FAST UINT8_MAX / 2
#    define RGB_MATRIX_ANIMATION_SPEED_MEDIUM UINT8_MAX / 4
#    define RGB_MATRIX_ANIMATION_SPEED_SLOW UINT8_MAX / 8
#    define RGB_MATRIX_ANIMATION_SPEED_SLOWER UINT8_MAX / 24

#    if defined(THEME_GODSPEED)
#        define THEME_HSV 132, 255, 125
#    elif defined(THEME_GODSPEED_ARES)
#        define THEME_HSV HSV_ORANGE
#    elif defined(THEME_LASER)
#        undef RGB_MATRIX_TYPING_ACTIVE
#        undef RGB_MATRIX_TYPING_PASSIVE
#        define THEME_HSV HSV_PURPLE
#        define RGB_MATRIX_TYPING_ACTIVE RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#        define RGB_MATRIX_TYPING_PASSIVE RGB_MATRIX_CYCLE_LEFT_RIGHT
#    elif defined(THEME_MILKSHAKE)
#        undef RGB_MATRIX_TYPING_ACTIVE
#        undef RGB_MATRIX_TYPING_PASSIVE
#        define THEME_HSV 30, 255, 218
#        define RGB_MATRIX_TYPING_ACTIVE RGB_MATRIX_TYPING_HEATMAP
#        define RGB_MATRIX_TYPING_PASSIVE RGB_MATRIX_CYCLE_LEFT_RIGHT
#    else
#        define THEME_HSV HSV_ORANGE // default to PULSE
#    endif
#endif
