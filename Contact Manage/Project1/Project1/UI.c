#include <stdio.h>
#include "FileOpearte.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;
/*
 *   �Զ����ӡ�ַ����ĺ���
 *   ����sz���͵��ַ���
 *   ��ӡ������ַ���
 */
void MyPrint(char *szStr)
{
    printf("%s", szStr);
}


/*
 *   �û���ʼ����
 *   �޲��� ���߼�����
 *   ��������ʾ����
 */
void StartInterface(void)
{
    int nCount = 0;

    for (nCount = 0; nCount < 40; nCount++)
    {
        MyPrint("* ");
    }
    MyPrint("\r\n");
    MyPrint("* ");

    for (nCount = 0; nCount <= 20; nCount++)
    {
        MyPrint(" ");
    }

    MyPrint("Dynamic Management System");

    for (nCount = 0; nCount < 30; nCount++)
    {
        MyPrint(" ");
    }
    MyPrint("* ");
    MyPrint("\r\n");

    for (nCount = 0; nCount < 40; nCount++)
    {
        MyPrint("* ");
    }

    MyPrint("\r\n");

    MyPrint("1.�����ַ���         2.ɾ���ַ���\
             3.�޸��ַ���         4.��ѯ�ַ���\
         \r\n5.ͳ����ĸ           6.�鿴�洢��Ϣ\
           7.��Ƭ����");

    MyPrint("\r\n");
}

/*
 *   ��ʾ�û��������ַ���
 */
void ShowInputString(void)
{
    struct tagManger *stMangerTemp = g_pstMangerHead;
    char *stMemoryTemp = g_pMenmoryAreaHead;
    int nCount = 0;

    MyPrint("                                 ��ǰ�ַ���\r\n");
    MyPrint("================================================================================\r\n");

    while (NULL != stMangerTemp)
    {
        if (1 == stMangerTemp->isOccupy)
        {
            printf("����:");
            while ('`' != *(stMemoryTemp + stMangerTemp->nOffset + nCount))
            {
                putchar(*(stMemoryTemp + stMangerTemp->nOffset + nCount));
                nCount++;
            }
            printf("     ");
            nCount++;

            printf("�ֻ�:");
            while ('`' != *(stMemoryTemp + stMangerTemp->nOffset + nCount))
            {
                putchar(*(stMemoryTemp + stMangerTemp->nOffset + nCount));
                nCount++;
            }
            printf("     ");
            nCount++;

            printf("��ַ:");
            while ('\0' != *(stMemoryTemp + stMangerTemp->nOffset + nCount))
            {
                putchar(*(stMemoryTemp + stMangerTemp->nOffset + nCount));
                nCount++;
            }

            printf("\r\n");
        }
        stMangerTemp = stMangerTemp->pstNext;
        nCount = 0;
    }

    MyPrint("================================================================================\r\n");
}