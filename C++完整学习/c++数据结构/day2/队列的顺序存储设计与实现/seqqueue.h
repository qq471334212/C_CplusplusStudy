#pragma once
#ifndef _MY_SEQQUEUE_H_
#define _MY_SEQQUEUE_H_

typedef void SeqQueue;

SeqQueue* SeqQueue_Create(int capacity);

void SeqQueue_Destroy(SeqQueue* queue);

void SeqQueue_Clear(SeqQueue* queue);

//添加元素，从队列尾部入队列
int SeqQueue_Append(SeqQueue* queue, void* item);

//出队列，从队列头部
void* SeqQueue_Retrieve(SeqQueue* queue);

//获取头部元素
void* SeqQueue_Header(SeqQueue* queue);

int SeqQueue_Length(SeqQueue* queue);

int SeqQueue_Capacity(SeqQueue* queue);


#endif
