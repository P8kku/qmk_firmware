 // Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later
// custom keymap /u/P8kku
// First keymap I've defined using QMK's firmware docs, previously daily'd keyboard was a Keychron Q8
// so you'll probably see alot of influence from that layout here :')

//random keymappings so I won't forget
//KC_MINS "-"
//KC_GRV "`"
//KC_RSFT "Right Shift"

/*Previously used keybinds:

 Layer:Raise
 8 KC_8
 9 KC_9
 / KC_SLSH
 [ KC_RBRC
 ] KC_LBRC
 \ KC_BACKSLASH

*/

#include QMK_KEYBOARD_H
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
//#define SftEnt  SFT_T(KC_ENT)   // Shift when held, Enter when tapped
//#define BSCTL   LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped
//tap macro examples


//#define ZOOM_IN KC_MS_WH_UP(KC_LEFT_CTRL) //QWERTY KEYMAP ENCODER DEF
//#define ZOOM_OUT KC_MS_WH_DOWN(KC_LEFT_CTRL)
#define LW_ZOOM_IN LCTL(KC_MINUS) //LOWER MOD KEYMAP ENCODER DEF
#define LW_ZOOM_OUT LCTL(KC_EQUAL)

enum layers {
    _QWERTY,
    _FL,
    _RAISE,
    _LOWER
};

enum custom_keycodes {
  ZOOMIN = SAFE_RANGE,
  ZOOMOUT,
  LWZOOMIN,
  LWZOOMOUT
};

enum combos{
    CTLBSP_DEL,
    CTLENT_HOME,
    CTLSHFTBSPC_END,
    CTL9_LBRC,
    CTL8_RBRC,
    CTLSLSH_BKSLSH
};

/* TODO potentially use combo functionality to accomplish this?

make: ctrl+backspace='delete'
make: ctrl+enter='HOME'
make: ctrl+shift+enter='END'
make: ctrl+9='['
make: ctrl+0=']'
make: ctrl+/= '\'

*/

const uint16_t PROGMEM DELETE_DEF[] = {KC_LCTL, KC_BSPC, COMBO_END};
const uint16_t PROGMEM HOME_DEF[] = {KC_LCTL, KC_ENT, COMBO_END};
const uint16_t PROGMEM END_DEF[] = {KC_LCTL, KC_LSFT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM LBRC_DEF[] = {KC_LCTL, KC_9, COMBO_END};
const uint16_t PROGMEM RBRC_DEF[] = {KC_LCTL, KC_8, COMBO_END};
const uint16_t PROGMEM BACKSLASH_DEF[] =   {KC_LCTL, KC_SLSH, COMBO_END};

combo_t key_combos[]={

    [CTLBSP_DEL] = COMBO(DELETE_DEF, KC_DEL),
    [CTLENT_HOME] = COMBO(HOME_DEF, KC_HOME),
    [CTLSHFTBSPC_END] = COMBO(END_DEF, KC_END),
    [CTL9_LBRC] = COMBO(LBRC_DEF, KC_LBRC),
    [CTL8_RBRC] = COMBO(RBRC_DEF, KC_RBRC),
    [CTLSLSH_BKSLSH] = COMBO(BACKSLASH_DEF, KC_BACKSLASH)

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BKSPC|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Enter|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|Mute    |   |Play   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |--------|   |-------|   B  |   N  |   M  |   ,  |   .  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Space \  |RAISE | FN   | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,  KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                           KC_LGUI, KC_LALT,    LOWER, KC_SPC, KC_SPC, RAISE, MO(_FL), KC_RGUI
),

/* _FL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~`  |   F1 |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F12 |      |  DEL |BKLTSP|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |PRSCR | SCRLK|KCPAUS|      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /PG UP  /       \PG DN \  | HOME |  FN  | END |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FL] = LAYOUT(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,           KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,
    KC_F12,  _______, KC_DEL, BL_STEP,_______,_______,         _______, _______, _______, _______, _______, _______,
    KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
                           _______, _______, _______, KC_PGUP,  KC_PGDN , KC_HOME, MO(_FL), KC_END
),




/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |CMBOTGL|     |      |      |      |      |                    |      |      |      |      |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | HOME |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   |   |   _  |   +  |   {  |   }  |  /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |  END | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  QK_COMBO_TOGGLE, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, KC_DELETE,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_HOME,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BACKSLASH,
                             _______, _______, _______, _______, _______,  _______, KC_END, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |  UP  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | [    | LEFT  | Down | Right|   ew  |
 * |------+------+------+------+------+------|RGB_TOG|    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |  |      | |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  RGB_MOD, RGB_RMOD,RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_UP,    _______,    KC_0,    _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   RGB_TOG, _______,  KC_PLUS, KC_MINS, KC_EQL,  _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(LW_ZOOM_IN,LW_ZOOM_OUT) },
  [_LOWER]  = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
  [_RAISE]  = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),  ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
  [_FL] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI),  ENCODER_CCW_CW(_______, _______) }
};
#endif


layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _FL);
};

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
};
