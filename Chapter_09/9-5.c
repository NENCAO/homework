#include <stdio.h>
double larger_of(double x, double y);
int main(void)
{
	double x = 5.7;
	double y = 6.6;

	x = larger_of(x, y);
	y = larger_of(x, y);
	printf("%lf  %lf", x, y);

	getchar();
	getchar();
	return 0;
}

double larger_of(double x, double y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}

}
