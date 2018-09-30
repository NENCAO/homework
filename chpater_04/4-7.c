#include<stdio.h>
#include<float.h>
int main(void)
{
	double n = 1.0 / 3.0;
	float m = 1.0 / 3.0;
	printf("%.6lf %.6f\n", n, m);
	printf("%.12lf %.12f\n", n, m);
	printf("%.16lf %.16f\n", n, m);
	printf("%d %d\n", FLT_DIG, DBL_DIG);// 精确位数 FLT=float  DBL=double

	getchar();
	return 0;

}
