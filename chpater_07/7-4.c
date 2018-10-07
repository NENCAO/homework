#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char c;
	int count = 0;

	printf("Please enter a string # to ends.\n");
	while ((c = getchar()) != '#')
	{
		if (c == '.')
		{
			c = '!';
			count++;
		}

		else if (c == '!')
		{
			printf("!");
			count++;
		}
		printf("%c", c);
	}
	printf("Replace %d times", count);

	getchar();
	getchar();
	return 0;
}
