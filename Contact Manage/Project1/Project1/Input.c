#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Input.h"

/*
 *   作用:获取用户输入的字符串
 *   参数:传入char型数组的指针 
 *   返回:void
 *
 *   注意:
 *   1. char数组应该要 >= MaxInputLength + 1 (还要放'\0')
 *   2. 只能输入100个字符以内的字符串(在Input.h中可以修改)
 */
void GetStrUserInput(char * szUserName, char * szUserPhone, char *szUserAddress)
{
    int nTemp = 0;/*清缓存用*/
    int nCount = 0;

    /*输入前 需要将以前的输入清理掉*/
    memset(szUserName, 0, sizeof(szUserName));
    memset(szUserPhone, 0, sizeof(szUserPhone));
    memset(szUserAddress, 0, sizeof(szUserAddress));

    printf("请输入姓名 最多输入100个字符 空格或者回车结束输入\r\n");
    nCount = scanf(INPUT_TYPE(MaxInputLength), szUserName);
    if (nCount == 0)
    {
        printf("输入失败\r\n");
        system("pause");
        exit(0);
    }
    while ((nTemp = getchar()) != '\n' && nTemp != EOF);

    printf("请输入电话 最多输入100个字符 空格或者回车结束输入\r\n");
    nCount = scanf(INPUT_TYPE(MaxInputLength), szUserPhone);
    if (nCount == 0)
    {
        printf("输入失败\r\n");
        system("pause");
        exit(0);
    }
    while ((nTemp = getchar()) != '\n' && nTemp != EOF);

    printf("请输入地址 最多输入100个字符 空格或者回车结束输入\r\n");
    nCount = scanf(INPUT_TYPE(MaxInputLength), szUserAddress);
    if (nCount == 0)
    {
        printf("输入失败\r\n");
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
 *   作用:获取用户输入的字符串长度
 *   参数:传入char型数组的指针
 *   返回:字符串的长度(包括\0)
 *
 *   注意:
 *   1. 长度已经包含\0占用的长度
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
 *   接受用户输入数字
 *   返回int型整数
 */
int GetIntUserInput(void)
{
    int nInput = 0;
    int nTemp = 0;/*清缓存用*/

    while (scanf("%d", &nInput) == 0)
    {
        printf("请输入数字!\r\n");
        while ((nTemp = getchar()) != '\n');
    }

    while ((nTemp = getchar()) != '\n');

    return nInput;
}

/*
 *   接受用户输入查找的字符串
 *   传入存放字符串的地址
 */
void GetUserFindInput(char * cInput)
{
    int nTemp = 0;/*清缓存用*/

    while (scanf(INPUT_TYPE(MaxInputLength), cInput) == 0)
    {
        printf("Input Error please re-enter");
        while ((nTemp = getchar()) != '\n' && nTemp != EOF);
    }

    while ((nTemp = getchar()) != '\n'&& nTemp != EOF);

    return;
}