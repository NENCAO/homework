#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	double water = 0;
	int weight;
	printf("Please enter weight of the water\n");
	scanf("%d", &weight);
	water = weight * 950 / 3e-23;

	printf("Water molecule is %lf\n", water);
	
	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}

/*int类型有溢出风险 这里选用double 64bit 1.7977E+308 范围比unsigned int 4294967295大很多 而且3e-23也是浮点数*/
