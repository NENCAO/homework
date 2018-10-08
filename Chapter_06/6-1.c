#include<stdio.h>

int main(void)
{
	int a[26];
	char letter = 'a';
	for (int i = 0; i < 26; i++)
	{
		a[i] = letter;
		letter++;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%c", a[i]);
	}

	getchar();
	return 0;
}

