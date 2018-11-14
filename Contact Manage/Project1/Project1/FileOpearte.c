#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MEMFILE_NAME "Memory.bin"
#define MEMOPEN_MODE "rb+"
#define SUCCESS  1
#define FAIL    -1


/*
 *   打开内存文件
 *   成功返回 SUCCESS
 *   失败返回 FAIL
 */

static FILE *fpStream = NULL;
int OpenMemoryFile(void)
{
    if ((fpStream = fopen(MEMFILE_NAME, MEMOPEN_MODE)) == NULL)
    {
        printf("打开失败!\r\n");
        return FAIL;
    }
    else
    {
        printf("已成功打开!\r\n");
        return SUCCESS;
    }
}

/*
 *   关闭内存文件
 *   成功返回 1
 *   失败返回-1
 */
int CloseMemoryFile(void)
{
    if (fclose(fpStream))
    {
        printf("关闭失败!\r\n");
        return FAIL;
    }
    else
    {
        printf("关闭成功!\r\n");
        return SUCCESS;
    }
}

/*
 *   写入内存文件
 *   传入写入区的地址 写入长度(字节)
 *   成功返回 SUCCESS
 *   失败返回 FAIL
 */
int MemoryWrite(void *buffer,size_t nSize)
{
    size_t nCount = 0;

    nCount = fwrite(buffer, sizeof(char), nSize, fpStream);

    if (nSize == nCount)
    {
        printf("全部写入成功!\r\n");
        return SUCCESS;
    }
    else if (0 == nCount)
    {
        printf("写入失败!\r\n");
        return FAIL;
    }
    else
    {
        printf("未全部写入!\r\n");
        return FAIL;
    }
}

/*
 *   读取内存文件
 *   传入读取区的头地址 写入长度(字节)
 *   成功返回 SUCCESS
 *   失败返回 FAIL
 */
int MemoryRead(void *buffer, size_t nSize)
{
    size_t nCount = 0;

    fseek(fpStream, 0, SEEK_SET);
    nCount = fread(buffer, sizeof(char), nSize, fpStream);

    if (nSize == nCount)
    {
        printf("全部读入成功!\r\n");
        return SUCCESS;
    }
    else if (0 == nCount)
    {
        printf("读取失败!\r\n");
        return FAIL;
    }
    else
    {
        printf("未全部读取!\r\n");
        return FAIL;
    }
}