#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ���洰��λ�úʹ�С��ͬһĿ¼�µ��ļ�
void SaveWindowSettings(const char* filename) {
    // ��ȡ��ǰ����ڵ�λ�úʹ�С��Ϣ
    RECT rect;
    if (!GetWindowRect(GetForegroundWindow(), &rect)) {
        printf("��ȡ����λ�úʹ�Сʧ�ܡ�\n");
        return;
    }
    // ���ļ���д��ģʽ
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("�޷����ļ� %s ����д�롣\n", filename);
        return;
    }
    // ������λ�úʹ�С��Ϣд���ļ�
    fprintf(file, "%ld,%ld,%ld,%ld", rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
    // �ر��ļ�
    fclose(file);
}
// ��ͬһĿ¼�µ��ļ��ָ�����λ�úʹ�С
void RestoreWindowSettings(const char* filename) {
    // ���ļ��Զ�ȡģʽ
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("�޷����ļ� %s ���ж�ȡ��\n", filename);
        return;
    }
    // ��������洢������Ĵ���λ�úʹ�С����
    int left, top, width, height;
    // ���ļ��ж�ȡ����λ�úʹ�С��Ϣ
    if (fscanf(file, "%d,%d,%d,%d", &left, &top, &width, &height) != 4) {
        printf("���ļ��ж�ȡ��������ʧ�ܡ�\n");
        fclose(file);
        return;
    }
    // �ر��ļ�
    fclose(file);
    // ���ô���λ�úʹ�С
    if (!SetWindowPos(GetForegroundWindow(), NULL, left, top, width, height, SWP_NOZORDER)) {
        printf("���ô���λ�úʹ�Сʧ�ܡ�\n");
    }
}
