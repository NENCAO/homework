#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define INCH 0.39
#define FEET 12
int main(void)
{
	float cm, inch;
	int feet;
	char c;
	printf("Enter a height in centimeters.\n");
	while (scanf("%f", &cm))
	{
		if (cm <= 0)
		{
			break;
		}

		inch = cm * INCH;
		feet = inch / FEET;
		inch = inch - (feet * FEET);
		printf("%.1f cm = %d feet %.1f inches\n", cm, feet, inch);
		while ((c = getchar()) != '\n');
		printf("Enter a height in centimeters.(<=0 to quit)\n");
	}

	printf("bye");
	getchar();
	getchar();
	return 0;
}
