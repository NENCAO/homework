#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI.h"
#include "FileOpearte.h"
#include "AddString.h"
#include "Input.h"
#include "Find.h"
#include "Delete.h"

/*�����������׵�ַ*/
struct tagManger *g_pstMangerHead = NULL;
/*�ַ����������׵�ַ*/
char *g_pMenmoryAreaHead = NULL;

int main(void)
{
    int nMode = 0;

    /*�������ļ�д���ڴ�*/
    CreatManagerList();
    /*�ַ��������ļ�д���ڴ�*/
    CreatMemoryList();

    while (1)
    {
        /*��ʾ�˵��͵�ǰ������Ϣ*/
        ShowInputString();
        StartInterface();
        MyPrint("��ѡ��ģʽ\r\n");
        nMode = GetIntUserInput();
        switch (nMode)
        {
        case 1:
            AddString();
            break;
        case 2:
            Delete();
            break;
        case 4:
            Find();
            system("pause");
            break;
        default:
            MyPrint("û������ģʽ!������\r\n");
            system("pause");
            break;
        }
        system("cls");
    }

    system("pause");
    return 0;
}