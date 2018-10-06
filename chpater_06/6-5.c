#include<stdio.h>
#define LETTER 'A'
#define LINE 5
int main(void)
{
	for (int i = 0; i < LINE; i++)
	{
		int letter = LETTER;
		int space = 1;

		while (LINE - i > space) //打印(行数-1个空格)
		{
			printf(" ");
			space++;
		}

		for (int m = 0; m < i + 1; m++)
		{
			printf("%c", letter);
			letter++;
		}

		letter--; //左边生成之后 实际上letter存储的已经+过一次

		for(int n = 0; n < i; n++)
		{
			letter--;
			printf("%c", letter);
			
		}

		printf("\n");

	}


	getchar();
	return 0;
}

