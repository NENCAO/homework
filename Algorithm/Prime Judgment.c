#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>//sqrt()的文件头
int main(void)
{
	int enter;
	int sq;//判断素数只需要2-根号n
	int s = 0; //标记素数 0为素数

	printf("Please enter a number.\n");
	scanf("%d", &enter);

	for (int i = 2; i <= enter; i++)//外部循环
	{
		sq = sqrt(i);//2的情况下 sq=1是进不去for循环的 不必对2做特殊处理了
		for (int j = 2; j <= sq; j++)//循环判断并标记 
		{
			if (i % j == 0)
			{
				s = 1;
				break;

			}
		}
		
		if (s == 0)
		{
			printf("%d ", i);
		}
		s = 0;
	}

	getchar();
	getchar();
	return 0;
}