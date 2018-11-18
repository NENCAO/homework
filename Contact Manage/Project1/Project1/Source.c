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
#include "MemInfo.h"
#include "Modify.h"
#include "Diskfragment.h"
#include "Count.h"

/*管理表链表的首地址*/
struct tagManger *g_pstMangerHead = NULL;
/*字符串堆区的首地址*/
char *g_pMenmoryAreaHead = NULL;

int main(void)
{
    int nMode = 0;

    /*管理表从文件写入内存*/
    CreatManagerList();
    /*字符串区从文件写入内存*/
    CreatMemoryList();
    system("cls");
    while (1)
    {
        /*显示菜单和当前已有信息*/
        ShowInputString();
        StartInterface();
        MyPrint("请选择模式\r\n");
        nMode = GetIntUserInput();
        switch (nMode)
        {
        case 1:
            AddString();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Modify();
            break;
        case 4:
            Find();
            break;
        case 5:
            Count();
            break;
        case 6:
            MemInfo();
            break;
        case 7:
            DiskFragment();
            break;
        default:
            MyPrint("没有这种模式!请重输\r\n");
            system("pause");
            break;
        }
        system("cls");
    }

    system("pause");
    return 0;
}