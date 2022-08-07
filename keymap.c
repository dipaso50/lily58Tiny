#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER, 
    _RAISE, 
    _TILDE,
    _FUNCTION,
    _NUMBER,
    _OPTION,
    _ADJUST,
};

enum {
    //TD_PARENTESIS_CAPS,
    TD_QUOTES,
    TD_TILDE,
    TD_SLASH,
    TD_COLONS,
    TD_QUESTION,
    TD_EXCLAMATION,
    TD_ESCQ
};


void dance_one(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1)
        register_code16(ES_LPRN);
    else
        register_code16(ES_LBRC);
}


void dance_one_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1)
        unregister_code16(ES_LPRN);
    else
        unregister_code16(ES_LBRC);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for " twice por '
    [TD_QUOTES] = ACTION_TAP_DANCE_DOUBLE(ES_QUOT, ES_DQUO),
    // Tap once for ' twice por `
    [TD_TILDE] = ACTION_TAP_DANCE_DOUBLE(ES_ACUT, ES_GRV),
    [TD_SLASH] = ACTION_TAP_DANCE_DOUBLE(ES_SLSH, ES_BSLS),
    [TD_COLONS] = ACTION_TAP_DANCE_DOUBLE(ES_SCLN, ES_COLN),
    [TD_QUESTION] = ACTION_TAP_DANCE_DOUBLE(ES_QUES, ES_IQUE),
    [TD_EXCLAMATION] = ACTION_TAP_DANCE_DOUBLE(ES_EXLM, ES_IEXL),
    [TD_ESCQ] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

#define KC_CAPW LGUI(LSFT(KC_3)) // Capture whole screen 
#define KC_CPYW LGUI(LSFT(LCTL(KC_3))) // Copy whole screen 
#define KC_CAPP LGUI(LSFT(KC_4)) // Capture portion of screen   
#define KC_CPYP LGUI(LSFT(LCTL(KC_4))) // Copy portion of screen

#define RALT_TD_TILDE RALT(TD(TD_TILDE)) //tab for tilde, double tab for ` 
#define TD_QUES TD(TD_QUESTION)// tab for ? double tab for ¿
#define TD_EXCL TD(TD_EXCLAMATION) //tab for ! double tab for ¡
#define TD_Q_ESC TD(TD_ESCQ)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  


[_QWERTY] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, TD_Q_ESC, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, LT(_OPTION,KC_O), KC_P, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, KC_A, KC_S, KC_D, LT(_TILDE, KC_F), KC_G,                           KC_H, LT(_FUNCTION,KC_J), KC_K, KC_L, KC_SCLN, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, LCTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B,          XXXXXXX, XXXXXXX,    LT(_NUMBER,KC_N ), KC_M, KC_COMM, KC_DOT, KC_SLSH,XXXXXXX,
    //----------------------------------                            -------------------------------------
             XXXXXXX, XXXXXXX, OSM(MOD_LSFT) , LT(_RAISE, KC_SPC), LT(_LOWER, KC_ENT),KC_BSPC, XXXXXXX, XXXXXXX),


[_FUNCTION] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                                XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX,  KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

[_NUMBER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX,  KC_1, KC_2, KC_3, KC_4, KC_5,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX,  KC_6, KC_7, KC_8, KC_9, KC_0,                                      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, ES_PLUS, ES_MINS, ES_ASTR, ES_SLSH, ES_EQL,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
    //----------------------------------                                         -------------------------------------


[_OPTION] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, KC_F4, XXXXXXX,                          XXXXXXX, KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

[_LOWER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK,                        XXXXXXX, XXXXXXX, ES_PIPE, XXXXXXX, ES_PERC, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, ES_LCBR, ES_RCBR, ES_SLSH, ES_BSLS,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, ES_LBRC, ES_RBRC, ES_ASTR, ES_AMPR,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

[_RAISE] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, KC_BSPC, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   XXXXXXX, XXXXXXX,
    //----------------------------------                                         -------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, ES_SCLN, ES_COLN, ES_UNDS, XXXXXXX,
    //----------------------------------                                         -------------------------------------
                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX),


  [_TILDE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   ES_GRV, ES_ACUT , ES_QUOT, ES_DQUO, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD_QUES, TD_EXCL, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),



  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ) 

};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST ); }



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}
