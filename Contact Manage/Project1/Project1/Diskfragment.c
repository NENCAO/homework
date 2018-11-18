#include <stdio.h>
#include <string.h>
#include "FileOpearte.h"
#include "Delete.h"

/*管理表链表的首地址*/
extern struct tagManger *g_pstMangerHead;
/*字符串堆区的首地址*/
extern char *g_pMenmoryAreaHead;

void DiskFragment(void)
{
    struct tagManger *pstTemp = g_pstMangerHead;
    struct tagManger *pstNext = NULL;
    char *pcMemTemp = g_pMenmoryAreaHead;
    int nTemp = 0;

    pstNext = pstTemp->pstNext;

    while (NULL != pstNext)
    {
        /*能进行补位的地方 必然前面空闲 后面占用*/
        if (0 == pstTemp->isOccupy && 1 == pstNext->isOccupy)
        {
            /*把内存移动到空闲位置上*/
            memcpy(pcMemTemp + pstTemp->nOffset, pcMemTemp + pstNext->nOffset, pstNext->nSize);

            /*交换链表数据*/
            pstNext->isOccupy = 0;
            pstNext->nOffset = pstTemp->nOffset + pstNext->nSize;
            nTemp = pstNext->nSize;
            pstNext->nSize = pstTemp->nSize;

            //---------------------占用链表更新为空闲---------------------//
            pstTemp->isOccupy = 1;
            pstTemp->nSize = nTemp;
            //---------------------空闲链表更新为占用---------------------//

            //合并之后可能出现2个连续空链表 进行合并后再继续从pstTemp开始检查
            ListMerging();
            continue;
        }
        pstTemp = pstTemp->pstNext;
        pstNext = pstTemp->pstNext;
    }
    WritMemoryToFile();
    WriteManagerToFile();
}