#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
	char *ps, *pr, ch, s[N];
	int strlen_pre, strlen_now = 0, flag = 1, white = 0;
	printf("Enter your text:\n");
	gets(s);
	printf("strlen(s):%d\n", strlen(s));
	for(ps = pr = s; *ps; pr++)
		{
			if(*pr != ' ')
			{
				if(flag == 1)
			{
				*s = *pr;
				ps = s;
				flag = 0;
			}
				else 
				{
				*++ps = *pr;
				white = 0;
			}
		}
			if(white == 0 && flag == 0 && *pr == ' ')
				{
				*++ps = ' ';
				white = 1;
			}
			if(*pr == '\0')
				*ps = '\0';
			}
	printf("After moving unnecessary white space characters:\n");
	puts(s);
	printf("strlen(s):%d\n", strlen(s));										
	return 0; 		
 } 
