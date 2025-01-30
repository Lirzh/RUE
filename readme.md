# RUE

C++头文件

###### 可以让你的C++程序记住窗口位置。

<u>SaveWindowSettings(<英文文件名>);</u>  来保存当前窗口位置。

比如`SaveWindowSettings(RUE);`。命名请使用 char* 。

<u>RestoreWindowSettings(<英文文件名>);</u>  来读取当前窗口位置。

比如`RestoreWindowSettings(RUE);`。命名请使用 char* 。

只需在你的程序开头加上`#include"RUE.h"`并把**`RUE.h`**与你的程序放在同一个目录下即可。

已经 include 了这些库：`<string.h><stdlib.h><stdio.h><windows.h>`

样例：

```
#include"RUE.h"
using namespace std;
int main() {
    const char* filename = "window_settings.txt";
    // 保存窗口设置
    SaveWindowSettings(filename);
    printf("窗口设置已保存到 %s。\n", filename);
    // 模拟改变窗口位置和大小
    printf("请手动改变窗口位置和大小，然后按任意键继续...\n");
    getchar();
    getchar();  // 消耗掉缓冲区中的换行符
    // 恢复窗口设置
    RestoreWindowSettings(filename);
    printf("窗口设置已从 %s 恢复。\n", filename);
    return 0;
}
```

在样例中， window_settings.txt 储存了窗口的配置。