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

// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
#define RGB_DI_PIN D3
#define RGBLED_NUM 64

#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 32, 32 }

#define RGBLIGHT_LIMIT_VAL 120

// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

// #define RGBLIGHT_LAYERS

// https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_audio
#ifdef AUDIO_ENABLE
	#define AUDIO_PIN C6
	#define AUDIO_PIN_ALT B5
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
#define TAPPING_FORCE_HOLD

// https://beta.docs.qmk.fm/using-qmk/guides/flashing/flashing#qmk-dfu
#define QMK_ESC_OUTPUT F5 // COL 0
#define QMK_ESC_INPUT D4  // ROW 0
