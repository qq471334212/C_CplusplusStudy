#pragma once
#ifndef __MY_SEQLIST_H__
#define __MY_SEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;   //����Э��Ľڵ�������void����˿�ܸ���������ҵ��ڵ���ʲô���ͣ��κνṹ�嶼����ʹ��

//�������Ա�
SeqList* SeqList_Create(int capacity);

//�������Ա�
void SeqList_Destroy(SeqList* list);

//������Ա�����
void SeqList_Clear(SeqList* list);

//��ȡ���Ա���
int SeqList_Length(SeqList* list);

//���Ա�����
int SeqList_Capacity(SeqList* list);

//ָ��λ�ò���ڵ�
int SeqList_Insert(SeqList* list, SeqListNode* node,int pos);

//��ȡָ��λ�ýڵ�
SeqListNode* SeqList_Get(SeqList* list, int pos);

//ɾ���ö�λ�ýڵ�
SeqListNode* SeqList_Delete(SeqList* list, int pos);


#endif
