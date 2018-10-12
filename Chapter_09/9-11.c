#include <stdio.h>
int Fibonacci(int n);
int main(void)
{
	for (int i = 1; i < 20; i++)
	{
		printf("%d ", Fibonacci(i));
	}

	getchar();
}

unsigned long Fibonacci(int n)
{
	unsigned long n1 = 1;
	unsigned long n2 = 1;
	unsigned long temp;
	
	for (int i = 2; i < n; i++)
	{
		temp = n2 + n1;
		n1 = n2;
		n2 = temp;
	}

	return n2;
}