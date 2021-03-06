/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define LAYOUT_kc( \
    L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29, L30, L31, R32, R33, R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
) \
{ \
    { KC_NO, KC_NO, KC_##L05,   KC_##L04,   KC_##L03,   KC_##L02,   KC_##L01,   KC_##L00   }, \
    { KC_NO, KC_NO, KC_##L17,   KC_##L16,   KC_##L15,   KC_##L14,   KC_##L13,   KC_##L12   }, \
    { KC_##L31,   KC_##L30,   KC_##L29,   KC_##L28,   KC_##L27,   KC_##L26,   KC_##L25,   KC_##L24   }, \
    { KC_##L44,   KC_##L43,   KC_##L42,   KC_##L41,   KC_##L40,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_##R06,   KC_##R07,   KC_##R08,   KC_##R09,   KC_##R10,   KC_##R11   }, \
    { KC_NO, KC_NO, KC_##R18,   KC_##R19,   KC_##R20,   KC_##R21,   KC_##R22,   KC_##R23   }, \
    { KC_##R32,   KC_##R33,   KC_##R34,   KC_##R35,   KC_##R36,   KC_##R37,   KC_##R38,   KC_##R39   }, \
    { KC_##R45,   KC_##R46,   KC_##R47,   KC_##R48,   KC_##R49,   KC_NO, KC_NO, KC_NO }, \
}
