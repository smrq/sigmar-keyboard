#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _INTER,
    _FN,
    _EXTRA
};

enum unicode_names {
    _ENDASH,
    _EMDASH
};

enum custom_keycodes {
    _CUSTOM_ARROW = SAFE_RANGE,
    _CUSTOM_FUNCTION,
};

const uint32_t PROGMEM unicode_map[] = {
    [_ENDASH] = 0x2013,
    [_EMDASH] = 0x2014
};

#define CC_ARRW _CUSTOM_ARROW
#define CC_FUNC _CUSTOM_FUNCTION

#define CC_KILL LCMD(LOPT(KC_ESC))
#define CC_SNIP LCMD(LSFT(KC_5))
#define CC_DSKL LCMD(LCTL(KC_LEFT))
#define CC_DSKR LCMD(LCTL(KC_RGHT))

#define MO_LOWR MO(_LOWER)
#define MO_RAIS MO(_RAISE)
#define MO_INTR MO(_INTER)
#define MO_FN   MO(_FN)
#define MO_EXT  MO(_EXTRA)

#define UC_NDSH X(_ENDASH)
#define UC_MDSH X(_EMDASH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
MO_EXT,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_TAB,   KC_ENT,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
MO_FN,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MUTE,  KC_MPLY,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  MO_FN,
KC_LGUI,  KC_LALT,  KC_LCTL,  KC_BSPC,  MO_LOWR,  KC_LSFT,                      KC_SPC,   MO_RAIS,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI
    ),
    [_LOWER] = LAYOUT(
_______,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_ASTR,                      UC_MDSH,  KC_AMPR,  KC_PIPE,  KC_CIRC,  KC_TILD,  UC_NDSH,
_______,  KC_0,     KC_4,     KC_5,     KC_6,     KC_EQL,   _______,  _______,  KC_LABK,  KC_LPRN,  KC_LCBR,  KC_LBRC,  KC_EXLM,  KC_GRV,
_______,  KC_DOT,   KC_1,     KC_2,     KC_3,     KC_PLUS,  _______,  _______,  KC_RABK,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_BSLS,  _______,
_______,  _______,  _______,  KC_DEL,   _______,  _______,                      _______,  MO_INTR,  _______,  _______,  _______,  _______
    ),
    [_RAISE] = LAYOUT(
_______,  XXXXXXX,  KC_AMPR,  KC_ASTR,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
_______,  XXXXXXX,  KC_DLR,   KC_PERC,  KC_CIRC,  CC_ARRW,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,
_______,  XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  XXXXXXX,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   XXXXXXX,  XXXXXXX,
_______,  _______,  _______,  _______,  MO_INTR,  _______,                      KC_BSPC,  _______,  _______,  _______,  _______,  _______
    ),
    [_INTER] = LAYOUT(
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  CC_FUNC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,                      XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [_FN] = LAYOUT(
XXXXXXX,  KC_F12,   KC_F7,    KC_F8,    KC_F9,    XXXXXXX,                      XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F12,   XXXXXXX,
XXXXXXX,  KC_F11,   KC_F4,    KC_F5,    KC_F6,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F11,   XXXXXXX,
_______,  KC_F10,   KC_F1,    KC_F2,    KC_F3,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F10,   _______,
_______,  _______,  _______,  XXXXXXX,  XXXXXXX,  _______,                      XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______
    ),
    [_EXTRA] = LAYOUT(
_______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_HUI,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PAUS,  XXXXXXX,
CC_KILL,  XXXXXXX,  CC_DSKL,  XXXXXXX,  CC_DSKR,  XXXXXXX,  RGB_MOD,  RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  CC_SNIP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
_______,  _______,  _______,  XXXXXXX,  XXXXXXX,  _______,                      KC_INS,   XXXXXXX,  KC_CAPS,  XXXXXXX,  KC_SLCK,  KC_NLCK
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();

    switch (keycode) {
        case KC_SPC: {
            static bool registered;
            if (record->event.pressed) {
                if (mods & MOD_MASK_SHIFT) {
                    // Send underscore (shift + minus)
                    register_code(KC_MINS);
                    registered = true;
                    return false;
                }
            } else {
                if (registered) {
                    unregister_code(KC_MINS);
                    registered = false;
                    return false;
                }
            }
            break;
        }
        case _CUSTOM_ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case _CUSTOM_FUNCTION:
            if (record->event.pressed) {
                SEND_STRING("function");
            }
            break;
    }
    return true;
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
