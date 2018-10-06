#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char enter[256];
	int n;
	scanf("%s", &enter);
	n = strlen(enter);
	for (int i = n; i >= 0; i--)
	{
		printf("%c", enter[i-1]);
	}


	getchar();
	getchar();
	return 0;
}
