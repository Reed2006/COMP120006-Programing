#include <stdio.h>
#define lower 0
#define upper 100
int main()
{
	double f, c, step;
	f = lower, c = 0, step = 10;
	
	printf("�����¶��������¶ȵĶ��ձ�����:\n") ;
	while(f <= upper)
	{
		c = 5.0 / 9.0 * (f - 32.0);
		printf("\%3.0f\%6.1f\n", f, c);
		f += step;	
	}
	
	return 0;
} 
