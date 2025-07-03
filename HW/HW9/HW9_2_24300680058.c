#include<stdio.h>
#define N 1000
int main()
{
	int n, a[N] = {0}, carry, m = 1, i, j;
	printf("Enter n:\n");
	scanf("%d", &n);
	a[1] = 1;
	
	for(i = 2; i <= n; i++)
	{
		carry = 0;
		for (j = 1; j <= m; j++)
		{
		int product = a[j] * i + carry;    // 当前位乘i并加上之前的carry  
		a[j] = product % 10;                // low digit  
		carry = product / 10;               // new carry
	}
		 while (carry > 0)
		{  
            m++; // 增加新的位数  
            a[m] = carry % 10; // 将剩余的进位存到新数组元素中  
            carry /= 10; // 减少进位  
        }  
	}
	for (i = m; i >= 1; i--)  
        printf("%d", a[i]); 
    
 } 
