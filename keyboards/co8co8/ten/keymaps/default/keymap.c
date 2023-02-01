#include QMK_KEYBOARD_H
#include <stdio.h>

//#define OLED_RENDER_LOGO

  /*
    A1-A6
    B1-B6
    C1-C6
    D1-D6

    A6-A1: 7,8,9,     -,HOME,PGUP
    B6-B1: 4,5,6,   DEL,END ,PGDN
    C6-c1: 1,2,3,     -,UP  ,-
    D6-D1: 0,-,RET,LEFT,DOWN,RIGHT

    PU  PD  -  R    x x x x
    HM  END UP DWN  x x x x
    -   DEL -  LEFT x x x x
    9   6   3  RET  x x x x
    8   5   2  -    x x x x
    7   4   1  0    x x x x
  */

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
    [0] = LAYOUT_ten(
    KC_PGUP,   KC_PGDN, XXXXXXX,  KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_HOME,   KC_END,  KC_UP,    KC_DOWN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,   KC_DEL,  XXXXXXX,  KC_LEFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_9,      KC_6,    KC_3,     KC_ENTER, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_8,      KC_5,    KC_2,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_7,      KC_4,    KC_1,     KC_0,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
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

#ifdef OLED_ENABLE
#ifdef OLED_RENDER_LOGO
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}
#endif

static unsigned int type_count = 0;
static uint16_t lastkey = 0;
static void count_type(void) {
    type_count++;
}
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
/*
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
*/
    //スクロールエリア設定
    oled_scroll_set_area(0,3);
    return rotation;
}
#endif
// キーを押す・離すタイミングで呼ばれる関数
// 関数自体なければ関数ごと追加、あれば`#ifdef OLED_ENABLE`内だけ追加する
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        count_type();
        lastkey = keycode;
    }
#endif
    return true;
}
#ifdef OLED_ENABLE
static void oled_write_type_count(void) {
    static char type_count_str[7];
    oled_write_P(PSTR("Type count: "), false);
    itoa(type_count, type_count_str, 10);
    oled_write_ln(type_count_str, false);
}
static void oled_write_type_lastkey(void) {
    static char dbgbuf[20];
    sprintf(dbgbuf,"%02d(0x%02X)",lastkey,lastkey);
    oled_write_P(PSTR("Last key: "), false);
    oled_write_ln(dbgbuf, false);
}
static void oled_write_2digit(unsigned int digit) {
    static char buf[6];
    itoa(digit, buf, 10);
    if (digit < 10) {
        oled_write_char('0', false);
    }
    oled_write(buf, false);
}

static void oled_write_uptime(void) {
    static uint32_t uptime_s;
    uptime_s = timer_read32() / 1000;
    oled_write_P(PSTR("Uptime "), false);
    // hour
    oled_write_2digit((uptime_s / 3600) % 60);
    oled_write_char(':', false);
    // minutes
    oled_write_2digit((uptime_s / 60) % 60);
    oled_write_char(':', false);
    // seconds
    oled_write_2digit(uptime_s % 60);
    oled_write_char('\n', false);
}
#endif
bool oled_task_user(void) {
#ifdef OLED_ENABLE
    // OLED
    //oled_write_ln_P(PSTR("Hello, world!"), false);
    //oled_write_layer_state();

#ifdef OLED_RENDER_LOGO
    render_logo();//これはこれで他とは同時表示ができないっぽい
    if(!is_oled_scrolling()){
        oled_scroll_left();
    }
#endif
    
    oled_write_uptime();
    oled_write_type_count();
    oled_write_type_lastkey();

#endif
    return false;
}
