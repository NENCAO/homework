#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void chline(char ch, int i, int j);
int main(void)
{
	char ch = 'A';
	int i = 5;
	int j = 6;

	chline(ch, i, j);
	getchar();
	return 0;
}

void chline(char ch, int i, int j)
{
	for (int x = 0; x < j; x++)
	{
		for (int y = 0; y < i; y++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}