#include <stdio.h>
#include <string.h>
#include <math.h>
int digit;
int find_k_num(int a) 
{
	int tes, count = 0;
	int temp = a;
	for(digit = 0; temp ; temp /= 10)
	{
		digit = digit + (temp % 10) * pow(10,count);
		tes = digit + temp / 10;
		if(tes * tes == a)
			return temp / 10;
		count++;
}
	return 0;
}
	int main()
	{
		int n, i, temp;
		printf("Enter N([10, 1000000]):\n");
		scanf("%d", &n);
		printf("K-numbers within %d\n", n);
		for (i = 10; i < n; i++)
		{
			if(find_k_num(i))
			{
				temp = find_k_num(i);
				printf("%d = (%d + %d) ^ 2\n", i, temp,  digit);
			}
			}
		return 0 ;	
	}
