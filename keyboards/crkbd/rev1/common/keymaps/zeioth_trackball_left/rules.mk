
MOUSEKEY_ENABLE      = yes    # Mouse keys
AUTO_SHIFT_ENABLE    = yes    # Auto presses shift on key hold 
DYNAMIC_MACRO_ENABLE = no
EXTRAKEY_ENABLE      = yes 

OLED_DRIVER_ENABLE   = no 
RGBLIGHT_ENABLE      = no     # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE    = no
VIA_ENABLE           = no     # Enable VIA
LTO_ENABLE           = yes


PIMORONI_TRACKBALL_ENABLE = no

SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    SRC += pimoroni_trackball.c
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    POINTING_DEVICE_ENABLE := yes
endif
