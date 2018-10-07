#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int odd = 0;
	int even = 0; 
	int oddc = 0;
	int evenc = 0;
	float odda = 0;
	float evena = 0;

	int enter;
	
	scanf("%d", &enter);
	while (enter != 0)
	{
		if (enter % 2 != 0)
		{
			oddc++;
			odd += enter;
		}
		else
		{
			evenc++;
			even += enter;
		}
		scanf("%d", &enter);
	}

	if (oddc != 0)
	{
		odda = ((float)odd / oddc); //右边都是int型 返回不了float的数据 必须做一次强制转换
	}
	if (even != 0)
	{
		evena = ((float)even / evenc);
	}

	printf("%d odd numbers average %f\n"
		"%d eve number average %f\n"
		, oddc,odda, evenc, evena);

	getchar();
	getchar();
	return 0;
}

