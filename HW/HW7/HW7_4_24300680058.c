#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define WIDTH 12

void convert(int ori, int con, int width)
{
	char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int count, i, j;
	char temp[N] = {'0'};
	
 	temp[0] = digits[ori % con];
	for (count = 1; ori /= con; count++)
		temp[count] = digits[ori % con];//初始化 
	
	for (i=count - 1; i>=0; i--) 
		printf("%c", temp[i]);//取余输出 
	for (j = 0; j < width - count ; j++)//填补对齐 
		printf(" ");
}

int main()
{
	int base[4] = {10};
	int i, n, j, k, m, a[N], bin[N], sex[N], tra, temp, count, space;
	srand((unsigned int)time(NULL));
	n = 10 + rand() % 10;
	printf("%d random integers:\n", n);//生成随机数	
	for (i = 0; i != n; i++)
		printf("%d ", a[i] = rand() % 1024);
			
	printf("\n\nEnter 3 base numbers:");
	scanf("%d%d%d", &base[1], &base[2], &base[3]);
	printf("Base-%-7dBase-%-7dBase-%-7dBase-%-7d\n", base[0], base[1], base[2], base[3]);
		
	for (j = 0; j < n; j++)
	{
		for(k = n - 1 ; k > j; k--)
		{
			if (a[k] <= a[k - 1])
				{
				temp = a[k - 1]; a[k - 1] = a[k]; a[k] = temp;
			}
		}
}//冒泡法
	for (k = 0; k!=n ; ++k)
		{
			printf("%-*d" ,WIDTH, a[k]);
			for(m = 1; m!= 4; ++m)
				convert(a[k], base[m], WIDTH);
			putchar('\n');
		}
		
	return 0;
}
	
	
	
