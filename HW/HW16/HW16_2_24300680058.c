#include <stdio.h>
#include <string.h>
#define N 100

struct record {
	char name[40];
	int midterm, final;
	int hw[16];
	double grade;
};


void input(struct record students[], int* n, int* m)
{
	FILE *fp;
	char c = '\0', *p;
	if((fp = fopen("students.csv", "r")) == NULL)
		printf("can not open file students.csv.");
	*n = 0;
	while ((c = fgetc(fp)) != EOF) {  //�ж�ÿ�ж���ĵ�һ���ַ��Ƿ�Ϊ���з�(����) 
		students[*n].name[0] = c;
		int i = 1;
		while((c = fgetc(fp)) != ',')
			students[*n].name[i++] = c;
		fscanf(fp, "%d,%d,", &students[*n].midterm, &students[*n].final);
		for (*m = 0; c != '\n'; ++(*m))
			fscanf(fp, "%d%c", students[*n].hw + *m, &c);//������ҵ�ɼ������Ŀհ��ַ�
		(*n)++;
	}
	fclose(fp);
}

int maxLen(struct record *students, int n)
{
	int len, maxlen_name;
	struct record *p;

	maxlen_name = strlen(students[0].name);
	for (p = students + 1; p < students + n; p++) {
		len = strlen(p->name);
		if (len > maxlen_name)
			maxlen_name = len;
	}
	return maxlen_name;
}

void print(struct record *pStu[], int n, int m, int max)
{
	int i, j;
	for (i = 0; i < n; i++) {
		printf("%-*s", max + 1, pStu[i]->name);
		printf("%-4d%-4d", pStu[i]->midterm, pStu[i]->final);
		for (j = 0; j < m; j++)
			printf("%-4d", pStu[i]->hw[j]);
		printf("\n");
	}
}

void calculate(struct record *pStu, int m)
{
	int i, sum = 0;
	for (i = 0; i < m; i++)
		sum += pStu->hw[i];
	pStu->grade = 0.2 * pStu->midterm + 0.4 * pStu->final + 0.4 * sum / m;
}

void sort(struct record *pStu[], int n)
{
	int i, j;
	struct record *p;

	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++)
			if (strcmp(pStu[j]->name, pStu[j + 1]->name) > 0) {
				// ����ָ��
				p = pStu[j];
				pStu[j] = pStu[j + 1];
				pStu[j + 1] = p;
			}
}

void print_grade(struct record* pStu[], int n, int max)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%-*s%.1f\n", max+1, pStu[i]->name, pStu[i]->grade);
	printf("\n");
}

int main()
{
	struct record students[N], *pStu[N];
	int n, m;  //n��������, m������ҵ����
	int i, maxlen_name;	//max: ����ֵĳ���

	input(students, &n, &m);
	for (i = 0; i < n; i++) {
		pStu[i] = students + i;  //��ָ������Ԫ�ظ�ֵ
		calculate(pStu[i], m);  //����ÿλѧ���������ɼ� 
	}

	printf("All students'records:\n");
	maxlen_name = maxLen(students, n);
	print(pStu, n, m, maxlen_name);

	//����������
	sort(pStu, n);

	printf("\nAll students' final grades (sorted by name):\n");
	print_grade(pStu, n, maxlen_name);

	FILE *fp;
	if((fp = fopen("grades.csv", "w")) == NULL)
		printf("can not open file grades.csv");
	for(i = 0; i < n; i++)
	{
		fprintf(fp, "%s,%.1f", pStu[i]->name, pStu[i]->grade);
		fprintf(fp, "\n");
	}
	fclose(fp);
	return 0;
} 
