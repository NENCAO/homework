#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char cKey[15] = { 'f' + 10,'u' + 10,'d' + 10,'u' + 10,'j' + 10,'i' + 10,'n' + 10,'u' + 10,'m' + 10,'o' + 10,'n' + 10,'e' + 10 };
char inputKey[15] = { 0 };
void get_key(void);

int main(void)
{
    int inputChance = 3;

    get_key();

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        if (key_verification(inputKey) == 0)
        {
            printf("Password error! You remaining %d chances\r\n", inputChance--);
            memset(inputKey, 0, sizeof(char) * 15);
            get_key();
            printf("\n");
        }
        else
        {
            break;
        }
    }

    if (inputChance == 0)
    {
        printf("Self-destruct in five seconds %c", 7);
    }
    else
    {
        printf("Login successful!\r\n");
    }

    system("pause");
}

void get_key(void)
{
    char cTakeinput = '\0';
    int cKeyLength = 0;


    while (1)
    {
        cTakeinput = _getch();//获取用户输入

        if (cTakeinput == 0)//_getch()实际获取了string会返回 ch & \0 所以需要移除\0
        {
            continue;
        }
        else if (cTakeinput < 0)//因为一些组合键会先返回一个负数(比如方向键 -32) 吃掉第二次生成的char
        {
            _getch();
        }
        else if ('\b' == cTakeinput)//Backspace功能模块
        {
            if (cKeyLength == 0)//防止cKeyLength越界
            {
                continue;
            }

            cKeyLength--;
            printf("\b \b");//光标前移并替换成空格显示\0不会刷新缓存区
            continue;
        }

        if (cTakeinput == '\r')
        {
            return;
        }

        if (cKeyLength <= 15)
        {
            if (input_test(cTakeinput))
            {
                inputKey[cKeyLength] = cTakeinput + 10;
                cKeyLength++;
                printf("*");
            }
        }
    }

}

int input_test(char cTestChar)//测试输入是否为字母和数字
{
    if (cTestChar < '0')
    {
        return 0;
    }
    else if (cTestChar > '9' && cTestChar < 'A')
    {
        return 0;
    }
    else if (cTestChar > 'Z' && cTestChar < 'a')
    {
        return 0;
    }
    else if (cTestChar > 'z')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int key_verification(char* inputKey)
{
    int nCount = 0;
    for (nCount; nCount < 15; nCount++)
    {
        if(inputKey[nCount] != cKey[nCount])
        {
            return 0;
        }
        nCount++;
    }
    return 1;
}