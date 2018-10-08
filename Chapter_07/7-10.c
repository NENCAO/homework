#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n = 0;
	int enter, base;
	float tax, wage;
	char c;

	while (1) //输入正确为止
	{
		printf("seclect you type.\n");
		printf("1)single      2)master\n"
			"3)married     4)divorce\n");

		scanf("%d", &enter);
		switch (enter)
		{
		case 1: base = 17850;
			break;
		case 2: base = 23900;
			break;
		case 3: base = 29750;
			break;
		case 4: base = 14875;
			break;
		default:printf("Input Error! please re-enter.\n");
			while ((c = getchar()) != '\n');
			continue;
		}
		break;
	}

	printf("Please enter your wages.\n");
	while ((c = getchar()) != '\n');
	scanf("%f", &wage);
	if (wage < base)
	{
		tax = wage * 0.15;
	}
	else
	{
		tax = wage * 0.15 + (wage - base)*0.28;
	}

	printf("tax is %.2f", tax);

	getchar();
	getchar();
	return 0;
}
