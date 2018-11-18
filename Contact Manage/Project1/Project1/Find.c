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
int NameFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char UserInput[MaxInputLength] = { '\0' };
    char *pcCheckMod = NULL;
    int nCount = 0;
    int isFind = 0;

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
 *   ���绰��ģ������
 *   ����1�����ݱ��ҵ�
 *   ����0û�����ݱ��ҵ�
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


/*����ַģ������*/
int AddressFind(void)
{
    struct tagManger * pstTemp = g_pstMangerHead;
    char *pcTemp = g_pMenmoryAreaHead;
    char szUserInput[MaxInputLength] = { '\0' };
    char szFindString[MaxInputLength] = { '\0' };
    int nTemp = 0;
    int nCount = 0;
    int isFind = 0;

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
 *  ��ѯ������
 *  �н������  1
 *  û�н������0
 */
int Find(void)
{
    int nMode = 0;
    int isFind = 0;

    system("cls");
    ShowInputString();
    MyPrint("���������ģʽ\r\n1.�����ֲ���    2.���绰�Ų���    3.����ַ����\r\n");
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
        MyPrint("û������ģʽ!\r\n");
        system("pause");
        return isFind;
    }
    if (isFind)
    {
        MyPrint("=================�ҵ�����ϵ��=================\r\n");
        return isFind;
    }
    else
    {
        MyPrint("û���ҵ�!\r\n");
        system("pause");
        return isFind;
    }

}
