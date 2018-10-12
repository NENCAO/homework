#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double custom(double n, int p);
int main(void)
{
	double x= 5;
	int xpow = -1;
	printf("%lf",custom(x, xpow));
	getchar();
	getchar();
	return 0;
}

double custom (double n, int p)
{
	double pow = 1;
	int i, temp;

	if (p == 0)
	{
		if (n == 0)
		{
			printf("undefine!\n");
			return 1;
		}
		else
		{
			return 1;
		}

	}
	else if (p > 0)
	{
		for (i = 0; i < p; i++)
		{
			pow *= n;
		}
	}
	else
	{

		for (i = 0; i > p; i--)
		{
			pow /= n;
		}
	}
	return pow;
}