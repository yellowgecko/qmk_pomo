/*
Copyright 2021 Pierre Chevalier <pierrechevalier83@gmail.com>

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

#pragma once


// maxlayers
#define LAYER_STATE_8BIT


//#define DEBUG_MATRIX_SCAN_RATE

// Underglow configuration
#ifdef RGBLIGHT_ENABLE
//  #define RGBLIGHT_ANIMATIONS     // depreciated
  #define RGBLED_NUM 1
  #define RGB_DI_PIN F0
  #define RGBLIGHT_EFFECT_BREATHING

  /* #define RGBLIGHT_EFFECT_TWINKLE */
  /* #define RGBLIGHT_EFFECT_TWINKLE_LIFE 70 */
  /* #define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 1 */

  #define RGBLIGHT_LAYERS_RETAIN_VAL
//  #define RGBLIGHT_MODE_BREATHING 1             // 0,1,2,3
  #define RGBLIGHT_EFFECT_BREATHE_MAX 120       // max 255
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
  #define RGBLIGHT_DEFAULT_HUE 127      // 0 is red
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// reduce space - no audio, no one shots and no locking support
  #define NO_MUSIC_MODE
  #undef LOCKING_SUPPORT_ENABLE
  #undef LOCKING_RESYNC_ENABLE
  /* #define NO_ACTION_ONESHOT */
  #undef RGBLIGHT_LAYERS

#ifndef NO_DEBUG
    #define NO_DEBUG
#endif

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLED)
    #define NO_PRINT
#endif

// encoder configuration
#define ENCODERS_PAD_A { F1 }
#define ENCODERS_PAD_B { C7 }
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 4



// enable split specific sync options
#ifdef SPLIT_LAYER_STATE_ENABLE
    #undef SPLIT_LAYER_STATE_ENABLE
#endif

#ifdef SPLIT_MODS_ENABLE
    #undef SPLIT_MODS_ENABLE
#endif

/* disable standard keyboard features not needed */
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

/* one shots and other */
#define NO_ACTION_ONESHOTS
// #define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
#define DISABLE_LEADER

/* only max 8 layers */
//#define LAYER_STATE_8BIT
//#define LAYER_STATE_16BIT

// Combos
#undef COMBO_TERM
#define COMBO_TERM 35
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space
#define COMBO_ONLY_FROM_LAYER 0

// TAPPING
// Home-row mods: https://precondition.github.io/home-row-mods#tap-hold-configuration-settings
// Configure the global tapping term (default: 200ms)
#define QUICK_TAP_TERM_PER_KEY
/* #define TAPPING_TERM_PER_KEY */
/* #ifdef TAPPING_TERM_PER_KEY */
#define TAPPING_TERM 170
/* #else */
// Only for thumbs
/* #define TAPPING_TERM 180 */
/* #endif */

// Prevent normal rollover on alphas from accidentally triggering mods.
/* #define IGNORE_MOD_TAP_INTERRUPT */
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// has been depreciated and replaced by ...
#define QUICK_TAP_TERM 120
/* #define TAPPING_FORCE_HOLD */
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
// Immediately turn on layer if key is pressed quickly
#define HOLD_ON_OTHER_KEY_PRESS
