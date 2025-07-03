#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct speed {
	int min, sec;
	struct speed* next;
}Speed;

FILE* load(char* name)
{
	FILE *fp;
	char temp[100];
	strcpy(temp, name);
	temp[0] = temp[0] + 32;
	temp[5] = '\0';
	strcat(temp, ".txt");
	fp = fopen(temp, "r");
	return fp;
}

Speed *parse(FILE* fp)
{
	char c;
	int count = 0;
	while(count != 2)
	{
		c = fgetc(fp);
		if(c == ',')
			count++;
	}
	Speed *head, *p, *pFront, *q;
	head = (Speed*)malloc(sizeof(Speed));
	head->next = NULL;
	fseek(fp, -1, SEEK_CUR);
	fgetc(fp);
	while(fgetc(fp) != EOF)
	{ 
		q = (Speed*)malloc(sizeof(Speed));
		fscanf(fp, "%d%c%d", &q->min, &c, &q->sec);
	
		q->next = NULL;
		p = head->next;
		pFront = head;
		while(p && (60 * p->min + p->sec) < (60*q->min + q->sec))
			{
				p = p->next;
				pFront = pFront->next;   				
			}
			pFront->next = q;
			q->next = p;
	}
	return head;
} 

void output(char* name, Speed* head)
{
	printf("%s\t\t", name);
	int i;
	Speed *p = head->next;
	for(i = 0; i < 3; i++)
	{
		printf("%d:%d\t", p->min, p->sec);
		while((60 * p->min + p->sec) == (60*p->next->min + p->next->sec)) 
			p = p->next;
		p = p->next;   
	}
	printf("\n");
}
void freeLink(Speed* head)
{
	Speed* p = head, *np;
	for(p = head; p; p = np)
	{
		np = p->next;
		free(p); 
	}
}

int main()
{
	int i;
	FILE* fp;
	Speed* head;
	char* players[] = { "James Lee","Sarah Sweeney", "Julie Jones", "Mikey McManus" };

	printf("Name\t\tRecord1\tRecord2\tRecord3\n");
	for (i = 0; i != 4; ++i) {
		fp = load(players[i]);	//��ÿλѡ�ֵ��ļ�,�����ļ�ָ�� 
		if (fp == NULL)	//�ļ��򲻿�
			return 1;
		head = parse(fp);	//�����ļ����ݣ����ɴӿ쵽���Ĳ��ظ�ʱ������
		output(players[i], head);	//���ÿλѡ������3��ʱ���¼
		freeLink(head);	//�ͷ�����ռ�
	}
	return 0;
}
