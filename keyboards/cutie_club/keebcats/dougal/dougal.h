/* Copyright 2021 Cutie Club
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

#include "quantum.h"

#define LAYOUT_all( \
    k00_00, k00_01, k00_02, k00_03, k00_04, k00_05, k00_06, k00_07, k00_08, k00_09, k00_10, k00_11, k00_12, k00_13, k00_14, k00_15, \
    k01_00, k01_01, k01_02, k01_03, k01_04, k01_05, k01_06, k01_07, k01_08, k01_09, k01_10, k01_11, k01_12, k01_13,         k01_15, \
    k02_00, k02_01, k02_02, k02_03, k02_04, k02_05, k02_06, k02_07, k02_08, k02_09, k02_10, k02_11, k02_12, k02_13,         k02_15, \
    k03_00, k03_01, k03_02, k03_03, k03_04, k03_05, k03_06, k03_07, k03_08, k03_09, k03_10, k03_11, k03_12,         k03_13, k03_15, \
    k04_00, k04_01, k04_02,         k04_04,         k04_06,         k04_08, k04_09, k04_10, k04_11,         k04_12, k04_13, k04_15  \
) \
{ \
    { k00_00, k00_01, k00_02, k00_03, k00_04, k00_05, k00_06, k00_07, k00_08, k00_09, k00_10, k00_11, k00_12, k00_13, k00_14, k00_15 }, \
    { k01_00, k01_01, k01_02, k01_03, k01_04, k01_05, k01_06, k01_07, k01_08, k01_09, k01_10, k01_11, k01_12, k01_13, KC_NO,  k01_15 }, \
    { k02_00, k02_01, k02_02, k02_03, k02_04, k02_05, k02_06, k02_07, k02_08, k02_09, k02_10, k02_11, k02_12, k02_13, KC_NO,  k02_15 }, \
    { k03_00, k03_01, k03_02, k03_03, k03_04, k03_05, k03_06, k03_07, k03_08, k03_09, k03_10, k03_11, k03_12, k03_13, KC_NO,  k03_15 }, \
    { k04_00, k04_01, k04_02, KC_NO,  k04_04, KC_NO,  k04_06, KC_NO,  k04_08, k04_09, k04_10, k04_11, k04_12, k04_13, KC_NO,  k04_15 }  \
}
