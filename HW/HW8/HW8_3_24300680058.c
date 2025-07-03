#include <stdio.h>
#include <string.h>
#define N 100

int main()
{
	char a[N], b[N];
	int i, m , c[N] = {0}, count = 0, pos, k, j;
	printf("Enter 2 strings:\n");
	gets(a);
	gets(b);
	
	for(i = 0; a[i]; i++)//find the start position of the common characters
	{
		for (j = 0; b[j]; j++)
		{
			k = 0;//clear the k
			
			while(a[i + k]==b[j + k])//find the number of common characters
			k++;
			
			if(k > count)
			{
			count = k;
			pos = i;// pos for storing the start position
			}
		}
	}

	if(count)//count stores the number of common characters
	{
	for(m = pos; m < pos + count; m++)
		printf("%c", a[m]);
	}
	else
		printf("There is no common characters!");
		
	return 0;
}
		
	

