#include<stdio.h>
#define STR 40
int main(void)
{
	char name[STR], surname[STR];

	printf("Please enter you name and surname.\n"
			"example :zengming huang\n");
	scanf_s("%s %s", name, 40, surname, 40);//注意sancf_s不是ASCI标准 不可通用 最好不用!
	//书已经说过scanf函数不适合处理字符串 后面会讲新函数
	printf("\"%s,%s\"", name, surname);

	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}
