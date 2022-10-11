
# Bootloader selection
# the original is 'caterina'  used for pro micro.
BOOTLOADER = qmk-dfu

# Build options modified from original sweep rules.mk
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite - use reset buttons instead of keys
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
UNICODE_ENABLE = no        # Unicode
AUDIO_ENABLE = no           # Audio output
WPM_ENABLE = no

# Keylogging
CONSOLE_ENABLE = no

# additional build options
SWAP_HANDS_ENABLE = no
MIDI_ENABLE = no
MUSIC_ENABLE = no

TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
DIP_SWITCH_ENABLE = no

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
# link time optimization will disable action functions and macros
#LTO_ENABLE = yes
# EXTRAFLAGS += -flto

# disable key features 
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no


VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no

