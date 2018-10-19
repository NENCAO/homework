//十进制转10以内的进制
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char nTemp[101];//暂存转换的数字
int systemcoversion(int nTargetNum, int nBaseNum);

int main(void)
{
	int nTargetNum;
	int nBaseNum;
	int count;
	int flip = 1;//跳出开关

	while (flip)
	{
		printf("Please enter the conversion number q to quit\n");//输入转换的数
		while (scanf(" %d", &nTargetNum) != 1)
		{
			if (getchar() == 'q')//退出
			{
				flip = 0;
				break;
			}

			printf("The are not number! try again\n");
			char c;
			while ((c = getchar()) != '\n');
		}

		if (flip == 0)//提前退出
		{
			break;
		}

		printf("Please enter numerical system\n");//输入进制
		while (scanf(" %d", &nBaseNum) != 1)
		{
			if (getchar() == 'q')//退出
			{
				flip = 0;
				break;
			}

			printf("The are not number! try again\n");
			char c;
			while ((c = getchar()) != '\n');
		}

		count = systemcoversion(nTargetNum, nBaseNum);

		for (count; count >= 0; count--)
		{
			printf("%c", nTemp[count]);
		}
		printf("\n");
	}

	getchar();
	getchar();
	return 0;
}

//targetNum 待转换数 baseNum 转换进制
int systemcoversion(int nTargetNum,int nBaseNum)
{
	int count = 0;
	int temp;
	
	while (nTargetNum != 0)
	{
		temp = nTargetNum % nBaseNum;

		switch (temp)
		{

		case 0:temp = '0';
			break;
		case 1:temp = '1';
			break;
		case 2:temp = '2';
			break;
		case 3:temp = '3';
			break;
		case 4:temp = '4';
			break;
		case 5:temp = '5';
			break;
		case 6:temp = '6';
			break;
		case 7:temp = '7';
			break;
		case 8:temp = '8';
			break;
		case 9:temp = '9';
			break;
		case 10:temp = 'a';
			break;
		case 11:temp = 'b';
			break;
		case 12:temp = 'c';
			break;
		case 13:temp = '1';
			break;
		case 14:temp = 'd';
			break;
		case 15:temp = 'e';
			break;
		}//注意ascii码的顺序 也许可以不需要switch

		nTemp[count] = temp;
		nTargetNum /= nBaseNum;
		count++;
	}
	return count - 1;//因为最后 count++ 没有放入任何数值
}