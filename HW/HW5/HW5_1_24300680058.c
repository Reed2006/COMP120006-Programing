//����������n�����n��2n-1�еĿ��������Σ�*��ͼ��
#include<stdio.h>
int main()
{
	int n, i, j;
	printf("Enter n:");
	scanf("%d", &n); 
	
	for(i=1;i<=n;i++)//��forѭ��i����������С��n 
	{
		for (j = 1; j <= 2 * n - i; j++)//��forѭ����j������1-2n-i 
		{
			if (i == 1)
				printf("*");//��һ��* 
			else
			{
				if (j == i || j == 2 * n - i)//�Ǳ������  �������* 
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}

