#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c;
	int lower = 0;
	int upper = 0;
	while ((c = getchar()) != EOF)
	{
		if (islower(c))
		{
			lower++;
		}
		else if (isupper(c))
		{
			upper++;
		}
	}

	printf("There are %d lower and %d upper.\n", lower, upper);

	getchar();
	getchar();
	return 0;
}
