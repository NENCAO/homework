#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double custom(double n, int p);
int main(void)
{
	double x = 5;
	int xpow = -1;
	printf("%lf", custom(x, xpow));
	getchar();
	getchar();
	return 0;
}

double custom(double n, int p)
{
	double pow;

	if (p > 0)
	{
		pow = n * custom(n, p - 1);
	}
	else if (p < 0)
	{
		if (n != 0)
		{
			pow = (1.0 / n) * custom(n, p + 1);
		}
		else
		{
			pow = 0;
		}
	}
	else
	{
		pow = 1;
	}
	return pow;
}