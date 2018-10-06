#include<stdio.h>
#define LINE 5
int main(void)
{
	char a = '$';
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("%c", a);
		}
		printf("\n");
	}

	getchar();
	return 0;
}

