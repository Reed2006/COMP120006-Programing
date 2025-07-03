#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
#define ENCRYPT 1  //��־����, ������� 
#define DECRYPT 2  //��־����, ������� 

//��������ı�Ԫ���� 
struct node
{
	int i;
	struct node *next;
};

struct node* makeLoop(int n) {
    struct node *head = NULL, *p, *tail;
    int i;
    for (i = 0; i < n; i++) {
        p = (struct node*)malloc(sizeof(struct node));
        p->i = i;
        p->next = NULL;
        if (head == NULL)
		{
            head = p;
            tail = p;
        } 
		else
		{
            tail->next = p;
            tail = p;
        }
    }
    // �γɻ�������
    if (tail)
	{
        tail->next = head;
    }
    return head;
}
void process(char *original,int key, char *tar, int flag)
{
	struct node *p, *pfront, *head, *temp;
	int i, len = strlen(original), index = 0;
	head = makeLoop(len);
	p = head;
	pfront = NULL;

	while(p->next)
	{
		for(i = 0; i < key - 1; i++)
		{
			pfront = p;
			p = p->next;
		}
		if(flag == 1)
		*tar++ = *(original + p->i);
		else if(flag == 2) 
		*(tar + p->i) = original[index++];
		if(p->next == p)
			p->next = NULL;
		else
		{
		pfront->next = p->next;
		temp = p;
		p = p->next; 
		free(temp);
		}
	}
	tar[len] = '\0';	
} 

int main()
{
	int key;
	char original[N], cipher[N], decipher[N];

	printf("Enter some text (length < %d):\n", N);
	gets(original);
	printf("Enter the key: ");
	scanf("%d", &key);

	process(original, key, cipher, ENCRYPT);  //���� 
	printf("The cipher:\n%s\n", cipher);
	process(cipher, key, decipher, DECRYPT);  // ���� 
	printf("The decipher:\n%s\n", decipher);

	return 0;
}
