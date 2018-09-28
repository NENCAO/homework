#include<stdio.h>
void br(void);
void ic(void);

int main()
{
	br();
	printf(" ");
	ic();
	printf("\n");
	ic();
	printf("\n");
	br();
	getchar();//避免程序一运行就结束退出
	return 0;
}

void br(void)
{
	printf("Brazil, Russia");
}

void ic(void)
{
	printf("India, China");
}