#include <stdio.h>
#define N 100

int main()
{
	int n, m, i, a[N];
	printf("Enter number:");
	scanf("%d", &n);
	printf("Enter m");
	scanf("%d", &m);
	
	for(i = 0 ; i < n ; i++)
		a[i] = i + 1;

		
	int j = 0, k, tra;//ע���ʼ�� 
	for (k = 0 ; k < n; k++)//n�ֱ��� 
		{
		tra = 0;//������ 
		while(tra != m)
		{
			if (a[j]) 
			tra++;//û��0�ͱ��� 
			if(tra == m)
			{
			printf("%4d", a[j]);
			a[j] = 0;//����ͳ��� 
		}
			j = (j+1) % n;	//�����˾���һ�� 
		}
	}
 	} 
