#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
	int choice;
	void count(void);

	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case 'a':printf("Buy low, sell high.\n");
				 break;
		case 'b':putchar('\a');
				 break;
		case 'c':count();
				 break;
		default :printf("Program error!\n");
				 break;
		}
	}
	printf("Bye.\n");

	getchar();
	return 0;
}

void count(void)
{
	int n, i;
	printf("Count how far? Enter an integer:\n");
	n = get_int();
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", i);
	}
	while (getchar() != '\n')
		continue;
}

char get_choice(void)
{
	char ch;

	printf("Enter the letter of your choice:\n");
	printf("a. advice          b. bell\n");
	printf("c. count           q. quit\n");
	ch = get_first();
	while ((ch <'a' || ch>'c') && ch != 'q')
	{

		printf("Please respond with a , b , c or q.\n");
		ch = get_first();
	}

	return ch;
}

char get_first(void)
{
	char ch;
	char c;
	scanf(" %c",&ch);
	while ((c = getchar()) != '\n');

	return ch;
}

int get_int(void)
{
	int input;
	char ch;

	while (scanf("%d", &input) != 1)
	{
		while ((ch = getchar()) != 1)
		{
			putchar(ch);
		}
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value, such as 25, -178, or 3: ");
	}

	return input;
}