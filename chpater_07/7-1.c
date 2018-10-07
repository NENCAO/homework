#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char c;
	int space = 0;
	int back = 0;
	int character = 0;

	printf("Please enter a string # to end\n");
	while ((c = getchar()) != '#')
	{
		if (c == ' ')
		{
			space++;
		}

		if (c == '\n')
		{
			back++;
		}

		character++;
	}
	printf("space have %d  enter have %d  character have %d.\n", space, back, character);

	getchar();
	getchar();
	return 0;
}
