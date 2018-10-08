#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int word = 0;
	int count = 0;
	float ave = 0;
	char c;

	printf("Please enter words.\n");
	while ((c = getchar())!= EOF)
	{
		if (isalnum(c))
		{
			count++;
		}
		else if (isspace(c))
		{
			word++;
		}
	}
	
	if (word != 0)
	{
		ave = (float)count / word;
		printf("Average %.2f", ave);
	}
	else
	{
		printf("No word!");
	}


	getchar();
	getchar();
	return 0;
}
