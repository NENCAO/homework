#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double cube(double a);

int main(void)
{
	double enter;
	printf("Please enter a double.\n");
	scanf("%lf", &enter);
	printf("%lf",cube(enter));

	getchar();
	getchar();
	return 0;
}

double cube(double a)
{
	return a*a*a;
}