#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "Input.h"
#include "FileOpearte.h"
/*内存文件的名字*/
#define MEMFILE_NAME "Memory.bin"
/*内存文件打开模式*/
#define MEMOPEN_MODE "rb+"
/*管理文件的名字*/
#define MANAGE_NAME  "Manage.bin"
/*管理文件打开模式*/
#define MANAGE_MODE  "rb+"
#define SUCCESS  1
#define FAIL    -1

static FILE *fpMemStream = NULL; //内存文件流指针
static FILE *fpManStream = NULL; //管理表文件流指针

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*
 *   打开内存文件
 *   失败自动退出
 */

void OpenMemoryFile(void)
{
    if ((fpMemStream = fopen(MEMFILE_NAME, MEMOPEN_MODE)) == NULL)
    {
        printf("打开失败!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("已成功打开!\r\n");
    }
}

/*
 *   关闭内存文件
 *   失败自动退出
 */
void CloseMemoryFile(void)
{
    if (fclose(fpMemStream))
    {
        printf("关闭失败!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("关闭成功!\r\n");
    }
}

/*
 *   写入内存文件
 *   传入写入区的地址 写入长度(字节)
 *   成功返回 SUCCESS
 *   失败返回 FAIL
 */
void MemoryWrite(void *buffer,size_t nSize)
{
    
    size_t nCount = 0;

    nCount = fwrite(buffer, sizeof(char), nSize, fpMemStream);

    if (nSize == nCount)
    {
        printf("全部写入成功!\r\n");
    }
    else if (0 == nCount)
    {
        printf("写入失败!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("未全部写入!\r\n");
        system("pause");
        exit(0);
    }
}

/*
 *   读取内存文件
 *   传入读取区的头地址 读入长度(字节)
 *   失败自动退出
 */
void MemoryRead(void *buffer, size_t nSize)
{
    size_t nCount = 0;

    fseek(fpMemStream, 0, SEEK_SET);
    nCount = fread(buffer, sizeof(char), nSize, fpMemStream);

    if (nSize == nCount)
    {
        printf("全部读入成功!\r\n");
    }
    else if (0 == nCount)
    {
        printf("读取失败!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("未全部读取!\r\n");
        system("pause");
        exit(0);
    }
}


// --------------------内存----------------------//

/*
 *   打开管理表文件
 *   成功返回 SUCCESS
 *   失败返回 FAIL
 */

void OpenManagerFile(void)
{
    if ((fpManStream = fopen(MANAGE_NAME, MANAGE_MODE)) == NULL)
    {
        printf("打开失败!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("已成功打开!\r\n");
    }
}

/*
 *   关闭管理表文件
 *   失败自动退出
 */
void CloseManagerFile(void)
{
    if (fclose(fpManStream))
    {
        printf("关闭失败!\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("关闭成功!\r\n");
    }
}

/*
 *   读取管理表文件
 *   传入内存区的头地址 读入长度(字节)
 *   失败自动退出
 */
void ManagerRead(void *buffer, size_t nSize, size_t nOffset)
{
    size_t nCount = 0;

    if (0 != fseek(fpManStream, nOffset, SEEK_SET))
    {
        printf("文件偏移设置失败! ManagerRead -> fseek\r\n");
        system("pause");
        exit(0);
    }
    

    nCount = fread(buffer, sizeof(char), nSize, fpManStream);

    if (nSize == nCount)
    {
        printf("全部读入成功!\r\n");
    }
    else if (0 == nCount)
    {
        printf("读取失败! ManagerRead -> fread\r\n");
        system("pause");
        exit(0);
    }
    else
    {
        printf("未全部读取! ManagerRead -> fread\r\n");
        system("pause");
        exit(0);
    }
}

/*
 *   读取文件并建立管理表链表
 */
void CreatManagerList(void)
{
    struct tagManger *pstManger = NULL;
    struct tagManger *pstTemp = NULL;
    int nOffset = 0;
    g_pstMangerHead = NULL; //重建链表的时候 重头开始

    OpenManagerFile();

    do
    {
        pstManger = (struct tagManger *)malloc(sizeof(struct tagManger));
        if (NULL == pstManger)
        {
            printf("堆内存申请失败! CreatManagerList -> malloc\r\n");
            system("pause");
            exit(0);
        }

        /*读到尾部结束*/
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
 *   完成修改后 写入链表内容写入管理表
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
            printf("写入失败! WriteManagerList -> fwrite");
            system("pause");
            exit(0);
        }
        pstTemp = pstTemp->pstNext;
        nCount += sizeof(struct tagMangerData);
        fseek(fpManStream, nCount, SEEK_SET);
    }

    /*写入尾部读取标志*/
    fseek(fpManStream, nCount, SEEK_SET);
    if (1 != fwrite(&nFlag, sizeof(nFlag), 1, fpManStream))
    {
        printf("写入失败! WriteManagerList -> fwrite");
        system("pause");
        exit(0);
    }

    CloseManagerFile();
}

/*
 *   读取文件进入内存区
 */
void CreatMemoryList(void)
{
    g_pMenmoryAreaHead = NULL;

    OpenMemoryFile();

    g_pMenmoryAreaHead = (char *)malloc(MAXSIZE);
    if (NULL == g_pMenmoryAreaHead)
    {
        printf("堆内存申请失败! CreatMemoryList -> malloc\r\n");
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