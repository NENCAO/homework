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
 *   �޸���ϵ��������
 */
void Modify(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    int nID = -1;
    int isFind = 0;

    /*û�ҵ�ֱ���˳�*/
    isFind = Find();
    if (isFind != 1)
    {
        return;
    }

    printf("������ID�޸Ķ�Ӧ����ϵ��\r\n");
    nID = GetIntUserInput();
    while (NULL != pstTemp)
    {
        if (nID == pstTemp->nOffset)
        {
            /*ռ��״̬��Ϊ����*/
            pstTemp->isOccupy = 0;
            ListMerging();
            AddString();
            printf("�޸����\r\n");
            system("pause");
            return;
        }
        pstTemp = pstTemp->pstNext;
    }
    MyPrint("��IDû����ϵ��!\r\n");
    system("pause");
    return;
}