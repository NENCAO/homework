#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double Temperatures(double h);
int main(void)
{
	double hua;
	int c;
	char a;
	printf("Please enter Fahrenheit.\n");
	while ((c = scanf("%lf", &hua)))
	{
		Temperatures(hua);
		while ((a = getchar()) != '\n');
		printf("\nPlease enter Fahrenheit.\n");
	}
	
	getchar();
	getchar();
	return 0;
}

double Temperatures(double hua)
{
	double se, kai;
	se = 5.0 / 9.0*(hua - 32.0);
	kai = se + 273.16;
	printf("%.3lf℉ = %.3lf℃ = %.3lfK\n", hua, se, kai);
}