#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define BASE 10.00
#define OVERTIME 1.5
#define THRESHOLD1 300
#define THRESHOLD2 450
#define rate1 0.15
#define rate2 0.2
#define rate3 0.25
int main(void)
{
	int hours;
	float wage, tax, postwage;
	printf("Please enter working hours.\n");
	scanf("%d", &hours);

	if (hours > 40)
	{
		wage = BASE * (hours + (hours - 40) / 2);
	}
	else
	{
		wage = hours * BASE;
	}
	//有效工作时长

	if (wage > THRESHOLD2)
	{
		tax = THRESHOLD1 * rate1 + (THRESHOLD2 -THRESHOLD1) * rate2 + (wage - THRESHOLD2)*rate3;
		postwage = wage - tax;
	}
	else if(wage < THRESHOLD1)
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

	printf("wage is %f  tax is %f  postwage is %f", wage, tax, postwage);

	getchar();
	getchar();
	return 0;
}
