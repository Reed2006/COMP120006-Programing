#include <stdio.h>
#define N 30
int main()
{
	int n, flag = 1, i, j, k, m, a[30][30]={0},count = 1, diag;
	printf("Enter N:");
	scanf("%d", &n);
	//����tip�� ��diag��������ѭ�� flag������־���� 
	for(diag = 0; diag < 2 * n - 1 ; diag++, flag = 1 - flag)
		{
			for(i = 0; i < n; i++)
			{
				j = diag - i;
				if(j >= 0 && j <= n - 1)//������i��n-1��j�ᱣ�����ڷ�Χ�ڶ����������ͷ 
			{
				if(flag)//�Ǿ�˳�� 
				a[i][j] = count;
				else//�Ǿͷ��� 
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
			}	//�����ά���� 
	return 0;
	
}
