#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define STR 40
int main(void)
{
	char name[STR];
	int width;
	printf("Please enter you name and don't enter spaces.\n");
	scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	width = strlen(name) + 3;
	printf("%*s\n", width, name);

	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}
