#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char cInput[10] = { 0 };
    int nSumDigit = 0;
    int nCount = 0;

    struct month
    {
        char cMonthName[10];
        char cMonthAbb[4];
        int nDate;
        int nMonthNum;
    };

    struct month month[12] =
    {
        {"January","jan",31,1},
        {"February","feb",28,2},
        {"March","mar",31,3},
        {"April","apr",30,4},
        {"May","may",31,5},
        {"June","jun",30,6},
        {"July","jul",31,7},
        {"August","aug",31,8},
        {"September","sep",30,9},
        {"October","oct",31,10},
        {"November","nov",30,11},
        {"December","dec",31,12},
    };

    printf("Please enter a month\r\n");
    scanf("%10s", cInput);

    cInput[0] = toupper(cInput[0]);

    while (strcmp(cInput, month[nCount].cMonthName) != 0)
    {
        nSumDigit += month[nCount].nDate;
        nCount++;
        if (nCount++ > 12)
        {
            printf("Input Error!\r\n");
            system("pause");
            exit(0);
        }
    }

    printf("%d", nSumDigit);

    system("pause");
}