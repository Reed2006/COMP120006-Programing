#include <stdio.h>
 
int main()
{
	int mm,dd,yy,mm1,dd1,yy1;
		printf("Enter a date(mm/dd/yy):");
		scanf("%d/%d/%d", &mm1, &dd1, &yy1);
	mm = mm1; dd = dd1; yy = yy1;//输入第一个日期 默认为mm dd yy 
	
	while (yy1 != 0 && mm1 != 0 && dd1 != 0)//用yy1,mm1,dd1来检验是否结束循环 
		{
			printf("Enter a date(mm/dd/yy):");
			scanf("%d/%d/%d",&mm1,&dd1,&yy1);
			if( (yy1 < yy || (yy1 == yy && mm1 < mm) || (yy1 == yy &&mm1 == mm && dd1 < dd)) && (yy1 != 0 && mm1 != 0 && dd1 != 0))//打擂台方式判断更小 
				{
					mm = mm1;
					dd = dd1;
					yy = yy1;
				}			
		}
		
		printf("%d/%d/%d is the earliest date", mm, dd, yy);
		
		return 0;
}
