#include <stdio.h>
void custom(char ch, int n, int m);
int main(void)
{
	char ch = 'A';
	int a = 5;
	int b = 7;

	custom( ch, a, b);

	getchar();
	return 0;
}

void custom(char ch, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}