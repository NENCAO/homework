#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int lower, upper;
	printf("Enter lower and upper integer limits.\n");
	while (scanf("%d %d", &lower, &upper) == 2)
	{
		if (lower >= upper)
		{
			break;
		}

		int sum = 0;
		int temp = lower;
		char c;

		for (int i = 0; i <= upper - lower; i++)
		{
			sum += temp * temp;
			temp++;
		}

		printf("The sum of the squares form %d to %d is %d\n", lower*lower, upper*upper, sum);
		printf("Enter next set of limits: ");
		while ((c = getchar()) != '\n');

	}

	printf("Done");
	getchar();
	getchar();
	return 0;
}
