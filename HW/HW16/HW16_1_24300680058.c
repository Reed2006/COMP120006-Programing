#include <stdio.h>
#include <string.h>
#define MAX 1000
#define num "_24300680058"

int main()
{
	FILE *fp1, *fp2;
	char fname1[MAX], fname2[MAX], *p = fname2;
	int i, count = 1, mark;
	printf("Enter the file name:"); 
	gets(fname1);
	for(i = 0; i < strlen(fname1); i++)
	{
		if(*(fname1 + i) != '.')
			*p++ = *(fname1 + i);
		else
		{	
			mark = i;
			strcpy(p, num);
			p += strlen(num);
			break;
		}		
	}
	
	if((fp1 = fopen(fname1, "r")) == NULL)
	{
		printf("Can not open %s file.\n", fname1);
		return 1;
	}
	strcpy(p, fname1 + i);
		if((fp2 = (fopen(fname2, "w"))) == NULL)
	{
		printf("Can not open %s file.\n", fname2);
		return 1; 
	}
	printf("End of comment");
	char line[MAX];
	
	if(strcmp(fname2 + strlen(num) + mark , ".py") == 0)
	{ 
		while (fgets(line, MAX, fp1)) {
        char *t = line;
        while (*t == ' ' || *t == '\t') t++;

        if (*t != '\n' && *t != '#' && *t != '\0') 
		{
            fprintf(fp2, "%d. ", count++);
            fputs(line, fp2);
        } 
		else 
            fputs(line, fp2);
    }
}
	if(strcmp(fname2 + strlen(num) + mark , ".cpp") == 0)
	{ 
		while (fgets(line, MAX, fp1)) 
		{
        char *t = line;
        while (*t == ' ' || *t == '\t') t++;

        if (*t != '\n' && *t != '/' && *t != '\0') 
		{
            fprintf(fp2, "%d. ", count++);
            fputs(line, fp2);
        } 
		else 
            fputs(line, fp2);
    }
}	
	fclose(fp1);
	fclose(fp2);
	return 0;
} 
