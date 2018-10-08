#include<stdio.h>
void jolly(void);
void deny(void);

int main()
{
	jolly();
	jolly();
	jolly();
	deny();
	getchar();//避免程序一运行就结束退出
	return 0;
}


void jolly(void)
{
	printf("For he's a jolly good fellow\n");
}

void deny(void)
{
	printf("Which nobody can deny\n");
}