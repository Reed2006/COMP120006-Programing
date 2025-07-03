czsz#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int main()
{
	int i, n, *p, a[N] = {0}, sum = 0;
	srand((unsigned int)time(NULL));
	n = rand() % 100;
	printf("%Random integer array(%delements):\n", n);//生成随机数	
	for (i = 0; i != n; i++)
		printf("%d ", a[i] = rand() % 100);
	int max = *a, min = *a;
	for (p = a; p < a + n; p++)
	{
		sum += *p;
		if(*p > max)
			max = *p;
		if(*p < min)
			min = *p;
		}
	printf("\nMaximum integer : %d\n", max);
	printf("Mininum integer : %d\n", min);
	printf("Average integer: %.1f", (float) sum / (float) n);
	return 0;
 } 
