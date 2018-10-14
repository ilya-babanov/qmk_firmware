#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_RST RESET

#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
#define KC_GAME TO(_GAME)
#define KC_NORM TO(_QWERTY)

#define KC__LSFT OSM(MOD_LSFT)
#define KC__A_C CTL_T(KC_A)
#define KC__S_C CTL_T(KC_SCLN)
#define KC__SPC_C CTL_T(KC_SPC)
#define KC__SPC_G GUI_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , F  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC ,_A_C, S  , D  , T  , G  ,                H  , J  , K  , L  ,_S_C,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LALT, Z  , X  , C  , V  , B  ,GAME,     UNDS, N  , M  ,COMM,DOT ,SLSH,RALT,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       RASE,LOWR,LGUI,         SPC ,_LSFT,LGUI
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,QUES,MINS,ASTR,PLUS,    ,                   ,LABK,RABK,MINS,EXLM,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,CIRC,AT  ,PERC,QUOT,DLR ,               LBRC,LPRN,RPRN,RBRC,COLN,EQL ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,TILD,GRV ,HASH,DQUO,PIPE,    ,         ,AMPR,LCBR,RCBR,UNDS,BSLS,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,UNDS,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,LEFT,DOWN,UP  ,RGHT,               LEFT,DOWN,UP  ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,MPRV,MNXT,MPLY,    ,         ,MPLY,VOLD,VOLU,    ,    ,RST ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAME] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      G  , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      T  ,LALT, Q  , W  , E  , R  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC ,LSFT, A  , S  , D  , F  ,                H  , J  , K  , L  , S  ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      I  , B  , Z  , X  , C  , V  ,NORM,     NORM, N  , M  ,COMM,DOT ,SLSH,RALT,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       TAB ,LGUI,SPC ,          F5 , F6 , F9
  //                  `----+----+----'        `----+----+----'
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
