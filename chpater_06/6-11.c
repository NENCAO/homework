#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	double sum1 = 0;
	double sum2 = 0;
	int cycles;
	double n = 1;
	double m = 1;
	printf("Please enter ther number of cycles.\n");
	scanf("%d", &cycles);

	while (n <= cycles)
	{
		sum1 += 1.0 / n;
		sum2 += m / n;

		n++;
		m *= -1.0;
	}

	printf("formula1 is %lf\n"
		"formula2 is %lf\n", sum1, sum2);


	getchar();
	getchar();
	return 0;
}
