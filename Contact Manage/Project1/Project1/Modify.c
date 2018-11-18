#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include "FileOpearte.h"
#include "Input.h"
#include "Find.h"
#include "UI.h"
#include "Delete.h"
#include "AddString.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*
 *   修改联系人主函数
 */
void Modify(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    int nID = -1;
    int isFind = 0;

    /*没找到直接退出*/
    isFind = Find();
    if (isFind != 1)
    {
        return;
    }

    printf("请输入ID修改对应的联系人\r\n");
    nID = GetIntUserInput();
    while (NULL != pstTemp)
    {
        if (nID == pstTemp->nOffset)
        {
            /*占用状态变为空闲*/
            pstTemp->isOccupy = 0;
            ListMerging();
            AddString();
            printf("修改完成\r\n");
            system("pause");
            return;
        }
        pstTemp = pstTemp->pstNext;
    }
    MyPrint("该ID没有联系人!\r\n");
    system("pause");
    return;
}