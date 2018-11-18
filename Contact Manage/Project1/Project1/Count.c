#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileOpearte.h"
#include "Input.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

char szName[MAXSIZE / 6][MaxInputLength] = { 0 }; //存放名字的数组

//int nNameSum = 0;//联系人个数
/*
 *   获取联系人名字
 *   并放入szName中
 *   返回联系人个数
 */
int GetName(void)
{
    int nNameSum = 0;//联系人个数
    struct tagManger *pstManTemp = g_pstMangerHead;

    int nSize = 0;

    while (NULL != pstManTemp)
    {
        if (pstManTemp->isOccupy == 1)
        {
            nSize = (int)(strstr(g_pMenmoryAreaHead + pstManTemp->nOffset, "`") - (g_pMenmoryAreaHead + pstManTemp->nOffset));
            memcpy(szName[nNameSum],g_pMenmoryAreaHead + pstManTemp->nOffset, nSize);
            nNameSum++;
        }
        pstManTemp = pstManTemp->pstNext;
    }
    return nNameSum;
}

/*
 *   统计联系人个数和比例 并且输入
 */
void CountName(int nNameSum)
{
    int nCount = 0;
    int nCheck = 0;
    int nNameCount = 1;
    float fProportion = 0.0f;

    while (nCount < MAXSIZE / 6)
    {
        if (0 != szName[nCount][0])
        {
            nCheck = nCount + 1;
            while (nCheck < MAXSIZE / 6)
            {
                if (0 != szName[nCheck][0] && NULL != strstr(szName[nCount], szName[nCheck]))
                {
                    nNameCount++;
                    memset(szName[nCheck], 0, sizeof(szName[nCheck]));
                }
                nCheck++;
            }
            fProportion = nNameCount / (float)nNameSum;
            printf("联系人:%s  出现次数:%d  出现比例:%.2f\r\n", szName[nCount], nNameCount, fProportion);
        }
        nCount++;
        nNameCount = 1;
    }
}

/*统计主函数*/
void Count(void)
{
    int nNameSum = 0;
    memset(szName, 0, sizeof(szName));

    nNameSum = GetName();
    CountName(nNameSum);
    system("pause");
}