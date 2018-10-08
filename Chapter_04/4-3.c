#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	float n;
	printf("Please enter a float.\n");
	scanf("%f", &n);
	printf("The input is %.1f or %.1e\n",n,n);
	printf("The input is %.3f or %.3e\n",n,n);

	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}
