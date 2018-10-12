#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int custom(char *f);
int main(void)
{
	int a[40];
	scanf("%s", a);
	custom(a);

	getchar();
	getchar();
	return 0;
}

int custom(char *f)
{
	if (*f > 'A'&&*f<'Z' || *f>'a'&&*f < 'z')
	{
		printf("%c - ", *f);
		if (*f >= 'a')
		{
			printf("%d", *f - 96);
		}
		else
		{
			printf("%d", *f - 64);
		}
	}
	else
	{
		return -1;
	}
}