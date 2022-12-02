Zeioth keymap for [Corne Keyboard (crkbd)](https://github.com/foostan/crkbd)
---------------------------------------------------------------------------
## Keymap
Optimized for bilingual programmers who work in chinese/english/spanish.
Includes a bunch of macro examples that I use to increase my productivity
in I3/VIM particulary. It can be extended with extra layers and modes. 

* base maps
  * [base](#base-workman-for-spanish)
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
* [how to flash](#how-to-flase)
* [design notes](#design-notes)

-----------------------------------------------------------------------------
### BASE MAPS 
-----------------------------------------------------------------------------


### BASE (workman for spanish)
```c
//         |   |   |   |               |   |   |  |
   BCSP    q   d   r   w   b       j   f   u   p  ñ     BSPC 
   CTL     a   s   h   t   g       y   n   e   o  i     ´`      
   SHIF    z   x   m   c   v       k   l   ,   .  ?¿    SHIF

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
   SHIF    gap res move scp lym      flo   wp  wn FW  ri3   SHIF
   
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
   WIN    dat dap das dip dib          
   CTL    cat cap cas caw cib          
   SHIF   vat vap vas vaw vib         gmd gmu gtd gtu 

                  SUP LOW              RAI ALT
//                     |                |
```


### HYPER [super + raise] 
```c
// [POWER]
// [MOVE WORKSPACE]
//         |   |   |   |                |   |   |   |
   wea    bk  tb  sc  emo ex       rng  lc  mu  rc  vim   man 
   CTL    F11 doc act rof           mc  ml  md  mr  F1e   SP0         
   SHIF   F4  F3  F2  F1 F5        F10  F6  F7  F8  F9    SHIF

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
* base: workman standar keys.
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
### HOW TO FLASH
-----------------------------------------------------------------------------

* Install avr-gcc (8.3 and 11.x tested and working).
* go to the root directory of qmk
* run 

    ``` sh
    sudo make clean && sudo qmk flash -kb crkbd/rev1/common -km zeioth_trackball_right
    sudo make clean && sudo qmk flash -kb crkbd/rev1/common -km zeioth_trackball_left
    ```
-----------------------------------------------------------------------------
### DESIGN NOTES 
-----------------------------------------------------------------------------

