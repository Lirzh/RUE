# RUE

C++ Header File

###### This allows your C++ program to remember the window position, which requires the use of the registry and is somewhat risky.

Use <u>SaveWindow(name);</u> to save the current window position.

For example, `SaveWindow(RUE);`. Please use char* for the name.

Use <u>RestoreWindow(name);</u> to read the current window position.

For example, `RestoreWindow(RUE);`. Please use char* for the name.

Simply add `#include "RUE.h"` at the beginning of your program and place **`RUE.h`** in the same directory as your program.