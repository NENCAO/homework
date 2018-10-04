#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int enter;
	printf("Please enter a integer.\n");
	scanf("%d", &enter);
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", enter);
		enter++;
	}

	getchar();
	getchar();
	return 0;
}
