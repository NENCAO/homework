#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Input.h"

/*
 *   ����:��ȡ�û�������ַ���
 *   ����:����char�������ָ�� 
 *   ����:void
 *
 *   ע��:
 *   1. char����Ӧ��Ҫ >= MaxInputLength + 1 (��Ҫ��'\0')
 *   2. ֻ������100���ַ����ڵ��ַ���(��Input.h�п����޸�)
 */
void GetStrUserInput(char * szUserName, char * szUserPhone, char *szUserAddress)
{
    int nTemp = 0;/*�建����*/
    int nCount = 0;

    /*����ǰ ��Ҫ����ǰ�����������*/
    memset(szUserName, 0, sizeof(szUserName));
    memset(szUserPhone, 0, sizeof(szUserPhone));
    memset(szUserAddress, 0, sizeof(szUserAddress));

    printf("���������� �������100���ַ� �ո���߻س���������\r\n");
    nCount = scanf(INPUT_TYPE(MaxInputLength), szUserName);
    if (nCount == 0)
    {
        printf("����ʧ��\r\n");
        system("pause");
        exit(0);
    }
    while ((nTemp = getchar()) != '\n' && nTemp != EOF);

    printf("������绰 �������100���ַ� �ո���߻س���������\r\n");
    nCount = scanf(INPUT_TYPE(MaxInputLength), szUserPhone);
    if (nCount == 0)
    {
        printf("����ʧ��\r\n");
        system("pause");
        exit(0);
    }
    while ((nTemp = getchar()) != '\n' && nTemp != EOF);

    printf("�������ַ �������100���ַ� �ո���߻س���������\r\n");
    nCount = scanf(INPUT_TYPE(MaxInputLength), szUserAddress);
    if (nCount == 0)
    {
        printf("����ʧ��\r\n");
        system("pause");
        exit(0);
    }
    while ((nTemp = getchar()) != '\n' && nTemp != EOF);

    strcat(szUserName, "`");
    strcat(szUserName, szUserPhone);
    strcat(szUserName, "`");
    strcat(szUserName, szUserAddress);

    return;
}

/*
 *   ����:��ȡ�û�������ַ�������
 *   ����:����char�������ָ��
 *   ����:�ַ����ĳ���(����\0)
 *
 *   ע��:
 *   1. �����Ѿ�����\0ռ�õĳ���
 */
int GetStrLength(char *szUserInput)
{
    if (strlen(szUserInput) != 0)
    {
        return strlen(szUserInput) + 1;
    }
    else
    {
        return 0;
    }
}

/*
 *   �����û���������
 *   ����int������
 */
int GetIntUserInput(void)
{
    int nInput = 0;
    int nTemp = 0;/*�建����*/

    while (scanf("%d", &nInput) == 0)
    {
        printf("����������!\r\n");
        while ((nTemp = getchar()) != '\n');
    }

    while ((nTemp = getchar()) != '\n');

    return nInput;
}

/*
 *   �����û�������ҵ��ַ���
 *   �������ַ����ĵ�ַ
 */
void GetUserFindInput(char * cInput)
{
    int nTemp = 0;/*�建����*/

    while (scanf(INPUT_TYPE(MaxInputLength), cInput) == 0)
    {
        printf("Input Error please re-enter");
        while ((nTemp = getchar()) != '\n' && nTemp != EOF);
    }

    while ((nTemp = getchar()) != '\n'&& nTemp != EOF);

    return;
}