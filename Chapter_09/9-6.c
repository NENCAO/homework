#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void compare(double *a, double*b, double *c);
int main(void)
{
	double a[3] = { 3,2,1 };
	compare(a, a + 1, a + 2);
	printf("%lf %lf %lf", a[0], a[1],a[2]);
	getchar();
	getchar();
	return 0;
}

void compare(double *a, double*b, double *c)
{
	double temp;
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}

	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}

	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}