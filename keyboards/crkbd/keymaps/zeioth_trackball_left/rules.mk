
MOUSEKEY_ENABLE      = yes    # Mouse keys
AUTO_SHIFT_ENABLE    = no     # Auto presses shift on key hold 
DYNAMIC_MACRO_ENABLE = no
EXTRAKEY_ENABLE      = yes 

OLED_DRIVER_ENABLE   = no 
RGBLIGHT_ENABLE      = no     # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE    = no
VIA_ENABLE           = no     # Enable VIA
LTO_ENABLE           = yes

# Pimoroni (left side)
POINTING_DEVICE_DRIVER = pimoroni_trackball
PIMORONI_TRACKBALL_SCALE = 10  # DPI multiplier

SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \



