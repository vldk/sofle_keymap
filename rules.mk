#This enables Link Time Optimization.This can save a good chunk of space(several KB for me), but the macro and function... functions cause it to error out.
LTO_ENABLE = yes

#Build Options
#change to "no" to disable the options, or define them in the Makefile in
#the appropriate keymap folder that will get included automatically
#
NKRO_ENABLE        = yes  # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
DYNAMIC_MACRO_ENABLE = no

RGBLIGHT_ENABLE    = no   # Enable WS2812 RGB underlight.
BOOTMAGIC_ENABLE   = no   # Virtual DIP switch configuration(+1000)
CONSOLE_ENABLE     = no   # Console for debug(+400)
COMMAND_ENABLE     = no   # Commands for debug and configuration
BACKLIGHT_ENABLE   = no   # Enable keyboard backlight functionality
MIDI_ENABLE        = no   # MIDI controls
AUDIO_ENABLE       = no   # Audio output on port C6
UNICODE_ENABLE     = no   # Unicode
BLUETOOTH_ENABLE   = no   # Enable Bluetooth with the Adafruit EZ-Key HID
SWAP_HANDS_ENABLE  = no   # Enable one-hand typing
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no
MUSIC_ENABLE       = no

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

ifeq ($(OLED_ENABLE),yes)
	SRC += ./oled.c
endif


ifeq ($(RGB_MATRIX_ENABLE),yes)
	SRC += ./rgb.c
endif
