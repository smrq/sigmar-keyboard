#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ARROWS,
    _FN,
    _EXTRA
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
MO_FN,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MPLY,  RGB_MOD,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_INS,
KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  MO_LOWR,  KC_SPC,                       KC_SPC,   MO_RAIS,  KC_RSFT,  KC_RGUI,  KC_RALT,  KC_RCTL
    ),
    [_LOWER] = LAYOUT(
_______,  KC_SLSH,  KC_7,     KC_8,     KC_9,     KC_ASTR,                      KC_CIRC,  KC_AMPR,  KC_PIPE,  KC_TILD,  KC_EXLM,  _______,
_______,  KC_0,     KC_4,     KC_5,     KC_6,     KC_EQL,   _______,  _______,  KC_LABK,  KC_LPRN,  KC_LCBR,  KC_LBRC,  _______,  KC_GRV,
_______,  KC_MINS,  KC_1,     KC_2,     KC_3,     KC_PLUS,  _______,  _______,  KC_RABK,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_BSLS,  _______,
_______,  _______,  _______,  _______,  _______,  KC_BSPC,                      KC_BSPC,  _______,  _______,  _______,  _______,  _______
    ),
    [_RAISE] = LAYOUT(
_______,  _______,  KC_AMPR,  KC_ASTR,  _______,  _______,                      KC_CIRC,  KC_AMPR,  KC_PIPE,  KC_TILD,  KC_EXLM,  _______,
_______,  _______,  KC_DLR,   KC_PERC,  KC_CIRC,  _______,  _______,  _______,  KC_LABK,  KC_LPRN,  KC_LCBR,  KC_LBRC,  _______,  KC_GRV,
_______,  _______,  KC_EXLM,  KC_AT,    KC_HASH,  _______,  _______,  _______,  KC_RABK,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_BSLS,  _______,
_______,  _______,  _______,  _______,  _______,  KC_DEL,                       KC_DEL,   _______,  _______,  _______,  _______,  _______
    ),
    [_ARROWS] = LAYOUT(
_______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_FN] = LAYOUT(
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  XXXXXXX,
_______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [_EXTRA] = LAYOUT(
_______,  MU_TOG,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,
RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_CAPS,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;
        case 1:
            tap_code(clockwise ? KC_BRIU : KC_BRID);
            break;
    }
    return true;
}
