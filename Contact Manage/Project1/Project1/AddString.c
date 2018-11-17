#include <stdlib.h>
#include <string.h>
#include "FileOpearte.h"
#include "Input.h"


extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*
 *   ������ʣ��ռ��Ƿ��㹻
 *   �����û������ַ�������
 *   �ɹ��ҵ� ���� �������ڵ�ָ��
 *   ����ʧ�� ���� NULL
 */
void *FindSpace(int nLength)
{
    struct tagManger *pstTemp = g_pstMangerHead;

    while (NULL != pstTemp)
    {
        /*�����㹻���Ҵ��ڿ���״̬*/
        if (nLength <= pstTemp->nSize && pstTemp->isOccupy == 0)
        {
            return pstTemp;
        }
        pstTemp = pstTemp->pstNext;
    }
    return NULL;
}

/*
 *   �޸Ĺ���� ��д���ļ�
 *   �����ҵ��Ĺ�����λ��ָ�� �ַ����ĳ���
 */
void ModifyManagment(struct tagManger *pstFindMangerHead,int nLength)
{
    struct tagManger *pstTemp = NULL;

    /*�������ռ���� �����ٽ����б�*/
    if (nLength == pstFindMangerHead->nSize)
    {
        /* ռ��״̬��Ϊ1 ռ��*/
        pstFindMangerHead->isOccupy = 1;

        /* ���׵�ַƫ�� = ��ǰλ��(����)*/
        //pstFindMangerHead->nOffset;

        /* �ַ���ռ�ó��� */
        pstFindMangerHead->nSize = nLength;

        /*�����д���ļ�*/
        WriteManagerToFile();
        return;
    }
    else
    {
        pstTemp = (struct tagManger *)malloc(sizeof(struct tagManger));
        if (NULL == pstTemp)
        {
            printf("�ڴ�����ʧ�� AddString -> ModifyManagment\r\n");
            system("pause");
            exit(0);
        }

        /* ռ��״̬��Ϊ0 ���� */
        pstTemp->isOccupy = 0;

        /*���׵�ַ�����Ϊ ԭƫ��+ռ�ó���*/
        pstTemp->nOffset = pstFindMangerHead->nOffset + nLength;

        /* ���д�С��Ϊ ԭ��С-ռ�ô�С */
        pstTemp->nSize = pstFindMangerHead->nSize - nLength;

        /*ָ��ԭ�������һ����ַ*/
        pstTemp->pstNext = pstFindMangerHead->pstNext;
        //----------------------���б����---------------------//

        /* ռ��״̬��Ϊ1 ռ��*/
        pstFindMangerHead->isOccupy = 1;

        /* ���׵�ַƫ�� = ��ǰλ��(����)*/
        //pstFindMangerHead->nOffset;

        /* �ַ���ռ�ó��� */
        pstFindMangerHead->nSize = nLength;

        /*ָ���¿�����������׵�ַ*/
        pstFindMangerHead->pstNext = pstTemp;

        /*�����д���ļ�*/
        WriteManagerToFile();
    }
    return;
}

/*
 *   �޸��ַ����ڴ� ��д���ļ�
 *   �����ҵ��Ĺ�����λ��ָ�� �����ַ������׵�ַ �ַ����ĳ���
 */
void ModifyMemory(struct tagManger *pstFindMangerHead,char *szUserName, int nLength)
{
    char *pcTemp = g_pMenmoryAreaHead;

    /*���ÿ���ƫ��*/
    pcTemp = pcTemp + pstFindMangerHead->nOffset;
    memcpy(pcTemp, szUserName, nLength);

    /*д���ļ���*/
    WritMemoryToFile();
}

void AddString(void)
{
    /*szUserNameװ�����ƴ�Ӻõ������ַ��� ��`�ָ��ַ���*/
    char szUserName[(MaxInputLength + 1)*3] = { '\0' };
    char szUserPhone[MaxInputLength + 1] = { '\0' };
    char szUserAddress[MaxInputLength + 1] = { '\0' };
    struct tagManger *pstFindMangerHead = NULL;
    int nLength = 0;

    /*��ȡ�û�����������,�绰,��ַ*/
    GetStrUserInput(szUserName, szUserPhone, szUserAddress);

    /*��ȡ�û�������ַ�������*/
    nLength = GetStrLength(szUserName);

    /*�Ƿ����㹻�Ŀռ����*/
    pstFindMangerHead = FindSpace(nLength);
    if (NULL == pstFindMangerHead)
    {
        printf("�ռ䲻��\r\n");
        return;
    }

    /*����ܷ��� �޸Ĺ����*/
    ModifyManagment(pstFindMangerHead, nLength);

    ModifyMemory(pstFindMangerHead, szUserName, nLength);


}