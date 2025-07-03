#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct intnode
{
	int num;
	struct intnode *gen;
	struct intnode *asc;
}; 

int num;
struct intnode *Init()
{
	srand((unsigned int)time(NULL));
	int i;
	struct intnode *head = (struct intnode*)malloc(sizeof(struct intnode)), *tail = head;
	struct intnode *p;
	for(i = 0; i < num; i++)
		{
			p = (struct intnode*)malloc(sizeof(struct intnode));
			p->num = rand() % 100;
			p->gen = NULL;
			tail->gen = p;
			tail = p;
		}
	return head;
}

void ascend(struct intnode *head)
{
    struct intnode *p = head->gen, *next_p = NULL;
    head->asc = NULL; 
    while (p)
    {
        next_p = p->gen; 
        struct intnode *qfront = head;
        struct intnode *q = head->asc;

        while (q && q->num < p->num)
        {
            qfront = q; 
            q = q->asc;
        }

        if (qfront == head) 
		{
            p->asc = head->asc;
            head->asc = p;
        } 
		else 
		{
            p->asc = q;
            qfront->asc = p;
        }

        p = next_p;
    }
}

void output(struct intnode *head, int flag)
{
	struct intnode *p;
	if(flag == 1)
	{
		for(p =head->gen ; p; p = p->gen)
		printf("%d ", p->num);
	}
	else
	{
		for(p =head->asc; p; p = p->asc)
		printf("%d ", p->num);
	}
	printf("\n");
	
}
int main()
{
	num = 10 + rand() % 10;
	struct intnode *head;
	head = Init();
	printf("Randomly generating %d integers:\n", num);
	output(head, 1);
	printf("Listed link by generation order:\n");
	output(head, 1);
	ascend(head);
	printf("Listed link by ascending order:\n");
	output(head, 2);
	return 0;	
}
