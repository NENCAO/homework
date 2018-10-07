#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define YANGJIN 2.05
#define TIANCAI 1.15
#define HULUOBO 1.09
float getinput();//返回浮点类型输入
float list(float yang, float tian, float hu);//计算和输出函数
int main(void)
{

	char select;
	int s = 0;//结束开关
	char c;
	float yang = 0;
	float tian = 0;
	float hu = 0;

	while (1)//斤数
	{
		printf("Welcome to ABC\n"
			"What do you want to buy?\n"
			"1)Yangjin $2.05/P    2)Tiancai $1.15/P\n"
			"3)Huluobo $1.09/P    q)quit\n");

		scanf("%c", &select);
		switch (select)
		{
		case '1': printf("Please enter the weight\n");
			yang += getinput();
			while ((c = getchar()) != '\n');
			break;
		case '2':printf("Please enter the weight\n");
			tian += getinput();
			while ((c = getchar()) != '\n');
			break;
		case '3':printf("Please enter the weight\n");
			hu += getinput();
			while ((c = getchar()) != '\n');
			break;
		case 'q': s = 1;
			break;
		default: printf("Please enter the correct options.\n");
			while ((c = getchar()) != '\n');
			continue;
		}

		if (s == 1)
		{
			break;
		}
	}

	list(yang, tian, hu);

	getchar();
	getchar();
	return 0;
}

void menu(void)
{

}

float getinput(void)
{
	float select;
	char c;
	while (scanf("%f", &select) == 0)
	{
		printf("Please enter correct nubmer!.\n");
		while ((c = getchar()) != '\n');
	}

	return select;
}

float list(float yang, float tian, float hu)
{
	float sumprice, yangprice, tianprice, huprice, sumweight, freight,account;
	float  discount = 0;

	yangprice = yang * YANGJIN;
	tianprice = tian * TIANCAI;
	huprice = hu * HULUOBO;
	sumprice = yangprice + tianprice + huprice;
	sumweight = yang + tian + hu;

	if (sumprice > 100)
	{
		discount = sumprice * 0.05;
		sumprice *= 0.95;
	}

	if (sumweight <= 5)
	{
		freight = 6.5;
	}
	else if (sumweight > 20)
	{
		freight = 14 + (sumweight - 20)*0.5;
	}
	else
	{
		freight = 14;
	}
	account = sumprice + freight;

	printf("Yangjin $%f/p  %6.2fP  %6.2f$\n", YANGJIN, yang, yangprice);
	printf("Tiancai $%f/p  %6.2fP  %6.2f$\n", TIANCAI, tian, tianprice);
	printf("Huluobo $%f/p  %6.2fP  %6.2f$\n", HULUOBO, hu  , huprice);
	printf("Order price is %6.2f$\n", sumprice);
	if (discount != 0)
	{
		printf("discount is %6.2f$\n", discount);
	}
	printf("freight is %6.2f$\n", freight);
	printf("account payable %6.2f$\n", account);

}