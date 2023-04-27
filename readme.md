# Zeioth QMK drivers (crkbd/corne keyboard)

My wired keyboard firmware. Includes support for the  pimoroni trackball.


## Keymap
Optimized for bilingual programmers who work in chinese/english/spanish.
Includes a bunch of macro examples that I use to increase my productivity
in Sway/VIM particulary. It can be extended with extra layers and modes.

* base maps
  * [base](#base-colemak-dh-for-spanish)
  * [lower](#lower)
  * [lower (shifted)](#lower-shifted)
* advanced functions
  * [super](#super)
  * [raise](#raise)
  * [raise (shifted)](#raise-shifted)
  * [hyper](#hyper-super--raise)
  * [conf](#conf)
* special layers
  * [arrow layer](#arrow-layer)
* other maps
  * [alt (tmux)](#alt-tmux)
  * [alt (ranger)](#alt-ranger)
* [how to use](#how-to-use)
* [how to setup](#how-to-setup)
* [how to flash](#how-to-flash)
* [design notes](#design-notes)

-----------------------------------------------------------------------------
### BASE MAPS
-----------------------------------------------------------------------------


### BASE (colemak-dh for spanish)
```c
//         |   |   |   |               |   |   |  |
   BCSP    q   w   f   p   b       j   l   u   y  ñ     BSPC
   CTL     a   r   s   t   g       y   n   e   o  i     ´`
   SHIF    z   x   c   d   v       k   h   ,   .  ?¿    SHIF

                  SUP LOW ENT      SPA RAI ALT
//                     |                |
```

### LOWER
```c
//          |   |   |   |               |   |   |  |
    WIN     4   3   2   1   5       0   6   7   8  9     AGR
    CTL     !   #   "   '   %       +   -   *   /  =     ALT
    SHIF    <   >   (   )   &       ||  }   {   ]  [     SHIF

                  SUP LOW           BPC RAI DEL
//                     |                |
```

### LOWER (SHIFTED)
```c
//          |   |   |   |               |   |   |  |
//  WIN     |   |   |   |               |   |   |  |     AGR
    CTL     ¡   ~   ¨   ·   ¬       @   _   ^   \        ALT
    SHIF    ←   →   €   $   ª       º                    SHIF

                  SUP LOW           BSP RAI DEL
//                     |                |
```

* ALT work as ESC when tapped.
* RLOCK keeps the RAISE layer active until pressed again.

-----------------------------------------------------------------------------
### ADVANCED FUNCTIONS
-----------------------------------------------------------------------------


### SUPER
```c
// [WORKSPACES, MEDIA CONTROLS, KILL]
// [LAYOUT, SCRATCHPAD]
//         |   |   |   |                   |   |   |  |
   WIN     lok vd vu   m             gkl   p   <   >  pwd   AGR
   CTL      7   1   2   3    FS      wtab  6   5   4  8
   SHIF    dis res move scp lym      flo   |  |  sho  rst   SHIF

                  SUP LOW          BSP RAI DEL
//                     |                |
```

### SUPER (SHIFTED)
```c
// [MOVE ELEMENT]
// [MOVE WORKSPACE]
//         |   |   |   |    kl          |   |   |   |
   WIN     |   |   |   |                |   |   |   |     AGR
   CTL    mv5 mv6 mv7 mv8              mv1 mv2 mv3 mv4
   SHIF    |   |   |  mscp              |   |   |   |     SHIF

                  SUP LOW           BSP RAI DEL
//                     |                |
```

### RAISE
```c
// [ COL, PAG, (i)SELECTION, MOV]
// [ GOTO CLASS, GOTO METHOD]
//         |   |   |   |                 |   |   |   |
   WIN    ci  cip cis ciw ciB        HOM END PD  PU  |   AGR
   CTL    vit vip vis viw viB         l   d   u   r AS*
   SHIF   dit dip dis diw diB           gmd gmu gtd gtu  SHIF

                  SUP LOW              RAI ALT
//                     |                |
```


### RAISE (SHIFTED)
```c
// [(a) SELECTION]
//         |   |   |   |               |   |   |   |
   WIN    dit dip dis dip dib
   CTL    cit cip cis ciw cib
   SHIF   vit vip vis viw vib         gmd gmu gtd gtu

                  SUP LOW              RAI ALT
//                     |                |
```


### HYPER [super + raise]
```c
// [POWER]
// [MOVE WORKSPACE]
//         |   |   |   |                |   |   |   |
   wea    bk  up  sc  emo gfm      rng  lc  mu  rc  vim   man
   CTL    F11 gpt foo wof           mc  ml  md  mr  F1e   SP0
   SHIF   F4  F3  F2  F1  F5       F10  F6  F7  F8  F9    SHIF

                  SUP LOW          SP2 SP1 ALT
//                     |                |
```

### CONF
```c
// [POWER]
// [MOVE WORKSPACE]
//         |   |   |   |                |   |   |   |
              sp+ hu+ sa+ va+          mod  |   |   |
              sp- hu- sa- va-           |  hlp vhlp |
   FX      |   |   |  tog               |   |   |   |

                  SUP    SPA               ALT
//                     |                |
```

* For more info about AS look (here)[https://docs.qmk.fm/#/feature_auto_shift].

-----------------------------------------------------------------------------
### SPECIAL LAYERS
-----------------------------------------------------------------------------
### ARROW LAYER [SHIF+RLOCK]
```c
// [ARROWS]
//         |   |   |   |                   |   |   |   |
      BASE                                                      BASE

                       UP                  UP

                 LEFT DOWN RIGHT    LEFT DOWN RIGHT
//                     |                   |
```



-----------------------------------------------------------------------------
### OTHER MAPS
-----------------------------------------------------------------------------
### ALT (tmux)
```c
// [WINDOWS, PANS, KILL]
// [SCROLL, FUZZY, SHOW]
//         |   |   |   |                   |   |   |   |
   WIN     w1  w2  w3  w4 tgw        rng       su  sd  vim  AGR
   CTL     p4  p3  p2  p1 tgp             fcd ffi fh
   SHIF    ks  kw  kp  Z             ls   sw  ss            SHIF

                  SUP LOW SPA      ENT RAI ALT
//                     |                |
```
### ALT (ranger)
```c
// [POWER]
//         |   |   |   |                   |   |   |   |
   WIN                                                     AGR
   CTL     p4  p3  p2  p1 tgp             fcd ffi fh
   SHIF                                                    SHIF

                  SUP LOW SPA      ENT RAI ALT
//                     |                |
```

**Note**: On Tmux, ALT+ENT spawns a new window with 4 panes.

-----------------------------------------------------------------------------
### HOW TO USE
-----------------------------------------------------------------------------
## layers
* base: Colemak-dh standar keys.
* super: System macros. By default optimized for Manjaro I3.
* lower: Symbols.
* raise: Reserved for specific programs (vim, when on vim mode, etc)
* hyper: Rofi and programs.

## modes
The idea after modes is pretty simple: All layers remain the same, but
macros in the raise layer, which usually is reserved for vim, are replaced
by new ones. For example, if you create a "gimp" layer, you would bind your
macros there.

-----------------------------------------------------------------------------
### HOW TO SETUP QMK
-----------------------------------------------------------------------------

* `sudo pacman -S qmk`
* `sudo downgrade avr-gcc` # here choose version 8.x
* `sudo make git-submodule`   # Run en the main directory

You should be able to flash the firmware now. If you find any issue, check QMK
website because it can change from time to time. Please follow all steps,
because all of them are necessary. Also for pimoroni/cirque docs see:
./docs/feature_pointing_device.md

-----------------------------------------------------------------------------
### HOW TO FLASH
-----------------------------------------------------------------------------

Go to the root directory of qmk and run

``` sh
sudo make clean && sudo qmk flash -kb crkbd -km zeioth_trackball_right
sudo make clean && sudo qmk flash -kb crkbd -km zeioth_trackball_left
```

## Credits
This firmware used [greyhatmiddleman](https://github.com/greyhatmiddleman/crkbd-pimoroni-trackball)
as reference for the implementation of the pimoroni trackball.
