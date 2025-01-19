/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

 enum combos {
   ALTR_ALTSFT,
   ALTF_ALTCTRL
 };
 const uint16_t PROGMEM altr_combo[] = {KC_LALT, KC_R, COMBO_END};
 const uint16_t PROGMEM altf_combo[] = {KC_LALT, KC_F, COMBO_END};
 combo_t key_combos[] = {
   [ALTR_ALTSFT] = COMBO(altr_combo, LALT(S(KC_NO))),
   [ALTF_ALTCTRL] = COMBO(altf_combo, LALT(LCTL(KC_NO))),
 };
 enum {
     TD_H,
 };
 tap_dance_action_t tap_dance_actions[] = {
   [TD_H] = ACTION_TAP_DANCE_DOUBLE(KC_H, S(KC_H)),
 };
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    C(S(KC_T))  , S(KC_TAB)   , A(C(KC_TAB)), KC_BSPC    , KC_ESC     ,                            KC_P7      , KC_P8      , KC_P9     , _______     , KC_HOME     ,
    C(KC_W)     , C(S(KC_TAB)), C(KC_TAB)   , KC_ENT     , C(KC_T)    ,                            KC_P4      , KC_P5      , KC_P6     , _______     , KC_END      ,
    KC_LSFT     , KC_LEFT     , KC_RGHT     , KC_F2      , KC_SPC     ,                            KC_P1      , KC_P2      , KC_P3     , KC_PDOT     , KC_PEQL     ,
    KC_LCTL     , _______     , _______     ,_______     , TO(4)      , MO(1)         , KC_NUM   , TO(2)      , MO(1)      , KC_P0     , KC_BSPC     , KC_PENT
  ),

  [1] = LAYOUT_universal(
    A(C(KC_C))  , KC_F11      , KC_F        , S(KC_DEL)  , KC_DEL     ,                           KC_F6       , KC_R       , KC_S      , KC_U        , G(KC_X)     ,
    KC_F5       , C(S(KC_Z))  , C(KC_Z)     , KC_HOME    , KC_END     ,                           A(C(KC_F11)), A(C(KC_F7)), A(C(KC_M)), G(KC_P1)    , _______     ,
    KC_TAB      , C(KC_A)     , C(KC_X)     , C(KC_C)    ,C(KC_V)     ,                           KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, _______ , _______,
    A(KC_F4)    , _______     , _______     , _______    , TO(5)      , MO(1)         , _______  , _______    , MO(1)      , C(S(KC_N)), A(KC_PSCR)  , G(KC_PSCR)
  ),

  [2] = LAYOUT_universal(
    KC_Q        , KC_W        , KC_E        , KC_R       , KC_T       ,                           KC_Y        , KC_U       , KC_I      , KC_O       , KC_P         ,
    KC_A        , KC_S        , KC_D        , KC_F       , KC_G       ,                           KC_H        , KC_J       , KC_K      , KC_L       , KC_AT        ,
    KC_Z        , KC_X        , KC_C        , KC_V       , KC_B       ,                           KC_N        , KC_M       , KC_COMM   , KC_DOT     , KC_MINS      ,
    KC_DEL      , _______     , _______     , _______    , TO(0)      , KC_SPC        , KC_LSFT , TO(0)       , MO(3)      , KC_SCLN   , KC_QUOT    , KC_ENT
  ),

  [3] = LAYOUT_universal(
    C(KC_F)     , KC_UP       , _______     , KC_EQL     , KC_BSLS    ,                           KC_7        , KC_8       , KC_9      , KC_MHEN    , KC_HOME      ,
    KC_LEFT     , KC_DOWN     , KC_RGHT     , KC_LBRC    , KC_RBRC    ,                           KC_4        , KC_5       , KC_6      , KC_INS     , KC_HOME      ,
    KC_LSFT     , KC_TAB      , C(KC_Z)     , KC_SLSH    , KC_GRV     ,                           KC_1        , KC_2       , KC_3      , _______    , KC_END       ,
    KC_LCTL     , _______     , _______     , _______    , S(KC_CAPS) , KC_CAPS       , C(KC_C) , C(KC_V)     , MO(3)      , KC_0      , _______    , KC_ENT
  ),

   [4] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),

   [5] = LAYOUT_universal(
    _______  , AML_TO   , AML_I50  , _______  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  // Auto enable scroll mode when the highest layer is 7
   keyball_set_scroll_mode(get_highest_layer(state) == 7);
 
  uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
            rgblight_sethsv(HSV_RED);
            break;
        case 1:
            rgblight_sethsv(HSV_AZURE);
            break;
        case 2:
            rgblight_sethsv(HSV_GREEN);
            break;
        case 3:
            rgblight_sethsv(HSV_AZURE);
            break;
        case 4:
            rgblight_sethsv(HSV_BLUE);
            break;        
        case 5:
            rgblight_sethsv(HSV_ORANGE);
            break;
        case 7:
            rgblight_sethsv(HSV_AZURE);
            break;
    }
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
