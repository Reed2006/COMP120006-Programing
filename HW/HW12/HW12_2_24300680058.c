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

	initArray(a, N);	//���������ʼ������ 
	printf("Data:\t");
	outputArray(a, N);	//������� 

	initPointerArray(a, N, pa);	//��ʼ��ָ������ 
	sortByPointer(pa, N);		//����ָ����������: pa[0]ָ����С��, ..., pa[N-1]ָ������� 
	rankArray(b, a, pa, N);		//����ָ���������ɱ������ 

	printf("No:\t");
	outputArray(b, N);	//���������� 

	return 0;
}
