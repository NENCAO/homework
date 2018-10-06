#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char word[40];
	int length;
	scanf("%s", word);
	length = strlen(word);
	for (int i = 0; i < length; i++)
	{
		printf("%c", word[length - 1 - i]);
	}

	getchar();

	getchar();
	return 0;
}


