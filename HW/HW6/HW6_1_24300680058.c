#include <stdio.h>
#include <math.h>
#define n 1e10
int main()
{
	int num = 0;
	printf("Enter a positive integer n (1 <= n <= 2147483647):");
	scanf("%d", &num);
	
	int integer = num;//����n 
	int i = 2, j =2, first = 1;//��ʼ������
	printf("%d =", integer); //��ʽΪn = �ֽ������� 

	while (i <= sqrt(num))
	{
		int flag = 1;//flag���������ж��Ƿ�i���� 
		for (; j <= sqrt(i); j++)//����sqrt��i�� �ж����� 
		{
		if (i % j == 0)
		flag *= 0;
		else
		flag *= 1;
		}
		
	if (first && flag == 1 && num % i == 0)//�ж��ǲ��ǵ�һ������ 
		{
		printf("%d",i);
		first = 0;
		num /= i; 
	}
	
	while (flag == 1 && num % i == 0)//�ж�ͬһ�������Ƿ��γ��� 
		{
		num /= i;
		printf("*%d", i);
	}
	i++;
 } 
 
 	if (num != 1)
 	printf("*%d",num);//������ȫ������ ��1ȥ�� 
 
 	return 0;
}
