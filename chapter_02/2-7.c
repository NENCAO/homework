#include<stdio.h>
void smile(void);
int main()
{
	
	smile();
	smile();
	smile();
	printf("\n");
	smile();
	smile();
	printf("\n");
	smile();
	/*
	int n = 3;
	int m = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			smile();
		}
		printf("\n");
		m--;
	}
	*/
	//后面学到的更通用的方法 补充

	getchar();//避免程序一运行就结束退出
	return 0;
}

void smile(void)
{
	printf("Smile!");
}
