#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 保存窗口位置和大小到同一目录下的文件
void SaveWindowSettings(const char* filename) {
    // 获取当前活动窗口的位置和大小信息
    RECT rect;
    if (!GetWindowRect(GetForegroundWindow(), &rect)) {
        printf("获取窗口位置和大小失败。\n");
        return;
    }
    // 打开文件以写入模式
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件 %s 进行写入。\n", filename);
        return;
    }
    // 将窗口位置和大小信息写入文件
    fprintf(file, "%ld,%ld,%ld,%ld", rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
    // 关闭文件
    fclose(file);
}
// 从同一目录下的文件恢复窗口位置和大小
void RestoreWindowSettings(const char* filename) {
    // 打开文件以读取模式
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s 进行读取。\n", filename);
        return;
    }
    // 定义变量存储解析后的窗口位置和大小坐标
    int left, top, width, height;
    // 从文件中读取窗口位置和大小信息
    if (fscanf(file, "%d,%d,%d,%d", &left, &top, &width, &height) != 4) {
        printf("从文件中读取窗口设置失败。\n");
        fclose(file);
        return;
    }
    // 关闭文件
    fclose(file);
    // 设置窗口位置和大小
    if (!SetWindowPos(GetForegroundWindow(), NULL, left, top, width, height, SWP_NOZORDER)) {
        printf("设置窗口位置和大小失败。\n");
    }
}
