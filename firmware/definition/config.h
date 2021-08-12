#pragma once

#include "config_common.h"

// https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options#hardware-options
#define VENDOR_ID    0xF055
#define PRODUCT_ID   0x5164
#define DEVICE_VER   0x0002
#define MANUFACTURER smrq
#define PRODUCT      Sigmar Keyboard

#define MATRIX_ROWS 8
#define MATRIX_COLS 7
#define MATRIX_ROW_PINS { D4, D7, E6, B4 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options#features-that-can-be-disabled
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix

#ifdef RGB_MATRIX_ENABLE
	#define RGB_DI_PIN D3
	#define DRIVER_LED_TOTAL 64

	#define RGB_MATRIX_SPLIT { 32, 32 }
	// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
	#define RGB_MATRIX_KEYPRESSES
	#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120

	#define DISABLE_RGB_MATRIX_ALPHAS_MODS
	#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
	#define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
	#define DISABLE_RGB_MATRIX_BREATHING
	#define DISABLE_RGB_MATRIX_BAND_SAT
	#define DISABLE_RGB_MATRIX_BAND_VAL
	#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
	#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
	#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
	#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
	#define DISABLE_RGB_MATRIX_CYCLE_ALL
	#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
	#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
	// #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
	#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
	#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
	#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
	#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
	#define DISABLE_RGB_MATRIX_DUAL_BEACON
	#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
	#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
	#define DISABLE_RGB_MATRIX_RAINDROPS
	#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
	#define DISABLE_RGB_MATRIX_HUE_BREATHING
	#define DISABLE_RGB_MATRIX_HUE_PENDULUM
	// #define DISABLE_RGB_MATRIX_HUE_WAVE
	#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
	#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
	#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
	#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
	#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
	// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
	#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
	#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
	#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
	#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
	#define DISABLE_RGB_MATRIX_SPLASH
	// #define DISABLE_RGB_MATRIX_MULTISPLASH
	#define DISABLE_RGB_MATRIX_SOLID_SPLASH
	// #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

// https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_audio
#ifdef AUDIO_ENABLE
	#define SND_ONE_UP_SOUND \
	    Q__NOTE(_E6),    \
	    Q__NOTE(_G6),    \
	    Q__NOTE(_E7),    \
	    Q__NOTE(_C7),    \
	    Q__NOTE(_D7),    \
	    Q__NOTE(_G7),

	#define SND_ZELDA_PUZZLE \
	    Q__NOTE(_G5),    \
	    Q__NOTE(_FS5),   \
	    Q__NOTE(_DS5),   \
	    Q__NOTE(_A4),    \
	    Q__NOTE(_GS4),   \
	    Q__NOTE(_E5),    \
	    Q__NOTE(_GS5),   \
	    HD_NOTE(_C6),

	#define SND_MARIO_MUSHROOM \
	    S__NOTE(_C5 ), \
	    S__NOTE(_G4 ), \
	    S__NOTE(_C5 ), \
	    S__NOTE(_E5 ), \
	    S__NOTE(_G5 ), \
	    S__NOTE(_C6 ), \
	    S__NOTE(_G5 ), \
	    S__NOTE(_GS4), \
	    S__NOTE(_C5 ), \
	    S__NOTE(_DS5), \
	    S__NOTE(_GS5), \
	    S__NOTE(_DS5), \
	    S__NOTE(_GS5), \
	    S__NOTE(_C6 ), \
	    S__NOTE(_DS6), \
	    S__NOTE(_GS6), \
	    S__NOTE(_DS6), \
	    S__NOTE(_AS4), \
	    S__NOTE(_D5 ), \
	    S__NOTE(_F5 ), \
	    S__NOTE(_AS5), \
	    S__NOTE(_D6 ), \
	    S__NOTE(_F6 ), \
	    S__NOTE(_AS6), \
	    S__NOTE(_F6 )

	#define SND_RICK_ROLL      \
	    Q__NOTE(_F4),      \
	    Q__NOTE(_G4),      \
	    Q__NOTE(_BF4),     \
	    Q__NOTE(_G4),      \
	    HD_NOTE(_D5),      \
	    HD_NOTE(_D5),      \
	    W__NOTE(_C5),      \
	    S__NOTE(_REST),    \
	    Q__NOTE(_F4),      \
	    Q__NOTE(_G4),      \
	    Q__NOTE(_BF4),     \
	    Q__NOTE(_G4),      \
	    HD_NOTE(_C5),      \
	    HD_NOTE(_C5),      \
	    W__NOTE(_BF4),     \
	    S__NOTE(_REST),    \
	    Q__NOTE(_F4),      \
	    Q__NOTE(_G4),      \
	    Q__NOTE(_BF4),     \
	    Q__NOTE(_G4),      \
	    W__NOTE(_BF4),     \
	    H__NOTE(_C5),      \
	    H__NOTE(_A4),      \
	    H__NOTE(_A4),      \
	    H__NOTE(_G4),      \
	    H__NOTE(_F4),      \
	    H__NOTE(_F4),      \
	    W__NOTE(_C5),      \
	    W__NOTE(_BF4),

	#define AUDIO_PIN C6
	#define AUDIO_PIN_ALT B5

	#define UNICODE_SONG_MAC  SONG(TERMINAL_SOUND)
	#define UNICODE_SONG_LNX  SONG(UNICODE_LINUX)
	#define UNICODE_SONG_WIN  SONG(UNICODE_WINDOWS)
	#define UNICODE_SONG_WINC SONG(UNICODE_WINDOWS)

	#define NO_MUSIC_MODE
#endif

// https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_split_keyboard
#define EE_HANDS
// #define USE_I2C
#define USE_SERIAL
#define SOFT_SERIAL_PIN D0
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_USB_DETECT

// https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_encoders
#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { F4 }

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
