#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkqueue.h"
#include"LinkList.h"

//队列的底层数据结构，业务节点
typedef struct _tag_LinkQueueNode
{
	LinkListNode node;   //链表节点
	void* item;          //队列业务节点

}TLinkQueueNode;

//创建队列 相当于 创建线性表
LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

//销毁队列 相当于 销毁线性表

//涉及节点内存管理，生命周期管理，链表中的节点都是malloc出来的
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);     //先清空，再销毁
	LinkList_Destroy(queue);
}

//清空队列，需要显示的把所有结点弹出，释放每一个节点
void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	LinkList_Clear(queue);
}

//队列中添加元素 相当于 线性表尾部添加
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	TLinkQueueNode *tmp = NULL;
	tmp = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func LinkQueue_Append() malloc err:%d\n", ret);
		return ret;
	}
	memset(tmp,0, sizeof(TLinkQueueNode));  //初始化，对内存负责
	tmp->item = item;

	//需要把栈的item（业务节点） 转化成 链表的LinkListNode节点
	ret = LinkList_Insert(queue, (LinkListNode*)tmp, LinkList_Length(queue));
	if (ret != 0)
	{
		printf("func LinkList_Insert() err:%d\n", ret);
		if (tmp != NULL)
		{
			free(tmp);        //防止插入错误时造成内存泄漏
		}
		return ret;
	}
	return ret;
}

//队列中删除元素 相当于 线性表头部删除
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueueNode *tmp = NULL;
	void *ret = NULL;
	tmp = (TLinkQueueNode *)LinkList_Delete(queue, 0);
	if (tmp == NULL)
	{
		printf("func LinkList_Delete() err.\n");
		return NULL;
	}
	else
	{
		ret = tmp->item;
		free(tmp);              //删除之前缓存
	}
	return ret;
}

//获取队列头部元素 相当于 线性表的0号位置
void* LinkQueue_Header(LinkQueue* queue) 
{
	TLinkQueueNode *tmp = NULL;
	void *ret = NULL;
	tmp = (TLinkQueueNode *)LinkList_Get(queue, 0);
	if (tmp == NULL)
	{
		printf("func LinkList_Get() err.\n");
		return NULL;
	}
	ret = tmp->item;
	return ret;
}


int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}
