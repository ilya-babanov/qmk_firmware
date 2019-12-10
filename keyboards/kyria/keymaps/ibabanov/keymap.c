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
#include QMK_KEYBOARD_H

#include <stdlib.h>
#include <time.h>

#define _QWERTY 0
#define _GAME 1
#define _LOWER 2
#define _RAISE 3
#define _NUMB 4
#define _GUMB 5

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_RST RESET

#define KC_GAME TO(_GAME)
#define KC_NORM TO(_QWERTY)
#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
#define KC_NUMB MO(_NUMB)
#define KC_GUMB MO(_GUMB)

#define KC__LST OSM(MOD_LSFT)
#define KC__A_C CTL_T(KC_A)
#define KC__S_C CTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , F  ,                         Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     ESC ,_A_C, S  , D  , T  , G  ,                         H  , J  , K  , L  ,_S_C,ENT ,
  //|----+----+----+----+----+----+                       |----+----+----+----+----+----|
     LALT, Z  , X  , C  , V  , B  ,GAME,MPLY,    LEFT,RGHT, N  , M  ,COMM,DOT ,SLSH,RALT,
  //`----+----+----+----+----+----+---------*   *---------+----+----+----+----+----+----'
                  LGUI,NUMB,LOWR,LCTL,RASE,        LOWR,SPC ,_LST,RASE,NUMB
  //                   ----+----+----+----*       *----+----+----+----'
  ),

  [_GAME] = LAYOUT_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
      T  , G  , Q  , W  , E  , R  ,                         Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     ESC ,LSFT, A  , S  , D  , F  ,                         H  , J  , K  , UP , S  ,ENT ,
  //|----+----+----+----+----+----+                       |----+----+----+----+----+----|
     LALT,LCTL, Z  , X  , C  , V  ,NORM, J  ,        ,NORM, N  , M  ,LEFT,DOWN,RGHT, L  ,
  //`----+----+----+----+----+----+---------*   *---------+----+----+----+----+----+----'
                   M  ,TAB ,GUMB,SPC , I  ,         F5 , F6 ,SPC ,RASE,NUMB
  //                   ----+----+----+----*       *----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,QUES,MINS,ASTR,PLUS, NO ,                         NO ,LABK,RABK,MINS,EXLM,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,CIRC, AT ,PERC,QUOT,DLR ,                        LBRC,LPRN,RPRN,RBRC,COLN,EQL ,
  //|----+----+----+----+----+----+----.             ,----|----+----+----+----+----+----|
         ,TILD,GRV ,HASH,DQUO,PIPE,    ,    ,        ,    ,AMPR,LCBR,RCBR,UNDS,BSLS,    ,
  //`----+----+----+----+----+----+---------*   *---------+----+----+----+----+----+----'
                      ,    ,    ,    ,    ,            ,    ,UNDS,    ,
  //                   ----+----+----+----*       *----+----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         , NO , F7 , F8 , F9 , NO ,                         NO , NO , F10, F11, F12,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         , NO , F4 , F5 , F6 , NO ,                        LEFT,DOWN, UP ,RGHT, NO ,    ,
  //|----+----+----+----+----+----+----.             ,----|----+----+----+----+----+----|
         , NO , F1 , F2 , F3 , NO ,    ,    ,        ,    , F1 , F2 , F3 , F4 , F5 ,    ,
  //`----+----+----+----+----+----+---------*   *---------+----+----+----+----+----+----'
                      ,    ,    ,    ,    ,            ,    ,    ,    ,
  //                   ----+----+----+----*       *----+----+----+----'
  ),

  [_NUMB] = LAYOUT_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
      NO , NO , NO , NO , NO , NO ,                         NO ,  7 ,  8 ,  9 , NO ,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
      NO , NO , NO ,VOLD,VOLU, NO ,                         NO ,  4 ,  5 ,  6 , NO ,    ,
  //|----+----+----+----+----+----+----.             ,----|----+----+----+----+----+----|
      NO , NO ,MPLY,MPRV,MNXT, NO ,    ,    ,        ,    ,  0 ,  1 ,  2 ,  3 , NO ,    ,
  //`----+----+----+----+----+----+---------*   *---------+----+----+----+----+----+----'
                      ,    , NO , NO ,    ,            , 0  , 0  , 0  ,
  //                   ----+----+----+----*       *----+----+----+----'
  ),

  [_GUMB] = LAYOUT_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
      NO , NO ,  7 ,  8 ,  9 , T  ,                         NO ,  7 ,  8 ,  9 , NO ,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
      NO , NO ,  4 ,  5 ,  6 , G  ,                         NO ,  4 ,  5 ,  6 , NO ,    ,
  //|----+----+----+----+----+----+----.             ,----|----+----+----+----+----+----|
      NO , 0  ,  1 ,  2 ,  3 , B  ,    ,    ,        ,    ,  0 ,  1 ,  2 ,  3 , NO ,    ,
  //`----+----+----+----+----+----+---------*   *---------+----+----+----+----+----+----'
                      ,    , NO , NO ,    ,            , 0  , 0  , 0  ,
  //                   ----+----+----+----*       *----+----+----+----'
  )
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Shift"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Ctrl"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Alt"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Cmd"), (modifiers & MOD_MASK_GUI));
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("\n "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NUMB:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Functions\n"), false);
            break;
        case _GUMB:
            oled_write_P(PSTR("Gaming++\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
    oled_write_P(PSTR("\n\n\n\n"), false);
    render_mod_status(get_mods() | get_oneshot_mods());
}

/*
static void render_random_pixels(void) {
    srand(time(0));
    char data[128*64];
    int i;
    for (i = 0; i < 128*64; i++){
        data[i] = rand() % 255;
    }
    oled_write_raw_P(data, sizeof(data));
}
*/

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        oled_off();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
