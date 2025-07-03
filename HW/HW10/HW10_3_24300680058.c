#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

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
	printf("After moxing:\n");
	for (p = a + m; p != a + n; p++)
		printf("%d ", *p);
	for(p = a; p != a + m; p++)
		printf("%d ", *p);
	return 0;
	}
