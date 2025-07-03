#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, i, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	printf("Enter the number of students:");
	scanf("%d", &n);
	printf("Randomly generate the grades of %d students:\n", n);
	int *p = (int *)calloc(n, sizeof(int));
	srand((unsigned int)time(NULL));
	for(i = 0; i < n; i++)
	{
		*(p + i) = rand() % 101;
		printf("%-4d", *(p + i));
		if((i + 1) % 10 == 0)
		printf("\n"); 
	}
	for(i = 0; i < n; i++)
	{
		if(0 <= *(p + i) && *(p + i) < 60)
		count1++;
		else if(60 <= *(p + i) && *(p + i) < 70)
		count2++;
		else if(70 <= *(p + i) && *(p + i) < 80)
		count3++;
		else if(80 <= *(p + i) && *(p + i) < 90)
		count4++;
		else
		count5++;
	}
	printf("\nThe statistics of each score segment:\n");
	printf("[0,60) : %d人\n", count1);
	printf("[60,70) : %d人\n", count2);
	printf("[70,80) : %d人\n", count3);
	printf("[80,90) : %d人\n", count4);
	printf("[90,100] : %d人\n", count5);
	return 0;
}
