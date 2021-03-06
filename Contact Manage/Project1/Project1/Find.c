#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileOpearte.h"
#include "Input.h"
#include "UI.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*按名字模糊查找*/
int NameFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char UserInput[MaxInputLength] = { '\0' };
    char *pcCheckMod = NULL;
    int nCount = 0;
    int isFind = 0;

    printf("请输入名字查找 支持模糊查找\r\n");
    GetUserFindInput(UserInput);

    while (NULL != pstTemp)
    {
        /*内存区的指针 = 头指针 + 偏移量*/
        pcTemp = g_pMenmoryAreaHead + pstTemp->nOffset;
        if (1 == pstTemp->isOccupy)
        {
            pcCheckMod = strstr(pcTemp, UserInput);
            if (NULL != pcCheckMod)
            {
                /*通过查询分隔符个数来确定是姓名还是电话还是地址*/
                while ('\0' != *pcCheckMod)
                {
                    if ('`' == *pcCheckMod)
                    {
                        nCount++;
                    }
                    pcCheckMod++;
                }
                if (2 == nCount)
                {
                    ShowFindString(pcTemp, pstTemp);
                    isFind = 1;
                }
            }
        }
        pstTemp = pstTemp->pstNext;
        pcCheckMod = NULL;
        nCount = 0;
    }
    return isFind;
}

/*
 *   按电话号模糊查找
 *   返回1有数据被找到
 *   返回0没有数据被找到
 */
int PhoneFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char szUserInput[MaxInputLength] = { '\0' };
    char szFindString[MaxInputLength] = { '\0' };
    int nTemp = 0;
    int nCount = 0;
    int isFind = 0;

    printf("请输入电话号查找 支持模糊查找\r\n");
    GetUserFindInput(szUserInput);

    while (NULL != pstTemp)
    {
        /*内存区的指针 = 头指针 + 偏移量*/
        pcTemp = g_pMenmoryAreaHead + pstTemp->nOffset;
        if (1 == pstTemp->isOccupy)
        {
            char *pcFirst = NULL;
            char *pcSecond = NULL;

            pcFirst = strchr(pcTemp, '`');
            pcSecond = strchr(pcFirst + 1, '`');

            nTemp = (int)(pcSecond - pcFirst);

            memcpy(szFindString, pcFirst + 1, nTemp - 1);
            if (NULL != strstr(szFindString, szUserInput))
            {
                ShowFindString(pcTemp, pstTemp);
                isFind = 1;
            }
        }
        pstTemp = pstTemp->pstNext;
        memset(szFindString, 0, sizeof(szFindString));
        nTemp = 0;
        nCount = 0;
    }
    return isFind;
}


/*按地址模糊查找*/
int AddressFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char szUserInput[MaxInputLength] = { '\0' };
    char szFindString[MaxInputLength] = { '\0' };
    int nTemp = 0;
    int nCount = 0;
    int isFind = 0;

    printf("请输入地址查找 支持模糊查找\r\n");
    GetUserFindInput(szUserInput);

    while (NULL != pstTemp)
    {
        /*内存区的指针 = 头指针 + 偏移量*/
        pcTemp = g_pMenmoryAreaHead + pstTemp->nOffset;
        if (1 == pstTemp->isOccupy)
        {
            char *pcFirst = NULL;
            char *pcSecond = NULL;

            pcFirst = strchr(pcTemp, '`');
            pcSecond = strchr(pcFirst + 1, '`');

            if (NULL != strstr(pcSecond, szUserInput))
            {
                ShowFindString(pcTemp, pstTemp);
                isFind = 1;
            }
        }
        pstTemp = pstTemp->pstNext;
        memset(szFindString, 0, sizeof(szFindString));
        nTemp = 0;
        nCount = 0;
    }
    return isFind;
}

/*
 *  查询主函数
 *  有结果返回  1
 *  没有结果返回0
 */
int Find(void)
{
    int nMode = 0;
    int isFind = 0;

    system("cls");
    ShowInputString();
    MyPrint("请输入查找模式\r\n1.按名字查找    2.按手机号查找    3.按地址查找\r\n");
    nMode = GetIntUserInput();

    switch (nMode)
    {
    case 1:
        isFind = NameFind();
        break;
    case 2:
        isFind = PhoneFind();
        break;
    case 3:
        isFind = AddressFind();
        break;
    default:
        MyPrint("没有这种模式!\r\n");
        system("pause");
        return isFind;
    }
    if (isFind)
    {
        MyPrint("=================找到的联系人=================\r\n");
        system("pause");
        return isFind;
    }
    else
    {
        MyPrint("没有找到!\r\n");
        system("pause");
        return isFind;
    }

}
