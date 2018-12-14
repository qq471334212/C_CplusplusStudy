#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结构体定义静态链表，固定个数
//节点内存在栈中，容易造成野指针
typedef struct Teacher
{
	int data;
	struct Teacher  *next;       //指向链表下一个地址
}Teacher;

Teacher *CreateList()
{
	Teacher t1, t2, t3;
	Teacher *p = NULL;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = NULL;

	p = &t1;
	while (p)              //遍历指针
	{
		printf("data:%d\n", p->data);
		p = p->next;
	}

	return &t1;     //把链表头节点地址甩出来

}
void main02()
{
	Teacher *head = CreateList();

	system("pause");
	return;
}