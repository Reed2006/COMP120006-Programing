#include <stdio.h>
#include <string.h>
#define N 100

void normal_order(char *p, int len, int layer)
{	
	if (len == 0)
	return;
	else
	{
	int i;
	layer ++;
	printf("Recursion level %d,parameter n =", layer);
	for(i = 0; i < len ; i++)
	printf("%c", *(p + i));
	printf("\n");
	normal_order(p, len - 1, layer);	
	printf("%c\n", *(p + i - 1));
	printf("Recursion level %d return.\n", layer);
}
}

void reverse_order(char *p, int len, int layer)
{	
	if (len == 0)
	return;
	else
	{
	int i;
	layer ++;
	printf("Recursion level %d,parameter n =", layer);
	for(i = 0; i < len ; i++)
	printf("%c", *(p + i));
	printf("\n");
	printf("%c\n", *(p + i - 1));
	reverse_order(p, len - 1, layer);	
	printf("Recursion level %d return.\n", layer);
}
}

int main()
{
	char a[N];
	printf("Enter a positive integer:\n") ;
	gets(a);
	a[strlen(a)] = '\0';
	printf("output in normal order:\n");
	normal_order(a, strlen(a), 0);
	printf("output in reverse order:\n");
	reverse_order(a, strlen(a), 0);
	return 0;
}
