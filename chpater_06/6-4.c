#include<stdio.h>
#define LINE 6
int main(void)
{
	char a = 'A';
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("%c", a);
			a++;
		}
		printf("\n");
	}

	getchar();
	return 0;
}

