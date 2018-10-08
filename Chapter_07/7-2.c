#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char temp[50];
	int i = 0;
	int j = 0;
	int count = 0;
	char c;

	printf("Please enter a string # to ends.\n");
	while ((c = getchar()) != '#')
	{
		temp[i] = c;
		i++;
	}

	while (j < i-1)
	{
		printf("%c-%d   ", temp[j], temp[j]);
		j++;
		count++;

		if (count % 8 == 0)
		{
			printf("\n");
		}
	}
	getchar();
	getchar();
	return 0;
}
