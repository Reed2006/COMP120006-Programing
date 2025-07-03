#include <stdio.h>
#include <math.h>
#define n 1e10
int main()
{
	int num = 0;
	printf("Enter a positive integer n (1 <= n <= 2147483647):");
	scanf("%d", &num);
	
	int integer = num;//保留n 
	int i = 2, j =2, first = 1;//初始化变量
	printf("%d =", integer); //格式为n = 分解质因数 

	while (i <= sqrt(num))
	{
		int flag = 1;//flag变量用于判断是否i质数 
		for (; j <= sqrt(i); j++)//遍历sqrt（i） 判断质数 
		{
		if (i % j == 0)
		flag *= 0;
		else
		flag *= 1;
		}
		
	if (first && flag == 1 && num % i == 0)//判断是不是第一个因数 
		{
		printf("%d",i);
		first = 0;
		num /= i; 
	}
	
	while (flag == 1 && num % i == 0)//判断同一质因数是否多次出现 
		{
		num /= i;
		printf("*%d", i);
	}
	i++;
 } 
 
 	if (num != 1)
 	printf("*%d",num);//最后如果全部除完 把1去掉 
 
 	return 0;
}
