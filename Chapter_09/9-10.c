#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void to_base_n(unsigned target, int n);
int main(void)
{
	unsigned long number;
	int n;
	printf("Enter an integer and the base from 2 to 10 (q to quit): ");
	while (scanf("%lu %d", &number,&n) == 2)
	{
		printf("Binary equivalent: ");
		to_base_n(number,n);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");
}

void to_base_n(unsigned target, int n)
{
	int r;
	
	r = target % n;
	if (target >= n)
	{
		to_base_n(target / n, n);
	}
	printf("%d", r);
}

