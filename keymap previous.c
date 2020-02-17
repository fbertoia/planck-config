#include QMK_KEYBOARD_H
#include "muse.h"

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
  _ACCENT
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ALTER MO(_ALTER)
#define ACCENT MO(_ACCENT)

#define ESC_ALT LT(ALTER, KC_ESC)  // Tap for ESC, hold for ALTER

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

// enum unicode_names {
//     E_AIG,
//     E_GRV,
//     E_CIR,
//     A_GRV,
//     U_GRV,
//     O_CIR
// };

// const uint32_t PROGMEM unicode_map[] = {
//     [E_AIG]  = 0x00C9,
//     [E_GRV] = 0x00E8,
//     [E_CIR] = 0x00EA,
//     [A_GRV] = 0x00E0,
//     [U_GRV] = 0x00F9,
//     [O_CIR] = 0x00F4
// };
#define E_AIG UC(0x00E9)
#define E_GRV UC(0x00E8)
#define E_CIR UC(0x00EA)
#define E_TRM UC(0x00EB)
#define A_GRV UC(0x00E0)
#define U_GRV UC(0x00F9)
#define U_CIR UC(0x00FB)


#define O_CIR UC(0x00F4)
#define O_TRM UC(0x00F6)
#define I_TRM UC(0x00EF)
#define I_CIR UC(0x00EE)

#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * ESC_CTL|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ALTER | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    LT(ALTER, KC_TAB),  LT(ACCENT, KC_Q),    KC_W,    LT(ACCENT, KC_E),    KC_R,    KC_T,    KC_Y,    LT(ACCENT, KC_U),    LT(ACCENT,KC_I),   LT(ACCENT, KC_O),    KC_P,    KC_BSPC,
    ALTER, LT(ACCENT, KC_A),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    MO(ALTER),   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   MT(MOD_LSFT, KC_SPC), MT(MOD_LSFT, KC_SPC),   LT(RAISE, KC_ENT),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
// BACKLIT instead of RESET

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
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   LCTL(KC_C),   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

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
    LGUI(KC_TAB),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSLS,
    KC_GRV, LGUI(KC_Z),  LGUI(KC_X), LGUI(KC_C),   LGUI(KC_V),  KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,
    _______, _______, _______, _______, LGUI(KC_SPC), LGUI(KC_SPC), _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
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
    _______, _______,   _______,KC_MS_U, _______, RGB_HUI, RGB_HUD, RGB_SAI, KC_WH_D,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, KC_MS_L,  KC_MS_D,   KC_MS_R,  AG_NORM, AG_SWAP, KC_WH_R,  KC_WH_U,  KC_WH_L,  _______,  _______,
    _______, MUV_DE,  MUV_IN,   MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_BTN1, KC_BTN2, _______, _______, RESET,
    RGB_TOG, RGB_MOD, RGB_HUI,  RGB_HUD, _______, _______, _______, _______, _______,  _______, _______,   DEBUG
),

[_ALTER] = LAYOUT_planck_grid(
    KC_LSFT, XXXXXXX, XXXXXXX, LCTL(KC_E)	, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_U), KC_UP, LCTL(KC_O), KC_PGUP, _______,
    XXXXXXX, LCTL(KC_A)	, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN, _______,
    _______, XXXXXXX, CUT, COPY, PASTE, XXXXXXX, XXXXXXX, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _______, _______, _______, KC_LCTL, KC_ENT, KC_ENT, _______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT)
),

[_ACCENT] = LAYOUT_planck_grid(
    KC_ESC,  _______,  E_AIG, _______, E_GRV,   _______, _______, _______, U_GRV,   I_TRM, O_TRM, _______,
    _______,  _______,  A_GRV, _______, E_CIR,   _______, _______, _______, _______, I_CIR, O_CIR, _______,
    _______, _______, _______, _______, E_TRM, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}
