#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double n;
	scanf("%lf", &n);
	printf("%lf\n", n);
	printf("%e\n", n);
	printf("%a\n", n);//可以用.2限制成书上的  但是因为不知道结果 不建议限制位数


	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}


