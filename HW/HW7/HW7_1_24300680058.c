#include <stdio.h>
#define MAX 120
int main()
{
	int k, i, j, m, n, t, a[MAX] ={0};
	char ori[MAX], ch;
	
	printf("Enter source text:");
	for (i = 0; (ch = getchar()) != '\n'; i++)
		ori[i] = ch;//�������ַ�����ori���ַ����� 
	printf("Enter key:");
	scanf("%d", &k);
	
	for(n = 0; n < i; n++)
	a[n] = n+1;//a��n���������������Ϊ��������⣬���an�����1-i����ͷ�� 
	
	t = 0;
	for (j = 0; j < i; j++)
	{
		m = 0;
		while(m != k)
			{
				if(a[t])
				m++;
				if(m == k)
				{
					printf("%c", ori[a[t]-1]);
					a[t] = 0; 
				}
			t = (t + 1) % i;	
			 } 
 } //һ�����еĳ���
  
 	return 0;
 }
