#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	short bell = 7;
	printf("%c", bell);
	printf("Starled by the sudden sound, Sally shouted,\n"
			"\"By the Great Pumpkin, what was that!\"");

	getchar();//避免程序一运行就结束退出
	//getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}

