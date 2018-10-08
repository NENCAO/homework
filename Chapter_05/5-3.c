#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define WEEK 7
int main(void)
{
	int edays, week, days;
	char c;
	printf("Please enter days.\n");
	while (scanf("%d", &edays))
	{
		if (edays <= 0)
		{
			break;
		}

		week = edays / WEEK;
		days = edays % WEEK;
		printf("%d days are %d weeks %d days\n", edays, week, days);
		while ((c = getchar()) != '\n');
		printf("Please enter days.(<=0 to quit)\n");
	}

	getchar();
	getchar();
	return 0;
}
