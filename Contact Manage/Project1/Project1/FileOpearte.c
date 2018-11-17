#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "Input.h"
#include "FileOpearte.h"
/*�ڴ��ļ�������*/
#define MEMFILE_NAME "Memory.bin"
/*�ڴ��ļ���ģʽ*/
#define MEMOPEN_MODE "rb+"
/*�����ļ�������*/
#define MANAGE_NAME  "Manage.bin"
/*�����ļ���ģʽ*/
#define MANAGE_MODE  "rb+"
#define SUCCESS  1
#define FAIL    -1

static FILE *fpMemStream = NULL; //�ڴ��ļ���ָ��
static FILE *fpManStream = NULL; //������ļ���ָ��

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*
 *   ���ڴ��ļ�
 *   ʧ���Զ��˳�
 */

void OpenMemoryFile(void)
{
    if ((fpMemStream = fopen(MEMFILE_NAME, MEMOPEN_MODE)) == NULL)
    {
        printf("��ʧ��!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("�ѳɹ���!\r\n");
    }
}

/*
 *   �ر��ڴ��ļ�
 *   ʧ���Զ��˳�
 */
void CloseMemoryFile(void)
{
    if (fclose(fpMemStream))
    {
        printf("�ر�ʧ��!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("�رճɹ�!\r\n");
    }
}

/*
 *   д���ڴ��ļ�
 *   ����д�����ĵ�ַ д�볤��(�ֽ�)
 *   �ɹ����� SUCCESS
 *   ʧ�ܷ��� FAIL
 */
void MemoryWrite(void *buffer,size_t nSize)
{
    
    size_t nCount = 0;

    nCount = fwrite(buffer, sizeof(char), nSize, fpMemStream);

    if (nSize == nCount)
    {
        printf("ȫ��д��ɹ�!\r\n");
    }
    else if (0 == nCount)
    {
        printf("д��ʧ��!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("δȫ��д��!\r\n");
        system("pause");
        exit(0);
    }
}

/*
 *   ��ȡ�ڴ��ļ�
 *   �����ȡ����ͷ��ַ ���볤��(�ֽ�)
 *   ʧ���Զ��˳�
 */
void MemoryRead(void *buffer, size_t nSize)
{
    size_t nCount = 0;

    fseek(fpMemStream, 0, SEEK_SET);
    nCount = fread(buffer, sizeof(char), nSize, fpMemStream);

    if (nSize == nCount)
    {
        printf("ȫ������ɹ�!\r\n");
    }
    else if (0 == nCount)
    {
        printf("��ȡʧ��!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("δȫ����ȡ!\r\n");
        system("pause");
        exit(0);
    }
}


// --------------------�ڴ�----------------------//

/*
 *   �򿪹�����ļ�
 *   �ɹ����� SUCCESS
 *   ʧ�ܷ��� FAIL
 */

void OpenManagerFile(void)
{
    if ((fpManStream = fopen(MANAGE_NAME, MANAGE_MODE)) == NULL)
    {
        printf("��ʧ��!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("�ѳɹ���!\r\n");
    }
}

/*
 *   �رչ�����ļ�
 *   ʧ���Զ��˳�
 */
void CloseManagerFile(void)
{
    if (fclose(fpManStream))
    {
        printf("�ر�ʧ��!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("�رճɹ�!\r\n");
    }
}

/*
 *   ��ȡ������ļ�
 *   �����ڴ�����ͷ��ַ ���볤��(�ֽ�)
 *   ʧ���Զ��˳�
 */
void ManagerRead(void *buffer, size_t nSize, size_t nOffset)
{
    size_t nCount = 0;

    if (0 != fseek(fpManStream, nOffset, SEEK_SET))
    {
        printf("�ļ�ƫ������ʧ��! ManagerRead -> fseek\r\n");
        system("pause");
        exit(0);
    }
    

    nCount = fread(buffer, sizeof(char), nSize, fpManStream);

    if (nSize == nCount)
    {
        printf("ȫ������ɹ�!\r\n");
    }
    else if (0 == nCount)
    {
        printf("��ȡʧ��! ManagerRead -> fread\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("δȫ����ȡ! ManagerRead -> fread\r\n");
        system("pause");
        exit(0);
    }
}

/*
 *   ��ȡ�ļ����������������
 */
void CreatManagerList(void)
{
    struct tagManger *pstManger = NULL;
    struct tagManger *pstTemp = NULL;
    int nOffset = 0;
    g_pstMangerHead = NULL; //�ؽ������ʱ�� ��ͷ��ʼ

    OpenManagerFile();

    do
    {
        pstManger = (struct tagManger *)malloc(sizeof(struct tagManger));
        if (NULL == pstManger)
        {
            printf("���ڴ�����ʧ��! CreatManagerList -> malloc\r\n");
            system("pause");
            exit(0);
        }

        /*����β������*/
        ManagerRead(pstManger, sizeof(struct tagMangerData), nOffset);
        if (pstManger->isOccupy == 0xffffffff)
        {
            free(pstManger);
            break;
        }
        pstManger->pstNext = NULL;
        nOffset += sizeof(struct tagMangerData);

        if (NULL == g_pstMangerHead)
        {
            g_pstMangerHead = pstManger;
        }
        else
        {
            pstTemp->pstNext = pstManger;
        }

        pstTemp = pstManger;
        
    } while (1);

    CloseManagerFile();
}

/*
 *   ����޸ĺ� д����������д������
 */
void WriteManagerToFile(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    int nCount = 0;
    int nFlag = 0xffffffff;

    OpenManagerFile();
    
    while (pstTemp != NULL)
    {
        if (1 != fwrite(pstTemp, sizeof(struct tagMangerData), 1, fpManStream))
        {
            printf("д��ʧ��! WriteManagerList -> fwrite");
            system("pause");
            exit(0);
        }
        pstTemp = pstTemp->pstNext;
        nCount += sizeof(struct tagMangerData);
        fseek(fpManStream, nCount, SEEK_SET);
    }

    /*д��β����ȡ��־*/
    fseek(fpManStream, nCount, SEEK_SET);
    if (1 != fwrite(&nFlag, sizeof(nFlag), 1, fpManStream))
    {
        printf("д��ʧ��! WriteManagerList -> fwrite");
        system("pause");
        exit(0);
    }

    CloseManagerFile();
}

/*
 *   ��ȡ�ļ������ڴ���
 */
void CreatMemoryList(void)
{
    g_pMenmoryAreaHead = NULL;

    OpenMemoryFile();

    g_pMenmoryAreaHead = (char *)malloc(MAXSIZE);
    if (NULL == g_pMenmoryAreaHead)
    {
        printf("���ڴ�����ʧ��! CreatMemoryList -> malloc\r\n");
        system("pause");
        exit(0);
    }

    MemoryRead(g_pMenmoryAreaHead, MAXSIZE);

    CloseMemoryFile();
}

void WritMemoryToFile(void)
{
    OpenMemoryFile();

    MemoryWrite(g_pMenmoryAreaHead, MAXSIZE);

    CloseMemoryFile();
}