#include <stdio.h>
#include <stdlib.h>
struct poly
{
	int power;
	int check;
	float coef;
	struct poly* next;
};
struct poly* init()
{
    int p;
    float coef;
    struct poly *temp, *head = NULL;
    char ch;

    printf("\nPower (enter a non-numeric character to end): ");
    while(scanf("%d", &p) == 1) 
    {
        printf("Coefficient of power %d: ", p);
        scanf("%f", &coef);

        temp = (struct poly*)malloc(sizeof(struct poly));
        temp->coef = coef;
        temp->power = p;
        temp->next = head;
        temp->check = 0;
        head = temp;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Power (enter a non-numeric character to end): ");
    }

    while ((ch = getchar()) != '\n' && ch != EOF);

    return head;
}
struct poly* addpoly(struct poly *lf, struct poly *rf)
{
	struct poly *temp1, *temp2, *sum, *head = NULL;
	for(temp1 = lf; temp1; temp1 = temp1->next)
	{
		for(temp2 = rf; temp2; temp2 = temp2->next)
		{
			if(temp1->power == temp2->power)
			{
				sum = (struct poly*)malloc(sizeof(struct poly));
				temp1->check = 1;
				temp2->check = 1;
				sum->coef = temp1->coef + temp2->coef;
				sum->power = temp1->power;
				sum->next = head;
				head = sum;
			}
		}
	}
	for(temp1 = lf; temp1; temp1 = temp1->next)
	{
		if(temp1->check == 0)
		{
		sum = (struct poly*)malloc(sizeof(struct poly));
		sum->coef = temp1->coef;
		sum->power = temp1->power;
		sum->next = head;
		head = sum;
		}
	}
	for(temp2 = rf; temp2; temp2 = temp2->next)
	{
		if(temp2->check == 0)
		{
		sum = (struct poly*)malloc(sizeof(struct poly));
		sum->coef = temp2->coef;
		sum->power = temp2->power;
		sum->next = head;
		head = sum;
		}
	}
	return head; 
}

struct poly* copySorted(struct poly* link) {
	struct poly* head4 = NULL, * pFront4, * p4, *p, *newNode;
	p = link;
	while (p) {
		newNode = (struct poly*)malloc(sizeof(struct poly));
		newNode->coef = p->coef;
		newNode->power = p->power;
		p4 = head4;
		while (p4 && p4->power > p->power) 
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

void outputLink(struct poly *head) 
{
    struct poly *p = head; 
	int isEmpty = 1;

    for (p = head; p -> power; p = p->next) {
        if (p->coef != 0) {
            isEmpty = 0;
            break;
        }
    }

    if (isEmpty != 1)
    	printf("(");
    for(p = head; p; p = p->next) 
	{
        if (p->coef > 0 && p != head) {
            printf(" + ");
        }
        if(p->coef != 0 && p->power != 1 && p->power != 0)
        	printf("%gx^%d", p->coef, p->power);
        else if(p->coef != 0 && p->power == 1)
        	printf("%gx", p->coef);
        else if(p->power == 0)
        	printf("%g", p->coef);
    }
    if (isEmpty != 1)
		printf(")");
}

void freePoly(struct poly *head) 
{
    struct poly *current = head;
    struct poly *next;
    while (current != NULL)
	{
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
	printf("\t\tPolinomial summation:\n");
	printf("Enter the power and the coefficent of the 1st polinomial:");
	struct poly* lf, *rf,* sum;
	lf = init();
	printf("Enter the power and the coefficient of the 2nd polinomial:");
	rf = init();
	sum = addpoly(lf, rf);
	lf = copySorted(lf);
	rf = copySorted(rf);
	sum = copySorted(sum);
	outputLink(lf);
	printf("+");
	outputLink(rf);
	printf(" = ");
	outputLink(sum);
	freePoly(lf);
    freePoly(rf);
    freePoly(sum);
	return 0;
}
