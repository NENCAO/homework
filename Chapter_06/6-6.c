#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b;
	char c;
	while (1)
	{
		printf("Please enter first number.\n");
		scanf("%d", &a);
		while ((c = getchar()) != '\n');
		printf("Please enter second number.\n");
		scanf("%d", &b);
		while ((c = getchar()) != '\n');
		if (b < a)
		{
			printf("second must > a.\n");
			continue;
		}
		break;
	}

	for (int i = 0; i < b - a + 1; i++)
	{
		int temp = a + i;
		printf("%-10d %-10d %-10d\n", temp, temp *temp, temp *temp*temp);
	}

	getchar();
	return 0;
}


