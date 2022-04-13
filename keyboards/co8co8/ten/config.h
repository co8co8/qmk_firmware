// Copyright 2022 co8co8 (@co8co8)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
//#define VENDOR_ID       0x6338
//#define PRODUCT_ID      0x4651
#define DEVICE_VER      0x0001
//#define MANUFACTURER    co8co8
#define PRODUCT         tenkeypad by te96
#define DESCRIPTION     ten key prototype

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 8

//#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5 }
//#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }
//#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
//#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5


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
