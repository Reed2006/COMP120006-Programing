//HW3_2. ��д����, ����4������, ��������е����ֵ����Сֵ.  
// Ҫ��ʹ�þ������ٵ�if...else...��������(��Ŀ)������ʽ, ��Ϊһ������(��Ŀ)������ʽ�൱��һ��if...else...�ṹ. 
#include<stdio.h>

int main() 
{
    int a, b, c, d;//��abcd���洢���ĸ����� 
    printf("Enter 4 integers:");
    scanf("%d%d%d%d", &a, &b, &c, &d);//�������ĸ����� 

    int max1 = a >= b ? a : b;//Ѱ�Ҳ��洢a��b���ֵ 
    int max2 = c >= d ? c : d;//Ѱ�Ҳ��洢c��d���ֵ 
    int max = max1 >= max2 ? max1 : max2;//�Ƚ��������ֵ ��ȷ��abcd���ֵ 

    int min1 = a <= b ? a : b;//Ѱ�Ҳ��洢a��b��Сֵ 
    int min2 = c <= d ? c : d;//Ѱ�Ҳ��洢c��d��Сֵ 
    int min = min1 <= min2 ? min1 : min2;//�Ƚ�������Сֵ ��ȷ��abcd��Сֵ 

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
    
}
