#include<stdio.h>
#define LINE 6
int main(void)
{
	for (int i = 0; i < LINE; i++)
	{
		char a = 'F';
		for (int j = 0; j < i + 1; j++)
		{
			printf("%c", a);
			a--;
		}

		printf("\n");
	}
	getchar();
	return 0;
}

