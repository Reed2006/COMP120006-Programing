#include <stdio.h>
#include <math.h> 
#define epsilon 1e-10

int main()
{
	int count, i, num;
	double test_number, sum, x, x_for_calculate;
	
	printf("Enter x:");
	scanf("%lf", &x);//����x 
	
	int flag = x / fabs(x);//flag������������ 
	x_for_calculate = flag * x;
	
		for(i = 1, test_number = 1.0, sum = 0; test_number > epsilon ; i++)//���Ǹ�С��ʮ�ĸ�ʮ�η���test_number ��sum 
		{
			sum += test_number;
			test_number = test_number * x_for_calculate / i ;
		}//forѭ���������� 
	
	if (flag == -1)
		sum = 1 / sum;//���x�� ��e��x��֮һ ����ȷ 
		
	printf("e^(%g) = %.15g", x, sum);
	
	return 0; 
 } 
