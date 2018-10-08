#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char c;
	int count = 0;

	printf("Please enter a string.\n");
	while ((c = getchar()) != EOF) //windows下模拟EOF  新的一行ctrl+z
	{
		count++;
	}
	printf("There are %d characters.\n",count -1 ); //模拟EOF导致要敲个回车..

	getchar();
	return 0;
}
