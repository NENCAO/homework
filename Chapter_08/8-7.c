#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define OVERTIME 1.5
#define THRESHOLD1 300
#define THRESHOLD2 450
#define rate1 0.15
#define rate2 0.2
#define rate3 0.25
int main(void)
{
	int s = 0;//程序跳出开关
	int hours;
	char enter;
	float wage, tax, postwage;
	float base = 0;
	char c;
	while (1) //由s控制是否跳出
	{
		printf("please select hourly rate.\n");
		for (int i = 0; i < 40; i++)
		{
			printf("* ");
		}//*号

		printf("\nEnter the character corresponding to the desired pay rate or action:\n"
			"a) $8.75/hr            b) $9.33/hr\n"
			"c) $10.00/hr           d) $11.20hr\n"
			"q) quit\n");

		for (int i = 0; i < 40; i++)
		{
			printf("* ");
		}//*号
		printf("\n");

		while (1)//直到获取正确的输入
		{
			scanf("%c", &enter);
			switch (enter)
			{
			case 'a':base = 8.75;
				break;
			case 'b':base = 9.33;
				break;
			case 'c':base = 10.00;
				break;
			case 'd':base = 11.20;
				break;
			case 'q':s = 1;
				break;
			default:while ((c = getchar()) != '\n');
				printf("Please retype the correct number.\n");
				continue;
			}
			break;
		}

		if (s == 1)//输入5之后就结束输入
		{
			break;
		}

		//下面为计算部分
		printf("Please enter working hours.\n");
		scanf("%d", &hours);

		if (hours > 40)
		{
			wage = base * (hours + (hours - 40) / 2);
		}
		else
		{
			wage = hours * base;
		}
		//有效工作时长

		if (wage > THRESHOLD2)
		{
			tax = THRESHOLD1 * rate1 + (THRESHOLD2 - THRESHOLD1) * rate2 + (wage - THRESHOLD2)*rate3;
			postwage = wage - tax;
		}
		else if (wage < THRESHOLD1)
		{
			tax = wage * rate1;
			postwage = wage - tax;
		}
		else
		{
			tax = THRESHOLD1 * rate1 + (wage - THRESHOLD1)*rate2;
			postwage = wage - tax;
		}
		//计算工资和税务

		printf("wage is %f  tax is %f  postwage is %f\n", wage, tax, postwage);
	}

	printf("Bye");
	getchar();
	getchar();
	return 0;
}