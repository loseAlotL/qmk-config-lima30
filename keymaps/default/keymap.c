// Copyright 2024 Lima Lima
//hehehah

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _GAMING,
    _FIRST,
    _SECOND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * -------------------------------------------------        -------------------------------------------------
     * | SHIFT |   Q   |   W   |   E   |   R   |   T   |        |   Y   |   U   |   I   |   O   |   P   |  BACK |
     * |-----------------------------------------------|        |-----------------------------------------------|
     * |  CTRL |   A   |   S   |   D   |   F   |   G   |        |   H   |   J   |   K   |   L   |   ;   | ENTER |
     * ------------------------------------------------|        |------------------------------------------------
     *                         |  ESC  | SPACE |  TAB  |        |  LAY1 | SPACE | LAY2  |
     *                         -------------------------        -------------------------
     */
    [_QWERTY] = LAYOUT(
        KC_LSFT,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        KC_LCTL,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_ENT,
                                      KC_ESC,  KC_SPC,  KC_TAB,           MO(_FIRST),   KC_SPC,   MO(_SECOND)
    ),

    [_GAMING] = LAYOUT(
        KC_LSFT,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        KC_LCTL,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,   KC_NO,
                                      KC_ESC,  KC_SPC,  KC_TAB,           KC_F1,   KC_F2,   KC_F3
    ),
    
    [_FIRST] = LAYOUT(
        KC_1,     KC_2,       KC_3,    KC_4,    KC_5,    KC_6,             KC_7,      KC_8,     KC_9,     KC_0,    KC_MINS,     KC_EQL,
        KC_GRV,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_COMM,   KC_DOT,   KC_SLSH,  KC_LBRC,    KC_RBRC,   KC_NO,
                                      KC_LSFT,   KC_NO,   KC_NO,            KC_TRNS,     KC_NO,    KC_TRNS
    ),

    [_SECOND] = LAYOUT(
        KC_F1,   KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F6,             KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,
        KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
                                      KC_LSFT,    KC_NO,    KC_NO,             KC_TRNS,    KC_NO,    KC_TRNS
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 2) {
      if(clockwise) {
        tap_code(KC_PGUP);
      }
      else{
        tap_code(KC_PGDN);
      }
    }
    else if (index == 3  ) {
        // Page up/Page down
        if (clockwise) {
          tap_code(KC_WH_U);
        } else {
          tap_code(KC_WH_D);
        }
    }
    return true;
}
#endif