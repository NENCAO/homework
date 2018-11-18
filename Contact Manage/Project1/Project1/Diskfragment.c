#include <stdio.h>
#include <string.h>
#include "FileOpearte.h"
#include "Delete.h"

/*�����������׵�ַ*/
extern struct tagManger *g_pstMangerHead;
/*�ַ����������׵�ַ*/
extern char *g_pMenmoryAreaHead;

void DiskFragment(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    struct tagManger *pstNext = NULL;
    char *pcMemTemp = g_pMenmoryAreaHead;
    int nTemp = 0;

    pstNext = pstTemp->pstNext;

    while (NULL != pstNext)
    {
        /*�ܽ��в�λ�ĵط� ��Ȼǰ����� ����ռ��*/
        if (0 == pstTemp->isOccupy && 1 == pstNext->isOccupy)
        {
            /*���ڴ��ƶ�������λ����*/
            memcpy(pcMemTemp + pstTemp->nOffset, pcMemTemp + pstNext->nOffset, pstNext->nSize);

            /*������������*/
            pstNext->isOccupy = 0;
            pstNext->nOffset = pstTemp->nOffset + pstNext->nSize;
            nTemp = pstNext->nSize;
            pstNext->nSize = pstTemp->nSize;

            //---------------------ռ���������Ϊ����---------------------//
            pstTemp->isOccupy = 1;
            pstTemp->nSize = nTemp;
            //---------------------�����������Ϊռ��---------------------//

            //�ϲ�֮����ܳ���2������������ ���кϲ����ټ�����pstTemp��ʼ���
            ListMerging();
            continue;
        }
        pstTemp = pstTemp->pstNext;
        pstNext = pstTemp->pstNext;
    }
    WritMemoryToFile();
    WriteManagerToFile();
}