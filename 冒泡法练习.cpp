#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
	int i, n, j, k, m, a[N] = {0}; 
	srand((unsigned int)time(NULL));
	n = 10 + rand() % 10;
	printf("%d random integers:\n", n);//���������	
	
	for (i = 0; i != n; i++)
		printf("%d ", a[i] = rand() % 1024);
		
	printf("\n");

		for(j = 1; j < n; j++)//����j=1����Ϊ��һ�α�����Ҫ��n-1�α��� 
		{
			for (k = n - 1; k >= j; k--)//������ڵ���j����Ϊ��һ��Ҫ��a[1] 
			{
				if (a[k] - a[k - 1] <= 0)
					{
					int temp = a[k];
					a[k] = a[k - 1];
					a[k - 1] = temp;
				}
			}
		}
		
	for (m = 0; m != n; m++)
		printf("%d ", a[m]);
		printf("\n");
	//�����ǵ�һ���Ż� 
	int b, c, d;
	
	for( b = 1; b < n; b++)
		{
			int flag = 1;//�����Ǽ�⻹Ҫ��Ҫ���� 
			for (c = n- 1; c >= b; c--)
			{
				if (a[c] - a[c - 1] <= 0)
					{
					int temp = a[c];
					a[c] = a[c - 1];
					a[c - 1] = temp;
					flag = 0;
			}
		}
		if(flag)
			break;
		}
		for (d = 0; d != n; d++)
		printf("%d ", a[d]);
		
	//�����ٴ��Ż�
	int pos, e, end = n- 1;
	while (end > 0)
	{
		for (pos = e = 0; e < end ; e++)
		{
			if (a[e] > a[e + 1])
			{
				int temp = a[e];
				a[e] = a[e - 1];
				a[e - 1] = temp;
				pos = j;
			}
		
		}
	end = pos;	
	 } 
	return 0;
}
