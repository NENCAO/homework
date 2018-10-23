/*
  计算 10000! 的结果并打印
  运算时间在1S内
*/

#include <stdio.h>    
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159
#define E 2.718
int factorial_digit(int nMlutply);

int main(void)
{
    clock_t t1, t2;//计时器
    t1 = clock();

    int nResult[40001] = { 0 };//存放结果的数组
    int nArrayMax = 40000;//数组尾部的位置
    int nMlutply = 2;//初始乘数
    int nResultPointer = 0;//数组指向的位置
    int nCarry = 0;//进位数
    int nFactorial[10000] = { 0 };//存放阶乘位数的数组
    int nCount = 0;

    for (nCount = 1; nCount <= 10000; nCount++)//存放阶乘位数到数组中
    {
        nFactorial[nCount - 1] = factorial_digit(nCount);
    }

    nResult[0] = 1;//初始化第一个元素为1
    while (nMlutply <= 10000)//阶乘数
    {
        nCarry = 0;
        nResultPointer = 0;//初始化进位和数组位置

        while (nResultPointer <= nFactorial[nMlutply - 1] / 5)//检测到阶乘最大位数即可 数组从0开始 所以要-1
        {
            nResult[nResultPointer] = nResult[nResultPointer] * nMlutply + nCarry;//乘以乘数 + 进位
            nCarry = nResult[nResultPointer] / 100000;//获得进位
            nResult[nResultPointer] %= 100000;//位数还原成一位
            nResultPointer++;//向后移动
        }
        nMlutply++;
    }

    t2 = clock();//计时器

    nResultPointer = nFactorial[9999] - 1;//已知结果的长度

    while (nResult[nResultPointer] == 0)//从后找不为0的数 即为结果的开头
    {
        nResultPointer--;
    }

    printf("%d", nResult[nResultPointer]);//第一位可能不满足5位
    nResultPointer--;

    while (nResultPointer >= 0)
    {
        printf("%05d", nResult[nResultPointer]);
        nResultPointer--;
    }

    printf("\r\nRun time is %dms", t2 - t1);

    system("pause");
    return 0;
}

int factorial_digit(int nMlutply)
{
    double nDigit = 0;
    nDigit = log10(sqrt(2 * PI*nMlutply)) + nMlutply * log10(nMlutply / E) + 1;//斯特林公式求阶乘位数
    nDigit = (int)nDigit;
    return nDigit;
}