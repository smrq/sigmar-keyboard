#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOW,
    _RAI,
    _ARR,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
MO(_FN),  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,              KC_MINS,
KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     LT(_ARR, KC_SCLN), KC_QUOT,
KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_TAB,   KC_ENT,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,
          KC_LCTL,  KC_LALT,  KC_LGUI,  MO(_LOW), KC_SPC,                       KC_SPC,   MO(_RAI), KC_RGUI,  KC_RALT,  KC_RCTL
    ),
    [_LOW] = LAYOUT(
_______,  KC_SLSH,  KC_7,     KC_8,     KC_9,     KC_ASTR,                      KC_CIRC,  KC_AMPR,  KC_PIPE,  KC_TILD,  KC_EXLM,  _______,
_______,  KC_0,     KC_4,     KC_5,     KC_6,     KC_EQL,                       KC_LABK,  KC_LPRN,  KC_LCBR,  KC_LBRC,  _______,  KC_GRV,
_______,  KC_MINS,  KC_1,     KC_2,     KC_3,     KC_PLUS,  _______,  _______,  KC_RABK,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_BSLS,  _______,
          _______,  _______,  _______,  _______,  KC_BSPC,                      KC_BSPC,  _______,  _______,  _______,  _______
    ),
    [_RAI] = LAYOUT(
_______,  _______,  KC_AMPR,  KC_ASTR,  _______,  _______,                      KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,
_______,  _______,  KC_DLR,   KC_PERC,  KC_CIRC,  _______,                      KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,  _______,
_______,  _______,  KC_EXLM,  KC_AT,    KC_HASH,  _______,  _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,  _______,
          _______,  _______,  _______,  _______,  KC_DEL,                       KC_DEL,   _______,  _______,  _______,  _______
    ),
    [_ARR] = LAYOUT(
_______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,
          _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______
    ),
    [_FN] = LAYOUT(
_______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_CAPS,
          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};
