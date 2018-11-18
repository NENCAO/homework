#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileOpearte.h"
#include "Input.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

char szName[MAXSIZE / 6][MaxInputLength] = { 0 }; //������ֵ�����

//int nNameSum = 0;//��ϵ�˸���
/*
 *   ��ȡ��ϵ������
 *   ������szName��
 *   ������ϵ�˸���
 */
int GetName(void)
{
    int nNameSum = 0;//��ϵ�˸���
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
 *   ͳ����ϵ�˸����ͱ��� ��������
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
            printf("��ϵ��:%s  ���ִ���:%d  ���ֱ���:%.2f\r\n", szName[nCount], nNameCount, fProportion);
        }
        nCount++;
        nNameCount = 1;
    }
}

/*ͳ��������*/
void Count(void)
{
    int nNameSum = 0;
    memset(szName, 0, sizeof(szName));

    nNameSum = GetName();
    CountName(nNameSum);
    system("pause");
}