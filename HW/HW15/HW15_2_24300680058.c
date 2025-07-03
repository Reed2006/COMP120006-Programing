/***
*
* 生成n级法雷序列。
* 算法: 依次生成分母小于等于n的真分数, 约分, 插入到链表中的正确位置(按从小到大顺序插入链表).
* 要求:
*	1) 将类型定义和函数声明保存在头文件中, 源程序文件包含该头文件
*	2) 定义6个函数: I. 求最大公约数函数; II. 创建表元(并填入不可约真分数)函数;
*	III. 按不可约真分数的大小顺序将表元插入链表函数; 
*	IV. 创建链表函数; V. 输出链表函数; VI. 释放链表函数
*
***/
#include "Farey.h"

int main()
{
	int num;
	struct Farey *head;

	printf("Enter a positive integer：");
	scanf("%d", &num);

	head = makeFarey(num);
	outputFarey(head, num);
	freeFarey(head);

	return 0;
}
