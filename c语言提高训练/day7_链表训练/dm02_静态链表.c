#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ṹ�嶨�徲̬�����̶�����
//�ڵ��ڴ���ջ�У��������Ұָ��
typedef struct Teacher
{
	int data;
	struct Teacher  *next;       //ָ��������һ����ַ
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
	while (p)              //����ָ��
	{
		printf("data:%d\n", p->data);
		p = p->next;
	}

	return &t1;     //������ͷ�ڵ��ַ˦����

}
void main02()
{
	Teacher *head = CreateList();

	system("pause");
	return;
}