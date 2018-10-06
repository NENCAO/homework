#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int friend = 5;
	int minus = 1;
	int week = 0;
	while (1)
	{
		friend -= minus;
		friend *= 2;
		minus++;
		week++;
		if (friend > 150)
		{
			break;
		}
	}

	printf("%d", week);

	getchar();
	return 0;
}
