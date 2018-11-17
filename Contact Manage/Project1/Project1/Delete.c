#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include "FileOpearte.h"
#include "Input.h"
#include "Find.h"
#include "UI.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*
 *   链表合并 从前向后寻找连续的空闲区 查找链表是否可以合并
 *   合并一次后从头再次遍历 直到遍历完整个链表结束
 */
void ListMerging(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    struct tagManger *pstNext = NULL;

    while (NULL != pstNext)
    {
        pstTemp = g_pstMangerHead;
        while (NULL != pstNext)
        {
            pstNext = pstTemp->pstNext;
            if (pstTemp->isOccupy == 0 && pstNext->isOccupy == 0)
            {
                /*偏移地址不变*/
                //pstTemp->nOffset

                /*大小合并*/
                pstTemp->nSize = pstTemp->nSize + pstNext->nSize;

                /*链表尾更改*/
                pstTemp->pstNext = pstNext->pstNext;

                SAFE_FREE(pstNext);
                break;
            }
            pstTemp = pstTemp->pstNext;
        }
    }
}

/*删除字符串主函数*/
void Delete(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    int nID = -1;

    Find();

    printf("请输入想删除的ID\r\n");
    nID = GetIntUserInput();
    while (NULL != pstTemp)
    {
        if (nID == pstTemp->nOffset)
        {
            /*占用状态变为空闲*/
            pstTemp->isOccupy = 0;
            MyPrint("删除成功\r\n");
            system("pause");
            WriteManagerToFile();
            return;
        }
        pstTemp = pstTemp->pstNext;
    }
    MyPrint("该ID没有信息!\r\n");
    system("pause");
    return;
}