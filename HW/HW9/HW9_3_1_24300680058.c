#include <stdio.h>
#include <string.h>
#define N 100

void normal_order(char *p)
{
	if (*p == '\0')
	{
		printf("\n");
	}
	else
	{
		printf("%c ", *p);
		normal_order(++p);
	}
}

void reverse_order(char *p)
{
	if (*p == '\0');
	else
	{
		reverse_order(++p);
		printf("%c ", *(p - 1));
	}
	
}

int main()
{
	char a[N];
	printf("Enter a positive integer:\n") ;
	gets(a);
	a[strlen(a)] = '\0';
	printf("output in normal order:\n");
	normal_order(a);
	printf("output in reverse order:\n");
	reverse_order(a);
	return 0;
}
