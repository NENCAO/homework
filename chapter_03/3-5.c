#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	long s;
	int ages;
	printf("Please enter your ages\n");
	scanf("%u", &ages);
	s = ages * 3.156 * 10000000;
	printf("%d ages is %d second\n", ages, s);


	
	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}

