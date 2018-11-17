#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "FileOpearte.h"
#include "AddString.h"
#include "Input.h"

/*管理表链表的首地址*/
struct tagManger *g_pstMangerHead = NULL;
/*字符串堆区的首地址*/
char *g_pMenmoryAreaHead = NULL;

int main(void)
{
    /*管理表从文件写入内存*/
    CreatManagerList();
    /*字符串区从文件写入内存*/
    CreatMemoryList();

    ShowInputString();

    //while (1)
    //{
    //    AddString();
    //}


    system("pause");
    return 0;
}