VIM MANUAL
=====================================

This file describe my personal vim strategies to write code (and shortcuts). For other stuff
refer to the official documentation.

* basics
  * [verbs](#verbs)
  * [modifiers](#modifiers)
  * [nouns](#nouns)
  * [grammar examples](#grammar-examples)
  * [move](#move)
  * [motions](#motions)
  * [copy paste](#copy-paste)
  * [root keys](#root-keys)
  * [lead keys](#lead-keys)
  * [ctrl shortcuts](#ctrl-shortcuts)
  * [registers](#registers)
* strategies
  * [search and replace](#search-and-replace)
  * [buffers](#buffers)
  * [coding](#coding)
* strategies for border cases
  * [align elements](#align-elements)
  * [debugging/compiling](#debuggingcompiling)

VERBS
-------------------------------------

Operation to perform. 

```
i: insert before selection.
a: append after selection.
c: change.
r: replace a character.
y: yank.
p: paste.
```

MODIFIERS
-------------------------------------

They can be preceeded by a number, to indicate the n of elements affected.

```text
i: inside 
a: around
t: until (inside)
f: until (around) 
/: until the search term (inside)
```

NOUNS
-------------------------------------

Subject of the operation.

```text
w: word.
s: sentence.
p: paragraph.
t: tag.
b: block of code bewteen ().
B: block of code bewteen {}.
```

GRAMMAR EXAMPLES
-------------------------------------

```text
ciw: change inside word.
cis: change inside sentence.
cip: change inside paragraph.
cit: change inside tag.
* Insteas of c, you can use any other verb, like d for delete, y to yank...


ci': change inside ''
ci": change inside ""
ci<: change inside <


d2iw: delete 2 inside words. 
c5aw: change 5 words. 
df{: delete until {
dt{: delete until {, non-inclusive.
d/potato: Delete until the word potato, non-inclusive.


```


MOVE
-------------------------------------
Press shift to ignore separators like commas.
```text
w:  prev sentence.
b:  prev sentence.
e:  last char of the next word..
```


MOTIONS
-------------------------------------

Special keys to move faster in some scenarios.

```text
%:   find partner ([{< 
):   next sentence.
(:   prev sentence.
}:   next paragraph
{:   prev paragreaph
]]:  next class.
[[:  previous class.
]m:  next method.
[m:  prev method.
12n: moves the cursor 12 lines down.
12e: moves the cursor 12 lines up.
```

COPY PASTE
-------------------------------------

Yank keys

```text
KEY             ACTION

y               yank text
ctrl+y          yank to system's clipboard
vy              yank in visual mode
```

Paste keys

```text
KEY             ACTION

p               paste after
P               paste before
ctrl+p          paste from system's clipboard

ñ               yankstack+
Ñ               yankstack-
```

ROOT KEYS
--------------------------------------

Standar vim with these changes.

```text
h <-> y
j <-> n
k <-> e
l <-> o
```

LEAD KEYS
---------------------------------------

```vim
let g:lead_maps = {
  \'name': "<Lead>",
  \'<CR>': "Turn off    (highlights)",
  \'b': "buffers     (fuzzy list)",
  \'ba': "buffers all (delete)",
  \'bd': "buffer (delete)",
  \'c': {
    \'name': "[COC]",
  \},
  \'d': "diff   (toggle)",
  \'e': "edit   (vim settings)",
  \'f': "open   (any buffer)",
  \'g': "open (prev buffer)",
  \'o': "open (recent buffer)",
  \'r': "ranger   (open)",
  \'s': "sessions (fuzzy)",
  \'t': {
    \'name': "[TABS]",
  \},
  \'w': "write",
  \'z': "zen mode",
\}
```

CTRL SHORTCUTS
--------------------------------------

```vim
let g:ctrl_maps = {
  \'name': "CTRL keymap",
  \'<c-q>': "Show ctrl keybindings",
  \'<c-i>': "retrace pos ->",
  \'<c-0>': "retrace pos <-",
  \'<c-r>': "redo",
  \'<c-v>': "v-block",
  \'<c-w>': "window",
  \'<c-w>-h': "v-split",
  \'<c-w>-v': "v-split",
  \'<c-w><c-w>': "toggle window",
\}
```

REGISTERS
--------------------------------------

We use registers as a clipboard.

```text
REGISTERS
"anykey           Enables a register. You can yank or paste on it.

EXAMPLE
"ay               Yank entry 1
"sy               Yank entry 2

"ap               Paste entry 1
"sp               Paste entry 2

We use yankstack instead
Ctrl+p            Cycles though the n last yanks
```

STRATEGIES
-------------------------------------------

# GENERAL STRATEGY

The most eficiente cross scenario way to move in vim would be

```text
MOTION          MEANING
12e             go 12 lines up
/(as            search for '(as' and press enter
v/os)c          select until 'os)' and change
```

Just remember you can search during a visual selection.


# SEARCH AND REPLACE

99% of the time the time we'll only use

* search <space>
* search in project ,<space>
* replace ":%s/foo/bar/g" ('c' to confirm individually)

Border cases are

* Replace in project ,ar

```text
  KEY          ACTION                 CMD
  ,space       search in project      Farf foo bar **/*.py  (alias)
  ,as          Search in project      Farf foo far **/*.py
  ,ar          replace in project     Farr foo far **/*.py
  ,au          Undo changes           Farundo

FAR KEYBINDINGS:
  KEY     ACTION
  t       unmark
  s       substitute in place (so you dont need to run fardo)
  u       undo
  q       quit

```

# BUFFERS

Buffers are the files we open in vim. Use <leader>b and...

```vim
  \'b': {
    \'name': "[BUFFER]",
    \'b':     "buffers (fuzzy list)",
    \'a':      "buffers all (delete)",
    \'d':      "buffer delete (delete)",
    \'g': {
      \'name': "[GOTO]",
      \'u':       "prev buffer",
      \'p':       "next buffer",
      \'a':       "buffer 4",
      \'s':       "buffer 3",
      \'h':       "buffer 2",
      \'t':       "buffer 1",
      \'g':       "buffer 5",
      \'y':       "buffer 0",
      \'n':       "buffer 6",
      \'e':       "buffer 7",
      \'o':       "buffer 8",
      \'i':       "buffer 9",
    \}
  \},

```

# CODING

Go to definition:

```text
KEY       ACTION
gt        Go to documentation
gf        Go to file
gd        Go to definition
ctrl+o    go back
ctrl+i    go forward


TAB+rshi  autocompletes
```

Coc

``` text
Coc misc:
KEY       ACTION
,ca       CodeAction
,cp       List code resume

,cf       Autofixes selected line
,ct       Tidy selected code
,cp       CodeAction selection


Coc settings:
KEY       ACTION
,cc       Coc commands. To manage plugins.
```

Comment code:

```text
KEY        ACTION
gc         (go &) comment selection
gcc        (go &) comment line
gcap       (go &) comment paragraph
```

Surround code:

```text
KEY       ACTION
jss"      Just surround sentence with "
jss<div>  Just surround sentence with <div> (or any tag)
ds        Delete existing surroundings

V<div>    Surround current selection with <div> (or any tag)
```

Markdown:

```text
,n        add unordered item  
,ld       insert a line of dashes 
,lh       insert a line of hashes
```

BORDER CASE STRATEGIES
-------------------------------------------

# Align elements

```text
COMMAND          ACTION
:Tabular /,      Align the words of the paragraph with ',' as separator.
```

# Debugging/compiling

This operations depend of the language. I recommend using external tools,
in order to keep vim clean.

```text
LANG        TOOL
Python      pycharm
C#          monodevelop
JS          Chrome/Firerox
Android     Androidstudio
```

