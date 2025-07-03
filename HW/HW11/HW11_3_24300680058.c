#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void reverse(int tar[], int n)
{
	int i, j, temp[N] = {0}; 
	int *a = tar;
	for(j = 0; j < n; j++, a++)
		*(temp + j) = *a;
	for(i = 0; i < n ; i++)
		*(tar + n - 1 - i) = *(temp + i);  
 } 
 int main()
 {
 	int n, m, i, a[N], *p;
	p = a;
	printf("Enter n(<100):");
	scanf("%d", &n) ;
	srand((unsigned int)time(NULL));
	printf("Randomly generate 10 non negative integers within 100:\n");//生成随机数	
	for (p = a; p != a + n; p++)
		printf("%d ", *p = rand() % 100);
		
	printf("\nEnter m(<10):");
	scanf("%d", &m);
	printf("After moving:\n");
	
	reverse(a, m);
	reverse(a + m, n-m);
	reverse(a, n);
	
	for(p = a; p != a + n; p++)
		printf("%d ", *p);
		
	return 0;
 }
