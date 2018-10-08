#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int min = 0;
	int max = 100;
	int guess = 50;
	int select;
	char c;
	int s = 0;//跳出开关

	do 
	{
		printf("The number is %d?\n", guess);
		printf("1) big     2) small    3) bingo\n");
		scanf("%d", &select);
		while ((c = getchar()) != '\n');

		switch (select)
		{
		case 1:max = guess;
			guess = (max + min) / 2;
			break;
		case 2:min = guess;
			guess = (max + min) / 2;
			break;
		case 3:s = 1;
			break;
		default:printf("Error re-enter!\n");
			break;
		}

		if (max - min == 1)
		{
			guess++;
		}
	} while (s == 0);

	printf("The number is %d", guess);
	getchar();
	getchar();
	return 0;
}