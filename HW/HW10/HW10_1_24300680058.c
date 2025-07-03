#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N 101
int main()
{
	int m, n, i, j, k, temp = 0, sum = 0, s[10][10] = {0}; char s1[] = "1", s2[] = "col", s3[N], s4[] = "Infinity", s5[] = "Row";
	
	srand((unsigned int)time(NULL));
	m = rand() % 5 + 1; 
	n = rand() % 5 + 1; 
	
	printf("随机矩阵为:\n");
	for(i = 0; i < m; i++)
	{
		for(j=0; j < n; j++)
			printf("%*d", 3, s[i][j] = rand() % 10 - 5);
		printf("\n");
	}
	
	scanf("%s", s3);
	
	if(strcmp(s3,s1) == 0 || strcmp(s3, s2) == 0)
{
	for(j = 0; j < n; j++)
	{
		for(temp = i = 0; i < m; i++)
			temp += abs(s[i][j]);
		if(temp > sum)
			sum = temp;
}
	printf("该区间的列和范数为：%d", sum);
}

	else if(strcmp(s3,s4) == 0 || strcmp(s3, s5) == 0)
{
	for(i = 0; i < m; i++)
	{
		for(temp = j = 0; j < n; j++)
			temp += abs(s[i][j]);
		if(temp > sum)
			sum = temp;
}
	printf("该区间的行和范数为：%d", sum);
}
	return 0;
 } 
 
