#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int array[8];
	int enter;
	char c;

	printf("Please enter eight integer.\n");
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &enter);
		array[i] = enter;
	}

	for (int i = 8 - 1; i >= 0; i--)
	{
		printf("%d ", array[i]);
	}

	getchar();
	getchar();
	return 0;
}
