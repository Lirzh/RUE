// 定义头文件的包含守卫，防止头文件被重复包含
#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H
// 头文件内容开始
// 包含Windows API头文件，提供窗口和注册表操作的接口
#include <windows.h>
// 包含标准输入输出库头文件，提供格式化字符串函数
#include <stdio.h>
// 头文件内容结束
#endif // HEADER_FILE_NAME_H
// 保存窗口位置的函数
void SaveWindow(char* name) {
    // 获取当前活动窗口的位置信息
    RECT rect;
    GetWindowRect(GetForegroundWindow(), &rect);
    // 创建一个字符数组用于存储窗口位置信息
    char buffer[256];
    // 使用snprintf安全地格式化窗口位置信息
    snprintf(buffer, sizeof(buffer), "%ld,%ld", rect.left, rect.top);
    // 创建或打开注册表键，用于保存窗口位置信息
    HKEY hKey;
    RegCreateKeyEx(HKEY_CURRENT_USER, name, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
    // 将窗口位置信息保存到注册表中
    RegSetValueEx(hKey, "WindowPosition", 0, REG_SZ, (BYTE*)buffer, strlen(buffer) + 1);
    // 关闭注册表键
    RegCloseKey(hKey);
}
// 读取窗口位置的函数
void RestoreWindow(char* name) {
    // 声明注册表键变量
    HKEY hKey;
    // 创建一个字符数组用于读取窗口位置信息
    char buffer[256];
    // 设置读取缓冲区的大小
    DWORD size = sizeof(buffer);
    // 尝试打开注册表键
    if (RegOpenKeyEx(HKEY_CURRENT_USER, name, 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        // 从注册表中读取窗口位置信息
        RegQueryValueEx(hKey, "WindowPosition", NULL, NULL, (BYTE*)buffer, &size);
        // 关闭注册表键
        RegCloseKey(hKey);
        // 定义变量存储解析后的窗口位置坐标
        int x, y;
        // 使用sscanf_s安全地解析字符串为两个整数
        sscanf_s(buffer, "%d,%d", &x, &y);
        // 设置窗口位置
        SetWindowPos(GetForegroundWindow(), NULL, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
}
