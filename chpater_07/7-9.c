#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	int test,enter;
	int prime = 0;//检测是否是素数
	printf("Please enter a number.\n");
	scanf("%d", &enter);

	for (enter; enter >= 2; enter--)
	{
		test = (int)sqrt(enter); //sqrt返回的是double的值
		for (int i = 2; i <= test; i++)
		{
			if (enter % i == 0)
			{
				prime = 1;
				break;
			}
		}

		if (prime == 0)
		{
			printf("%d ", enter);
		}

		prime = 0;//还原检测数
	}

	getchar();
	getchar();
	return 0;
}
