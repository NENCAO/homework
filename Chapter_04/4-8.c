#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define L 3.785
#define KIL 1.609
int main(void)
{
	float gas, mile, liter, kilo, euscheme, usascheme;
	printf("Please enter mileage and gasoline.\n");
	scanf("%f %f", &gas, &mile);
	liter = gas * L;
	kilo = mile * KIL;
	euscheme = mile / gas;
	usascheme = liter / 100;
	printf("euscheme:%.4f  usascheme:%.4f\n", euscheme, usascheme);

	getchar();
	getchar();
	return 0;
}
