#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MONTHS 12 /*一年的月份数*/
#define YEARS 5 /*年数*/

int main(void)
{
    const float aryfRain[YEARS][MONTHS] =
    {
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    int nYear = 0;
    int nMonth = 0;
    float fSubtot = 0.0f;
    float fTotal = 0.0f;

    printf(" YEAR     RAINFAIL    (inches)\r\n");
    /*每一年降水的总和*/
    for (nYear = 0, fTotal = 0.0f; nYear < YEARS; nYear++)
    {
        for (nMonth = 0, fSubtot = 0.0f; nMonth < MONTHS; nMonth++)
        {
            //fSubtot += aryfRain[nYear][nMonth];
            fSubtot += *(*(aryfRain + nYear) + nMonth);
        }
        printf("%5d %15.1f\r\n", 2010 + nYear, fSubtot);
        fTotal += fSubtot;/*5年的降水总量*/
    }

    printf("\r\nThe yearly average is %.1f inches.\r\n\r\n", fTotal / YEARS);
    printf("MONTHLY AVERAGES:\r\n\r\n");
    printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  ");
    printf("Nov  Dec\r\n");

    for (nMonth = 0; nMonth < MONTHS; nMonth++)
    {
        for (nYear = 0, fSubtot = 0.0f; nYear < YEARS; nYear++)
        {
            //fSubtot += aryfRain[nYear][nMonth];
            fSubtot += *(*(aryfRain + nYear) + nMonth);
        }
        printf("%-5.1f", fSubtot / YEARS);
    }
    printf("\r\n");

    system("pause");
    return 0;
}
