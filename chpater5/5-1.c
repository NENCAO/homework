#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define H 60
int main(void)
{
	int min, c,hours,temp;
	char a;

	printf("Please enter minute.\n");
	c = scanf("%d", &min);
	while (c == 1)
	{
		if (min <= 0)
		{
			break;
		}

		hours = min / 60;
		temp = min % 60;
		printf("%d is %dhours %dminute.\n", min, hours,temp);
		while ((a = getchar()) != '\n');
		printf("\nPlease enter minute. (<=0 to quit)\n");
		c = scanf("%d", &min);
	}

	getchar();
	getchar();
	return 0;
}
