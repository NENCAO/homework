#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	float accrual1 = 0;
	float accrual2 = 0;
	float sum1 = 100;
	float sum2 = 100;
	int year = 0;

	accrual1 += sum1 * 0.1;

	while (sum1 >= sum2)
	{
		accrual2 = sum2 * 0.05;
		sum1 += accrual1;
		sum2 += accrual2;
		year++;
	}


	printf("need %d years.\n", year);
	printf("Daphne have %f.  Deivdre have %f ", sum1, sum2);


	getchar();
	return 0;
}
