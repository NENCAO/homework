#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char enter = 0;//也可以定义成int 就不会显示警告了
	printf("Please enter a ASCIIcode\n");
	scanf("%d", &enter);
	printf("%c", enter);

	getchar();//避免程序一运行就结束退出
	getchar();//scanf()函数缓冲区留下一个\n getchar()会读取 程序秒退
	return 0;
}


/*VS会自动提示错误警告 因为这里enter溢出了 #define _CRT_SECURE_NO_WARNINGS 声明必须在include上面才有效！
添加之后依然会警告溢出
简单解释下溢出原因 char只分配了1个字节大小的内存空间  %d会占用4个字节（int）
所以内存地址上 后3个字节空间溢出 被改写了！ 后面课程会使用更安全的方法
*/