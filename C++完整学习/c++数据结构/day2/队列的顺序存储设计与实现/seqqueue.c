#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqqueue.h"
#include"seqlist.h"


//队列是特殊的线性表 先进先出

//创建一个线性队列 相当于 创建一个线性表
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//销毁一个线性队列 相当于 销毁一个线性表
void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return;
}

//清空一个线性队列 相当于 清空一个线性表
void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return;
}

//向队列添加元素进队列，相当于 线性表尾插
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

//出队列 相当于 从线性表头部弹出元素
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue, 0);
}

void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue, 0);;
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}
