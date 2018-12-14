#pragma once
#ifndef __MY_SEQLIST_H__
#define __MY_SEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;   //定义协议的节点类型是void，因此框架根本不关心业务节点是什么类型，任何结构体都可以使用

//创建线性表
SeqList* SeqList_Create(int capacity);

//销毁线性表
void SeqList_Destroy(SeqList* list);

//清除线性表数据
void SeqList_Clear(SeqList* list);

//获取线性表长度
int SeqList_Length(SeqList* list);

//线性表容量
int SeqList_Capacity(SeqList* list);

//指定位置插入节点
int SeqList_Insert(SeqList* list, SeqListNode* node,int pos);

//获取指定位置节点
SeqListNode* SeqList_Get(SeqList* list, int pos);

//删除置顶位置节点
SeqListNode* SeqList_Delete(SeqList* list, int pos);


#endif
