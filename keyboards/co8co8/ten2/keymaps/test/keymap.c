#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
  SEND_A1 = SAFE_RANGE,
  SEND_B1,  SEND_C1,  SEND_D1,  SEND_E1,  SEND_F1,  SEND_G1,  SEND_H1,  SEND_I1,  SEND_J1,  
  SEND_A2,  SEND_B2,  SEND_C2,  SEND_D2,  SEND_E2,  SEND_F2,  SEND_G2,  SEND_H2,  SEND_I2,  SEND_J2,  
  SEND_A3,  SEND_B3,  SEND_C3,  SEND_D3,  SEND_E3,  SEND_F3,  SEND_G3,  SEND_H3,  SEND_I3,  SEND_J3,  
  SEND_A4,  SEND_B4,  SEND_C4,  SEND_D4,  SEND_E4,  SEND_F4,  SEND_G4,  SEND_H4,  SEND_I4,  SEND_J4,  
  SEND_A5,  SEND_B5,  SEND_C5,  SEND_D5,  SEND_E5,  SEND_F5,  SEND_G5,  SEND_H5,  SEND_I5,  SEND_J5,  
  SEND_A6,  SEND_B6,  SEND_C6,  SEND_D6,  SEND_E6,  SEND_F6,  SEND_G6,  SEND_H6,  SEND_I6,  SEND_J6,
  SEND_61,  SEND_62,  SEND_63,  SEND_64,  SEND_65,
  SEND_SA1, SEND_SB1, SEND_SC1, SEND_SD1, SEND_SE1, SEND_SF1, SEND_SG1, SEND_SH1, SEND_SI1, SEND_SJ1, 
  SEND_SA2, SEND_SB2, SEND_SC2, SEND_SD2, SEND_SE2, SEND_SF2, SEND_SG2, SEND_SH2, SEND_SI2, SEND_SJ2, 
  SEND_SA3, SEND_SB3, SEND_SC3, SEND_SD3, SEND_SE3, SEND_SF3, SEND_SG3, SEND_SH3, SEND_SI3, SEND_SJ3, 
  SEND_SA4, SEND_SB4, SEND_SC4, SEND_SD4, SEND_SE4, SEND_SF4, SEND_SG4, SEND_SH4, SEND_SI4, SEND_SJ4, 
  SEND_SA5, SEND_SB5, SEND_SC5, SEND_SD5, SEND_SE5, SEND_SF5, SEND_SG5, SEND_SH5, SEND_SI5, SEND_SJ5, 
  SEND_SA6, SEND_SB6, SEND_SC6, SEND_SD6, SEND_SE6, SEND_SF6, SEND_SG6, SEND_SH6, SEND_SI6, SEND_SJ6,
  SEND_S61,  SEND_S62,  SEND_S63,  SEND_S64,  SEND_S65,
};

//#define OLED_RENDER_LOGO

/*
#define LAYOUT_ten( \
    l00, l01, l02, l03,  l04,l05,l06,l07,       \
    l10, l11, l12, l13,  l14,l15,l16,l17,       \
    l20, l21, l22, l23,  l24,l25,l26,l27,       \
    l30, l31, l32, l33,  l34,l35,l36,l37,         \
    l40, l41, l42, l43,  l44,l45,l46,l47           \
  ) \
  { \
      { l00, l01, l02, l03  ,l04,l05,l06,l07},     \
      { l10, l11, l12, l13  ,l14,l15,l16,l17},        \
      { l20, l21, l22, l23  ,l24,l25,l26,l27},           \
      { l30, l31, l32, l33  ,l34,l35,l36,l37},              \
      { l40, l41, l42, l43  ,l44,l45,l46,l47}                  \
  }
*/
#define LAYOUT_ten( \
    l00, l01, l02, l03,\
    l10, l11, l12, l13,\
    l20, l21, l22, l23,\
    l30, l31, l32, l33,\
    l40, l41, l42, l43\
  ) \
  { \
      { l00, l01, l02, l03},\
      { l10, l11, l12, l13},\
      { l20, l21, l22, l23},\
      { l30, l31, l32, l33},\
      { l40, l41, l42, l43} \
  }

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ten(
        XXXXXXX,     KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS, XXXXXXX,     KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS,
        KC_7,        KC_8,       KC_9,          KC_KP_PLUS,  KC_7,        KC_8,       KC_9,          KC_KP_PLUS,
        KC_4,        KC_5,       KC_6,          XXXXXXX,     KC_4,        KC_5,       KC_6,          XXXXXXX,    
        KC_1,        KC_2,       KC_3,          KC_ENTER,    KC_1,        KC_2,       KC_3,          KC_ENTER,   
        KC_0,        XXXXXXX,    KC_DOT,        XXXXXXX,     KC_0,        XXXXXXX,    KC_DOT,        XXXXXXX
        )
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
    [0] = LAYOUT_ten(
        XXXXXXX,     KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS,
        KC_7,        KC_8,       KC_9,          KC_KP_PLUS, 
        KC_4,        KC_5,       KC_6,          XXXXXXX,    
        KC_1,        KC_2,       KC_3,          KC_ENTER,   
        KC_0,        XXXXXXX,    KC_DOT,        XXXXXXX
        )
*/
    [0] = LAYOUT_ten(
        SEND_A1,SEND_B1,SEND_C1,SEND_D1,
        SEND_A2,SEND_B2,SEND_C2,SEND_D2,
        SEND_A3,SEND_B3,SEND_C3,SEND_D3,
        SEND_A4,SEND_B4,SEND_C4,SEND_D4,
        SEND_A5,SEND_B5,SEND_C5,SEND_D5
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
bool process_record_user1(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        count_type();
        lastkey = keycode;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEND_A1: if (record->event.pressed) SEND_STRING("A1"); break;
    case SEND_B1: if (record->event.pressed) SEND_STRING("B1"); break;
    case SEND_C1: if (record->event.pressed) SEND_STRING("C1"); break;
    case SEND_D1: if (record->event.pressed) SEND_STRING("D1"); break;
    case SEND_E1: if (record->event.pressed) SEND_STRING("E1"); break;
    case SEND_F1: if (record->event.pressed) SEND_STRING("F1"); break;
    case SEND_G1: if (record->event.pressed) SEND_STRING("G1"); break;
    case SEND_H1: if (record->event.pressed) SEND_STRING("H1"); break;
    case SEND_I1: if (record->event.pressed) SEND_STRING("I1"); break;
    case SEND_J1: if (record->event.pressed) SEND_STRING("J1"); break;

  case SEND_61: if (record->event.pressed) SEND_STRING("61"); break;
  case SEND_62: if (record->event.pressed) SEND_STRING("62"); break;
  case SEND_63: if (record->event.pressed) SEND_STRING("63"); break;
  case SEND_64: if (record->event.pressed) SEND_STRING("64"); break;
  case SEND_65: if (record->event.pressed) SEND_STRING("65"); break;

  case SEND_S61: if (record->event.pressed) SEND_STRING("S61"); break;
  case SEND_S62: if (record->event.pressed) SEND_STRING("S62"); break;
  case SEND_S63: if (record->event.pressed) SEND_STRING("S63"); break;
  case SEND_S64: if (record->event.pressed) SEND_STRING("S64"); break;
  case SEND_S65: if (record->event.pressed) SEND_STRING("S65"); break;
	    
      
    case SEND_A2: if (record->event.pressed) SEND_STRING("A2"); break;
    case SEND_B2: if (record->event.pressed) SEND_STRING("B2"); break;
    case SEND_C2: if (record->event.pressed) SEND_STRING("C2"); break;
    case SEND_D2: if (record->event.pressed) SEND_STRING("D2"); break;
    case SEND_E2: if (record->event.pressed) SEND_STRING("E2"); break;
    case SEND_F2: if (record->event.pressed) SEND_STRING("F2"); break;
    case SEND_G2: if (record->event.pressed) SEND_STRING("G2"); break;
    case SEND_H2: if (record->event.pressed) SEND_STRING("H2"); break;
    case SEND_I2: if (record->event.pressed) SEND_STRING("I2"); break;
    case SEND_J2: if (record->event.pressed) SEND_STRING("J2"); break;
    case SEND_A3: if (record->event.pressed) SEND_STRING("A3"); break;
    case SEND_B3: if (record->event.pressed) SEND_STRING("B3"); break;
    case SEND_C3: if (record->event.pressed) SEND_STRING("C3"); break;
    case SEND_D3: if (record->event.pressed) SEND_STRING("D3"); break;
    case SEND_E3: if (record->event.pressed) SEND_STRING("E3"); break;
    case SEND_F3: if (record->event.pressed) SEND_STRING("F3"); break;
    case SEND_G3: if (record->event.pressed) SEND_STRING("G3"); break;
    case SEND_H3: if (record->event.pressed) SEND_STRING("H3"); break;
    case SEND_I3: if (record->event.pressed) SEND_STRING("I3"); break;
    case SEND_J3: if (record->event.pressed) SEND_STRING("J3"); break;
    case SEND_A4: if (record->event.pressed) SEND_STRING("A4"); break;
    case SEND_B4: if (record->event.pressed) SEND_STRING("B4"); break;
    case SEND_C4: if (record->event.pressed) SEND_STRING("C4"); break;
    case SEND_D4: if (record->event.pressed) SEND_STRING("D4"); break;
    case SEND_E4: if (record->event.pressed) SEND_STRING("E4"); break;
    case SEND_F4: if (record->event.pressed) SEND_STRING("F4"); break;
    case SEND_G4: if (record->event.pressed) SEND_STRING("G4"); break;
    case SEND_H4: if (record->event.pressed) SEND_STRING("H4"); break;
    case SEND_I4: if (record->event.pressed) SEND_STRING("I4"); break;
    case SEND_J4: if (record->event.pressed) SEND_STRING("J4"); break;
    case SEND_A5: if (record->event.pressed) SEND_STRING("A5"); break;
    case SEND_B5: if (record->event.pressed) SEND_STRING("B5"); break;
    case SEND_C5: if (record->event.pressed) SEND_STRING("C5"); break;
    case SEND_D5: if (record->event.pressed) SEND_STRING("D5"); break;
    case SEND_E5: if (record->event.pressed) SEND_STRING("E5"); break;
    case SEND_F5: if (record->event.pressed) SEND_STRING("F5"); break;
    case SEND_G5: if (record->event.pressed) SEND_STRING("G5"); break;
    case SEND_H5: if (record->event.pressed) SEND_STRING("H5"); break;
    case SEND_I5: if (record->event.pressed) SEND_STRING("I5"); break;
    case SEND_J5: if (record->event.pressed) SEND_STRING("J5"); break;
    case SEND_A6: if (record->event.pressed) SEND_STRING("A6"); break;
    case SEND_B6: if (record->event.pressed) SEND_STRING("B6"); break;
    case SEND_C6: if (record->event.pressed) SEND_STRING("C6"); break;
    case SEND_D6: if (record->event.pressed) SEND_STRING("D6"); break;
    case SEND_E6: if (record->event.pressed) SEND_STRING("E6"); break;
    case SEND_F6: if (record->event.pressed) SEND_STRING("F6"); break;
    case SEND_G6: if (record->event.pressed) SEND_STRING("G6"); break;
    case SEND_H6: if (record->event.pressed) SEND_STRING("H6"); break;
    case SEND_I6: if (record->event.pressed) SEND_STRING("I6"); break;
    case SEND_J6: if (record->event.pressed) SEND_STRING("J6"); break;
    case SEND_SA1: if (record->event.pressed) SEND_STRING("SA1"); break;
    case SEND_SB1: if (record->event.pressed) SEND_STRING("SB1"); break;
    case SEND_SC1: if (record->event.pressed) SEND_STRING("SC1"); break;
    case SEND_SD1: if (record->event.pressed) SEND_STRING("SD1"); break;
    case SEND_SE1: if (record->event.pressed) SEND_STRING("SE1"); break;
    case SEND_SF1: if (record->event.pressed) SEND_STRING("SF1"); break;
    case SEND_SG1: if (record->event.pressed) SEND_STRING("SG1"); break;
    case SEND_SH1: if (record->event.pressed) SEND_STRING("SH1"); break;
    case SEND_SI1: if (record->event.pressed) SEND_STRING("SI1"); break;
    case SEND_SJ1: if (record->event.pressed) SEND_STRING("SJ1"); break;
    case SEND_SA2: if (record->event.pressed) SEND_STRING("SA2"); break;
    case SEND_SB2: if (record->event.pressed) SEND_STRING("SB2"); break;
    case SEND_SC2: if (record->event.pressed) SEND_STRING("SC2"); break;
    case SEND_SD2: if (record->event.pressed) SEND_STRING("SD2"); break;
    case SEND_SE2: if (record->event.pressed) SEND_STRING("SE2"); break;
    case SEND_SF2: if (record->event.pressed) SEND_STRING("SF2"); break;
    case SEND_SG2: if (record->event.pressed) SEND_STRING("SG2"); break;
    case SEND_SH2: if (record->event.pressed) SEND_STRING("SH2"); break;
    case SEND_SI2: if (record->event.pressed) SEND_STRING("SI2"); break;
    case SEND_SJ2: if (record->event.pressed) SEND_STRING("SJ2"); break;
    case SEND_SA3: if (record->event.pressed) SEND_STRING("SA3"); break;
    case SEND_SB3: if (record->event.pressed) SEND_STRING("SB3"); break;
    case SEND_SC3: if (record->event.pressed) SEND_STRING("SC3"); break;
    case SEND_SD3: if (record->event.pressed) SEND_STRING("SD3"); break;
    case SEND_SE3: if (record->event.pressed) SEND_STRING("SE3"); break;
    case SEND_SF3: if (record->event.pressed) SEND_STRING("SF3"); break;
    case SEND_SG3: if (record->event.pressed) SEND_STRING("SG3"); break;
    case SEND_SH3: if (record->event.pressed) SEND_STRING("SH3"); break;
    case SEND_SI3: if (record->event.pressed) SEND_STRING("SI3"); break;
    case SEND_SJ3: if (record->event.pressed) SEND_STRING("SJ3"); break;
    case SEND_SA4: if (record->event.pressed) SEND_STRING("SA4"); break;
    case SEND_SB4: if (record->event.pressed) SEND_STRING("SB4"); break;
    case SEND_SC4: if (record->event.pressed) SEND_STRING("SC4"); break;
    case SEND_SD4: if (record->event.pressed) SEND_STRING("SD4"); break;
    case SEND_SE4: if (record->event.pressed) SEND_STRING("SE4"); break;
    case SEND_SF4: if (record->event.pressed) SEND_STRING("SF4"); break;
    case SEND_SG4: if (record->event.pressed) SEND_STRING("SG4"); break;
    case SEND_SH4: if (record->event.pressed) SEND_STRING("SH4"); break;
    case SEND_SI4: if (record->event.pressed) SEND_STRING("SI4"); break;
    case SEND_SJ4: if (record->event.pressed) SEND_STRING("SJ4"); break;
    case SEND_SA5: if (record->event.pressed) SEND_STRING("SA5"); break;
    case SEND_SB5: if (record->event.pressed) SEND_STRING("SB5"); break;
    case SEND_SC5: if (record->event.pressed) SEND_STRING("SC5"); break;
    case SEND_SD5: if (record->event.pressed) SEND_STRING("SD5"); break;
    case SEND_SE5: if (record->event.pressed) SEND_STRING("SE5"); break;
    case SEND_SF5: if (record->event.pressed) SEND_STRING("SF5"); break;
    case SEND_SG5: if (record->event.pressed) SEND_STRING("SG5"); break;
    case SEND_SH5: if (record->event.pressed) SEND_STRING("SH5"); break;
    case SEND_SI5: if (record->event.pressed) SEND_STRING("SI5"); break;
    case SEND_SJ5: if (record->event.pressed) SEND_STRING("SJ5"); break;
    case SEND_SA6: if (record->event.pressed) SEND_STRING("SA6"); break;
    case SEND_SB6: if (record->event.pressed) SEND_STRING("SB6"); break;
    case SEND_SC6: if (record->event.pressed) SEND_STRING("SC6"); break;
    case SEND_SD6: if (record->event.pressed) SEND_STRING("SD6"); break;
    case SEND_SE6: if (record->event.pressed) SEND_STRING("SE6"); break;
    case SEND_SF6: if (record->event.pressed) SEND_STRING("SF6"); break;
    case SEND_SG6: if (record->event.pressed) SEND_STRING("SG6"); break;
    case SEND_SH6: if (record->event.pressed) SEND_STRING("SH6"); break;
    case SEND_SI6: if (record->event.pressed) SEND_STRING("SI6"); break;
    case SEND_SJ6: if (record->event.pressed) SEND_STRING("SJ6"); break;
  default:if (record->event.pressed) {
      //char dbgstr[3];
      //dbgstr[2]=0;
      //dbgstr[0]=keycode/10+'0';
      //dbgstr[1]=keycode%10+'0';
      SEND_STRING("nazo:");
      //SEND_STRING(dbgstr);
    }
      break;
  }
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
