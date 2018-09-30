#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define STR 40
int main(void)
{
	float height;
	char name[STR];
	int c;
	printf("Please enter you height.\n");
	scanf("%f", &height);
	while ((c = getchar()) != '\n' && c != EOF); //清缓存 fflush部分编译器是不支持的
	printf("Please enter you name.\n");
	scanf("%s", name);
	printf("%s, you are %.3f feet tall.\n"
		, name, height);

	getchar();
	getchar();
	return 0;
}
