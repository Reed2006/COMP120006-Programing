#include <stdio.h>

int c, d;
void gcd(int a, int b)
{ 
	static int count = 0;
	if(a == b)
	{
	count ++;
	printf("Recursive layer %d:a = %d, b = %d\n", count, a, b);
	printf("The greatest common divisor of %d and %d is %d", c, d, a);
	}
	else if (a > b)
	{
	count ++;
	printf("Recursive layer %d:a = %d, b = %d\n", count, a, b);
	a = a - b; 
	return gcd(a, b);
	}
	else
	{
	count ++;
	printf("Recursive layer %d:a = %d, b = %d\n", count, a, b);
	b = b - a;
	return gcd(a, b);
	}
} 

int main()
{
	printf("Enter 2 integers:");
	scanf("%d%d", &c, &d);
	
	gcd(c, d);
	
	return 0;
	
}
