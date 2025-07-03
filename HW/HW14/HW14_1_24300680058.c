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

struct intNode* copy(struct intNode* head)
{
	struct intNode *p, *q, *head1, *qfront;
	q = (struct intNode*)malloc(sizeof(struct intNode));
	q->value = head->value ;
	head1 = q;
	qfront = q;
	for(p = head->next; p; p = p->next)
	{
		q = (struct intNode*)malloc(sizeof(struct intNode));
		qfront->next = q;
		q->value = p->value;
		qfront = q; 	
	}
	q->next = NULL;
	return head1;
}

struct intNode *copyReversed(struct intNode *head)
{
	struct intNode *p, *q;
	struct intNode *head2 = NULL;
	for(p = head; p; p = p->next )
	{
		q = (struct intNode*)malloc(sizeof(struct intNode));
		q->value = p->value;
		q->next = head2;
		head2 = q;
	}
	return head2;
}

struct intNode* copySorted(struct intNode* link) {
	struct intNode* head4 = NULL, * pFront4, * p4, *p, *newNode;
	p = link;
	while (p) {
		newNode = (struct intNode*)malloc(sizeof(struct intNode));
		newNode->value = p->value;
		p4 = head4;
		while (p4 && p4->value < p->value) 
		{
			pFront4 = p4;
			p4 = p4->next;
		}
		if (p4 == head4)		
			head4 = newNode;
		else
			pFront4->next = newNode;
		newNode->next = p4;
		p = p->next;
	}
	return head4;
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
	struct intNode *p = head, *next;
	for(p = head; p; p = next)
	{
		next = p->next;
		free(p);
	}
}

int main()
{
	struct intNode* h[4];
	int i;

	h[0] = initLink();
	h[1] = copy(h[0]);
	h[2] = copyReversed(h[0]);
	h[3] = copySorted(h[0]);

	char* prompt[] = { "Random list", "List copy", "Reversed list copy", "Sorted list copy" };
	for (i = 0; i < 4; i++) {
		printf("%s: \n", prompt[i]);
		outputLink(h[i]);
	}

	for (i = 0; i < 4; i++)
		freeLink(h[i]);

	return 0;
}
