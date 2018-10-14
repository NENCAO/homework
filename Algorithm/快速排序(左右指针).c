#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void quicksort(int left, int right);
int a[101]; //存放数组
int main(void)
{
	int n,i;//n为需要排序的个数 
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	quicksort(0, i - 1);//i<n时i已经++了 所以用i-1

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	getchar();
	getchar();
	return 0;
}

void quicksort(int left, int right)
{
	if (left > right)//递归的跳出条件
	{
		return;
	}
	int i, j, t;
	int base;
	base = a[left];//定义左边为基数
	i = left;
	j = right;


	while (i != j)//i = j时基数归位
	{
		while (a[j] >= base && i < j)//i<j为必要条件 仔细考虑极端情况 比如 5 5 5 会越界
		{
			j--;
		}

		while (a[i] <= base && i < j)//=号也不可丢掉 i会停在第一位 
		{
			i++;
		}
		if (i < j)//换位
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//检测到i = j 基数归位
	a[left] = a[i];
	a[i] = base;

	//递归调用
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}