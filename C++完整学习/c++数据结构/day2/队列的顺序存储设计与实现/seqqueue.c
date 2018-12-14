#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqqueue.h"
#include"seqlist.h"


//��������������Ա� �Ƚ��ȳ�

//����һ�����Զ��� �൱�� ����һ�����Ա�
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//����һ�����Զ��� �൱�� ����һ�����Ա�
void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return;
}

//���һ�����Զ��� �൱�� ���һ�����Ա�
void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return;
}

//��������Ԫ�ؽ����У��൱�� ���Ա�β��
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

//������ �൱�� �����Ա�ͷ������Ԫ��
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
