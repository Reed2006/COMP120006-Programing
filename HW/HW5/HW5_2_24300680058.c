#include <stdio.h>
#include <math.h> 
#define epsilon 1e-10

int main()
{
	int count, i, num;
	double test_number, sum, x, x_for_calculate;
	
	printf("Enter x:");
	scanf("%lf", &x);//输入x 
	
	int flag = x / fabs(x);//flag变量保存正负 
	x_for_calculate = flag * x;
	
		for(i = 1, test_number = 1.0, sum = 0; test_number > epsilon ; i++)//找那个小于十的负十次方的test_number 找sum 
		{
			sum += test_number;
			test_number = test_number * x_for_calculate / i ;
		}//for循环计量级数 
	
	if (flag == -1)
		sum = 1 / sum;//如果x负 用e的x分之一 更精确 
		
	printf("e^(%g) = %.15g", x, sum);
	
	return 0; 
 } 
