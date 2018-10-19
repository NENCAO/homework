#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//仅适用于正数和int范围内的数字


void dectobin(int n);
int main(void)
{
	int nNum1 = 200;
	int nNum2 = 4587;
	
	dectobin(nNum1);
	dectobin(nNum2);
	
	return 0;
}

//将结果存在一个long函数中,通过k*10移位 不需要用数组的方法 缺点是容易溢出
void dectobin(int n) 
{
	long result = 0, k = 1;
	int i, temp;
	temp = n;
	while (temp)
	{
		i = temp % 2;
		result = k * i + result;
		k = k * 10;
		temp = temp / 2;
	}
	printf("%d\n", result);
}
