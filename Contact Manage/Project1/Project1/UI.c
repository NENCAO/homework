#include <stdio.h>


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