// Copyright 2022 co8co8 (@co8co8)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
//#define VENDOR_ID       0x6338
//#define PRODUCT_ID      0x4651
#define DEVICE_VER      0x0001
//#define MANUFACTURER    co8co8
#define PRODUCT         tenkeypad 
#define DESCRIPTION     ten key 2

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

//#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4}
//#define MATRIX_COL_PINS { F4, F5, F6, F7 }
//#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
//#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 50


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define OLED_BRIGHTNESS 100

//LED
#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#define RGBLED_NUM 8
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
#define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
//#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif /* RGB_DI_PIN*/
