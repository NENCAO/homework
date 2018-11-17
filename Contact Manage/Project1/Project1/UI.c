#include <stdio.h>
#include "FileOpearte.h"

extern struct tagManger *g_pstMangerHead;
extern char *g_pMenmoryAreaHead;
/*
 *   自定义打印字符串的函数
 *   传入sz类型的字符串
 *   打印传入的字符串
 */
void MyPrint(char *szStr)
{
    printf("%s", szStr);
}


/*
 *   用户初始界面
 *   无参数 无逻辑运算
 *   仅用于显示界面
 */
void StartInterface(void)
{
    int nCount = 0;

    for (nCount = 0; nCount < 40; nCount++)
    {
        MyPrint("* ");
    }
    MyPrint("\r\n");
    MyPrint("* ");

    for (nCount = 0; nCount <= 20; nCount++)
    {
        MyPrint(" ");
    }

    MyPrint("Dynamic Management System");

    for (nCount = 0; nCount < 30; nCount++)
    {
        MyPrint(" ");
    }
    MyPrint("* ");
    MyPrint("\r\n");

    for (nCount = 0; nCount < 40; nCount++)
    {
        MyPrint("* ");
    }

    MyPrint("\r\n");

    MyPrint("1.增加字符串         2.删除字符串\
             3.修改字符串         4.查询字符串\
         \r\n5.统计字母           6.查看存储信息\
           7.碎片整理");

    MyPrint("\r\n");
}

/*
 *   显示用户输入后的字符串
 */
void ShowInputString(void)
{
    struct tagManger *stMangerTemp = g_pstMangerHead;
    char *stMemoryTemp = g_pMenmoryAreaHead;
    int nCount = 0;

    MyPrint("                                 当前字符串\r\n");
    MyPrint("================================================================================\r\n");

    while (NULL != stMangerTemp)
    {
        if (1 == stMangerTemp->isOccupy)
        {
            printf("姓名:");
            while ('`' != *(stMemoryTemp + stMangerTemp->nOffset + nCount))
            {
                putchar(*(stMemoryTemp + stMangerTemp->nOffset + nCount));
                nCount++;
            }
            printf("     ");
            nCount++;

            printf("手机:");
            while ('`' != *(stMemoryTemp + stMangerTemp->nOffset + nCount))
            {
                putchar(*(stMemoryTemp + stMangerTemp->nOffset + nCount));
                nCount++;
            }
            printf("     ");
            nCount++;

            printf("地址:");
            while ('\0' != *(stMemoryTemp + stMangerTemp->nOffset + nCount))
            {
                putchar(*(stMemoryTemp + stMangerTemp->nOffset + nCount));
                nCount++;
            }

            printf("\r\n");
        }
        stMangerTemp = stMangerTemp->pstNext;
        nCount = 0;
    }

    MyPrint("================================================================================\r\n");
}