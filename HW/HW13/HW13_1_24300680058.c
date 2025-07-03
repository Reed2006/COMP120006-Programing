#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct score
{
    char name[10];
    int midterm_exam;
    int final_exam;
    int HW_score[16];
    int HW_count;
    float final_score;
};

void input_score(struct score *students, int *n) 
{
    int count = 0;
    char line[256];
    while (count < 100)
	{
		gets(line);
        if (line[0] == '\0')  // 如果输入空行，结束输入
            break;

        int i = 0, id = 0;

        while (line[i] != '\0' && line[i] != ' ') 
            students[count].name[id++] = line[i++];
        students[count].name[id] = '\0';
        while (line[i] == ' ') i++;
        students[count].midterm_exam = 0;
        students[count].final_exam = 0;

		while(line[i] != ' ' && line[i] != '\0')
		{
        	students[count].midterm_exam = students[count].midterm_exam * 10 + line[i] - '0';
        	i++;
		}
		while (line[i] == ' ') i++;
		
        while(line[i] != ' ' && line[i] != '\0')
		{
        	students[count].final_exam = students[count].final_exam * 10 + line[i] - '0';
        	i++;
		}

        while (line[i] == ' ') i++;

        students[count].HW_count = 0;
        while (line[i] != '\0') 
		{
            students[count].HW_score[students[count].HW_count] = 0;
            while (line[i]!= '\0' && line[i]!= ' ')
            {
            students[count].HW_score[students[count].HW_count] =students[count].HW_score[students[count].HW_count] * 10 + line[i] - '0';
            i++;
        	}
            while (line[i] == ' ') i++;
            students[count].HW_count ++;
        }
        count++;
    }
    *n = count;
}

void sortBycha(struct score *p, int n)
 {
    int i, j;
    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n - i - 1; j++)
		 {
            if (strcmp(p[j].name, p[j + 1].name) > 0) 
			{
                struct score temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void final_score(struct score *p) 
{
    int term_score = 0, i;
    float ave_score;
    for (i = 0; i < p->HW_count; i++)
        term_score += p->HW_score[i];
    if (p->HW_count > 0)
        ave_score = (float)term_score / p->HW_count ;
    p->final_score = 0.2 * p->midterm_exam + 0.4 * p->final_exam + 0.4 * ave_score;
}

void output_score1(struct score *p, int n)
{
	printf("\nAll students' records\n");
	int max = 0, temp = 0, i, j, k;
	for(i = 0; i < n; i++)
	{
		temp = strlen(p[i].name);
		if(temp > max)
		max = temp;
		temp = 0;
	}
	for(i = 0; i < n; i++)
	{
		printf("%s", p[i].name);
		for(j = 0; j <= max - strlen(p[i].name); j++)
		printf(" ");
		printf("%-4d", p[i].midterm_exam);
		printf("%-4d", p[i].final_exam);
		for(k = 0; k < p[i].HW_count; k++)
		printf("%-4d", p[i].HW_score[k]);
		printf("\n");
	}
}
void output_score2(struct score *p, int n) 
{
    printf("\nAll students' final grades(sorted by names)\n");
    int max = 0, temp = 0, i, j, k;
	for(i = 0; i < n; i++)
	{
		temp = strlen(p[i].name);
		if(temp > max)
		max = temp;
		temp = 0;
	}
	for(i = 0; i < n; i++)
	{
		printf("%s", p[i].name);
		for(j = 0; j <= max - strlen(p[i].name); j++)
		printf(" ");
		printf("%.1f\n", p[i].final_score);
	}
}

int main() {
    struct score students[100];
    int n = 0, i;
    printf("Enter the original records:\n");
    input_score(students, &n);
    for (i = 0; i < n; i++)
        final_score(&students[i]);
    output_score1(students, n);
    sortBycha(students, n);
    output_score2(students, n);
    return 0;
}
