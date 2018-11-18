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
 *   ����ϲ� ��ǰ���Ѱ�������Ŀ����� ���������Ƿ���Ժϲ�
 *   �ϲ�һ�κ��ͷ�ٴα��� ֱ�������������������
 */
void ListMerging(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    struct tagManger *pstNext = NULL;
    
    pstNext = pstTemp->pstNext;

    while (NULL != pstNext)
    {
        if (pstTemp->isOccupy == 0 && pstNext->isOccupy == 0)
        {
            /*ƫ�Ƶ�ַ����*/
            //pstTemp->nOffset

            /*��С�ϲ�*/
            pstTemp->nSize = pstTemp->nSize + pstNext->nSize;

            /*����β����*/
            pstTemp->pstNext = pstNext->pstNext;

            SAFE_FREE(pstNext);
            pstNext = pstTemp->pstNext;
            continue;
        }
        pstTemp = pstTemp->pstNext;
        pstNext = pstTemp->pstNext;
    }

}

/*ɾ���ַ���������*/
void Delete(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    int nID = -1;
    int isFind = 0;

    /*û������ֱ���˳�*/
    isFind = Find();
    if (isFind != 1)
    {
        return;
    }

    printf("��������ɾ����ID\r\n");
    nID = GetIntUserInput();
    while (NULL != pstTemp)
    {
        if (nID == pstTemp->nOffset)
        {
            /*ռ��״̬��Ϊ����*/
            pstTemp->isOccupy = 0;
            ListMerging();
            MyPrint("ɾ���ɹ�\r\n");
            system("pause");
            WriteManagerToFile();
            return;
        }
        pstTemp = pstTemp->pstNext;
    }
    MyPrint("��IDû����Ϣ!\r\n");
    system("pause");
    return;
}