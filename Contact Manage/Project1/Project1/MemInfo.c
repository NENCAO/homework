#include<stdio.h>
#include <stdlib.h>
#include "FileOpearte.h"

/*�����������׵�ַ*/
extern struct tagManger *g_pstMangerHead;
/*�ַ����������׵�ַ*/
extern char *g_pMenmoryAreaHead;

/*
 *  ��ʾ�ڴ���Ϣ
 */
void MemInfo(void)
{
    struct tagManger *pstManTemp = g_pstMangerHead;
    int nCount = 0;
    int nLineControl = 0;

    while (NULL != pstManTemp)
    {
        if (1 == pstManTemp->isOccupy)
        {
            while (nCount < pstManTemp->nSize)
            {
                printf("U");
                nLineControl++;
                nCount++;
                if (nLineControl % 100 == 0)
                {
                    printf("\r\n");
                }
            }
            nCount = 0;
        }
        else if (0 == pstManTemp->isOccupy)
        {
            while (nCount < pstManTemp->nSize)
            {
                printf("F");
                nLineControl++;
                nCount++;
                if (nLineControl % 100 == 0)
                {
                    printf("\r\n");
                }
            }
            nCount = 0;
        }
        pstManTemp = pstManTemp->pstNext;
    }
    system("pause");
}