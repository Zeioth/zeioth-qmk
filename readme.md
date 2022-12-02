# Zeioth crkbd/corne firmware

This firmware is considerably more advanced than what you find around.
Feel free to get ideas from here, or use it as base for your own driver.

## HOW TO USE

After you clone this repo, run this inside of it:

    qmk setup

Then:

* check ./keyboards/crkbd/rev1/common/keymaps
* You will find **'zeioth_trackball_left'** and **'zeioth_trackball_right'**
* Inside each of this folders you will find a README.md with documentation.
  Enjoy!

## Cool features

* Pimoroni trackball support (if you are not gonna use it, disable it in the
  settings)
* Full RGB support.
* Macros for full integration with I3/sway.
* Instruction manuals.

## Limitations

RGB is currently disabled by default in the config file. I did this so I can pack
as much features as possibly in the little space provided by pro-micro.

If you wan't RGB, you can either use a bigger controller like nice!nano,
or just remove a couple macros you don't need from the keymap, it should fit
with rbg enabled without much effort.

Display is also disabled by default. The reason is, when using a pointing device
like pimoroni trackball, or any other, it's not possible to add logic to the
display (because only the main side can have add logic to the display in QMK,
out of the box, and we use it for pimoroni).

But if you don't use pomorini, then you can disable it and enable display
instead on both sides if you want.

## CREDITS

This firmware is based on [the work of greyhatmiddleman](https://github.com/greyhatmiddleman/qmk_firmware), who added pimoroni
trackball support to crkbd. Note: Apparently he moved the project from 'crkbd/rev1/common' to 'crkbd/keymaps'. Feel free to take his code as reference if you wan't to update that. It's not necessary at all. Just in case you have OCD or something.

## TODO

* Add cool photos
* Donations button? Never did that shit before.
