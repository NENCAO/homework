#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MEMFILE_NAME "Memory.bin"
#define MEMOPEN_MODE "rb+"
#define SUCCESS  1
#define FAIL    -1


/*
 *   ���ڴ��ļ�
 *   �ɹ����� SUCCESS
 *   ʧ�ܷ��� FAIL
 */

static FILE *fpStream = NULL;
int OpenMemoryFile(void)
{
    if ((fpStream = fopen(MEMFILE_NAME, MEMOPEN_MODE)) == NULL)
    {
        printf("��ʧ��!\r\n");
        return FAIL;
    }
    else
    {
        printf("�ѳɹ���!\r\n");
        return SUCCESS;
    }
}

/*
 *   �ر��ڴ��ļ�
 *   �ɹ����� 1
 *   ʧ�ܷ���-1
 */
int CloseMemoryFile(void)
{
    if (fclose(fpStream))
    {
        printf("�ر�ʧ��!\r\n");
        return FAIL;
    }
    else
    {
        printf("�رճɹ�!\r\n");
        return SUCCESS;
    }
}

/*
 *   д���ڴ��ļ�
 *   ����д�����ĵ�ַ д�볤��(�ֽ�)
 *   �ɹ����� SUCCESS
 *   ʧ�ܷ��� FAIL
 */
int MemoryWrite(void *buffer,size_t nSize)
{
    size_t nCount = 0;

    nCount = fwrite(buffer, sizeof(char), nSize, fpStream);

    if (nSize == nCount)
    {
        printf("ȫ��д��ɹ�!\r\n");
        return SUCCESS;
    }
    else if (0 == nCount)
    {
        printf("д��ʧ��!\r\n");
        return FAIL;
    }
    else
    {
        printf("δȫ��д��!\r\n");
        return FAIL;
    }
}

/*
 *   ��ȡ�ڴ��ļ�
 *   �����ȡ����ͷ��ַ д�볤��(�ֽ�)
 *   �ɹ����� SUCCESS
 *   ʧ�ܷ��� FAIL
 */
int MemoryRead(void *buffer, size_t nSize)
{
    size_t nCount = 0;

    fseek(fpStream, 0, SEEK_SET);
    nCount = fread(buffer, sizeof(char), nSize, fpStream);

    if (nSize == nCount)
    {
        printf("ȫ������ɹ�!\r\n");
        return SUCCESS;
    }
    else if (0 == nCount)
    {
        printf("��ȡʧ��!\r\n");
        return FAIL;
    }
    else
    {
        printf("δȫ����ȡ!\r\n");
        return FAIL;
    }
}