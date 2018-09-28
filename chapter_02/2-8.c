#include<stdio.h>
void one_three(void);
void two(void);

int main()
{
	printf("starting now\n");
	one_three();
	printf("done!");
	getchar();//避免程序一运行就结束退出
	return 0;
}

void one_three(void)
{
	printf("one\n");
	two();
	printf("three\n");
}

void two(void)
{
	printf("two\n");
}