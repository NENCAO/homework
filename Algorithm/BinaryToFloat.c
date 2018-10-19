#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dec_to_bin(int nNum);//整数二进制计算
int fra_to_bin(float nNum);//小数二进制计算
int nTemp[32];//暂时存整数的二进制
int fraTemp[32];//暂时存小数数的二进制

int main(void)
{
	float fNum = 58.25;
	int nHex[32];
	int nNum;//整数部分
	float fraNum;//小数部分

	nNum = (int)fNum;
	fraNum = fNum - nNum;

	dec_to_bin(nNum);
	fra_to_bin(fraNum);


	system("pause");
	return 0;
}

int dec_to_bin(int nNum)//整数转二进制 返回位数 倒序
{
	int count = 0;
	while (nNum != 0)
	{
		nTemp[count] = nNum % 2;
		nNum /= 2;
		count++;
	}
	return count - 1;
}

int fra_to_bin(float nNum)//小数转二进制 返回位数 正序
{
	int count = 0;

	while (1)
	{
		nNum *= 2;

		if (nNum >= 1)
		{
			nNum--;
			fraTemp[count] = 1;
			count++;
		}
		else if (nNum == 0)//跳出口
		{
			return count;
		}
		else
		{
			fraTemp[count] = 0;
			count++;
		}
		
		if (count > 32)
		{
			break;
		}
	}

}