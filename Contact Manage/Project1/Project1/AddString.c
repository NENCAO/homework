#include <stdlib.h>
#include <string.h>
#include "FileOpearte.h"
#include "Input.h"


extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;

/*
 *   查找是剩余空间是否足够
 *   传入用户输入字符串长度
 *   成功找到 返回 链表所在的指针
 *   查找失败 返回 NULL
 */
void *FindSpace(int nLength)
{
    struct tagManger *pstTemp = g_pstMangerHead;

    while (NULL != pstTemp)
    {
        /*长度足够并且处于空闲状态*/
        if (nLength <= pstTemp->nSize && pstTemp->isOccupy == 0)
        {
            return pstTemp;
        }
        pstTemp = pstTemp->pstNext;
    }
    return NULL;
}

/*
 *   修改管理表 并写入文件
 *   传入找到的管理表的位置指针 字符串的长度
 */
void ModifyManagment(struct tagManger *pstFindMangerHead,int nLength)
{
    struct tagManger *pstTemp = NULL;

    /*如果长度占完了 不用再建空闲表*/
    if (nLength == pstFindMangerHead->nSize)
    {
        /* 占用状态置为1 占用*/
        pstFindMangerHead->isOccupy = 1;

        /* 距首地址偏移 = 当前位置(不变)*/
        //pstFindMangerHead->nOffset;

        /* 字符串占用长度 */
        pstFindMangerHead->nSize = nLength;

        /*管理表写入文件*/
        WriteManagerToFile();
        return;
    }
    else
    {
        pstTemp = (struct tagManger *)malloc(sizeof(struct tagManger));
        if (NULL == pstTemp)
        {
            printf("内存申请失败 AddString -> ModifyManagment\r\n");
            system("pause");
            exit(0);
        }

        /* 占用状态置为0 空闲 */
        pstTemp->isOccupy = 0;

        /*距首地址距离变为 原偏移+占用长度*/
        pstTemp->nOffset = pstFindMangerHead->nOffset + nLength;

        /* 空闲大小变为 原大小-占用大小 */
        pstTemp->nSize = pstFindMangerHead->nSize - nLength;

        /*指向原链表的下一个地址*/
        pstTemp->pstNext = pstFindMangerHead->pstNext;
        //----------------------空闲表更新---------------------//

        /* 占用状态置为1 占用*/
        pstFindMangerHead->isOccupy = 1;

        /* 距首地址偏移 = 当前位置(不变)*/
        //pstFindMangerHead->nOffset;

        /* 字符串占用长度 */
        pstFindMangerHead->nSize = nLength;

        /*指向新空闲区链表的首地址*/
        pstFindMangerHead->pstNext = pstTemp;

        /*管理表写入文件*/
        WriteManagerToFile();
    }
    return;
}

/*
 *   修改字符串内存 并写入文件
 *   传入找到的管理表的位置指针 输入字符串的首地址 字符串的长度
 */
void ModifyMemory(struct tagManger *pstFindMangerHead,char *szUserName, int nLength)
{
    char *pcTemp = g_pMenmoryAreaHead;

    /*设置拷贝偏移*/
    pcTemp = pcTemp + pstFindMangerHead->nOffset;
    memcpy(pcTemp, szUserName, nLength);

    /*写入文件中*/
    WritMemoryToFile();
}

void AddString(void)
{
    /*szUserName装了最后拼接好的整个字符串 由`分隔字符串*/
    char szUserName[(MaxInputLength + 1)*3] = { '\0' };
    char szUserPhone[MaxInputLength + 1] = { '\0' };
    char szUserAddress[MaxInputLength + 1] = { '\0' };
    struct tagManger *pstFindMangerHead = NULL;
    int nLength = 0;

    /*获取用户的输入姓名,电话,地址*/
    GetStrUserInput(szUserName, szUserPhone, szUserAddress);

    /*获取用户输入的字符串长度*/
    nLength = GetStrLength(szUserName);

    /*是否有足够的空间放下*/
    pstFindMangerHead = FindSpace(nLength);
    if (NULL == pstFindMangerHead)
    {
        printf("空间不足\r\n");
        return;
    }

    /*如果能放下 修改管理表*/
    ModifyManagment(pstFindMangerHead, nLength);

    ModifyMemory(pstFindMangerHead, szUserName, nLength);


}