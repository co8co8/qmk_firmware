#include QMK_KEYBOARD_H

#define LAYOUT_ten( \
    l00, l01, l02, l03, l04, l05, l06, l07, \
    l10, l11, l12, l13, l14, l15, l16, l17, \
    l20, l21, l22, l23, l24, l25, l26, l27, \
    l30, l31, l32, l33, l34, l35, l36, l37, \
    l40, l41, l42, l43, l44, l45, l46, l47, \
    l50, l51, l52, l53, l54, l55, l56, l57 \
  ) \
  { \
    { l00, l01, l02, l03, l04, l05, l06, l07 }, \
    { l10, l11, l12, l13, l14, l15, l16, l17 }, \
    { l20, l21, l22, l23, l24, l25, l26, l27 }, \
    { l30, l31, l32, l33, l34, l35, l36, l37 }, \
    { l40, l41, l42, l43, l44, l45, l46, l47 }, \
    { l50, l51, l52, l53, l54, l55, l56, l57 } \
  }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ten(
    KC_PGUP,   KC_PGDN, XXXXXXX,  KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_HOME,  KC_END,   KC_UP,   KC_DOWN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,   KC_DEL,   XXXXXXX,   KC_LEFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_9,    KC_6,    KC_3,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_8,    KC_5,    KC_2,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_7,    KC_4,    KC_1,    KC_0,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};
void oled_write_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:                               // 
            oled_write_ln_P(PSTR("Base"), false); // 
            break;
        case 1:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}
bool oled_task_user(void) {
  // OLED
  oled_write_ln_P(PSTR("Hello, world!"), false);
  //oled_write_layer_state();
  return false;
}
