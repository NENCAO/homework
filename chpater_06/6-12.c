#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a[8];
	int temp = 1;
	int n = 0;

	for (int i = 0; i < 8; i++)
	{
		a[i] = temp;
		temp *= 2;
	}
	do 
	{
		printf("the %d power is %d\n", n, a[n]);
		n++;
	} while (n < 8);


	getchar();
	getchar();
	return 0;
}
