#include QMK_KEYBOARD_H
#include <print.h>

#include "muse.h"
#include "config.h"

#define SFT_ENT  FUNC(0)    // Tap for enter, hold for right shift


// Function definitions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
};

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ALTER,
  _ACC_A,
  _ACC_E,
  _ACC_I,
  _ACC_O,
  _ACC_U,
  _ACC_C,
  // _ACCENT,
};

enum custom_keycodes {
  // Google sheets keycode
  QMKBEST = SAFE_RANGE,
  GS_IU,
  GS_ID,
  GS_IL,
  GS_IR,
  GS_DC,
  GS_DR,
  // accent
  ACC_A,
  ACC_E,
  ACC_I,
  ACC_O,
  ACC_U,
  ACC_C,
};
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define ALTER MO(_ALTER)
#define ACC_A MO(_ACC_A)
#define ACC_E MO(_ACC_E)
#define ACC_I MO(_ACC_I)
#define ACC_O MO(_ACC_O)
#define ACC_U MO(_ACC_U)
#define ACC_C MO(_ACC_C)

// #define ACCENT MO(_ACCENT)

#define ESC_ALT LT(ALTER, KC_ESC)  // Tap for ESC, hold for ALTER

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define TMP_O_CIR "00F4"
#define TMP_E_AIG "00E9"
#define TMP_E_GRV "00E8"
#define TMP_E_CIR "00EA"
#define TMP_E_TRM "00EB"
#define TMP_A_GRV "00E0"
#define TMP_A_CIR "00E2"
#define TMP_U_GRV "00F9"
#define TMP_U_CIR "00FB"
#define TMP_C_CED "00E7"
#define TMP_EURO "20AC"


#define E_AIG UC(0x00E9)
#define E_GRV UC(0x00E8)
#define E_CIR UC(0x00EA)
#define E_TRM UC(0x00EB)
#define A_GRV UC(0x00E0)
#define A_CIR UC(0x00E2)
#define U_GRV UC(0x00F9)
#define U_CIR UC(0x00FB)
#define C_CED UC(0x00E7)
#define EURO UC(0x20AC)


#define O_CIR UC(0x00F4)
#define O_CIR UC(0x00F4)
#define O_TRM UC(0x00F6)
#define I_TRM UC(0x00EF)
#define I_CIR UC(0x00EE)

#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define SPC_MAJ  MT(MOD_LSFT, KC_SPC)
#define DWN_CTL MT(MOD_LCTL, KC_PGDOWN)
// #define A_ACC  LT(ACCENT, KC_A)
// #define E_ACC  LT(ACCENT, KC_E)
// #define I_ACC  LT(ACCENT, KC_I)
// #define O_ACC  LT(ACCENT, KC_O)
// #define U_ACC  LT(ACCENT, KC_U)
// #define C_ACC  LT(ACCENT, KC_C)


#define A_ACC  LT(ACC_A, KC_A)
#define E_ACC  LT(ACC_E, KC_E)
#define I_ACC  LT(ACC_I, KC_I)
#define O_ACC  LT(ACC_O, KC_O)
#define U_ACC  LT(ACC_U, KC_U)
#define C_ACC  LT(ACC_C, KC_C)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * ESC_CTL|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ALTER | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,    KC_Q,    KC_W,    E_ACC,	  KC_R,    KC_T,     KC_Y,      U_ACC,         	 I_ACC,   O_ACC,   KC_P,    LT(ALTER, KC_ESC),
    KC_LCTL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,     KC_H,      KC_J,     		   KC_K,    KC_L,    KC_SCLN, KC_LGUI,
    KC_LSFT,   KC_Z,    KC_X,    C_ACC,    KC_V,    KC_B,     KC_N,      KC_M,     		   KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
    KC_SPC, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SPC_MAJ,  SPC_MAJ,   LT(RAISE, KC_ENT), KC_LALT, KC_LALT, KC_LCTL,   KC_RGHT
),
// BACKLIT instead of RESET
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   tab|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  -  |   =   |  {  |   }   |   [  |   ]  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
// Config Standard
    LGUI(KC_TAB),  KC_PGUP,     LCTL(KC_U), KC_UP,      LCTL(KC_O),   _______,    	_______,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_LCTL,       DWN_CTL,   KC_LEFT,    KC_DOWN,    KC_RGHT,      KC_DEL, 		  KC_BSPC,    KC_4,    KC_5,    KC_6,    KC_MINS, _______,
// Config warcraft 3
    //  KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,	  KC_5,    KC_6,     KC_Y,      U_ACC,   O_ACC,   KC_P,    LT(ALTER, KC_ESC),
    //  KC_LCTL, LCTL(KC_1),    LCTL(KC_2),    LCTL(KC_3),    LCTL(KC_4),	  LCTL(KC_5),    LCTL(KC_6),     KC_Y,      U_ACC,   O_ACC,   KC_P,    LT(ALTER, KC_ESC),
// Config warcraft 3
    KC_LSFT,       KC_GRV,      KC_QUOT,    KC_BSLS,    KC_LBRC,      KC_RBRC, 		  _______,    KC_1,    KC_2,    KC_3,    KC_EQL,  TG(_QWERTY),
    _______,   	   KC_LCTL,     KC_LALT,    KC_LGUI,   	_______,      SPC_MAJ,      SPC_MAJ,      LT(ADJUST, KC_ENT),    _______, _______, KC_LCTL, KC_VOLU
),

// [_LOWER] = LAYOUT_planck_grid(
//     LGUI(KC_TAB),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSLS,
//     KC_GRV, LGUI(KC_Z),  LGUI(KC_X), LGUI(KC_C),   LGUI(KC_V),  KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,
//     _______, _______, _______, _______, LGUI(KC_SPC), LGUI(KC_SPC), _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
// ),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_PGUP,      LCTL(KC_U),  KC_UP,      LCTL(KC_O),  _______, EURO,  KC_AMPR, 	KC_ASTR,  KC_LPRN, KC_RPRN, _______,
    KC_LCTL, DWN_CTL,    KC_LEFT,     KC_DOWN,    KC_RGHT, 	   KC_DEL, 	  KC_BSPC,  KC_DLR, KC_PERC,  KC_CIRC, KC_UNDS,  _______,
    KC_LSFT, KC_TILD,       KC_DQUO,     KC_PIPE,    KC_LCBR,     KC_RCBR, 	_______,  KC_EXLM,  KC_AT,    KC_HASH, KC_PLUS ,  KC_LSFT,
    RESET, KC_LCTL,      KC_LALT,     KC_LGUI,    ADJUST, 	   SPC_MAJ, 	SPC_MAJ,  _______,  KC_LGUI, KC_LALT, KC_LCTL, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Lclick|Rclick|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ADJUST] = LAYOUT_planck_grid(
    KC_LSFT, XXXXXXX, XXXXXXX, LCTL(KC_E)	, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_U), KC_UP, LCTL(KC_O), KC_PGUP, _______,
    RGB_HUI, RGB_HUD	, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN, _______,
    RGB_TOG, RGB_MOD, CUT, COPY, PASTE, XXXXXXX, XXXXXXX, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
    XXXXXXX, _______, _______, _______, KC_LCTL, _______, _______, KC_ENT, _______, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ALTER] = LAYOUT_planck_grid(
    KC_WAKE, _______, GS_DC,  GS_IU, GS_DR, RGB_HUI, RGB_HUD,   KC_F7,   KC_F8,    KC_F9,   KC_F10, KC_DEL ,
    _______, _______, GS_IL,  GS_ID, GS_IR, AG_NORM, _______,   KC_F4,   KC_F5,    KC_F6,   KC_F11,  DEBUG,
    _______, MUV_DE,  MUV_IN,   GS_DC,   MU_OFF,  MI_ON,   _______,   KC_F1,   KC_F2,    KC_F3,   KC_F12, RESET,
    RGB_TOG, RGB_MOD, RGB_HUI,  RGB_HUD, _______, _______, _______,   _______, KC_MUTE,  KC_VOLD, KC_VOLU, KC_MPLY
),

// [_ACC_A] = LAYOUT_planck_grid(
//     _______,  _______,  _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______,
//     _______,  _______,  A_GRV, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, A_CIR, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// [_ACC_E] = LAYOUT_planck_grid(
//     _______, _______, E_AIG,   _______, E_GRV,   _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, E_CIR,   _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// [_ACC_I] = LAYOUT_planck_grid(
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, I_TRM,   _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, I_CIR,   _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// [_ACC_O] = LAYOUT_planck_grid(
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, O_TRM,   _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, O_CIR,   _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// [_ACC_U] = LAYOUT_planck_grid(
//     _______, _______, _______, _______, _______, _______, _______, _______, U_GRV,   _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, U_CIR,   _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// [_ACC_C] = LAYOUT_planck_grid(
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, C_CED,   _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

[_ACC_A] = LAYOUT_planck_grid(
    _______,  _______,  _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______,
    _______,  _______,  _______, _______, _______,   _______, _______, _______, A_GRV, A_CIR, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_E] = LAYOUT_planck_grid(
    _______, _______, _______,   _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, E_AIG, E_GRV, E_CIR, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_I] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
    _______, _______, _______, I_CIR, I_TRM, _______, _______, _______, _______, _______,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_O] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, _______,    O_CIR,  O_TRM, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_U] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,   U_GRV,   U_CIR, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_C] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,   C_CED, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define TAPPING_TERM 200

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t my_hash_timer;
  static bool a;
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case A_ACC:
      if(record->event.pressed) {
        my_hash_timer = timer_read();
        a = true;
      } else {
        a = false;
        if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
          SEND_STRING("a"); // Change the character(s) to be sent on tap here
        }
      }
      return false;
    case KC_J:
      if(record->event.pressed) {
        if (a) 
          send_unicode_hex_string(TMP_A_AIG);
        else if (e)
          send_unicode_hex_string(TMP_E_AIG);
        else
          return true;
      }
      return false;
    // case KC_Y:
    //   if (record->event.pressed) {
    //     SEND_STRING("hellooooo");
    //   }
    //   break;
  /*
  ** integration google sheets features
  */
    case GS_IU:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL("ir")));
      }
      break;
    case GS_ID:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL("ib")));
      }
      break;
    case GS_IL:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL("ic")));
      }
      break;
    case GS_IR:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL("io")));
      }
      break;
    case GS_DC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL("ee")));
      }
      break;
    case GS_DR:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL("eD")));
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}