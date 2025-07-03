#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6

int main()
{
	float low = 0, high = 3, mid = 0, f_low = 0, f_high = 0, f_mid, final_mid= 0;
	
	mid = (low + high) / 2.0;
	f_mid = mid * mid * mid - mid * mid - 1;
	f_low = low * low * low - low * low - 1;
	f_high = high * high * high - high * high - 1;//第一次运算 
	
	printf("[low, high]\t\t\tmid\t\t\tf_low\t\t\tf_high\t\t\tf_mid\t\t\t\n");
	printf("[%.6f, %.6f]\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\t\t\n",low, high, mid, f_low, f_high, f_mid);
	
	while (f_low * f_high <= 0)//最小值和最大值是否异号 
	{
		if (f_mid * f_low <= 0)//中间值符号判断 
			high = mid;
		else 
			low = mid;
	
		mid = (low + high) / 2.0;
		f_mid = mid * mid * mid - mid * mid - 1;
		f_low = low * low * low - low * low - 1;
		f_high = high * high * high - high * high - 1;
	
		if (fabs(low - high) >= EPSILON)
		{
			printf("[%.6f, %.6f]\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\t\t\n",low, high, mid, f_low, f_high, f_mid);
		    final_mid = mid;//按照第一张图片示例 不再做一次mid 
		}
		else
		break;
	}
	
	printf("函数f(x) = x ^ 3 - x ^ 2 - 1 在区间[0, 3]上的实根为%.6f", final_mid);
	
	return 0;
 } 
