#include <stdio.h>
#include <stdlib.h>
int M = 0; 

struct Farey
{
	int num;
	int den;
	struct Farey * next;
}; 

int gcd(int num, int den)
{
    int temp;
    while (den != 0)
    {
        temp = num % den;
        num = den;
        den = temp;
    }
    return num;
}

void initnode(int num, int tar[][2])
{
    int i, j, k = 0;
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (gcd(j, i) == 1)
            {
                tar[k][0] = j;
                tar[k][1] = i; 
                k++;
            }
        }
    }
    M = k;
}


int compare_gcd(int num1, int den1, int num2, int den2)
{
	int fin_num1 = num1 * den2;
	int fin_num2 = num2 * den1;
	if(fin_num1 < fin_num2)
	return 0;
	else if(fin_num1 > fin_num2)
	return 1;
}

struct Farey* makeFarey(int num)
{
	struct Farey *p, *head, *tail;
	int i, j, temp, tar[num * num][2];
	initnode(num, tar);
	for(i = 0; i < M; i++) 
	{
		for(j = 0; j < M - i; j++)
		{
			if(compare_gcd(tar[j][0], tar[j][1], tar[j + 1][0], tar[j + 1][1]) == 1)
			{
				temp = tar[j][0];
				tar[j][0] = tar[j + 1][0];
				tar[j + 1][0] = temp;
				temp = tar[j][1];
				tar[j][1] = tar[j + 1][1];
				tar[j + 1][1] = temp;
			}
		}
	}
	head = (struct Farey*)malloc(sizeof(struct Farey));
	head->num = 0;
	head->den = 1;
	tail = head;
	for(i = 0; i < M; i++)
	{
		p = (struct Farey*)malloc(sizeof(struct Farey));
		p->num = tar[i][0];
		p->den = tar[i][1];
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return head;
}
void outputFarey(struct Farey* head, int num)
{
	struct Farey *p;
	for(p = head; p; p = p->next)
		printf("%d/%d ", p->num, p->den);
}
void freeFarey(struct Farey *head)
{
	struct Farey *p, *next_p;
	for(p = head; p; p = next_p)
	{
		next_p = p->next;
		free(p);	
	}
}
