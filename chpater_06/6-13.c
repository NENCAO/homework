#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	double array1[8] ,array2[8];
	double temp = 0;
	double enter;

	for (int i = 0; i < 8; i++)
	{
		printf("Please enter a double now is %d.\n",i);
		scanf("%lf", &enter);
		array1[i] = enter;
		temp += enter;
		array2[i] = temp;
	}

	for (int i = 0; i < 8; i++)
	{
		printf("%-6.2lf ", array1[i]);
	}

	printf("\n");

	for (int i = 0; i < 8; i++)
	{
		printf("%-6.2lf ", array2[i]);
	}

	getchar();
	getchar();
	return 0;
}
