#include QMK_KEYBOARD_H


void matrix_init_user(void) {
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


// ___ DEFINES __________________________________________________________________________ 
// layers
/* #define L_NAV LT(_NAV, KC_ENT) */        // removed enter key from this LT
#define L_NAV MO(_NAV)
#define L_NUM LT(_NUM, KC_BSPC)


// cosmetic
#define xxxxxxx KC_NO

// added space-control for right space key
/* #define SPCCTRL MT(MOD_LCTL, KC_SPC)    // SPACE or mod CTRL toggle */
#define ENTCTL CTL_T(KC_ENT)             // replacing SPCCTRL above
#define RTAB KC_TAB                     // normal tab
//#define LTAB RSFT(KC_TAB)               // tab back to the left ... currently not used


// COPY and PASTE
#define COPY LCTL(KC_C) // urxvt copy
#define PAST LCTL(KC_V)
#define UCOP LCTL(LALT(KC_C)) // urxvt copy
#define UPAS LCTL(LALT(KC_V)) // urxvtv paste


// awesome shortcuts
// plus a tap dance for moving between and resizing clients
#define AW_1 LGUI(KC_1)             // screen 1
#define AW_2 LGUI(KC_2)             // screen 2
#define AW_3 LGUI(KC_3)             // screen 3
#define AW_4 LGUI(KC_4)             // screen 4
#define AW_5 LGUI(KC_5)             // screen 5
#define AW_6 LGUI(KC_6)             // screen 6

#define AW_LAY LGUI(KC_SPC)         // next layout
#define AW_IS LGUI(LCTL(KC_J))      // increase gap
#define AW_DS LGUI(LCTL(KC_K))      // decrease gap
#define AW_FS LGUI(KC_F)            // full 

#define AW_RN LGUI(KC_R)            // run ...rofi 
#define AW_MN LGUI(KC_W)            // menu
                                    //
#define AW_CON LGUI(KC_ENT)         // new terminal
#define AW_QT LGUI(LSFT(KC_C))      // kill

#define AW_LK LGUI(LCTL(KC_A))      // lock screen
#define AW_TL LGUI(LSFT(KC_A))      // toggle lock screen for video stuff ... toggles compton as well
#define AW_WP LGUI(KC_C)            // change to next wallpaper

// home row SHIFT and CTRL mods.
// moving the CTRL mods to row UNDER shift mods as easy roll over typos
#define T_LSFT MT(MOD_LSFT, KC_T)
#define N_LSFT MT(MOD_LSFT, KC_N)
/* #define R_CTRL MT(MOD_LCTL, KC_R) */
/* #define E_CTRL MT(MOD_LCTL, KC_E) */

/* #define T_LSFT MT(MOD_LSFT, KC_T) */
/* #define N_LSFT MT(MOD_LSFT, KC_N) */
/* #define D_CTRL MT(MOD_LCTL, KC_D) */
/* #define H_CTRL MT(MOD_LCTL, KC_H) */
#define CONF LT(_CONF, KC_Q)
// #define A
// _LT LGUI(KC_J)         // previous client
// #define AW_RT LGUI(KC_K)         // next client
// #define AW_SL LGUI(LSFT(KC_J))   // switch previous client
// #define AW_SR LGUI(LSFT(KC_K))   // switch next client
// #define AW_IW LGUI(KC_H)         // increase size, columns
// #define AW_DW LGUI(KC_L)         // decrease size, columns
// #define AW_TAB LGUI(KC_TAB)      // next screen
// #define AW_FS LGUI(KC_F)         // full screen
// #define AW_FL LGUI(LCTL(KC_SPC)) // float client


enum ferris_layers {
  /* _QWERT, */
  _ISRT,
  _NUM,
  _NAV, 
  _CONF,
};

/* enum ferris_keycodes { */
/* //  QWERT = 0, */
/* //  ISRT, */
/*   LOGIN = SAFE_RANGE,         // switch keymap */
/*   /1* SWMAP, *1/ */
/*   /1* PASSWD, *1/ */
/*   /1* SECRT, *1/ */
/* //  NEMO, */
/* // TILD, */
/* // CIRC, */
/* }; */

enum {
    SPCSFT = 0,
    LEVEL,

    // tap dance brackets
    RND,
    SQR,
    CUR,

    // tad dances for symbols
    PIPE,           // slash, questionmark, backslash TD
    MINS,           // minus and underscore
    QUOT,           // quote, double quote and dead key grave
    COLN,           // for tap dance on colon key: colon, semicolon, pipe
    DOTCOM,         // dot comma tap dance for numpad
    ASTSLA,         // asterix slash tap dance for numpad
    TILD,           // TILDE or TILDE with SPACE
    CIRC,           // CIRC or CIRC with SPACE
    GRVE,           // GRAVE or GRAVE with SPACE

    // security stuff
    SECUR,          // passwd on double, secret on triple
    SWMAP,          // swap map: QWERTY to ISRT toggle
    LOGIN,

    // double tap navigation
    LE,             // left and home
    RE,             // right and end
    UP,             // up and pgup
    DN,             // down and pgdown

    // awesome change, more or resize client tap dance
    // awesome change, more or resize client tap dance
    // awesome change, more or resize client tap dance
    AWLE,           // next client left or re size client
    AWRE,           // previous client right or re size client
    AW1,            // for window switching using tap dance/ double tap
    AW2,
    AW3,
    AW4,
    AW5,
    AW6,
    };


/* ____________________________________________________________________________________ */
/* ___COMBOS __________________________________________________________________________ */
/* JK combo for nvim like esc */
/* A/U/O umlaute          */
enum _combos {
  NVIM_ESC,
  A_UML,
  O_UML,
  U_UML,
  COMBO_LENGTH                      // add this for calculating length of array below
};

uint16_t COMBO_LEN = COMBO_LENGTH;  // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM nvim_esc_combo[] = {KC_K, KC_Z, COMBO_END};
const uint16_t PROGMEM a_uml_combo[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM u_uml_combo[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM o_uml_combo[] = {KC_E, KC_O, COMBO_END};

combo_t key_combos[] = {
  [NVIM_ESC] = COMBO_ACTION(nvim_esc_combo),
  [A_UML] = COMBO_ACTION(a_uml_combo),
  [U_UML] = COMBO_ACTION(u_uml_combo),
  [O_UML] = COMBO_ACTION(o_uml_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case NVIM_ESC:
      if (pressed) {
        tap_code(KC_ESC);
        tap_code(KC_RGHT);
      }
      break;
    case A_UML:
      if (pressed) {
          register_code16 (KC_RSFT);    // this is using right shift so left shift can be used for capital letters.
          register_code16 (KC_QUOT);
          unregister_code16 (KC_RSFT);
          register_code16 (KC_A);
          unregister_code16 (KC_A);
      }
      break;
    case U_UML:
      if (pressed) {
          register_code16 (KC_RSFT);
          register_code16 (KC_QUOT);
          unregister_code16 (KC_RSFT);
          register_code16 (KC_U);
          unregister_code16 (KC_U);
      }
      break;
    case O_UML:
      if (pressed) {
          register_code16 (KC_RSFT);
          register_code16 (KC_QUOT);
          unregister_code16 (KC_RSFT);
          register_code16 (KC_O);
          unregister_code16 (KC_O);
      }
      break;
  }
}

/* ____________________________________________________________________________________ */
/* ___TAP DANCES ______________________________________________________________________ */

/* ___ TAP DANCE LOGIC ________________________________________________________________ */

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void spcsft_finished (qk_tap_dance_state_t *state, void *user_data);
void spcsft_reset    (qk_tap_dance_state_t *state, void *user_data);
/* void level_finished  (qk_tap_dance_state_t *state, void *user_data); */
/* void level_reset     (qk_tap_dance_state_t *state, void *user_data); */


int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
  else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
  else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = { .is_press_action = true,
  .state = 0
};



/* ___ SPACE SHIFT CAPSWORD  ________________________________________________________________ */
void spcsft_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_SPC); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: caps_word_on(); break;
    case DOUBLE_HOLD: break;
    case DOUBLE_SINGLE_TAP: register_code(KC_SPC); unregister_code(KC_SPC); register_code(KC_SPC); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void spcsft_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SPC); break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: unregister_code(KC_SPC); unregister_code(KC_SPC); break;
    case DOUBLE_HOLD: break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_SPC);
  }
  xtap_state.state = 0;
}

/* ___ LAYER SWITCH _____________________________________________________________________ */
// disabled one is the planck version
uint8_t mod_state;
/* __ ; : | __________DANCE COLON____________________________________________________ */
/* three taps ; : |                              */
void dance_colon_each (qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            del_mods(MOD_MASK_SHIFT);
            tap_code16(KC_SCLN);
            break;
        case 2:
            del_mods(MOD_MASK_SHIFT);
            tap_code16(LSFT(KC_SCLN));
            break;
        case 3:
            del_mods(MOD_MASK_SHIFT);
            tap_code16(LSFT(KC_BSLS));
            break;
        }
}

/* ____________ DANCE QUOTE____________________________________________________ */
void dance_quote_each (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_QUOT);
      tap_code16(KC_SPC);
    break;
  case 2:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(LSFT(KC_QUOT));
      tap_code16(KC_SPC);
    break;
  case 3:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_GRAVE);       // dead key
      tap_code16(KC_SPC);
      reset_tap_dance (state);
    break;
  }
}

/* __/ ? \ |__________DANCE PIPE____________________________________________________ */
void dance_pipe_each (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_SLSH);
//      tap_code16(KC_SPC);
    break;
  case 2:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(LSFT(KC_SLSH));
//      tap_code16(KC_SPC);
    break;
  case 3:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_BSLS);
      reset_tap_dance (state);
    break;
  }
}


/* ___________DANCE CIRC ____________________________________________________ */
void dance_circ (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(LSFT(KC_6));
      tap_code16(KC_SPC);
    break;
  case 2:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(LSFT(KC_6));
    break;
  case 3:
      reset_tap_dance (state);
    break;
  }
}
/* ___________DANCE TILD ____________________________________________________ */
void dance_tild (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(LSFT(KC_GRAVE));
      tap_code16(KC_SPC);
    break;
  case 2:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(LSFT(KC_GRAVE));
    break;
  case 3:
      reset_tap_dance (state);
    break;
  }
}


/* _____________________________________________________________________________ */
/* ___________DANCE GRVE ____________________________________________________ */
void dance_grve (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_GRAVE);
      tap_code16(KC_SPC);
    break;
  case 2:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(LSFT(KC_GRAVE));
//      tap_code16(KC_SPC);
    break;
  case 3:
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_BSLS);
      reset_tap_dance (state);
    break;
  }
}



/* _____________________________________________________________________________ */
/* ___________DANCE SECURE ____________________________________________________ */
void dance_secure (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
        break;
  case 2:
        SEND_STRING("placebo\n");
        break;
  case 3:
       SEND_STRING("AlabamaDrivingLicense\n");
       reset_tap_dance (state);
       break;
  }
}



/* _____________________________________________________________________________ */
/* ___________DANCE SWAP MAP ____________________________________________________ */
// no longer needed as QWERTY layer removed
/* void dance_swap_map (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->count) { */
/*   case 1: */
/*     break; */
/*   case 2: */
/* //      del_mods(MOD_MASK_SHIFT); */
/*       if (layer_state_is(_ISRT)) { */
/*           /1* SEND_STRING("ISRT is on. switching off ISRT\n"); *1/ */
/*           layer_off(_ISRT); */
/*       } else { */
/*           /1* SEND_STRING("ISRT is off. switching on ISRT\n"); *1/ */
/*           layer_on(_ISRT); */
/*       } */
/*       break; */
/*   case 3: */
/*       reset_tap_dance (state); */
/*       break; */
/*   } */
/* } */


/* _____________________________________________________________________________ */
/* ___________ TAP DANCES for AWESOMEWM window switching _______________________ */
void tdaw1 (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("1"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("1")));   // could add to move to the respective screen
    reset_tap_dance (state);
    break;
  }
}
/* ---------------- */


void tdaw2 (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("2"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("2")));   // could add to move to the respective screen
    reset_tap_dance (state);
    break;
  }
}
/* ---------------- */

void tdaw3 (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("3"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("3")));   // could add to move to the respective screen
    reset_tap_dance (state);
    break;
  }
}
/* ---------------- */

void tdaw4 (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("4"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("4")));   // could add to move to the respective screen
    reset_tap_dance (state);
    break;
  }
}
/* ---------------- */

void tdaw5 (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("5"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("5")));   // could add to move to the respective screen
    reset_tap_dance (state);
    break;
  }
}
/* ---------------- */

void tdaw6 (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("6"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("6")));   // could add to move to the respective screen
    reset_tap_dance (state);
    break;
  }
}
/* ---------------- */

/* _____________________________________________________________________________ */
/* ___________DANCE LOGIN ____________________________________________________ */
void dance_login (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    break;
  case 2:
      del_mods(MOD_MASK_SHIFT);
      SEND_STRING("markus\n");
      break;
  case 3:
      tap_code16(LGUI(LCTL(KC_A)));
      reset_tap_dance (state);
      break;
  }
}

/* _____________________________________________________________________________ */
/* _____________________________________________________________________________ */
/* ___ ALL AWESOMEWM DANCE FUNCTIONS ___________________________________________ */
void aw_left_each (qk_tap_dance_state_t *state, void *user_data) {

  switch (state->count) {
  case 1:
    // next client
    tap_code16(LGUI(KC_J));
    break;
  case 2:
    // switch with next client
    tap_code16(LGUI(KC_H));
    break;
  case 3:
    // increase client size
    tap_code16(LSG(KC_J));
    reset_tap_dance (state);
    break;
  }
}

void aw_right_each (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    // previous client
    tap_code16(LGUI(KC_K));
    break;
  case 2:
    // switch with previous client
    tap_code16(LGUI(KC_L));
    break;
  case 3:
    // decrease client size
    tap_code16(LSG(KC_K));
    reset_tap_dance (state);
    break;
  }
}



/* _____________________________________________________________________________ */
/* ___ ALL BRACKET DANCE FUNCTIONS _____________________________________________ */
void dance_rnd_brk_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 1:       // single tap .. open braket
          register_code (KC_LSFT); // send (
          register_code (KC_9);
          break;
      case 2:       // double tap ..close braket
          register_code (KC_LSFT);
          register_code (KC_0);
          break;
      case 3:
          register_code (KC_LSFT);
          register_code (KC_9); // send (
          register_code (KC_0); // send )
          unregister_code (KC_LSFT);
          register_code (KC_LEFT);
          break;
  }
}

/* ________________________________________________________________________ */
void dance_rnd_brk_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 1:
          unregister_code (KC_LSFT); // send (
          unregister_code (KC_9);
          break;
      case 2:
          unregister_code (KC_LSFT);
          unregister_code (KC_0);
          break;
      case 3:
          unregister_code (KC_9); // send (
          unregister_code (KC_0); // send )
          unregister_code (KC_LEFT);
          break;
  }
}

/* ============ SQUARE BRACKET =============================================*/
void dance_sqr_brk_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 1:
          unregister_code (KC_LSFT);
          register_code (KC_LBRC);
          break;
      case 2:
          unregister_code (KC_LSFT);
          register_code (KC_RBRC);
          break;
      case 3:
          unregister_code (KC_LSFT);
          register_code (KC_LBRC);
          register_code (KC_RBRC);
          register_code (KC_LEFT);
          break;
  }
}

void dance_sqr_brk_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 1:
          unregister_code(KC_LBRC);
          break;
      case 2:
          unregister_code (KC_RBRC);
          break;
      case 3:
          unregister_code (KC_LBRC);
          unregister_code (KC_RBRC);
          unregister_code (KC_LBRC); // send [
          unregister_code (KC_RBRC); // send ]
          unregister_code (KC_LEFT); // send LEFT
          break;
  }
}


void dance_cur_brk_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 1:                           // send curly bracket
          // SEND_STRING("{");
          register_code(KC_LSFT);
          register_code (KC_LBRC);
    // register_code (KC_LBRC);         // send {
          break;
      case 2:
          register_code(KC_LSFT);
          register_code (KC_RBRC);
          // SEND_STRING("]");
          break;
      case 3:
          // SEND_STRING("[]"SS_TAP(X_LEFT));
          register_code (KC_LSFT);
          register_code (KC_LBRC);
          register_code (KC_RBRC);
          unregister_code (KC_LSFT);
          register_code (KC_LEFT);
          break; // on triple tap
  }
}

void dance_cur_brk_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 1:
          unregister_code (KC_LSFT);
          unregister_code (KC_LBRC);
          break;
      case 2:                           // on double tab
          unregister_code (KC_LSFT);
          unregister_code (KC_RBRC);
          break;
      case 3:                           // on triple tap
          unregister_code (KC_LSFT);
          unregister_code (KC_LBRC); // send {
          unregister_code (KC_RBRC); // send }
          unregister_code (KC_LEFT); // send LEFT
          break;
  }
}


/* ___ ALL TAP DANCE FUNCTIONS _________________________________________________ */
//All tap dance functions would go here.

qk_tap_dance_action_t tap_dance_actions[] = {
    // navigation
    [LE] =      ACTION_TAP_DANCE_DOUBLE (KC_LEFT,C(KC_LEFT)),
    [RE] =      ACTION_TAP_DANCE_DOUBLE (KC_RGHT,C(KC_RGHT)),
    [UP] =      ACTION_TAP_DANCE_DOUBLE (KC_UP,KC_PGUP),
    [DN] =      ACTION_TAP_DANCE_DOUBLE (KC_DOWN,KC_PGDN),

    // brackets
    [RND] =     ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rnd_brk_finished, dance_rnd_brk_reset),
    [SQR] =     ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_sqr_brk_finished, dance_sqr_brk_reset),
    [CUR] =    ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cur_brk_finished, dance_cur_brk_reset),

    // symbols
    [PIPE] =    ACTION_TAP_DANCE_FN (dance_pipe_each),
    [QUOT] =    ACTION_TAP_DANCE_FN (dance_quote_each),
    [MINS] =    ACTION_TAP_DANCE_DOUBLE (KC_MINS,S(KC_MINS)),
    [COLN] =    ACTION_TAP_DANCE_FN (dance_colon_each),
    [DOTCOM] =  ACTION_TAP_DANCE_DOUBLE (KC_DOT, KC_COMM),
    [ASTSLA] =  ACTION_TAP_DANCE_DOUBLE (KC_ASTR, KC_SLSH),
    [TILD] =    ACTION_TAP_DANCE_FN (dance_tild),
    [CIRC] =    ACTION_TAP_DANCE_FN (dance_circ),
    [GRVE] =    ACTION_TAP_DANCE_FN (dance_grve),

    // security stuff
    [LOGIN] =   ACTION_TAP_DANCE_FN (dance_login),
    [SECUR] =   ACTION_TAP_DANCE_FN (dance_secure),
    /* [SWMAP] =   ACTION_TAP_DANCE_FN (dance_swap_map), */     // no longer needed as QWERTY layer removed
//    [SWMAP] =   ACTION_TAP_DANCE_DOUBLE (DF(_QWERT), DF(_ISRT)),          // only dfefault keycodes work in a TD double

    // awesome client manipulation
    [AWLE] =    ACTION_TAP_DANCE_FN (aw_left_each),
    [AWRE] =    ACTION_TAP_DANCE_FN (aw_right_each),

    // thumb keys
    [SPCSFT] =  ACTION_TAP_DANCE_FN_ADVANCED (NULL, spcsft_finished, spcsft_reset),
    /* [SPCSFT] =  ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, spcsft_finished, spcsft_reset, 150), */
//    [LEVEL] =   ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, level_finished, level_reset, 150),
    [AW1] = ACTION_TAP_DANCE_FN (tdaw1),
    [AW2] = ACTION_TAP_DANCE_FN (tdaw2),
    [AW3] = ACTION_TAP_DANCE_FN (tdaw3),
    [AW4] = ACTION_TAP_DANCE_FN (tdaw4),
    [AW5] = ACTION_TAP_DANCE_FN (tdaw5),
    [AW6] = ACTION_TAP_DANCE_FN (tdaw6),
    };


/* ____________________________________________________________________________________ */
/* ___ KEYMAPS ________________________________________________________________________ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* [_QWERT] = LAYOUT( */
	/* 	      KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,     KC_I,     KC_O,    KC_P, */ 
	/* 	      KC_A,     KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,     KC_K,     KC_L,TD(COLN), */ 
	/* 		  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,TD(DOTCOM),TD(QUOT),TD(PIPE), */ 
	/* 						        TD(SPCSFT),   L_NAV,      L_NUM,  SPCCTRL), */ 
							         /* L_NAV, TD(SPCSFT),     SPCCTRL,   L_NUM), */



	[_ISRT] = LAYOUT(
		      KC_Y,     KC_C,    KC_L,    KC_M,    KC_K,       KC_Z,    KC_F,      KC_U, TD(COLN),TD(PIPE), 
		      KC_I,     KC_S,    KC_R,  T_LSFT,    KC_G,       KC_P,  N_LSFT,      KC_E,     KC_A,    KC_O, 
			  CONF,     KC_V,    KC_W,    KC_D,    KC_J,       KC_B,    KC_H, TD(DOTCOM),  KC_COMM,    KC_X, 
							          /* L_NAV, TD(SPCSFT),    SPCCTRL,   L_NUM), */
							        /* TD(SPCSFT),   L_NAV,      L_NUM,  SPCCTRL), */
							          L_NAV, TD(SPCSFT),      L_NUM,  ENTCTL),


    [_NUM] = LAYOUT(
		    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,  TD(CUR), TD(ASTSLA),    KC_7,    KC_8,    KC_9, KC_PLUS,
		    KC_PERC,TD(CIRC),TD(TILD), KC_AMPR,  TD(SQR),     KC_EQL,    KC_4,    KC_5,    KC_6, TD(MINS),
		    /* KC_PERC,    CIRC,    TILD, KC_AMPR,  TD(SQR),     KC_EQL,    KC_4,    KC_5,    KC_6, TD(MINS), */
		    xxxxxxx, TD(QUOT),TD(GRVE),TD(MINS),  TD(RND),       KC_0,    KC_1,    KC_2,    KC_3,TD(DOTCOM),
			                           /* L_NAV, TD(SPCSFT),       RTAB,   L_NUM), */
			                        /* TD(SPCSFT),    L_NAV,      L_NUM,   RTAB), */
							          L_NAV, TD(SPCSFT),      L_NUM,  RTAB),

	[_NAV] = LAYOUT(
		    TD(AW1), TD(AW2), TD(AW3), TD(AW4), TD(AW5),    TD(AW6), KC_HOME, xxxxxxx,  xxxxxxx,   AW_FS,
		      AW_IS,   AW_DS,  AW_LAY,TD(AWLE),TD(AWRE),     TD(LE),  TD(DN),  TD(UP),   TD(RE),xxxxxxx,
		      AW_QT,   AW_WP,   AW_TL,   AW_RN,   AW_MN,    xxxxxxx,  KC_END, xxxxxxx,  xxxxxxx,  AW_CON,
							          /* L_NAV, TD(SPCSFT),        RTAB,  KC_DEL), */
							        /* TD(SPCSFT),   L_NAV,      KC_DEL,   RTAB), */
							          L_NAV, TD(SPCSFT),      KC_DEL,   RTAB),


    [_CONF] = LAYOUT(
		    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,   AW_LK,
		    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,  TD(LOGIN), xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
		    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,  TD(SECUR), xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
							           xxxxxxx, xxxxxxx,    xxxxxxx, xxxxxxx),

};

/* _________________________________________________________________________________________________ */
// tri return enables _CONF when _NAV and _NUM are pressed together
/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _NUM, _NAV, _CONF); */
/* } */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      default:
       return true;

  }
}



/* using encoder map as enabled in rules.mk */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    /* [_QWERT] =  { ENCODER_CCW_CW(KC_RGHT, KC_LEFT),             ENCODER_CCW_CW(KC_DOWN, KC_UP) }, */
    [_ISRT] =   { ENCODER_CCW_CW(KC_RGHT, KC_LEFT),             ENCODER_CCW_CW(KC_DOWN, KC_UP)},    // same as QWERT
    [_NUM] =    { ENCODER_CCW_CW(LCTL(KC_RGHT), LCTL(KC_LEFT)),   }, /*  */
    [_NAV] =    { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),              ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_CONF] =   { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),              ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif
