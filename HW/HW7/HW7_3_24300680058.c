#include <stdio.h>
#define N 30
int main()
{
	int n, flag = 1, i, j, k, m, a[30][30]={0},count = 1, diag;
	printf("Enter N:");
	scanf("%d", &n);
	//按照tip走 用diag变量进行循环 flag变量标志方向 
	for(diag = 0; diag < 2 * n - 1 ; diag++, flag = 1 - flag)
		{
			for(i = 0; i < n; i++)
			{
				j = diag - i;
				if(j >= 0 && j <= n - 1)//这样当i到n-1后，j会保持仍在范围内而不会输出过头 
			{
				if(flag)//那就顺着 
				a[i][j] = count;
				else//那就反着 
				a[j][i] = count;
				count++;
			}			
		}
	}
	for (k = 0; k < n; k++)
		{
			for (m = 0; m < n; m++)
			printf("%4d", a[k][m]);
			printf("\n");
			}	//输出二维数组 
	return 0;
	
}
