#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

//业务数据结构体
typedef struct Teacher
{
	LinkListNode node;           //节点放在业务结构体首地址，企业级链表
	char name[64];
	int  age;

}Teacher;

int main()
{
	int ret = 0, len = 0, i = 0;
	LinkList *list = NULL;

	list = LinkList_Create();
	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	if (list == NULL)
	{
		ret = -1;
		printf("func LinkList_Create() err: %d \n", ret);
	}

	

	//链表的算法和具体业务节点的分离
	//指定位置插入节点
	ret = LinkList_Insert(list, (LinkListNode*)&t1, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t2, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t3, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t4, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t5, 0);
	//if (ret != 0)
	//{
	//	ret = -2;
	//	printf("func LinkList_Insert() err: %d\n", ret);
	//	return ret;
	//}

	//获取链式表长度
	len = LinkList_Length(list);

	for (i = 0; i < len; i++)
	{
		//获取指定位置节点
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp == NULL)
		{
				ret = -3;
				printf("func LinkList_Get() err: %d\n", ret);
				return ret;
		}
		printf("tmp->age:%d", tmp->age);
	}

	while (LinkList_Length(list) > 0)
	{
		//删除置顶位置节点
		Teacher* tmp = (Teacher*)LinkList_Delete(list, 0);
		if (tmp == NULL)
		{
			ret = -4;
			printf("func LinkList_Delete() err: %d\n", ret);
			return ret;
		}
		printf("tmp->age:%d", tmp->age);
	}

	LinkList_Destroy(list);
	

	system("pause");
	return ret;
}