#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	float a, b, result;
	printf("Please enter two float.\n");
	while (scanf("%f %f", &a, &b) == 2)
	{
		result = (a - b) / (a*b);
		printf("result is %f.\n", result);
		printf("Enter new float or q to quit.\n");
	}

	getchar();
	getchar();
	return 0;
}

