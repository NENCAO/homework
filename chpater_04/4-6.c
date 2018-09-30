#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define STR 40
int main(void)
{
	char name[STR];
	char surname[STR];
	int c, s, n;
	printf("Please enter you name.\n");
	scanf("%s", name);
	while ((c = getchar()) != '\n'&&c != EOF);
	printf("Please enter you surnmae.\n");
	scanf("%s", surname);
	n = strlen(name);
	s = strlen(surname);
	printf("%s %s\n%*d %*d\n", name, surname, n, n, s, s);
	printf("%s %s\n%-*d %-*d\n", name, surname, n, n, s, s);
	getchar();
	getchar();
	return 0;
}
