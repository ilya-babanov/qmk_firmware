#include QMK_KEYBOARD_H
#include "bootloader.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

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

#define KC__LSFT OSM(MOD_LSFT)
#define KC__A_C GUI_T(KC_A)
#define KC__S_C GUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , F  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC ,_A_C, S  , D  , T  , G  ,                H  , J  , K  , L  ,_S_C,ENT ,
  //|----+----+----+----+----+----+              |----+----+----+----+----+----|
     LALT, Z  , X  , C  , V  , B  ,                N  , M  ,COMM,DOT ,SLSH,RALT,
  //`----+----+----+----+----+----+---/      \---+----+----+----+----+----+----'
                       NUMB,LOWR,LCTL,         SPC ,_LSFT,RASE
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAME] = LAYOUT_kc(
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      T  , G  , Q  , W  , E  , R  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC ,LSFT, A  , S  , D  , F  ,                H  , J  , K  , UP , S  ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      I  ,LCTL, Z  , X  , C  , V  ,                N  , M  ,LEFT,DOWN,RGHT, L  ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       TAB ,GUMB,SPC ,          F5 , F6 , NORM
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,QUES,MINS,ASTR,PLUS, NO ,                NO ,LABK,RABK,MINS,EXLM,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,CIRC, AT ,PERC,QUOT,DLR ,               LBRC,LPRN,RPRN,RBRC,COLN,EQL ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,TILD,GRV ,HASH,DQUO,PIPE,               AMPR,LCBR,RCBR,UNDS,BSLS,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,UNDS,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO , F7 , F8 , F9 , NO ,                NO , NO , F10, F11, F12,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , NO , F4 , F5 , F6 , NO ,               LEFT,DOWN, UP ,RGHT, NO ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , NO , F1 , F2 , F3 , NO ,                F1 , F2 , F3 , F4 , F5 ,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       GAME,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMB] = LAYOUT_kc(
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO , NO , NO , NO , NO , NO ,                NO ,  7 ,  8 ,  9 , NO ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO , NO , NO ,VOLD,VOLU, NO ,                NO ,  4 ,  5 ,  6 , NO ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      NO , NO ,MPLY,MPRV,MNXT, NO ,                 0 ,  1 ,  2 ,  3 , NO ,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           , NO , NO ,           0 ,  0 ,  0
  //                  `----+----+----'        `----+----+----'
  ),

  [_GUMB] = LAYOUT_kc(
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , P  ,  7 ,  8 ,  9 , L  ,                NO ,  7 ,  8 ,  9 , NO ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , K  ,  4 ,  5 ,  6 , J  ,                NO ,  4 ,  5 ,  6 , NO ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,  0 ,  1 ,  2 ,  3 , M  ,                 0 ,  1 ,  2 ,  3 , NO ,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                         0 ,    ,  0 ,           0 ,    ,  0
  //                  `----+----+----'        `----+----+----'
  )
};
