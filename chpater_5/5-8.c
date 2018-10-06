#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int first, second, result;
	char c;
	printf("Enter an integer to serve as the second operand: ");
	scanf("%d", &second);
	while ((c = getchar()) != '\n');
	printf("Now enter the first operand: ");
	
	while (1)
	{
		scanf("%d", &first);
		if (first <= 0)
		{
			break;
		}

		result = first % second;
		printf("%d %% %d is %d\n", first, second, result);
		while ((c = getchar()) != '\n');
		printf("Enter next number for first operand (<=0 to quit): ");
	}
	printf("Done");

	getchar();
	getchar();
	return 0;
}
