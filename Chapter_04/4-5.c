#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	float speed, size, time;
	int c;
	printf("Please enter download speed(M/S).\n");
	scanf("%f", &speed);
	while ((c = getchar()) != '\n'&&c != EOF);
	printf("Please enter filesize(MB).\n");
	scanf("%f", &size);
	time = size / speed;
	printf("At %.2f megabits per second, afile of %.2f megabytes\n"
		"downloads in %.2f seconds\n",speed,size,time);


	getchar();
	getchar();
	return 0;
}
