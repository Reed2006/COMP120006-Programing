#include <stdio.h>

int main()
{
	int count_0 = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0, count_6 = 0, count_7 = 0, count_8 = 0, count_9 = 0;
	char ch;
	
	printf("Enter an integer:");
	
	while ((ch = getchar()) != '\n')
	{
		if (ch == ' ' || ch == '\t')//检验空白格 制表格
		continue;
		//用num来把字符转化为数字 
		int num = ch - '0';
		switch(num)
		{
			case 0:
				count_0 ++;
				break;
			case 1:
				count_1 ++;
				break;
			case 2 :
				count_2 ++;
				break;
			case 3 :
				count_3 ++;
				break;
			case 4 :
				count_4 ++;
				break;
			case 5 :
				count_5 ++;
				break;
			case 6 :
				count_6 ++;
				break;
			case 7 :
				count_7 ++;
				break;
			case 8 :
				count_8 ++;
				break;
			case 9 :
				count_9 ++;
				break;
			default:
				break;
		}
    } 
	 
	 printf("Digit\tOccurrences\n");
	 printf("0\t%d\n", count_0);
	 printf("1\t%d\n", count_1);
	 printf("2\t%d\n", count_2);
	 printf("3\t%d\n", count_3);
	 printf("4\t%d\n", count_4);
	 printf("5\t%d\n", count_5);
	 printf("6\t%d\n", count_6);
	 printf("7\t%d\n", count_7);
	 printf("8\t%d\n", count_8);
	 printf("9\t%d\n", count_9);
	  
	return 0 ;
	
} 
