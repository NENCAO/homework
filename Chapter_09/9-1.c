#include <stdio.h>
double compare(double x, double y);
int main(void)
{
	double x = 5.5;
	double y = 6.8;

	printf("%lf", compare(x, y));

	getchar();
	return 0;
}

double compare(double x, double y)
{
	if (x > y)
	{
		return y;
	}
	else
	{
		return x;
	}

}