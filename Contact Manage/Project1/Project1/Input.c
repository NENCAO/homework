#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxInputLength 100
#define _INPUT_TYPE(x) "%"#x"s"
#define INPUT_TYPE(x) _INPUT_TYPE(x)

/*
 *   获取用户输入的字符串
 *   传入char型数组的指针 char数组应该要 >= MaxInputLength + 1 (还要放'\0')
 *   只能输入100个字符以内的字符串
 */
void GetStrUserInput(char * cInput)
{
    int nTemp = 0;/*清缓存用*/
    int nCount = 0;

    /*输入前 需要将以前的输入清理掉*/
    for (nCount = 0; nCount < MaxInputLength; nCount++)
    {
        cInput[nCount] = '\0';
    }

    printf("最多输入100个字符  空格或者回车结束输入\r\n");
    scanf(INPUT_TYPE(MaxInputLength), cInput);
    while ((nTemp = getchar()) != '\n' && nTemp != EOF);

    return;
}
