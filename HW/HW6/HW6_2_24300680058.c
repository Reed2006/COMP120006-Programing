#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6

int main()
{
	float low = 0, high = 3, mid = 0, f_low = 0, f_high = 0, f_mid, final_mid= 0;
	
	mid = (low + high) / 2.0;
	f_mid = mid * mid * mid - mid * mid - 1;
	f_low = low * low * low - low * low - 1;
	f_high = high * high * high - high * high - 1;//��һ������ 
	
	printf("[low, high]\t\t\tmid\t\t\tf_low\t\t\tf_high\t\t\tf_mid\t\t\t\n");
	printf("[%.6f, %.6f]\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\t\t\n",low, high, mid, f_low, f_high, f_mid);
	
	while (f_low * f_high <= 0)//��Сֵ�����ֵ�Ƿ���� 
	{
		if (f_mid * f_low <= 0)//�м�ֵ�����ж� 
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
		    final_mid = mid;//���յ�һ��ͼƬʾ�� ������һ��mid 
		}
		else
		break;
	}
	
	printf("����f(x) = x ^ 3 - x ^ 2 - 1 ������[0, 3]�ϵ�ʵ��Ϊ%.6f", final_mid);
	
	return 0;
 } 
