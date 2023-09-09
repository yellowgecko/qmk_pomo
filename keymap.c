#include QMK_KEYBOARD_H


void keyboard_post_init_user(void) {
    rgblight_sethsv_at(HSV_GOLD, 0); // led 0
    rgblight_mode(0);           // set to static mode
    rgblight_disable();         // turn light off
    /* rgblight_set(); */
}
void matrix_init_user(void) {
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


// ___ DEFINES __________________________________________________________________________
// layers
#define L_NAV LT(_NAV, KC_ESC)
/* #define L_NAV MO(_NAV) */
#define L_NUM LT(_NUM, KC_BSPC)             // /*! TODO: enhance to tap hold to repeat backspace

// cosmetic
#define xxxxxxx KC_NO

// added space-control for right space key
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


#define AW_MON LGUI(LSFT(KC_M))     // switch monitor toggle
#define AW_LAY LGUI(KC_SPC)         // next layout
#define AW_IS LGUI(LCTL(KC_J))      // increase gap
#define AW_DS LGUI(LCTL(KC_K))      // decrease gap
#define AW_FS LGUI(KC_F)            // full

#define AW_RN LGUI(KC_R)            // run ...rofi
#define AW_MN LGUI(KC_W)            // menu
                                    //
#define AW_CON LGUI(KC_ENT)         // new terminal
/* #define AW_QT LGUI(LSFT(KC_C))      // kill --> became a double tap */

#define AW_LK LGUI(LCTL(KC_A))      // lock screen
#define AW_TL LGUI(LSFT(KC_A))      // toggle lock screen for video stuff ... toggles compton as well
#define AW_WP LGUI(KC_C)            // change to next wallpaper

// home row SHIFT and CTRL mods.
// moving the CTRL mods to row UNDER shift mods as easy roll over typos
#define T_LSFT MT(MOD_LSFT, KC_T)
#define N_LSFT MT(MOD_LSFT, KC_N)

#define CONF LT(_CONF, KC_Q)


// set initial RGB values
/* rgblight_setrgb_at(RGB_TEAL, 0); */
#define T10                         // 10 sec timer

enum ferris_layers {
  _ISRT,
  _NUM,
  _NAV,
  _CONF,
};

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
    ASTSLA,         // asterix slash tap dance for numpad /*! TODO: currently not used in keymap
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

    TERM,           // double tap for terminal or terminal PLUS nnn
    AWQT,           // double top to quit
    AWLE,           // next client left or re size client
    AWRE,           // previous client right or re size client
    AW1,            // for window switching using tap dance/ double tap
    AW2,
    AW3,
    AW4,
    AW5,
    AW6,
    POMO,
    ARLF,
    ARRG,
    };


/* ____________________________________________________________________________________ */
/* ___COMBOS __________________________________________________________________________ */
/* JK combo for nvim like esc */
/* A/U/O umlaute          */
enum _combos {
  /* NVIM_ESC, */
/*! TODO: find a better NVIM_ESC, maybe 'ii' */
  A_UML,
  O_UML,
  U_UML,
  COMBO_LENGTH                      // add this for calculating length of array below
};

uint16_t COMBO_LEN = COMBO_LENGTH;  // remove the COMBO_COUNT define and use this instead!

/* const uint16_t PROGMEM nvim_esc_combo[] = {KC_G, KC_P, COMBO_END}; */
const uint16_t PROGMEM a_uml_combo[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM u_uml_combo[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM o_uml_combo[] = {KC_E, KC_O, COMBO_END};

combo_t key_combos[] = {
  /* [NVIM_ESC] = COMBO_ACTION(nvim_esc_combo), */
  [A_UML] = COMBO_ACTION(a_uml_combo),
  [U_UML] = COMBO_ACTION(u_uml_combo),
  [O_UML] = COMBO_ACTION(o_uml_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    /* case NVIM_ESC: */
    /*   if (pressed) { */
    /*     tap_code(KC_ESC); */
    /*     tap_code(KC_RGHT); */
    /*   } */
    /*   break; */
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
  TD_NONE = 0,
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

int cur_dance (tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void spcsft_finished (tap_dance_state_t *state, void *user_data);
void spcsft_reset    (tap_dance_state_t *state, void *user_data);
/* void level_finished  (tap_dance_state_t *state, void *user_data); */
/* void level_reset     (tap_dance_state_t *state, void *user_data); */


int cur_dance (tap_dance_state_t *state) {
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
  .state = TD_NONE
};



/* ___ SPACE SHIFT CAPSWORD  ________________________________________________________________ */
void spcsft_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: tap_code(KC_SPC); break;
    /* case SINGLE_TAP: register_code(KC_SPC); break; */
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: caps_word_on(); break;
    case DOUBLE_HOLD: break;
    case DOUBLE_SINGLE_TAP: register_code(KC_SPC); unregister_code(KC_SPC); register_code(KC_SPC); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void spcsft_reset (tap_dance_state_t *state, void *user_data) {
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
void dance_colon_each (tap_dance_state_t *state, void *user_data) {
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
void dance_quote_each (tap_dance_state_t *state, void *user_data) {
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
void dance_pipe_each (tap_dance_state_t *state, void *user_data) {
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
void dance_circ (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    del_mods(MOD_MASK_SHIFT);
    tap_code16(LSFT(KC_6));
    break;
  case 2:
    tap_code16(KC_CIRC);
    break;
  case 3:
      reset_tap_dance (state);
    break;
  }
}
/* ___________DANCE TILD ____________________________________________________ */
void dance_tild (tap_dance_state_t *state, void *user_data) {
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
void dance_grve (tap_dance_state_t *state, void *user_data) {
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
void dance_secure (tap_dance_state_t *state, void *user_data) {
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


/* __________ terminal or nnn tap dance _____________________________________ */

 void dance_terminal (tap_dance_state_t *state, void *user_data) {
   switch (state->count) {
   case 1:
     // previous client
     SEND_STRING(SS_LGUI("\n"));
     break;
   case 2:
     SEND_STRING(SS_LGUI("\n"));
     SEND_STRING(SS_DELAY(300) "nn\n");
     reset_tap_dance (state);
     break;
   }
 }

/* _____________________________________________________________________________ */
/* ___________ TAP DANCES for AWESOMEWM window switching _______________________ */
void tdaw1 (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("1"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("1")));   // could add to move to the respective screen
    /* reset_tap_dance (state); */
    break;
  case 3:
    SEND_STRING(SS_LGUI(SS_LSFT("1")));   // could add to move to the respective screen
    SEND_STRING(SS_LGUI("1"));  // go to screen 1
    reset_tap_dance (state);
    break;
    }
}

/* ---------------- */
void tdaw2 (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("2"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("2")));   // could add to move to the respective screen
    /* reset_tap_dance (state); */
    break;
  case 3:
    SEND_STRING(SS_LGUI(SS_LSFT("2")));   // could add to move to the respective screen
    SEND_STRING(SS_LGUI("2"));  // go to screen 1
    reset_tap_dance (state);
    break;
    }
}

/* ---------------- */
void tdaw3 (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("3"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("3")));   // could add to move to the respective screen
    /* reset_tap_dance (state); */
    break;
 case 3:
    SEND_STRING(SS_LGUI(SS_LSFT("3")));   // could add to move to the respective screen
    SEND_STRING(SS_LGUI("3"));  // go to screen 1
    reset_tap_dance (state);
    break;
    }
}

/* ---------------- */
void tdaw4 (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("4"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("4")));   // could add to move to the respective screen
    /* reset_tap_dance (state); */
    break;
 case 3:
    SEND_STRING(SS_LGUI(SS_LSFT("4")));   // could add to move to the respective screen
    SEND_STRING(SS_LGUI("4"));  // go to screen 1
    reset_tap_dance (state);
    break;
    }
}

/* ---------------- */
void tdaw5 (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("5"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("5")));   // could add to move to the respective screen
    /* reset_tap_dance (state); */
    break;
 case 3:
    SEND_STRING(SS_LGUI(SS_LSFT("5")));   // could add to move to the respective screen
    SEND_STRING(SS_LGUI("5"));  // go to screen 1
    reset_tap_dance (state);
    break;
    }
}

/* ---------------- */
void tdaw6 (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    SEND_STRING(SS_LGUI("6"));  // go to screen 1
    break;
  case 2:
    SEND_STRING(SS_LGUI(SS_LSFT("6")));   // could add to move to the respective screen
    /* reset_tap_dance (state); */
    break;
  case 3:
    SEND_STRING(SS_LGUI(SS_LSFT("6")));   // could add to move to the respective screen
    SEND_STRING(SS_LGUI("6"));  // go to screen 1
    reset_tap_dance (state);
    break;
    }
}
/* ---------------- */

/* _____________________________________________________________________________ */
/* ___________DANCE LOGIN ____________________________________________________ */
void dance_login (tap_dance_state_t *state, void *user_data) {
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
void aw_left_each (tap_dance_state_t *state, void *user_data) {

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

void aw_right_each (tap_dance_state_t *state, void *user_data) {
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
void dance_rnd_brk_finished (tap_dance_state_t *state, void *user_data) {
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
void dance_rnd_brk_reset (tap_dance_state_t *state, void *user_data) {
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
void dance_sqr_brk_finished (tap_dance_state_t *state, void *user_data) {
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

void dance_sqr_brk_reset (tap_dance_state_t *state, void *user_data) {
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


void dance_cur_brk_finished (tap_dance_state_t *state, void *user_data) {
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
          // SEND_STRING("["SS_TAP(X_LEFT));
          register_code (KC_LSFT);
          register_code (KC_LBRC);
          register_code (KC_RBRC);
          unregister_code (KC_LSFT);
          register_code (KC_LEFT);
          break; // on triple tap
  }
}

void dance_cur_brk_reset (tap_dance_state_t *state, void *user_data) {
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


/* ============ NEW SENTENCE =============================================*/
void new_sentence (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 2:
          if (!(get_mods() & MOD_MASK_SHIFT )) {
              tap_code (KC_SPC);
              add_oneshot_mods(MOD_BIT(KC_LSFT));
          } else {
              tap_code (KC_DOT);
          }
          break;

      case 3:
          tap_code (KC_BSPC);
          tap_code (KC_DOT);
          tap_code (KC_DOT);
          break;

      default:
          tap_code (KC_DOT);
  }
}

void new_sentence_finsihed (tap_dance_state_t *state, void *user_data) {
    /* tap_code16 (KC_SPC); */
}

/* ============ ARRROWS =============================================*/
void arrow_left (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 2:
          tap_code16 (KC_LT);
          tap_code16 (KC_LT);
          break;

      case 3:
          tap_code16 (KC_LT);
          tap_code16 (KC_MINS);
          tap_code16 (KC_MINS);
          break;

      default:
          tap_code16 (KC_LT);
  }
}


void arrow_right (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 2:
          tap_code16 (KC_GT);
          tap_code16 (KC_GT);
          break;

      case 3:
          tap_code16 (KC_MINS);
          tap_code16 (KC_MINS);
          tap_code16 (KC_GT);
          break;

      default:
          tap_code16 (KC_GT);
  }
}


/* ____________________________________________________________________________________ */
/* ___TIMERS __________________________________________________________________________ */
/* deferred execution timers for testing */
// uint32_t t_pomo_work = 7000;     // 10 sec - 3 sec
// uint32_t t_pomo_alarm = 3000;     // 3 sec
// uint32_t t_pomo_break = 3000;   // 6 sec - 3 sec
// uint32_t t_pomo_pause = 10000;    // 10 sec

/* deferred execution timers */
uint32_t t_pomo_work = 1490000;     // 25min - 10 sec
uint32_t t_pomo_alarm = 10000;     // 10 sec
uint32_t t_pomo_break = 290000;   // 5 min - 10 sec
uint32_t t_pomo_pause = 890000;    // 15 min

uint8_t pomo_loop = 0;
bool pomo_alarm = true;
bool pomo_work = false;
deferred_token timer_run = INVALID_DEFERRED_TOKEN;
// phase w=work, s=short break, l=long break, c=canceled
typedef enum { WORK,
              BREAK,
              PAUSE,
              FINISHED,
              /* CANCELED, */
} phase;

phase pomo_phase = WORK;

bool pomo_canceled = false;

/* ___SET COLORS HELPER FUNCTIONS _______________________________________________________ */

void pomo_work_colors (void) {
          rgblight_enable_noeeprom();         // turn light on
          rgblight_sethsv_noeeprom(HSV_TEAL); // sets the color to teal/cyan without saving
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1);
          pomo_phase = WORK;
          pomo_loop += 1;
          if ( pomo_loop == 4 ) { pomo_phase = PAUSE; }
}


void pomo_alarm_colors (void) {
          rgblight_sethsv_noeeprom(HSV_RED); // sets the color to teal/cyan without saving
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 4);
          rgblight_enable_noeeprom();         // turn light on
}

void pomo_break_colors (void) {
          rgblight_sethsv_noeeprom(HSV_GOLD); // sets the color to teal/cyan without saving
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1);
          rgblight_enable_noeeprom();         // turn light on
          pomo_phase = BREAK;
}

void pomo_pause_colors (void) {
          rgblight_sethsv_noeeprom(HSV_GREEN); // sets the color to teal/cyan without saving
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 0);
          rgblight_enable_noeeprom();         // turn light on
          pomo_phase = BREAK;
          pomo_loop = 0;
}

void pomo_off (void) {
          rgblight_disable_noeeprom();         // turn light on
          pomo_loop = 0;
          pomo_alarm = true;
          cancel_deferred_exec(timer_run);
}

/* CALLBACK when timer is finished */
/* used deferred for last seconds warning */
uint32_t pomo_timer_end (uint32_t trigger_time, void *cb_arg) {
  // do i need to process alarm at end of phase?
  /* if ((pomo_alarm == true) && (pomo_phase != CANCELED)) { */
  if (pomo_alarm == true)  {
      pomo_alarm_colors();
      pomo_alarm = false;
      return t_pomo_alarm;
  }
  else {
      // reset alarm and set up next timer and increase loop counter
      /* if (pomo_loop == 4) { pomo_phase = FINISHED; } */
      /* if (pomo_loop == 4) { pomo_phase = PAUSE;} */
      pomo_alarm = true;
      // set up next timer - either break ore work
      switch(pomo_phase) {
          case WORK:
              // this is end of work timer
              pomo_break_colors();
              timer_run = defer_exec(t_pomo_break, pomo_timer_end, NULL);
                return 0;

            case BREAK:
                // this is end of break timer
                pomo_work_colors();
                timer_run = defer_exec(t_pomo_work, pomo_timer_end, NULL);
                return 0;

            case PAUSE:
                pomo_pause_colors();
                timer_run = defer_exec(t_pomo_pause, pomo_timer_end, NULL);
                /* pomo_off(); */
                return 0;

            case FINISHED:
                pomo_off();
                return 0;
        }
        return 0;
    }
}
/* bool repeat = my_deferred_functionality(); */

void pomo_start (void) {
    if (pomo_loop == 0) {
        pomo_work_colors();
        timer_run = defer_exec(t_pomo_work, pomo_timer_end, NULL);
    }
}

/* ___POMO timer tap dance _______________________________________________________ */
void pomo_timer (tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:       // start if not running
    pomo_start();
    break;
  case 2:       // stop if running
    pomo_off();
    reset_tap_dance (state);
    break;
  }
}

/* deferred_token my_token = defer_exec(10000, t10s, NULL); */
/* ___ ALL TAP DANCE FUNCTIONS _________________________________________________ */
//All tap dance functions would go here.

tap_dance_action_t tap_dance_actions[] = {
    // navigation
    [LE] =      ACTION_TAP_DANCE_DOUBLE (KC_LEFT,S(KC_LEFT)),
    [RE] =      ACTION_TAP_DANCE_DOUBLE (KC_RGHT,S(KC_RGHT)),
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

    [TERM] =    ACTION_TAP_DANCE_FN (dance_terminal),
    [AWQT] = ACTION_TAP_DANCE_DOUBLE (KC_NO, LGUI(LSFT(KC_C))),
    // security stuff
    [LOGIN] =   ACTION_TAP_DANCE_FN (dance_login),
    [SECUR] =   ACTION_TAP_DANCE_FN (dance_secure),

    // awesome client manipulation
    [AWLE] =    ACTION_TAP_DANCE_FN (aw_left_each),
    [AWRE] =    ACTION_TAP_DANCE_FN (aw_right_each),

    // thumb keys
    [SPCSFT] =  ACTION_TAP_DANCE_FN_ADVANCED (NULL, spcsft_finished, spcsft_reset),
    [AW1] = ACTION_TAP_DANCE_FN (tdaw1),
    [AW2] = ACTION_TAP_DANCE_FN (tdaw2),
    [AW3] = ACTION_TAP_DANCE_FN (tdaw3),
    [AW4] = ACTION_TAP_DANCE_FN (tdaw4),
    [AW5] = ACTION_TAP_DANCE_FN (tdaw5),
    [AW6] = ACTION_TAP_DANCE_FN (tdaw6),
    [POMO] = ACTION_TAP_DANCE_FN (pomo_timer),
    [ARLF] = ACTION_TAP_DANCE_FN (arrow_left),                  // arrow left double taps
    [ARRG] = ACTION_TAP_DANCE_FN (arrow_right),                 // arrow right double taps
    };


/* ____________________________________________________________________________________ */
/* ___ KEYMAPS ________________________________________________________________________ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_ISRT] = LAYOUT(
		      KC_Y,     KC_C,    KC_L,    KC_M,    KC_K,       KC_Z,    KC_F,     KC_U, KC_COMM, TD(PIPE),
		      KC_I,     KC_S,    KC_R,    KC_T,    KC_G,       KC_P,    KC_N,     KC_E,    KC_A,     KC_O,
		      /* KC_I,     KC_S,    KC_R,  T_LSFT,    KC_G,       KC_P,  N_LSFT,     KC_E,    KC_A,     KC_O, */
  			  CONF,     KC_V,    KC_W,    KC_D,    KC_J,       KC_B,    KC_H, TD(COLN),    KC_DOT,   KC_X,
							          TD(SPCSFT), L_NAV,       L_NUM, ENTCTL),
                                    /* L_NAV, TD(SPCSFT),    SPCCTRL,   L_NUM), */
                                    /* TD(SPCSFT),   L_NAV,      L_NUM,  SPCCTRL), */
                                    /* L_NAV, TD(SPCSFT),      L_NUM,  ENTCTL), */
                                    /* L_NAV, TD(SPCSFT), ENTCTL,    L_NUM), */



    [_NUM] = LAYOUT(
		     KC_EXLM,   KC_AT, KC_HASH, TD(CUR),   KC_DLR,       KC_PAST,    KC_7,    KC_8,    KC_9, KC_PPLS,
		     KC_AMPR,TD(ARLF),TD(ARRG), TD(SQR), TD(QUOT),       KC_SLSH,    KC_4,    KC_5,    KC_6, TD(MINS),
		    TD(CIRC),TD(TILD), KC_PERC, TD(RND), TD(GRVE),       KC_EQL,    KC_1,    KC_2,    KC_3,TD(DOTCOM),
							          TD(SPCSFT), L_NAV, L_NUM,   KC_0),
                                        /* L_NAV, TD(SPCSFT),       RTAB,   L_NUM), */
                                        /* TD(SPCSFT),    L_NAV,      L_NUM,   RTAB), */
                                        /* L_NAV,TD(SPCSFT),    RTAB,   L_NUM), */

	[_NAV] = LAYOUT(
		    TD(AW1), TD(AW2), TD(AW3), TD(AW4), TD(AW5),    TD(AW6), KC_HOME, xxxxxxx,   xxxxxxx,   AW_FS,
		      AW_IS,   AW_DS,  AW_LAY,TD(AWLE),TD(AWRE),     TD(LE),  TD(DN),  TD(UP),    TD(RE), xxxxxxx,
		      AW_WP,   AW_TL,   AW_RN,   AW_MN,TD(TERM),   TD(AWQT), KC_END, xxxxxxx, xxxxxxx, xxxxxxx,
                                        TD(SPCSFT), L_NAV, KC_DEL, RTAB),
							          /* L_NAV, TD(SPCSFT),        RTAB,  KC_DEL), */
							        /* TD(SPCSFT),   L_NAV,      KC_DEL,   RTAB), */
							          /* L_NAV, TD(SPCSFT),  RTAB,      KC_DEL), */

    [_CONF] = LAYOUT(
		    xxxxxxx, xxxxxxx, xxxxxxx,  AW_MON, xxxxxxx,    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,   AW_LK,
		    xxxxxxx, xxxxxxx, xxxxxxx,TD(POMO), xxxxxxx,  TD(LOGIN), xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
		    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,  TD(SECUR), xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
							           xxxxxxx, xxxxxxx,    xxxxxxx, xxxxxxx),

};

/* _________________________________________________________________________________________________ */
// tri return enables _CONF when _NAV and _NUM are pressed together
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _NAV, _CONF);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
          return false; // Skip all further processing of this key
      default:
       return true;

  }
}



/* using encoder map as enabled in rules.mk */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_ISRT] =   { ENCODER_CCW_CW(KC_RGHT, KC_LEFT),             ENCODER_CCW_CW(KC_DOWN, KC_UP)},    // same as QWERT
    [_NUM] =    { ENCODER_CCW_CW(LCTL(KC_RGHT), LCTL(KC_LEFT)),   }, /*  */
    [_NAV] =    { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),              ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_CONF] =   { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),              ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
};
#endif
