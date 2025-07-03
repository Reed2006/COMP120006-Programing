#include<stdio.h>
#define N 16
int findlist(int a[][5], int n)
{
	int (*p)[5] = a, i; 
	for(i = 0; i < N; i++)
	{
		if((*(*(p + i)) != n) && i != N - 1)
			continue; 
		else if (*(*(p + i)) == n)
			return i;
		else
			return N;	
 }
}
 int main()
 {
 	int list[][5] = 
	 {{201001, 75, 85, 77, 59}, {201002, 57, 78, 73, 66}, {201003, 89, 86, 70, 90}, 
	 {201004, 47, 70, 82, 73}, {201005, 72, 87, 88, 54}, {201006, 90, 96, 99, 99}, 
	 {201007, 81, 97, 99, 67}, {201008, 43, 98, 96, 79}, {201009, 67, 72, 73, 40}, 
	 {201010, 77, 70, 82, 65}, {201011, 77, 72, 73, 80}, {201012, 47, 70, 82, 73}, 
	 {201013, 77, 82, 83, 50}, {201014, 97, 90, 92, 95}, {201015, 87, 92, 93, 60}, 
	 {201016, 47, 90, 92, 73}};
	int m, n, tar, (*pList)[5] = list;
	printf("The grade form is:\n");
	for(m = 0; m < N; m++)
	{
		for(n = 0; n < 4; n++)
			printf("%d\t", *(*(pList + m) + n));
		if(n == 4)
				printf("%d\n", *(*(pList + m) + n));
	}
	printf("Enter a student ID:\n");
	scanf("%d", &tar);
	if(findlist(list , tar) == N)
		printf("Student ID %d not found", tar);
	else
	{
		for(n = 0; n < 5; n++)
		printf("%d\t", *(*(pList + findlist(list, tar))+ n));
	}
	return 0;
 }
