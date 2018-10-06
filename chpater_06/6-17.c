#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	float sum = 100;
	int year = 0;
	while (sum > 0)
	{
		sum += sum * 0.08;
		sum -= 10;
		year++;
	}

	printf("%d", year);


	getchar();
	return 0;
}
