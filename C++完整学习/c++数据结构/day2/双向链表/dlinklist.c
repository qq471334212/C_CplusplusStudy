#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dlinklist.h"

//框架内部数据结构
typedef struct _tag_DLinkList
{
	DLinkListNode header;    //头节点
	DLinkListNode *slider;   //游标
	int length;

}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	if (ret != 0)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}
	return ret;
}

//销毁链式线性表
void DLinkList_Destroy(DLinkList* list)
{
	if (list != NULL)
	{
		free(list);
	}
	return;
}

//清除链式表数据
void DLinkList_Clear(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->header.pre = NULL;
		sList->slider = NULL;
	}
	return;
}

//获取链式表长度
int DLinkList_Length(DLinkList* list)
{
	int length = -1;
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		length = sList->length;
	}
	return length;
}

//指定位置插入节点
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	int ret = 0, i = 0;
	TDLinkList *sList = (TDLinkList *)list;

	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	{
		//定义辅助指针变量，初始化
		DLinkListNode *current = (DLinkListNode*)sList;
		DLinkListNode *next = NULL;    //需增加一个next指针

		for (i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;         //当前指针指到要插入的位置
		}
		next = current->next;

		//步骤1-2
		current->next = node;
		node->next = next;

		//步骤3-4
		if (next != NULL)
		{
			next->pre = node;  //当链表插入第一个元素时要特殊处理,对next->pre不操作
		}
		node->pre = current;

		//插入第一个元素处理
		if (sList->length == 0)
		{
			sList->slider = node;   //当链表插入第一个元素时处理游标
		}
		//在0位置插入，当前结点地址是头节点，需要将节点node->pre=null;
		if (current == (DLinkListNode *)sList)
		{
			node->pre = NULL;
		}
		sList->length++;
	}
	return 0;
}


//获取指定位置节点
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	int i = 0;
	TDLinkList *sList = (TDLinkList *)list;
	DLinkListNode *current = (DLinkListNode*)sList;
	DLinkListNode *ret = NULL;

	for (i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;         //当前指针指到要插入的位置
	}
	ret = current->next;

	return ret;
}

//删除指定位置节点
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	int i = 0;
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL || pos < 0)
	{
		return NULL;
	}
	//三个辅助指针变量
	DLinkListNode *current = (DLinkListNode*)sList;
	DLinkListNode *ret = NULL;
	DLinkListNode *next = NULL;

	for (i = 0; i < pos; i++)
	{
		current = current->next;         //当前指针指到要删除的位置
	}
	//辅助指针赋值
	ret = current->next;
	next = ret->next;
	//步骤1
	current->next = next;

	//步骤2
	if (next != NULL)
	{
		next->pre = current;     //尾节点不需要这句操作
		if (current == (DLinkListNode*)sList)  //头节点操作
		{
			next->pre = NULL;
		}
	}
	//如果游标在要删除的位置，将其下移
	if (sList->slider == ret)
	{
		sList->slider = next;
	}

	sList->length--;
	return ret;
}

//重置游标位置
void DLinkList_Reset(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL )
	{
		return;
	}
	DLinkListNode *current = (DLinkListNode*)sList;
	sList->slider = current;
	return;
}

//让游标指向前一个位置
void DLinkList_Pre(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		return;
	}
	
	sList->slider = sList->header.pre;
	return;
}

//让游标指向下一个位置
void DLinkList_Next(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		return ;
	}

	sList->slider = sList->header.next;
	return;
}

//游标当前位置
DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		return NULL;
	}

	return sList->slider;
}

//删除游标
void DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	return;
}