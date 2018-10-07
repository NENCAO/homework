#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char c;
	int s = 0;
	int count = 0;
	while ((c = getchar()) != '#')
	{
		if (c == 'e')
		{
			s = 1;
			continue;//检测是否是e
		}

		if (s == 1&&c == 'i')
		{
			count++;
		}

		s = 0;//e后不是i要还原
	}
	printf("ei have %d", count);

	getchar();
	getchar();
	return 0;
}
