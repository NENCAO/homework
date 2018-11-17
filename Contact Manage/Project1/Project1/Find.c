#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileOpearte.h"
#include "Input.h"
#include "UI.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*������ģ������*/
void NameFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char UserInput[MaxInputLength] = { '\0' };
    char *pcCheckMod = NULL;
    int nCount = 0;

    printf("���������ֲ��� ֧��ģ������\r\n");
    GetUserFindInput(UserInput);

    while (NULL != pstTemp)
    {
        /*�ڴ�����ָ�� = ͷָ�� + ƫ����*/
        pcTemp = g_pMenmoryAreaHead + pstTemp->nOffset;
        if (1 == pstTemp->isOccupy)
        {
            pcCheckMod = strstr(pcTemp, UserInput);
            if (NULL != pcCheckMod)
            {
                /*ͨ����ѯ�ָ���������ȷ�����������ǵ绰���ǵ�ַ*/
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
                }
            }
        }
        pstTemp = pstTemp->pstNext;
        pcCheckMod = NULL;
        nCount = 0;
    }
}

/*���绰��ģ������*/
void PhoneFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char szUserInput[MaxInputLength] = { '\0' };
    char szFindString[MaxInputLength] = { '\0' };
    int nTemp = 0;
    int nCount = 0;

    printf("������绰�Ų��� ֧��ģ������\r\n");
    GetUserFindInput(szUserInput);

    while (NULL != pstTemp)
    {
        /*�ڴ�����ָ�� = ͷָ�� + ƫ����*/
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
            }
        }
        pstTemp = pstTemp->pstNext;
        memset(szFindString, 0, sizeof(szFindString));
        nTemp = 0;
        nCount = 0;
    }
}


/*����ַģ������*/
void AddressFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char szUserInput[MaxInputLength] = { '\0' };
    char szFindString[MaxInputLength] = { '\0' };
    int nTemp = 0;
    int nCount = 0;

    printf("�������ַ���� ֧��ģ������\r\n");
    GetUserFindInput(szUserInput);

    while (NULL != pstTemp)
    {
        /*�ڴ�����ָ�� = ͷָ�� + ƫ����*/
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
            }
        }
        pstTemp = pstTemp->pstNext;
        memset(szFindString, 0, sizeof(szFindString));
        nTemp = 0;
        nCount = 0;
    }
}

/*��ѯ������*/
void Find(void)
{
    int nMode = 0;

    system("cls");
    ShowInputString();
    MyPrint("���������ģʽ\r\n1.�����ֲ���    2.���绰�Ų���    3.����ַ����\r\n");
    nMode = GetIntUserInput();

    switch (nMode)
    {
    case 1:
        NameFind();
        break;
    case 2:
        PhoneFind();
        break;
    case 3:
        AddressFind();
        break;
    default:
        MyPrint("û������ģʽ!������\r\n");
        break;
    }

    MyPrint("=================�ҵ�������=================\r\n");
    return;
}
