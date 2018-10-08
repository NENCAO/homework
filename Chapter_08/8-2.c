#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char c;
	int count = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			printf("\\n - %d ", c);
			count++;
		}
		else if (c == '\t')
		{
			printf("\\t - %d ", c);
			count++;
		}
		else
		{
			printf("%c - %d ", c, c);
			count++;
		}

		if (count == 10)
		{
			printf("\n");
			count = 0;
		}
	}

	getchar();
	getchar();
	return 0;
}