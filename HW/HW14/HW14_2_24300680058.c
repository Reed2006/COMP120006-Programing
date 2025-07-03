#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct intNode
{
	int value;
	struct intNode* next;
};

struct intNode* initLink()
{
	srand((unsigned int)time(NULL));
	int i;
	struct intNode* head = NULL, *p;
	for(i = 0; i < 10; i++)
		{
			p = (struct intNode*)malloc(sizeof(struct intNode));
			p->value = rand() % 100;
			p->next = head;
			head = p;
		}
	return head;
}

struct intNode *delMin(struct intNode *head)
{
	struct intNode *p, *pmin = head, *pfront = head;
	int min;
	min = head->value;
	for(p = head; p; p = p->next)
	{
		if(p->value < min)
		{
			min = p->value;
			pmin = p;
		}
	}
		if(pmin == head)
		{
			head = head->next;	
		}
	
		else
		{
			while(pfront->next != pmin)
				pfront = pfront->next;
			pfront->next = pmin->next;
		}
		pmin->next = NULL;
		free(pmin);
		return head;
} 

void outputLink(struct intNode *head)
{
	struct intNode *p;
	for(p = head; p; p = p->next)
	{
		printf("%d ", p->value);
	}
	printf("\n");
}

void freeLink(struct intNode *head)
{
	struct intNode *p, *next;
	for(p = head; p != NULL; p = next)
	{
		next = p->next; 
		free(p);        
	}
}

int main()
{
	struct intNode* h[2];
	int i;
	char* prompt[] = { "Random list", "After deleting the minimum value:" };
	h[0] = initLink();
	printf("%s: \n", prompt[0]);
	outputLink(h[0]);
	h[1] = delMin(h[0]);
	printf("%s: \n", prompt[1]);
	outputLink(h[1]);
	freeLink(h[1]);
	return 0;
}
