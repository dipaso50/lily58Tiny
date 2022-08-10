#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include "custom.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER, 
    _RAISE, 
    _TILDE,
    _NUMBER,
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

#define TTT KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  

[_QWERTY] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTT , TTT, TTT, TTT, TTT, TTT,                                               TTT, TTT, TTT, TTT, TTT, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, TD_Q_ESC, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, KC_A, KC_S, KC_D, LT(_TILDE, KC_F), KC_G,                               KC_H, KC_J, KC_K, KC_L, KC_BSPC, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, LCTL_T(KC_Z), LGUI_T(KC_X), LALT_T(KC_C), LSFT_T(KC_V), KC_B,  TTT, TTT,      LT(_NUMBER,KC_N ), RSFT_T(KC_M), RALT_T(KC_COMM), RGUI_T(KC_DOT), LCTL_T(KC_SLSH),TTT,
    //----------------------------------                            -------------------------------------
             TTT, TTT, KC_TAB , LT(_RAISE, KC_SPC), LT(_LOWER, KC_ENT), OSM(MOD_LSFT), TTT, TTT),



[_NUMBER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTT, TTT, TTT, TTT, TTT, TTT,                                                TTT, TTT, TTT, TTT, TTT, TTT,
    //----------------------------------                                         -------------------------------------
    TTT,  KC_1, KC_2, KC_3, KC_4, KC_5,                                          TTT, TTT, TTT, TTT, TTT, TTT,
    //----------------------------------                                         -------------------------------------
    TTT,  KC_6, KC_7, KC_8, KC_9, KC_0,                                          TTT, TTT,  TTT, TTT, TTT, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, ES_PLUS, ES_MINS, ES_ASTR, ES_SLSH, ES_EQL,      TTT, TTT,              TTT, TTT, TTT, TTT, TTT, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT),
    //----------------------------------                                         -------------------------------------

[_LOWER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTT, TTT, TTT, TTT, TTT, TTT,                                                TTT, TTT, TTT, TTT, TTT, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, ES_HASH, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK,                            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, ES_AMPR, ES_LCBR, ES_RCBR, ES_SLSH, ES_BSLS,                            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, ES_AT, ES_LBRC, ES_RBRC, ES_ASTR, ES_EQL,   TTT,  TTT,                  KC_F11, KC_F12, TTT, TTT , TTT, TTT,
    //----------------------------------                                         -------------------------------------
                                       TTT, TTT, ES_PIPE, ES_PERC, TTT, TTT, TTT, TTT),

[_RAISE] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTT, TTT, TTT, TTT, TTT, TTT,                         TTT, TTT, TTT, TTT, TTT, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, TTT, TTT, TTT, TTT, TTT,                         TTT, KC_PGDN, KC_PGUP, KC_HOME, KC_END, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, TTT, TTT, TTT, TTT, TTT,                         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INS, TTT,
    //----------------------------------                                         -------------------------------------
    TTT, TTT, TTT, TTT, TTT, TTT,   TTT,  TTT,            TTT, KC_RSFT, ES_SCLN, ES_COLN, LCTL_T(ES_UNDS), TTT,
    //----------------------------------                                         -------------------------------------
                                       TTT, TTT, TTT, TTT, KC_PSCR, TTT, TTT, TTT),


  [_TILDE] = LAYOUT(
  TTT, TTT, TTT, TTT, TTT, TTT,                   TTT, TTT, TTT, TTT, TTT, TTT,
  TTT, TTT, TTT, TTT, TTT, TTT,                   ES_CIRC, ES_TILD, ES_DIAE, TTT, TTT, TTT,
  TTT, TTT, TTT, TTT, TTT, TTT,                   ES_GRV, ES_ACUT , ES_QUOT, ES_DQUO, TTT, TTT,
  TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT,         KC_SCLN, TD_QUES, TD_EXCL, TTT, TTT, TTT,
                             TTT, TTT, TTT, TTT, TTT,  TTT, TTT, TTT
  ),



  [_ADJUST] = LAYOUT(
  TTT, TTT, TTT, TTT, TTT, TTT,                   TTT, TTT, TTT, TTT, TTT, TTT,
  TTT, TTT, TTT, TTT, TTT, TTT,                   TTT, TTT, TTT, TTT, TTT, TTT,
  TTT, TTT, TTT, TTT, TTT, TTT,                   TTT, TTT, TTT, TTT, TTT, TTT,
  TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT, TTT,
                             TTT, TTT, TTT, TTT, TTT,  TTT, TTT, TTT
  ) 

};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST ); }



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   
    bool response = true;

    /*switch(keycode){
        case TILDE:
            accent = true; 
            tap_code16( KC_Z ); 
            response = false;
            break;
        case KC_N:                
            response = print_ene();
            break;

        case KC_A:
        case KC_E:
        case KC_I:
        case KC_O:
        case KC_U:
            response = handle_accent(keycode);
            break;

        default:
            return response;
    }  */          
    

    return response;
}



bool print_ene(){
    if (!accent) return true;

    tap_code16( KC_SCLN );   
    accent = false;
    return false;
}

bool handle_accent(uint16_t keycode){
    if (!accent) return true;

     tap_code16( ES_ACUT );
     tap_code16( keycode );
     accent = false;
     return false;
}

