//输入正整数n，输出n行2n-1列的空心三角形（*）图案
#include<stdio.h>
int main()
{
	int n, i, j;
	printf("Enter n:");
	scanf("%d", &n); 
	
	for(i=1;i<=n;i++)//用for循环i在列上设置小于n 
	{
		for (j = 1; j <= 2 * n - i; j++)//用for循环在j上设置1-2n-i 
		{
			if (i == 1)
				printf("*");//第一行* 
			else
			{
				if (j == i || j == 2 * n - i)//非边输出空  边上输出* 
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}

