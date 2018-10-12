#include <stdio.h>
double aver(double n, double m);
int main(void)
{
	double n = 2;
	double m = 4;

	printf("%lf", aver(n, m));

	getchar();
	return 0;
}

double aver(double n, double m)
{
	double temp;
	n = 1 / n;
	m = 1 / m;
	temp = (n + m) / 2;
	return 1 / temp;
}
