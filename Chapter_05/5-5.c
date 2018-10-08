#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int count;
	int sum = 0;
	int i = 0;
	printf("Please enter days.\n");
	scanf("%d", &count);
	while (i++ < count)
	{
		sum += i;
	}
	printf("sum = %d\n", sum);

	getchar();
	getchar();
	return 0;
}
