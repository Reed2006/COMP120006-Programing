#include <stdio.h>
#define MAX 120
int main()
{
	int k, i, j, m, n, t, a[MAX] ={0};
	char ori[MAX], ch;
	
	printf("Enter source text:");
	for (i = 0; (ch = getchar()) != '\n'; i++)
		ori[i] = ch;//将输入字符放入ori的字符数组 
	printf("Enter key:");
	scanf("%d", &k);
	
	for(n = 0; n < i; n++)
	a[n] = n+1;//a【n】数组的作用是作为计数、检测，因此an标记了1-i的人头数 
	
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
 } //一个出列的程序
  
 	return 0;
 }
