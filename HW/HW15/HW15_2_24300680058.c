/***
*
* ����n���������С�
* �㷨: �������ɷ�ĸС�ڵ���n�������, Լ��, ���뵽�����е���ȷλ��(����С����˳���������).
* Ҫ��:
*	1) �����Ͷ���ͺ�������������ͷ�ļ���, Դ�����ļ�������ͷ�ļ�
*	2) ����6������: I. �����Լ������; II. ������Ԫ(�����벻��Լ�����)����;
*	III. ������Լ������Ĵ�С˳�򽫱�Ԫ����������; 
*	IV. ����������; V. ���������; VI. �ͷ�������
*
***/
#include "Farey.h"

int main()
{
	int num;
	struct Farey *head;

	printf("Enter a positive integer��");
	scanf("%d", &num);

	head = makeFarey(num);
	outputFarey(head, num);
	freeFarey(head);

	return 0;
}
