#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "FileOpearte.h"
#include "AddString.h"
#include "Input.h"

/*�����������׵�ַ*/
struct tagManger *g_pstMangerHead = NULL;
/*�ַ����������׵�ַ*/
char *g_pMenmoryAreaHead = NULL;

int main(void)
{
    /*�������ļ�д���ڴ�*/
    CreatManagerList();
    /*�ַ��������ļ�д���ڴ�*/
    CreatMemoryList();

    ShowInputString();

    //while (1)
    //{
    //    AddString();
    //}


    system("pause");
    return 0;
}