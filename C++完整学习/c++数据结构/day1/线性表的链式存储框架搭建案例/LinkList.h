#pragma once
#ifndef __LinkList_H__
#define __LinkList_H__

typedef void LinkList;     //定义一个结构体类型
//typedef struct _tag_LinkListNode LinkListNode;
//struct _tag_LinkListNode
//{
//	LinkListNode *next;
//};

//定义链表节点类型
typedef struct _tag_LinkListNode 
{
	struct _tag_LinkListNode *next;     //链表的下一个节点地址
}LinkListNode;

//创建链式线性表
LinkList* LinkList_Create();

//销毁链式线性表
void LinkList_Destroy(LinkList* list);

//清除链式表数据
void LinkList_Clear(LinkList* list);

//获取链式表长度
int LinkList_Length(LinkList* list);

//指定位置插入节点
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

//获取指定位置节点
LinkListNode* LinkList_Get(LinkList* list, int pos);

//删除置顶位置节点
LinkListNode* LinkList_Delete(LinkList* list, int pos);


#endif