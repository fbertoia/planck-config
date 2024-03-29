#include QMK_KEYBOARD_H
#include "muse.h"
#include "config.h"
#include "password.h"

#define SFT_ENT  FUNC(0)    // Tap for enter, hold for right shift


// Function definitions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
};

enum planck_layers {
  _QWERTY,
  _QWERTY_GAME,
  _ALTER,
  _ACC_A,
  _ACC_E,
  _ACC_I,
  _ACC_O,
  _ACC_U,
  _ACC_C,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LOWER_GAME,

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
  A_GRV,
  GAME_LR,
  EMAIL_EQS,
  EMAIL_F,
  PWD_EQS,
  PWD_SSH,
  NAME,
  SURNAME,
  ADDRESS,
  SIREN,

  E_AIG,
  E_GRV,
  E_CIR,
  E_TRM,
  A_CIR,
  U_GRV,
  U_CIR,
  C_CED,
  EURO,
  O_CIR,
  O_TRM,
  I_TRM,
  I_CIR,
  EMOJI,



};

#define LOWER MO(_LOWER)
#define LOWER_GAME MO(_LOWER_GAME)
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


#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

#define SPC_MAJ  MT(MOD_LSFT, KC_SPC)
#define J_CMD  MT(MOD_LGUI, KC_J)
#define S_ALT  MT(MOD_LALT, KC_S)
#define D_CTL  MT(MOD_LCTL, KC_D)
#define K_CTL  MT(MOD_LCTL, KC_K)
#define F_CMD  MT(MOD_LGUI, KC_F)
#define L_ALT  MT(MOD_LALT, KC_L)
#define MOD_SCLN  MT(MOD_L, KC_SCLN)
#define PG_DWN_CTL  MT(MOD_LCTL, KC_PGDOWN)


#define _4_CTL  MT(MOD_LCTL, KC_4)
#define _5_ALT  MT(MOD_LALT, KC_5)
#define _6_GUI  MT(MOD_LGUI, KC_6)
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

// #define LAYER_GAME DF(LOWER_GAME)


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
    KC_LCTL,   A_ACC,   KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,            KC_K,    KC_L,    KC_SCLN, KC_LGUI,
    KC_LSFT,   KC_Z,    KC_X,    C_ACC,    KC_V,    KC_B,     KC_N,      KC_M,     		   KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
    KC_SPC, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SPC_MAJ,  SPC_MAJ,   LT(RAISE, KC_ENT), KC_LALT, KC_LALT, KC_LCTL,   EMOJI
),
[_QWERTY_GAME] = LAYOUT_planck_grid(
    KC_TAB,    KC_Q,    KC_W,    E_ACC,	  KC_R,    KC_T,     KC_Y,      U_ACC,         	 I_ACC,   O_ACC,   KC_P,    LT(ALTER, KC_ESC),
    KC_LCTL,   A_ACC,   KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,            KC_K,    KC_L,    KC_SCLN, KC_LGUI,
    KC_LSFT,   KC_Z,    KC_X,    C_ACC,    KC_V,    KC_B,     KC_N,      KC_M,     		   KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
    KC_SPC, KC_LCTL, KC_LALT, KC_LGUI, LOWER_GAME,   SPC_MAJ,  SPC_MAJ,   LT(RAISE, KC_ENT), KC_LALT, KC_LALT, KC_LCTL,   KC_RGHT
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
    _______,  _______,  A_GRV, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, A_CIR, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, LM(LOWER, MOD_LCTL), _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_E] = LAYOUT_planck_grid(
    _______, _______, E_AIG,   _______, E_GRV,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, E_CIR,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_I] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, I_TRM,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, I_CIR,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_O] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, O_TRM,   _______,
    _______, _______, _______,    _______,  _______, _______, _______, _______, _______, _______, O_CIR,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_U] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, U_GRV, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, U_CIR, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
[_ACC_C] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, C_CED,   _______, _______,  _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

[_LOWER] = LAYOUT_planck_grid(
// Config Standard
    LGUI(KC_TAB),  KC_PGUP,     LALT(KC_LEFT), KC_UP,      LALT(KC_RGHT),   KC_TAB,    	KC_LALT,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_LCTL,       PG_DWN_CTL,   KC_LEFT,    KC_DOWN,    KC_RGHT,      KC_DEL, 		  KC_BSPC,     _4_CTL,     _5_ALT,     _6_GUI,    KC_MINS, _______,
// Config warcraft 3
    //  KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,	  KC_5,    KC_6,     KC_Y,      U_ACC,   O_ACC,   KC_P,    LT(ALTER, KC_ESC),
    //  KC_LCTL, LCTL(KC_1),    LCTL(KC_2),    LCTL(KC_3),    LCTL(KC_4),	  LCTL(KC_5),    LCTL(KC_6),     KC_Y,      U_ACC,   O_ACC,   KC_P,    LT(ALTER, KC_ESC),
// Config warcraft 3
    KC_LSFT,       KC_GRAVE,      KC_QUOT,    KC_BSLS,    KC_LBRC,      KC_RBRC, 		  _______,    KC_1,    KC_2,    KC_3,    KC_EQL,  TG(_QWERTY),
    _______,   	   KC_LCTL,     KC_LALT,    KC_LGUI,   	_______,      SPC_MAJ,      SPC_MAJ,      LT(_RAISE, KC_ENT),    _______, _______, KC_LCTL, KC_VOLU
),
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_PGUP,      LALT(KC_LEFT),  KC_UP,      LALT(KC_RGHT),  _______, EURO,  KC_AMPR, 	KC_ASTR,  KC_LPRN, KC_RPRN, _______,
    KC_LCTL, PG_DWN_CTL,    KC_LEFT,     KC_DOWN,    KC_RGHT, 	   KC_DEL, 	  KC_BSPC,  KC_DLR, KC_PERC,  KC_CIRC, KC_UNDS,  _______,
    KC_LSFT, S(KC_GRAVE),       KC_DQUO,     KC_PIPE,    KC_LCBR,     KC_RCBR, 	_______,  KC_EXLM,  KC_AT,    KC_HASH, KC_PLUS ,  KC_LSFT,
    RESET, KC_LCTL,      KC_LALT,     KC_LGUI,    _______, 	   SPC_MAJ, 	SPC_MAJ,  _______,  KC_LGUI, KC_LALT, KC_LCTL, KC_MPLY
),
[_ADJUST] = LAYOUT_planck_grid(
    KC_LSFT, XXXXXXX, XXXXXXX, LALT(LGUI(KC_UP)), XXXXXXX, EMAIL_EQS, EMAIL_F, LCTL(KC_U), KC_UP, LCTL(KC_O), PWD_EQS, _______,
    RGB_HUI, XXXXXXX, LALT(LGUI(KC_LEFT)), LALT(LGUI(KC_DOWN)), LALT(LGUI(KC_RGHT)), PWD_EQS, PWD_SSH, DM_REC1, KC_F1, KC_RGHT, KC_PGDOWN, _______,
    RGB_TOG, RGB_MOD, CUT, COPY, PASTE, NAME, ADDRESS, SIREN, DM_PLY2, XXXXXXX, XXXXXXX, RESET,
    XXXXXXX, _______, _______, _______, KC_LCTL, _______, _______, KC_ENT, _______, KC_VOLD, KC_VOLU, KC_MPLY
),
[_LOWER_GAME] = LAYOUT_planck_grid(
    LGUI(KC_TAB),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSLS,
    KC_NUBS, LGUI(KC_Z),  LGUI(KC_X), LGUI(KC_C),   LGUI(KC_V),  KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,
    _______, _______, _______, _______, LGUI(KC_SPC), LGUI(KC_SPC), _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),


};

layer_state_t layer_state_set_user(layer_state_t state) {
      printf("# %lu---------%lu\n", (unsigned long)state, (unsigned long)(_ACC_A + _LOWER));
      printf("# %lu  ACC_A----%lu\n", (unsigned long)state, (unsigned long)(_ACC_A));
      printf("# %lu  LOWER----%lu\n", (unsigned long)state, (unsigned long)(_LOWER));
      printf("# %lu  LOWER----%lu\n", (unsigned long)state, (unsigned long)(LM(_LOWER, MOD_LCTL)));
      printf("# %lu  LOWER----%lu\n", (unsigned long)state, (unsigned long)(_LOWER + MOD_LCTL));


    // return update_tri_layer_state(state, _ACC_A, _LOWER, (uint8_t)(LM(_LOWER, MOD_LCTL)));
  // if (state == (_ACC_A + _LOWER))
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void process_accent(char *letter, char *accent) {
  if (!strcmp(accent, "`")) {
      register_code(KC_LALT);
      register_code(KC_GRAVE);
      unregister_code(KC_LALT);
      SEND_STRING(letter);
  } else if (!strcmp(accent, "´")) {
      SEND_STRING(SS_LALT("e"));
      SEND_STRING(letter);
  } else if (!strcmp(accent, "^")) {
      SEND_STRING(SS_LALT("i"));
      SEND_STRING(letter);
  } else if (!strcmp(accent, "ç")) {
      SEND_STRING(SS_LALT("c"));
  } else if (!strcmp(accent, "€")) {
      SEND_STRING(SS_LALT(SS_LSFT("2")));
  } else if (!strcmp(accent, "¨")) {
      SEND_STRING(SS_LALT("u"));
      SEND_STRING(letter);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool game_layer = false;
  switch (keycode) {
    case GAME_LR:
      if (record->event.pressed) {
        game_layer = !game_layer;
        set_single_persistent_default_layer(game_layer ? _QWERTY_GAME : _QWERTY);
      }
      break;
    // case A_ACC:
    //   if (record->event.pressed) {
    //     SEND_STRING("ir");
    //   }
    //   break;
    // case KC_Y:
    //   if (record->event.pressed) {
    //     SEND_STRING("hellooooo");
    //   }
    //   break;
  /*
  ** integration google sheets features
  */
//   Insert row above
    case GS_IU:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_LALT("=r")));
      break;
//  Insert row below
    case GS_ID:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_LALT("=b")));
      break;
//  Insert column left
    case GS_IL:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_LALT("=c")));
      break;
// Insert column right
    case GS_IR:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_LALT("=o")));
        SEND_STRING(SS_LALT(SS_LCTL("io")));
      break;
// Delete column
    case GS_DC:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_LALT("-c")));
      break;
// Delete row
    case GS_DR:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_LALT("-r")));
      break;
////////////////////////////////////////////////////////
    case EMAIL_F:
      if (record->event.pressed)
        SEND_STRING("frederic.bertoia@gmail.com");
      break;
    case EMAIL_EQS:
      if (record->event.pressed)
        SEND_STRING("frederic.bertoia@equisafe.io");
      break;
    case PWD_EQS:
      if (record->event.pressed)
        SEND_STRING("Qwerty12345#");
      break;
    case PWD_SSH:
      if (record->event.pressed)
        SEND_STRING(SSH_PWD_EXPORT);
      break;
    case NAME:
      if (record->event.pressed)
        SEND_STRING("Bertoia");
      break;
    case SURNAME:
      if (record->event.pressed)
        SEND_STRING("Frederic");
      break;
    case ADDRESS:
      if (record->event.pressed)
        SEND_STRING("18, rue des Capucines");
      break;
    case SIREN:
      if (record->event.pressed)
        SEND_STRING("845383645");
      break;
    case A_GRV:
      if (record->event.pressed)
        process_accent("a", "`");
      break;
    case E_AIG:
      if (record->event.pressed)
        process_accent("e", "´");
      break;
    case E_GRV:
      if (record->event.pressed)
        process_accent("e", "`");
      break;
    case E_CIR:
      if (record->event.pressed)
        process_accent("e", "^");
      break;
    case E_TRM:
      if (record->event.pressed)
        process_accent("e", "¨");
      break;
    case A_CIR:
      if (record->event.pressed)
        process_accent("a", "^");
      break;
    case U_GRV:
      if (record->event.pressed)
        process_accent("u", "`");
      break;
    case U_CIR:
      if (record->event.pressed)
        process_accent("u", "^");
      break;
    case C_CED:
      if (record->event.pressed)
        process_accent("c", "ç");
      break;
    case EURO:
      if (record->event.pressed)
        process_accent("", "€");
      break;
    case O_CIR:
      if (record->event.pressed)
        process_accent("o", "^");
      break;
    case O_TRM:
      if (record->event.pressed)
        process_accent("o", "¨");
      break;
    case I_TRM:
      if (record->event.pressed)
        process_accent("i", "¨");
      break;
    case I_CIR:
      if (record->event.pressed)
        process_accent("i", "^");
      break;
    case EMOJI:
      if (record->event.pressed)
        SEND_STRING(SS_LCTL(SS_LGUI(" ")));
  }
  return true;
}
// e = ´


void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}
