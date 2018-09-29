#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float height;
	float cm;
	printf("Please enter you height (inches)\n");
	scanf("%f", &height);
	cm = height * 2.54;
	printf("you height is %.2fcm\n",cm);

	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}
