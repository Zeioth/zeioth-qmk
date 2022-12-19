/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

// #define MASTER_LEFT
// #define EE_HANDS




/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */
#define MASTER_RIGHT
//#define EE_HANDS
#define USE_SERIAL_PD2


#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
//#   define DISABLE_RGB_MATRIX_ALPHAS_MODS
//#   define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#   define DISABLE_RGB_MATRIX_CYCLE_ALL
//#   define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define DISABLE_RGB_MATRIX_DUAL_BEACON
//#   define DISABLE_RGB_MATRIX_RAINBOW_BEACON
//#   define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#   define DISABLE_RGB_MATRIX_RAINDROPS
//#   define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   define DISABLE_RGB_MATRIX_BREATHING
#   define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#   define DISABLE_RGB_MATRIX_DIGITAL_RAIN

#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   define DISABLE_RGB_MATRIX_SPLASH
#   define DISABLE_RGB_MATRIX_MULTISPLASH
#   define DISABLE_RGB_MATRIX_SOLID_SPLASH
#   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

// OLED 
//#define SSD1306OLED (don't define the model or it will fail)
//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
//#define OLED_TIMEOUT 36000
//#define OLED_FONT_WIDTH 6 
//#define OLED_FONT_HEIGHT 8 
//#define SPLIT_OLED_ENABLE

// Mouse keys
#define MK_3_SPEED 
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_UNMOD 6 
#define MK_C_OFFSET_0 1
#define MK_C_OFFSET_1 2
#define MK_C_OFFSET_2 4 

// Space cadet keys
#define LAPO_KEYS KC_LALT,KC_NO,KC_ESC
#define TAPPING_TERM 300 
#define IGNORE_MOD_TAP_INTERRUPT

// Auto shift settings
#define AUTO_SHIFT_TIMEOUT 175
#define NO_AUTO_SHIFT_NUMERIC
//#define NO_AUTO_SHIFT_ALPHA
//#define NO_AUTO_SHIFT_SPECIAL

// PIMORONI SETTINGS
#define PIMORONI_TRACKBALL_ENABLE
#define PIMORONI_TRACKBALL_CLICK
// orientation pimoroni text on top and trackball text at the bottom
#define PIMORONI_TRACKBALL_ROTATE
//#define PIMORONI_TRACKBALL_INVERT_Y
//#define PIMORONI_TRACKBALL_INVERT_X

