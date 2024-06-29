# RUE

C++头文件

###### 可以让你的C++程序记住窗口位置，需要使用注册表，有点危险。

<u>SaveWindow(命名);</u>  来保存当前窗口位置。

比如`SaveWindow(RUE);`。命名请使用 char* 。

<u>RestoreWindow(命名);</u>  来读取当前窗口位置。

比如`RestoreWindow(RUE);`。命名请使用 char* 。

只需在你的程序开头加上`#include"RUE.h"`并把**`RUE.h`**与你的程序放在同一个目录下即可。