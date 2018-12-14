#pragma once
#ifndef _MY_DLINKLIST_H_
#define _MY_DLINKLIST_H_

typedef void DLinkList;     //定义链表类型

typedef struct _tag_DLinkListNode              //定义链表节点类型
{
	struct _tag_DLinkListNode *next;   //后继节点
	struct _tag_DLinkListNode *pre;    //前驱节点 
}DLinkListNode;

//创建链式线性表
DLinkList* DLinkList_Create();

//销毁链式线性表
void DLinkList_Destroy(DLinkList* list);

//清除链式表数据
void DLinkList_Clear(DLinkList* list);

//获取链式表长度
int DLinkList_Length(DLinkList* list);

//指定位置插入节点
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

//获取指定位置节点
DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

//删除置顶位置节点
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);


//相比单链表新增的游标操作api
//重置游标位置
void DLinkList_Reset(DLinkList* list);

//让游标指向前一个位置
void DLinkList_Pre(DLinkList* list);

//让游标指向下一个位置
void DLinkList_Next(DLinkList* list);

//游标当前位置
DLinkListNode* DLinkList_Current(DLinkList* list);

//删除游标
void DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);


#endif
