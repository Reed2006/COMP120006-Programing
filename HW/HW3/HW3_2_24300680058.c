//HW3_2. 编写程序, 输入4个整数, 输出它们中的最大值和最小值.  
// 要求使用尽可能少的if...else...语句或条件(三目)运算表达式, 因为一个条件(三目)运算表达式相当于一个if...else...结构. 
#include<stdio.h>

int main() 
{
    int a, b, c, d;//用abcd来存储这四个整数 
    printf("Enter 4 integers:");
    scanf("%d%d%d%d", &a, &b, &c, &d);//输入这四个数据 

    int max1 = a >= b ? a : b;//寻找并存储a、b最大值 
    int max2 = c >= d ? c : d;//寻找并存储c、d最大值 
    int max = max1 >= max2 ? max1 : max2;//比较两者最大值 即确定abcd最大值 

    int min1 = a <= b ? a : b;//寻找并存储a、b最小值 
    int min2 = c <= d ? c : d;//寻找并存储c、d最小值 
    int min = min1 <= min2 ? min1 : min2;//比较两者最小值 即确定abcd最小值 

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
    
}
