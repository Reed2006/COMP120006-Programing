#include <stdio.h>

int main()
{
	printf("Enter two fractions separated by a plus sign:");
	int num1, num2, den1, den2, den, sum, num;
	int min = 1;
	scanf("%d/%d+%d/%d", &num1, &den1, &num2, &den2);
	
	int time_den = den1 * den2;
	int time_sum = num1 * den2 + num2 * den1;//暴力通分 
	
	if(time_sum % time_den == 0)
		printf("%d/%d+%d/%d=%d", num1, den1, num2, den2, time_sum / time_den);//检验是否为整数 
	else
	{
		int i; 
		for (i = time_den ; i > 0 ; i--)//寻找最大公约数 
		{
			if (time_sum % i == 0 && time_den % i == 0)
			{
			sum = time_sum / i;
			den = time_den / i;
			break; 
			}
			else
			{
			sum = time_sum;
			den = time_den;//化简完毕 
			}
		}
		printf("%d/%d+%d/%d=%d/%d", num1, den1, num2, den2, sum, den);
	}
	
	return 0;
 } 
