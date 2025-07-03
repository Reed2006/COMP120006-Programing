#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void initArray(int *a, int n)
{
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i != n; i++)
		*(a + i) = rand() % 100;
 } 
void outputArray(int *a, int n)
{
	int i;
	for (i = 0; i != n; i++)
		printf("%d\t", *(a + i));
	printf("\n");
}
void initPointerArray(int *a, int n, int* pa[])
{
	int i;
	for (i = 0; i != n; i++)
		*(pa + i) = a + i;
}
void sortByPointer(int* pa[], int n)
{
	int* temp, i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - i -1; j++)
		{
			if(**(pa + j) > **(pa + j + 1))
			{
				temp = *(pa + j);
				*(pa + j) = *(pa + j + 1);
				*(pa + j + 1) = temp;
			}
		}
	}
}
void rankArray(int *b, int *a, int* pa[], int n)
 {  
    int i, j; 
    for (i = 0; i < n; i++) 
	{  
        b[i] = 1; 
        for (j = 0; j < n; j++) 
            if (a[i] > *(pa[j]))
                b[i]++;            
    }  
}
int main()
{
	int a[N], b[N], * pa[N];

	initArray(a, N);	//用随机数初始化数组 
	printf("Data:\t");
	outputArray(a, N);	//输出数组 

	initPointerArray(a, N, pa);	//初始化指针数组 
	sortByPointer(pa, N);		//利用指针数组排序: pa[0]指向最小数, ..., pa[N-1]指向最大数 
	rankArray(b, a, pa, N);		//利用指针数组生成编号数组 

	printf("No:\t");
	outputArray(b, N);	//输出编号数组 

	return 0;
}
