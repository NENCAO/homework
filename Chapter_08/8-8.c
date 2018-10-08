#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
char menu(void);
double input(void);
int main(void)
{
	char p;//算法选择
	double first, second;
	int d;
	double result;

	while (1)
	{
		p = menu();

		if (p == 'q')//检测用户是否选择退出
		{
			break;
		}


		printf("Enter first number: ");
		first =  input();
		
		printf("Enter second number: ");
		second = input();


		if (p == 'd'&&second == 0)//检测除法除数为0的情况
		{
			while (second == 0)
			{
				printf("Enter a number other than 0: ");
				second = input();
			}
		}
		

		switch (p)
		{
		case 'a':result = first + second;
			printf("%.1lf + %.1lf = %.1lf",first,second,result);
			break;
		case 's':result = first - second;
			printf("%.1lf - %.1lf = %.1lf", first, second, result);
			break;
		case 'm':result = first * second;
			printf("%.1lf * %.1lf = %.1lf", first, second, result);
			break;
		case 'd':result = first / second;
			printf("%.1lf / %.1lf = %.1lf", first, second, result);
			break;
		}

		
	}

	getchar();
	return 0;
}

char menu(void)//菜单 返回一个char
{
	char select;
	char c;
	while (1)//直到输入正确选项返回
	{
		printf("Enter the operation of your choice.\n"
			"a. add         s. subtract\n"
			"m. multiply    d. divide\n"
			"q. quit\n");

		scanf("%c", &select);
		while ((c = getchar()) != '\n');

		switch (select)
		{
		case 'a': return select;
		case 's': return select;
		case 'm': return select;
		case 'd': return select;
		case 'q': return select;
		default: printf("Error re-enter.\n");
			break;
		}
	}
}

double input(void)//单次输入函数
{
	double value;
	char c;
	int a;
	while ((a = scanf("%lf", &value)) != 1)
	{
		printf("this is not number\n", value);
		while ((c = getchar()) != '\n');
	}
	return value;
}