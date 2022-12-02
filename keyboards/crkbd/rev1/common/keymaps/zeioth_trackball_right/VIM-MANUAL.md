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
w:  last char of the next word.
e:  next word.
b:  prev word.
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
  \'name': "Lead keymap",
  \'<CR>':    "Turn off        (highlights)",
  \'q':       "quit            (window)",
  \'e':       "edit            (vim settings)",
  \'f':       "open            (project buffer)",
  \'n':       "insert *        (list item)",
  \'ñ':       "yankstack+      (paste older)",
  \'Ñ':       "yankstack-      (paste newer)",
  \'o':       "open            (recent buffer)",
  \'p':       "paste           (after space)",
  \'P':       "paste           (endline)",
  \'r':       "ranger          (open)",
  \'s':       "sessions        (fuzzy)",
  \'w':       "write",
  \'z':       "zen mode",
  \'a': {
    \'name': "[SEARCH/REPLACE]",
    \'b': "search in buffer (code)",
    \'s': "search in project (code)",
    \'r': "replace (in file)",
    \'R': "replace (in project)",
    \'c': "confirm (replace in project)",
    \'u': "undo  (replace in project)",
  \},
  \'c': {
    \'name': "[COC]",
    \'1': "which_key_ignore",
    \'2': "which_key_ignore",
  \},
  \'g': {
    \'name': "[GIT]",
    \'b': "buffer commits  (show)",
    \'d': "diff  (toggle)",
    \'h': "gitHub (See file)",
    \'x': "blame  (enable)",
    \'m': "mergetool  (local/merged/remote)",
  \},
  \'d': {
    \'name': "[DEBUGGER]",
    \'h': "start   (debugging)",
    \'s': "stop (debugging)",
    \'r': "restart (debugging w/ same config)",
    \'b': "toggle (breakpoint)",
    \'l': "toggle  (logpoint or conditional break)",
    \'u': "add  (fnc. breakpoint under cursor)",
    \'c': "go     (to cursor)",
    \'n': "step    (next)",
    \'+': "step+  (into function)",
    \'-': "step-  (out of function)",
    \'>': "move+  (current call stack)",
    \'<': "move-  (current call stack)",
    \'e': "eval (expression)",
    \'j': "run (makefile)",
    \'f': "run (program)",
    \'t': {
      \'name': "[TESTS]",
      \'e': "e2e test (this)",
      \'ae': "e2e tests (all)",
      \'u': "unit test(this) ",
      \'au': "unit tests (all) ",
    \}
  \},
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
  \'h': {
    \'name': "[FAST]",
    \'h': "0",
    \'t': "50%",
    \'g': "75%",
  \},
  \'l': {
    \'name': "[LINE]",
      \'d':       "--- line",
      \'h':       "### line",
  \},
  \'t': {
    \'name': "[TABS]",
  \},
\}
```

CTRL SHORTCUTS
--------------------------------------

```vim
let g:ctrl_maps = {
  \'name': "CTRL keymap",
  \'i': "retrace forward",
  \'o': "retrace backwards",
  \'n': "markdown (preview)",
  \'ñ': "yank stack",
  \'j': "global yank",
  \'p': "global paste",
  \'r': "redo",
  \'t': "toggle (window)",
  \'v': "v-block", 
  \'w': "window", 
  \'w-=': "resize equally", 
  \'w-r': "rotate", 
  \'w-n': "h-split", 
  \'w-v': "v-split", 
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

The most eficient cross scenario way to move in vim would be

```text
MOTION          MEANING
12e             go 12 lines up
/(as            search for '(as' and press enter
v/os)c          select until 'os)' and change
```

Just remember you can search during a visual selection.

```text
CUSTOM BIND     MEANING
,hh              0%
,ht              50%
,hg              75%
```

Also, this custom keybinds make quicker to move horizontally.

```text
CUSTOM BIND     MEANING
t               append at the end of the word under the cursor (viwa).
```

Also, this custom keybinds make insert faster.


# SEARCH AND REPLACE

99% of the time the time we'll only use

* search <space>
* search in project ,as
* replace in project ,ar

Border cases are

* Replace in project ,ar

```text
  KEY          ACTION                 CMD
  ,as          Search in project      Farf
  ,ar          replace in project     Farr (fardo to commmit all changes)
  ,ac          Commit changes         Fardo
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

Once on the buffer selection menu, you can choose buffers with <C-z> and delete
them with F7.

# CODING

Go to definition:

```text
KEY       ACTION
gh        Go to help
gf        Go to file
gd        Go to definition
ctrl+o    go back
ctrl+i    go forward

TAB       autocomplete code definition
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
cs"'      Change surround " by '
ds        Delete existing surroundings

vS<div>    Surround current selection with <div> (or any tag)
```

Markdown:

```text
KEY       ACTION
<c-n>     preview in browser
,n        add unordered item  
,ld       insert a line of dashes 
,lh       insert a line of hashes
```

Snippets:

```text
KEY       ACTION
,cs       Fuzzy search for available snippets
<tab>     Autocomplete with an snippet
<c-b>     Navigate snippet fields after pressing <tab>


COMMAND             ACTION
:UltiSnipsEdit      Open the snippet editor.
```

Debugger:

```text
KEY       ACTION
,gdj      Compile (project)
,gdf      Run (project)

,gdr      Restart/Start (debugger)
,gds      Stop (debugger)
,gdh      Start (A different debugger)

,gdn      Next (line)
,gdc      To cursor (line)
,gdb      Breakpoint (line)

,gdte     Debugger test e2e
,gdtae    Debugger test all e2e
,gdtu     Debugger test unit
,gdtau    Debugged test all unit

```

Git:

```text
KEY       ACTION
,gt       Gitui
,gd       Diff (toggle)
,gm       Mergetool
<c-b>     Go to next field (After autocomplete w/ snippet)
<c-z>     Go to prev field
```


BORDER CASE STRATEGIES
-------------------------------------------

# Align elements

```text
COMMAND          ACTION
:Tabular /,      Align the words of the paragraph with ',' as separator.
```
