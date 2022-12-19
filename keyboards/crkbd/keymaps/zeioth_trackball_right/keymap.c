#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif


#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "drivers/sensors/pimoroni_trackball.h"
#endif

// Spanish aliases for the keys. We are not actually using them. 
#include "keymap_spanish.h"

uint8_t tmp_mod; // Save the mods



// ###########################################################################
// LAYER DEFINITION
// ###########################################################################
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _SUPER 1
#define _LOWER 2
#define _RAISE 3
#define _HYPER 4
#define _ARROW 5
#define _ADJUST 6


// ###########################################################################
// KEYCODE DEFINITION
// ###########################################################################
enum custom_keycodes {
  // LAYERS
  BASE = SAFE_RANGE,
  SUPER,
  LOWER,
  RAISE,
  HYPER,
  ARROW,
  CKC_EXIT_ARROW,
  ADJUST,
  BACKLIT,
  RGBRST,
  MODE_TOG, // In the future, will change mode. Modes change the raise layer.
  // BASE LAYER KEYS
  CKC_CTRLBS,
  CKC_BSPC,
  CKC_RLOCK,
  CKC_RSFT,
  // SUPER LAYER KEYCODES
  M_WS1,
  M_WS2,
  M_WS3,
  M_WS4,
  M_WS5,
  M_WS6,
  M_WS7,
  M_WS8,
  F_WL,
  F_WD,
  F_WU,
  F_WR,
  M_LOCK,
  M_PWMENU,
  I3_LYM,
  M_HELP,
  M_VIM_HELP,
  I3_FS,
  I3_DISPLAYS,
  I3_SCREENSHOT,
  I3_RESIZE,
  I3_MOVE,
  I3_SPAD,
  I3_FLOAT,
  I3_WINTAB,
  I3_KILL,
  I3_XKILL,
  I3_PW,
  I3_NW,
  I3_RESET,
  // LOWER LAYER KEYCODES
  CKC_ACCENT,
  CKC_HASH,
  CKC_QUOT,
  CKC_DQUOT,
  CKC_QMA,
  CKC_EXCLAM,
  CKC_PERC,
  CKC_PLUS,
  CKC_MINUS,
  CKC_ASTERISK,
  CKC_SLASH,
  CKC_EQUAL,
  CKC_MORE,
  CKC_LESS,
  CKC_O_PAR,
  CKC_C_PAR,
  CKC_AND,
  CKC_OR,
  CKC_O_CUR,
  CKC_C_CUR,
  CKC_O_BRK,
  CKC_C_BRK,
  // RAISE LAYER KEYCODES
  VIM_CIT,
  VIM_CIP,
  VIM_CIS,
  VIM_CIW,
  VIM_CIB,
  VIM_VIT,
  VIM_VIP,
  VIM_VIS,
  VIM_VIW,
  VIM_VIB,
  VIM_DIT,
  VIM_DIP,
  VIM_DIS,
  VIM_DIW,
  VIM_DIB,
  VIM_GTU,
  VIM_GTD,
  VIM_GMD,
  VIM_GMU,
  // HYPER LAYER KEYCODES
  M_CBACKUP,
  M_UPDATE_PACKAGES,
  M_ROFI,
  M_ROFI_SHORTCUTS,
  M_ROFI_EMOJI,
  M_CALC,
  M_ROFI_MANUALS,
  M_ROFI_DOCS,
  M_ROFI_ACTIVITIES,
  M_RANGER,
  M_FILEX,
  M_VIM,
  M_WEATHER
};


// ###########################################################################
// KEYMAPS DEFINITION
// ###########################################################################

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // #############################################################  BASE ########################################################################
  [_BASE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,           CKC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+-----------------+-----------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I, KC_O,            CKC_ACCENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+-----------------+-----------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, CKC_QMA,            CKC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+-----------------+-----------|
                                          SUPER,   LOWER,    KC_SPC,     KC_ENT, RAISE,   KC_LAPO \
                                      //`--------------------------'  `--------------------------'

  ),
  // ############################################################# SUPER ########################################################################
  [_SUPER] = LAYOUT_split_3x6_3( \
  //,-------------------------------------------------------------------------------.                    ,-----------------------------------------------------------------------------.
      KC_LGUI,  M_LOCK,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE,  I3_KILL,                    I3_XKILL,         KC_MPLY,       KC_MPRV,          KC_MNXT,  M_PWMENU, KC_RALT,\
  //|--------+--------+-------------------+----------------+--------------+---------|                    |-------+----------------+--------------+-----------------+--------+---------|
      KC_LCTL,   M_WS7,              M_WS1,           M_WS2,         M_WS3,    I3_FS,                   I3_WINTAB,           M_WS4,         M_WS5,           M_WS6,     M_WS8,   KC_NO,\
  //|--------+--------+-------------------+----------------+--------------+---------|                    |-------+----------------+--------------+--------------------------+---------|
      KC_LSFT, I3_DISPLAYS,          I3_RESIZE,         I3_MOVE, I3_SPAD,      KC_NO,                    I3_FLOAT,           I3_PW,         I3_NW,     I3_SCREENSHOT, I3_RESET, CKC_RSFT,\
  //|--------+--------+-------------------+----------------+--------------+-----------------|  |---------+-------+----------------+--------------+------------------+--------+---------|
                                                                     SUPER,    LOWER, ADJUST,  KC_NO, RAISE, KC_DEL \
                                                                    //`---------------------'  `------------------------'
  ),

  // ############################################################  LOWER ########################################################################
  [_LOWER] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------------.                   ,--------------------------------------------------------------------.
        KC_LGUI,     KC_4,      KC_3,      KC_2,       KC_1,     KC_5,                        KC_0,      KC_6,         KC_7,      KC_8,     KC_9,     KC_RALT,\
    //|--------+----------+---------+----------+-----------+---------|                   |--------+----------+-------------+----------+----------+------------|
        KC_LCTL, CKC_EXCLAM, CKC_HASH, CKC_QUOT, CKC_DQUOT, CKC_PERC,                    CKC_PLUS, CKC_MINUS, CKC_ASTERISK, CKC_SLASH, CKC_EQUAL,    KC_LAPO,\
    //|--------+----------+---------+----------+-----------+---------|                   |--------+----------+-------------+----------+----------+------------|
        KC_LSFT, CKC_LESS,  CKC_MORE, CKC_O_PAR,  CKC_C_PAR, CKC_AND,                     CKC_OR, CKC_C_CUR,    CKC_O_CUR, CKC_C_BRK, CKC_O_BRK,     CKC_RSFT,\
    //|--------+----------+---------+----------+-----------+---------+--------|  |-------+--------+----------+-------------+----------+----------+------------|
                                                      SUPER,    LOWER,  KC_TAB,    KC_TAB,   RAISE, KC_DEL \
                                                  //`-------------------------'  `-------+--------+---------'
    ),

  // ############################################################# RAISE ########################################################################
  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LGUI, VIM_DIT,   VIM_DIP, VIM_DIS, VIM_DIW, VIM_DIB,                      KC_HOME, KC_END, KC_PGDOWN, KC_PGUP, XXXXXXX, KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, VIM_CIT,   VIM_CIP, VIM_CIS, VIM_CIW, VIM_CIB,                      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_ASTG, KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, VIM_VIT,   VIM_VIP, VIM_VIS, VIM_VIW, VIM_VIB,                     XXXXXXX, VIM_GMD,  VIM_GMU, VIM_GTD, VIM_GTU, CKC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           SUPER, LOWER, CKC_CTRLBS,  CKC_CTRLBS,   RAISE, KC_NO \
                                      //`--------------------------'  `--------------------------'
  ),

  // ############################################################# HYPER ########################################################################
  [_HYPER] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------------------------------.                    ,--------------------------------------------------------------.
    M_WEATHER,      M_CBACKUP, M_UPDATE_PACKAGES,   M_ROFI_SHORTCUTS, M_ROFI_EMOJI, M_FILEX,                   M_RANGER, KC_MS_BTN2,    KC_MS_U, KC_MS_BTN3,   M_VIM, M_ROFI_MANUALS,\
  //|--------+---------------+------------+-------------------+-------------+--------|                    |--------+-----------+-----------+-----------+--------+--------|
      KC_LCTL,         KC_F11, M_ROFI_DOCS,  M_ROFI_ACTIVITIES,      M_ROFI,    M_CALC,                   KC_MS_BTN1,    KC_MS_L,    KC_MS_D,    KC_MS_R,  KC_F12, KC_ACL1,\
  //|--------+---------------+------------+-------------------+-------------+--------|                    |--------+-----------+-----------+-----------+--------+--------|
    KC_LSHIFT,          KC_F4,       KC_F3,              KC_F2,        KC_F1,   KC_F5,                      KC_F10,       KC_F6,      KC_F7,      KC_F8,   KC_F9, CKC_RSFT,\
  //|--------+---------------+------------+-------------------+-------------+--------+--------|  |--------+--------+-----------+-----------+-----------+--------+--------|
                                                                     KC_ACL2,   LOWER,   KC_NO,    KC_ACL2, KC_ACL1, KC_LAPO \
                                                                 //`--------------------------'  `--------------------------'
  ),
  // ############################################################# ARROW ########################################################################
  [_ARROW] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------------------------------.                    ,--------------------------------------------------------------.
        CKC_EXIT_ARROW, KC_NO,       KC_NO,              KC_NO,        KC_NO,   KC_NO,                        KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO, CKC_EXIT_ARROW,\
  //|--------+---------------+------------+-------------------+-------------+--------|                    |--------+-----------+-----------+-----------+--------+--------|
        CKC_EXIT_ARROW, KC_NO,       KC_NO,              KC_NO,        KC_NO,   KC_NO,                        KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO, CKC_EXIT_ARROW,\
  //|--------+---------------+------------+-------------------+-------------+--------|                    |--------+-----------+-----------+-----------+--------+--------|
        CKC_EXIT_ARROW, KC_NO,       KC_NO,              KC_NO,        KC_NO,   KC_UP,                        KC_UP,      KC_NO,      KC_NO,      KC_NO,   KC_NO, CKC_EXIT_ARROW,\
  //|--------+---------------+------------+-------------------+-------------+--------+--------|  |--------+--------+-----------+-----------+-----------+--------+--------|
                                                                     KC_LEFT, KC_DOWN,KC_RIGHT,    KC_LEFT, KC_DOWN, KC_RIGHT \
                                                                 //`--------------------------'  `--------------------------'
  ),
  // ############################################################ ADJUST #########################################################################
  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,                     MODE_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,                      XXXXXXX, M_HELP, M_VIM_HELP,  XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO, KC_NO \
                                      //`--------------------------'  `--------------------------'
  )
};


// ###########################################################################
// HELPER METHODS FOR LAYERS 
// ###########################################################################
int RGB_current_mode;

// Set the default layer
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// If layer1 + layer2 are combined: enble   layer3
// Else:                            disable layer3
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3, 
                      bool keep) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {layer_on(layer3);} 
  else {if(!keep){layer_off(layer3);}}
}

// Simulate a virtual key that prints the keycodes 'k1', or 'k2' if shifted. 
void press_virtual_key(uint16_t kc1, uint16_t kc2, bool lshift1, bool ralt1,
                                                   bool lshift2, bool ralt2) {
  tmp_mod = get_mods();
  if (!(get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))){
    if(lshift1){register_code(KC_LSHIFT);}
    if(ralt1){register_code(KC_RALT);}
    register_code(kc1);
    set_mods(tmp_mod);
  } else{
    clear_mods();
    if(lshift2){register_code(KC_LSHIFT);}
    if(ralt2){register_code(KC_RALT);}
    register_code(kc2);
    set_mods(tmp_mod);
  }
}

// Same as press_virtual_key, but allow all modifiers. For border cases.
void press_virtual_key_complex(uint16_t kc1, uint16_t kc2, 
                       bool lshift1, bool ctrl1, bool lgui1, bool lalt1, bool ralt1, 
                       bool lshift2, bool ctrl2, bool lgui2, bool lalt2, bool ralt2) 
{
  // TODO: Implement the paramters you are already passing.
  tmp_mod = get_mods();
  if (!(get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))){
    if(lshift1){register_code(KC_LSHIFT);}
    if(ctrl1){register_code(KC_LCTL);}
    if(lgui1){register_code(KC_LGUI);}
    if(lalt1){register_code(KC_LALT);}
    if(ralt1){register_code(KC_RALT);}
    register_code(kc1);
    set_mods(tmp_mod);
  } else{
    clear_mods();
    if(lshift2){register_code(KC_LSHIFT);}
    if(ctrl2){register_code(KC_LCTL);}
    if(lgui2){register_code(KC_LGUI);}
    if(lalt2){register_code(KC_LALT);}
    if(ralt2){register_code(KC_RALT);}
    register_code(kc2);
    set_mods(tmp_mod);
  }
}


// presses a keyboard shortcut
void trigger_shortcut(uint16_t kc1, bool lshift,  bool ctrl, bool lgui, 
                                    bool lalt,  bool ralt)
{
  if(lshift){register_code(KC_LSHIFT);}
  if(ctrl){register_code(KC_LCTL);}
  if(lgui){register_code(KC_LGUI);}
  if(lalt){register_code(KC_LALT);}
  if(ralt){register_code(KC_RALT);}
  register_code(kc1);
  clear_keyboard();
  // layer_off(_HYPER);
}

// tap hold behavior (space cadet shift)
// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM + 5000;
    }
}

// Trackball
#ifdef PIMORONI_TRACKBALL_ENABLE
bool set_scrolling = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

// Pimoroni led
switch (get_highest_layer(layer_state)) {
  case _BASE:
    pimoroni_trackball_set_rgbw(0,0,0,32);   // White
    break;
  case _SUPER:
    pimoroni_trackball_set_rgbw(32,0,0,0);   // Dark red
     break;
  case _LOWER:
     pimoroni_trackball_set_rgbw(0,32,0,0);   // Dark green
     break;
  case _RAISE:
     pimoroni_trackball_set_rgbw(0,0,32,0);   // Dark blue
     break;
  case _HYPER:
     pimoroni_trackball_set_rgbw(32,0,32,0);  // Dark Magenta 
     break;
  case _ARROW:
     pimoroni_trackball_set_rgbw(32,16,16,0); // Pink 
     break;
  case _ADJUST:
     pimoroni_trackball_set_rgbw(32,32,0,0);  // Yellow
     break;
  default:
     pimoroni_trackball_set_rgbw(0,0,0,0); // Turned off
  }

    // Enable mouse on 
    if (layer_state_is(_RAISE) || layer_state_is(_LOWER)) {
        set_scrolling = false;
    } else {
        set_scrolling = true;
    }

    // Overide the way mouse report behaves
    if (set_scrolling) {
      mouse_report.h = mouse_report.x;
      mouse_report.v = -mouse_report.y;
      mouse_report.x = mouse_report.y = 0;
    }
    else{
      mouse_report.x = mouse_report.x;
      mouse_report.y = mouse_report.y;
      mouse_report.h = mouse_report.h;
      mouse_report.v = mouse_report.v;

    }
    return mouse_report;
}
#endif

// ###########################################################################
// MACROS AND MODES
// ###########################################################################

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    //set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    // BASE LAYER MACROS 
    // -----------------------------------------------------------------------
    /* case CKC_CTRLBS: // CTRL + BACKSPACE (without repetition)*/
    /*   if (record->event.pressed) {trigger_shortcut(KC_BSPC,0,1,0,0,0);} */
    /*   return false; */
    case CKC_CTRLBS: // CTRL + BACKSPACE
      if (record->event.pressed) {
        press_virtual_key_complex(KC_BSPC, KC_DEL, 0, 1, 0, 0, 0,
                                                   0, 1, 0, 0, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_BSPC: // BACKSPACE AND DEL 
      if (record->event.pressed) {press_virtual_key(KC_BSPC, KC_DEL, 0, 0, 0, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_RLOCK: // RAISE LOCK and ARROW MODE
      if (record->event.pressed) {
        if ((get_mods() & MOD_BIT(KC_LSHIFT))){layer_on(_ARROW);}
        else {layer_invert(_RAISE);}
      }
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_RSFT: // RSHIFT AND ARROW MODE
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSHIFT)){layer_on(_ARROW);} // ARROW MODE
        else{register_code(KC_RSHIFT);}                         // RSHIFT
      }
      else {clear_keyboard();}
      return false;

    // SUPER LAYER MACROS 
    // -----------------------------------------------------------------------
    case M_WS1:
      if (record->event.pressed) {trigger_shortcut(KC_1,0,0,1,0,0);}
      return false;
    case M_WS2:
      if (record->event.pressed) {trigger_shortcut(KC_2,0,0,1,0,0);}
      return false;
    case M_WS3:
      if (record->event.pressed) {trigger_shortcut(KC_3,0,0,1,0,0);}
      return false;
    case M_WS4:
      if (record->event.pressed) {trigger_shortcut(KC_4,0,0,1,0,0);}
      return false;
    case M_WS5:
      if (record->event.pressed) {trigger_shortcut(KC_5,0,0,1,0,0);}
      return false;
    case M_WS6:
      if (record->event.pressed) {trigger_shortcut(KC_6,0,0,1,0,0);}
      return false;
    case M_WS7:
      if (record->event.pressed) {trigger_shortcut(KC_7,0,0,1,0,0);}
      return false;
    case M_WS8:
      if (record->event.pressed) {trigger_shortcut(KC_8,0,0,1,0,0);}
      return false;
    case F_WL:
      if (record->event.pressed) {trigger_shortcut(KC_LEFT,0,0,1,0,0);}
      return false;
    case F_WD:
      if (record->event.pressed) {trigger_shortcut(KC_DOWN,0,0,1,0,0);}
      return false;
    case F_WU:
      if (record->event.pressed) {trigger_shortcut(KC_UP,0,0,1,0,0);}
      return false;
    case F_WR:
      if (record->event.pressed) {trigger_shortcut(KC_RIGHT,0,0,1,0,0);}
      return false;
    case M_LOCK:
     if (record->event.pressed) {trigger_shortcut(KC_L,1,0,1,0,0);}
     return false;
    case M_PWMENU:
      if (record->event.pressed) {trigger_shortcut(KC_E,1,0,1,0,0);}
      return false;
    case I3_LYM:
     if (record->event.pressed) {trigger_shortcut(KC_F9,0,0,1,0,0);}
     return false;
    case M_HELP:
      if (record->event.pressed) {trigger_shortcut(KC_H,1,0,1,0,0);}
      return false;
    case M_VIM_HELP:
      if (record->event.pressed) {trigger_shortcut(KC_V,1,0,1,0,0);}
      return false;
    case I3_FS:
      if (record->event.pressed) {trigger_shortcut(KC_F,0,0,1,0,0);}
      return false;
    case I3_DISPLAYS: 
      if (record->event.pressed) {trigger_shortcut(KC_D,1,0,1,0,0);}
      return false;
    case I3_SCREENSHOT:
      if (record->event.pressed) {trigger_shortcut(KC_S,1,0,1,0,0);}
      return false;
   case I3_RESIZE:
      if (record->event.pressed) {trigger_shortcut(KC_R,0,0,1,0,0);}
      return false;
   case I3_MOVE:
      if (record->event.pressed) {trigger_shortcut(KC_A,1,0,1,0,0);}
      return false;
    case I3_SPAD:
      if (record->event.pressed) {trigger_shortcut(ES_MINS,0,0,1,0,0);}
      return false;
    case I3_WINTAB:
      if (record->event.pressed) {trigger_shortcut(KC_TAB,0,0,1,0,0);}
      return false;
    case I3_KILL:
      if (record->event.pressed) {
        press_virtual_key_complex(KC_NO, KC_Q, 1, 0, 1, 0, 0,
                                               1, 0, 1, 0, 0);
        clear_keyboard(); // Don't repeat
      }
      return false;
    case I3_XKILL:
      if (record->event.pressed) {trigger_shortcut(KC_X,1,0,1,0,0);}
    case I3_PW:
      if (record->event.pressed) {trigger_shortcut(KC_PGUP,0,0,1,0,0);}
      return false;
    case I3_NW:
      if (record->event.pressed) {trigger_shortcut(KC_PGDOWN,0,0,1,0,0);}
      return false;
    case I3_RESET:
      if (record->event.pressed) {
        trigger_shortcut(KC_C,1,0,1,0,0);
        trigger_shortcut(KC_R,1,0,1,0,0);
      }
     return false;
    case I3_FLOAT:
      if (record->event.pressed) {trigger_shortcut(KC_SPACE,1,0,1,0,0);}

    //  LOWER LAYER MACROS 
    // -----------------------------------------------------------------------
    case CKC_ACCENT: // ´ and `
      if (record->event.pressed) {press_virtual_key(ES_ACUT, ES_GRV, 0, 0, 0, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_HASH: // #
      if (record->event.pressed) {press_virtual_key(ES_3, ES_4, 0, 1, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_QUOT: // ' and · (bullet)
      if (record->event.pressed) {press_virtual_key(ES_QUOT, ES_3, 0, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_DQUOT: // " and ¨ (dieresis)
      if (record->event.pressed) {press_virtual_key(ES_2, ES_ACUT, 1, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_QMA: // ? and ¿
      if (record->event.pressed) {press_virtual_key(ES_QUOT, ES_IEXL, 1, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_EXCLAM: // ! and ¡
      if (record->event.pressed) {press_virtual_key(ES_1, ES_IEXL, 1, 0, 0, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_PERC: // % and ¬
      if (record->event.pressed) {press_virtual_key(ES_5, ES_6, 1, 0, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_PLUS: // +
      if (record->event.pressed) {press_virtual_key(ES_PLUS, ES_2, 0, 0, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_MINUS: // - and _ 
      if (record->event.pressed) {press_virtual_key(ES_MINS, ES_MINS, 0, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_ASTERISK: // * and ^
      if (record->event.pressed) {press_virtual_key(ES_PLUS, ES_GRV, 1, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_SLASH: // '/' and '\'
      if (record->event.pressed) {press_virtual_key(ES_7, ES_MORD, 1, 0, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_EQUAL: // =
      if (record->event.pressed) {press_virtual_key(ES_0, ES_0, 1, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_LESS: // < and ←
      if (record->event.pressed) {press_virtual_key(ES_LABK, KC_Y, 0, 0, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_MORE: // > and →
      if (record->event.pressed) {press_virtual_key(ES_LABK, KC_I, 1, 0, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_O_PAR: // ( and €
      if (record->event.pressed) {press_virtual_key(ES_8, ES_E, 1, 0, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_C_PAR: // ) and $
      if (record->event.pressed) {press_virtual_key(ES_9, KC_4, 1, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_AND: // & and ª 
      if (record->event.pressed) {press_virtual_key(ES_6, ES_MORD, 1, 0, 1, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_OR: // || and º 
      if (record->event.pressed) {press_virtual_key(ES_1, ES_MORD, 0, 1, 0, 0);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_O_CUR: // { 
      if (record->event.pressed) {press_virtual_key(ES_ACUT, ES_ACUT, 0, 1, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_C_CUR: // }
      if (record->event.pressed) {press_virtual_key(ES_CCED, ES_CCED, 0, 1, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_O_BRK: // [
      if (record->event.pressed) {press_virtual_key(ES_GRV, ES_GRV, 0, 1, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;
    case CKC_C_BRK: // ]
      if (record->event.pressed) {press_virtual_key(ES_PLUS, ES_PLUS, 0, 1, 0, 1);}
      else {clear_keyboard_but_mods();}
      return false;

    // RAISE LAYER HERE
    // ----------------------------------------------------------------------
    case VIM_CIT: // change inner tag 
      if (record->event.pressed) {
        press_virtual_key(KC_C, KC_C, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_T, KC_T, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_CIP: // change inner paragraph
      if (record->event.pressed) {
        press_virtual_key(KC_C, KC_C, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_P, KC_P, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_CIS: // change inner sentence
      if (record->event.pressed) {
        press_virtual_key(KC_C, KC_C, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_S, KC_S, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_CIW: // change inner word
      if (record->event.pressed) {
        press_virtual_key(KC_C, KC_C, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_W, KC_W, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_CIB: // chnge inner block of code {}
      if (record->event.pressed) {
        press_virtual_key(KC_C, KC_C, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_I, 0, 0, 0, 0);
        press_virtual_key(KC_B, KC_B, 1, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_VIT: // visual inner tag (selection)
      if (record->event.pressed) {
        press_virtual_key(KC_V, KC_V, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_T, KC_T, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_VIP: // visual inner paragraph (selection)
      if (record->event.pressed) {
        press_virtual_key(KC_V, KC_V, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_P, KC_P, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_VIS: // visual inner sentence (selection)
      if (record->event.pressed) {
        press_virtual_key(KC_V, KC_V, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_S, KC_S, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_VIW: // visual inner word (selection)
      if (record->event.pressed) {
        press_virtual_key(KC_V, KC_V, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_W, KC_W, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;

    case VIM_VIB: // visual inner block of code {}
      if (record->event.pressed) {
        press_virtual_key(KC_V, KC_V, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_I, 0, 0, 0, 0);
        press_virtual_key(KC_B, KC_B, 1, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_DIT: // delete inner tag 
      if (record->event.pressed) {
        press_virtual_key(KC_D, KC_D, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_T, KC_T, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_DIP: // delete inner paragraph
      if (record->event.pressed) {
        press_virtual_key(KC_D, KC_D, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_P, KC_P, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_DIS: // delete inner sentence
      if (record->event.pressed) {
        press_virtual_key(KC_D, KC_D, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_S, KC_S, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_DIW: // delete inner word
      if (record->event.pressed) {
        press_virtual_key(KC_D, KC_D, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_A, 0, 0, 0, 0);
        press_virtual_key(KC_W, KC_W, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_DIB: // delete inner block of code {}
      if (record->event.pressed) {
        press_virtual_key(KC_D, KC_D, 0, 0, 0, 0);
        press_virtual_key(KC_I, KC_I, 0, 0, 0, 0);
        press_virtual_key(KC_B, KC_B, 1, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_GMD: // Go method - down [m
      if (record->event.pressed) {
        press_virtual_key(ES_PLUS, ES_PLUS, 0, 1, 0, 1);
        press_virtual_key(KC_M, KC_M, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_GMU: // Go method - up ]m
      if (record->event.pressed) {
        press_virtual_key(ES_GRV, ES_GRV, 0, 1, 0, 1);
        press_virtual_key(KC_M, KC_M, 0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_GTD: // Go tag/class - down ,c1/]] 
      if (record->event.pressed) {
        press_virtual_key(KC_COMM, ES_PLUS, 0, 0, 0, 1);
        press_virtual_key(KC_C,    ES_PLUS, 0, 0, 0, 1);
        press_virtual_key(KC_1,    KC_NO,   0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;
    case VIM_GTU: // Go tag/clss - up ,c2/[[
      if (record->event.pressed) {
        press_virtual_key(KC_COMM, ES_GRV, 0, 0, 0, 1);
        press_virtual_key(KC_C,    ES_GRV, 0, 0, 0, 1);
        press_virtual_key(KC_2,    KC_NO,  0, 0, 0, 0);
      }
      else {clear_keyboard_but_mods();}
      return false;

    // HYPER LAYER MACROS 
    // ----------------------------------------------------------------------
   case M_CBACKUP:
      if (record->event.pressed) {trigger_shortcut(KC_F11,0,0,1,0,0);}
      return false;
    case M_UPDATE_PACKAGES:
      if (record->event.pressed) {trigger_shortcut(KC_B,0,1,1,0,0);}
      return false;
    case M_ROFI:
      if (record->event.pressed) {trigger_shortcut(KC_D,0,0,1,0,0);}
      return false;
    case M_ROFI_SHORTCUTS:
      if (record->event.pressed) {trigger_shortcut(KC_S,0,1,1,0,0);}
      return false;
    case M_ROFI_EMOJI:
      if (record->event.pressed) {trigger_shortcut(KC_E,0,1,1,0,0);}
      return false;
    case M_CALC:
      if (record->event.pressed) {trigger_shortcut(KC_F8,0,0,1,0,0);}
      return false;
    case M_ROFI_MANUALS:
      if (record->event.pressed) {trigger_shortcut(KC_M,0,1,1,0,0);}
      return false;
    case M_ROFI_DOCS:
      // if (record->event.pressed) {trigger_shortcut(KC_D,0,1,1,0,0);}
      if (record->event.pressed) {trigger_shortcut(KC_T,1,0,1,0,0);}
      return false;
    case M_ROFI_ACTIVITIES:
      //if (record->event.pressed) {trigger_shortcut(KC_A,0,1,1,0,0);}
      if (record->event.pressed) {trigger_shortcut(KC_T,0,0,1,0,0);}
      return false;
    case M_RANGER:
      if (record->event.pressed) {trigger_shortcut(KC_F1,0,0,1,0,0);}
      return false;
    case M_FILEX:
      if (record->event.pressed) {trigger_shortcut(KC_F2,0,0,1,0,0);}
      return false;
    case M_VIM:
      if (record->event.pressed) {trigger_shortcut(KC_F10,0,0,1,0,0);}
      return false;
    case M_WEATHER:
      if (record->event.pressed) {trigger_shortcut(KC_W,0,1,1,0,0);}
      return false;

    // SET LAYERS 'ON' ONLY WHILE PRESSED 
    // ----------------------------------------------------------------------
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_SUPER, _RAISE, _HYPER, 1);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_SUPER, _RAISE, _HYPER, 0);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
        rgblight_mode(RGB_current_mode);
        rgblight_step();
        RGB_current_mode = rgblight_config.mode;
      }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
        eeconfig_update_rgblight_default();
        rgblight_enable();
        RGB_current_mode = rgblight_config.mode;
      }
      #endif
    case SUPER:
      if (record->event.pressed) {
        layer_on(_SUPER);
        update_tri_layer_RGB(_SUPER, _RAISE, _HYPER, 1);
      } else {
        layer_off(_SUPER);
        update_tri_layer_RGB(_SUPER, _RAISE, _HYPER, 0);
      }

    // SPECIAL LAYERS 
    // ----------------------------------------------------------------------
    // Explanation: LShift+TAB enable arrow mode. Press again to  disable it.
    case CKC_EXIT_ARROW:
      layer_off(_ARROW);
      return false;

      break;
    }
  return true;
}

