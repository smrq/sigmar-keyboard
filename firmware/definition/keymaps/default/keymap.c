#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ARROWS,
    _FN,
    _EXTRA
};

enum unicode_names {
    NDASH,
    MDASH,
    GUILL,
    GUILR
};

const uint32_t PROGMEM unicode_map[] = {
    [NDASH] = 0x2013,
    [MDASH] = 0x2014,
    [GUILL] = 0x00AB,
    [GUILR] = 0x00BB
};

#define MO_LOWR MO(_LOWER)
#define MO_RAIS MO(_RAISE)
#define MO_ARR  MO(_ARROWS)
#define MO_FN   MO(_FN)
#define MO_EXT  MO(_EXTRA)

#define LT_SCLN LT(_ARROWS, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
MO_EXT,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_TAB,   KC_ENT,   KC_H,     KC_J,     KC_K,     KC_L,     LT_SCLN,  KC_QUOT,
MO_FN,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MUTE,  KC_MPLY,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_INS,
KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  MO_LOWR,  KC_SPC,                       KC_SPC,   MO_RAIS,  KC_RSFT,  KC_RGUI,  KC_RALT,  KC_RCTL
    ),
    [_LOWER] = LAYOUT(
_______,  KC_SLSH,  KC_7,     KC_8,     KC_9,     KC_ASTR,                      KC_CIRC,  KC_AMPR,  KC_PIPE,  KC_TILD,  KC_EXLM,  X(NDASH),
_______,  KC_0,     KC_4,     KC_5,     KC_6,     KC_EQL,   _______,  _______,  KC_LABK,  KC_LPRN,  KC_LCBR,  KC_LBRC,  XXXXXXX,  KC_GRV,
_______,  KC_MINS,  KC_1,     KC_2,     KC_3,     KC_PLUS,  _______,  _______,  KC_RABK,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_BSLS,  _______,
_______,  _______,  _______,  _______,  _______,  KC_BSPC,                      KC_BSPC,  _______,  _______,  _______,  _______,  _______
    ),
    [_RAISE] = LAYOUT(
_______,  XXXXXXX,  KC_AMPR,  KC_ASTR,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  X(MDASH),
_______,  XXXXXXX,  KC_DLR,   KC_PERC,  KC_CIRC,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
_______,  XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  X(GUILL), X(GUILR), XXXXXXX,  _______,
_______,  _______,  _______,  _______,  _______,  KC_DEL,                       KC_DEL,   _______,  _______,  _______,  _______,  _______
    ),
    [_ARROWS] = LAYOUT(
_______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_FN] = LAYOUT(
XXXXXXX,  KC_F21,   KC_F22,   KC_F23,   KC_F24,   XXXXXXX,                      XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,
KC_PAUS,  KC_F17,   KC_F18,   KC_F19,   KC_F20,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,
_______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_PSCR,
_______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______
    ),
    [_EXTRA] = LAYOUT(
_______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_VAI,  RGB_SPI,                      UC_M_MA,  UC_M_WI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
XXXXXXX,  KC_NLCK,  KC_SLCK,  KC_CAPS,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  KC_CAPS,  KC_SLCK,  KC_NLCK,  XXXXXXX
    )
};

bool encoder_update_user(uint8_t index, bool direction) {
    // `direction` is true for clockwise on the left hand
    // `direction` is true for counterclockwise on the right hand
    switch (index) {
        case 0: // left hand
            tap_code(direction ? KC_VOLU : KC_VOLD);
            break;
        case 1: // right hand
            tap_code(direction ? KC_PGDN : KC_PGUP);
            break;
    }
    return true;
}
