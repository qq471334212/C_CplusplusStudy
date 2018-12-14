#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

//ҵ��ṹ�������
typedef struct Teacher
{
	unsigned char name[64];
	int age;

}Teacher;

int main()
{
	int ret = 0;
	int i = 0;
	//�������Ա�
	SeqList *list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	int Init_Capacity = 10;
	list= SeqList_Create(Init_Capacity);
	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err: %d\n", ret);
	}

	//ָ��λ�ò���ڵ�,ͷ�巨
	SeqList_Insert(list, (SeqListNode*)&t1, 0);
	SeqList_Insert(list, (SeqListNode*)&t2, 0);
	SeqList_Insert(list, (SeqListNode*)&t3, 0);
	SeqList_Insert(list, (SeqListNode*)&t4, 0);
	SeqList_Insert(list, (SeqListNode*)&t5, 0);

	//��������
	for (i = 0; i < SeqList_Length(list); i++)
	{
		Teacher* tmp = SeqList_Get(list, i);
		if (tmp == NULL)
		{
			ret = -2;
			printf("func SeqList_Get() err: %d\n", ret);
			return ret;
		}
		printf("tmp->age:%d ", tmp->age);
	}

	//ɾ�������еĽڵ�
	while (SeqList_Length(list) > 0)
	{
		Teacher* tmp = SeqList_Delete(list, 0);
		if (tmp == NULL)
		{
			ret = -2;
			printf("func SeqList_Get() err: %d\n", ret);
			return ret;
		}
		printf("tmp->age:%d ", tmp->age);
	}


    SeqList_Destroy(list);



	system("pause");
	return ret;
}