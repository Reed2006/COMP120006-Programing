#include <stdio.h>
#define N 101

int main()
{
	int m, n, i, j, k, b = 0, c = 0, nums1[N] = {0}, nums2[N] = {0}, nums[2*N] = {0};
	scanf("%d", &m);
	for(i = 0; i < m; i++)
	scanf("%d", &nums1[i]);
	scanf("%d", &n);
	for(j = 0; j < n; j++)
	scanf("%d", &nums2[j]);
	
	for(k = 0; k < m + n; k++)
	{
		if((nums1[b] < nums2[c] && b < m) || c >= n)
		{
		nums[k] = nums1[b];
		b++;
		}	
		else
		{
		nums[k] = nums2[c];
		c++;
	}
	printf("%d ", nums[k]);
}
return 0;
 } 
