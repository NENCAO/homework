#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float pint;
	int cups, ounce,tables,teas;
	printf("Please enter cups\n");
	scanf("%d", &cups);
	pint = cups / 2;
	ounce = cups * 8;
	tables = ounce * 2;
	teas = tables * 3;
	
	printf("pint:%.2f  ounce:%d  tables:%d  teas:%d\n", pint, ounce, tables, teas);

	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}
