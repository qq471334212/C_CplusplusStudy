#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LinkList.h"

//框架内部使用的结构体
typedef struct _tag_LinkList 
{
	LinkListNode head;  //头节点
	int length;

}TLinkList;

//创建链式线性表
LinkList* LinkList_Create()
{
	int ret = 0;
	TLinkList *tmp = NULL;
	tmp = (TLinkList *)malloc(sizeof(TLinkList));
	memset(tmp, 0, sizeof(TLinkList));
	tmp->length = 0;
	tmp->head.next = NULL;
	return tmp;
}

//销毁链式线性表
void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//清除链式表数据
void LinkList_Clear(LinkList* list)
{
	TLinkList *tList = NULL;
	if (list == NULL)
	{
		return;
	}
	tList = (LinkList*)list;
	//恢复初始化
	tList->length = 0;
	tList->head.next = NULL;

	return;
}

//获取链式表长度
int LinkList_Length(LinkList* list)
{
	TLinkList *tList = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tList = (LinkList*)list;

	return tList->length;
}

//有头结点的链表比较方便，正规
//指定位置插入节点,插入时，先连后面的节点，再连前面的节点
//1.指针指向谁 就把谁的地址赋给指针
//2.分清楚链表的操作逻辑 和赋值指针变量之间的关系
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int ret = 0;
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Insert() err: %d \n", ret);
		return ret;
	}

	//初始化
	tList = (TLinkList*)list;
	current = &(tList->head);    //让辅助（当前位置）指针变量指向链表头部
	
    //将指针从头节点位置跳到要插入的节点前一个位置
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

    //插入过程
	node->next = current->next;
	current->next = node;
	tList->length++;            //插入后链表长度+1
	return ret;
}

//获取指定位置节点
LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int ret = 0;
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Get() err: %d \n", ret);
		return NULL;
	}

	//初始化
	tList = (TLinkList*)list;
	current = &(tList->head);    //让辅助（当前位置）指针变量指向链表头部

								 //将指针从头节点位置跳到要插入的节点前一个位置
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;       //将对应节点返回即可
}

//删除置顶位置节点
//需要两个辅助指针变量
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int ret = 0;
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;
	LinkListNode *tmp = NULL;       //存储要删除的节点
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Delete() err: %d \n", ret);
		return NULL;
	}

	//初始化
	tList = (TLinkList*)list;
	current = &(tList->head);    //让辅助（当前位置）指针变量指向链表头部

								 //将指针从头节点位置跳到要插入的节点前一个位置
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	tmp = current->next;
	current->next = tmp->next;
	tList->length--;            //删除后链表长度-1

	return tmp;                 //将要删除的节点返回，在业务程序中释放其内存
}