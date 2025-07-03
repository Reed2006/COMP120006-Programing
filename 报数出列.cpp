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

		
	int j = 0, k, tra;//注意初始化 
	for (k = 0 ; k < n; k++)//n轮报数 
		{
		tra = 0;//报数器 
		while(tra != m)
		{
			if (a[j]) 
			tra++;//没置0就报数 
			if(tra == m)
			{
			printf("%4d", a[j]);
			a[j] = 0;//置零就出列 
		}
			j = (j+1) % n;	//报完了就下一个 
		}
	}
 	} 
