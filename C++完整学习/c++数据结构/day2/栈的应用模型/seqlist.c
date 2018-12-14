#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"seqlist.h"

//��ʱ���涯̬��,��ʱ����Է�װ�ɶ�̬��
//�ڲ������������ͣ����ⲿ��װ
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int **node;        //�ṹ���׶���ָ�룬ָ������
	                            //�ö���ָ��ȽϺ�

}TSeqList;

//�������Ա�
SeqList* SeqList_Create(int capacity) 
{
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		printf("func SeqList_Create() err: \n");
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));

	tmp->node = (unsigned int **)malloc(sizeof(unsigned int *)*capacity);
	if (tmp->node == NULL)
	{
		printf("func SeqList_Create() malloc err: \n");
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;
}

//�������Ա�
void SeqList_Destroy(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return;
	}

	tList = (TSeqList*)list;
	if (tList->node != NULL)
	{
		free(tList->node);
	}
	free(tList);
	return;
}

//������Ա�����,�ص���ʼ��״̬
void SeqList_Clear(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return;
	}

	tList = (TSeqList*)list;
	tList->length = 0;
	return;
}

//��ȡ���Ա���
int SeqList_Length(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return -1;
	}

	tList = (TSeqList*)list;
	return tList->length;
}

//���Ա�����
int SeqList_Capacity(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return -1;
	}

	tList = (TSeqList*)list;
	return tList->capacity;
}

//ָ��λ�ò���ڵ�
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int ret = 0;
	int i = 0;
	TSeqList *tList = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return ret;
	}

	tList = (TSeqList*)list;
	//�ж����Ա��ǲ����Ѿ�����
	if (tList->length >= tList->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() (tList->length >= tList->capacity) err: %d", ret);
		return ret;
	}

	//�ݴ��������������ǰ������10��������6���ڵ㣨0��1��2��3��4��5�������8λ�ã�������뵽6λ��
	if (pos >= tList->length)
	{
		pos = tList->length;
	}

	//����λ�õĺ���Ԫ�����κ���
	for (i = tList->length; i > pos; i--)
	{
		tList->node[i] = tList->node[i - 1];
	}

	//tList->node[pos] = (unsigned int )node;
	tList->node[i] = node;
	tList->length = tList->length + 1;   //����󳤶�+1

	return ret;
}

//��ȡָ��λ�ýڵ�
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int ret = 0;
	TSeqList *tList = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}
	tList = (SeqList*)list;
	if (pos > tList->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}
	return (SeqListNode *)tList->node[pos];
}

//ɾ���ö�λ�ýڵ�
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i = 0;
	int ret = 0;
	TSeqList *tList = NULL;
	SeqListNode *tmp = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}
	tList = (SeqList*)list;
	tmp = (SeqListNode *)tList->node[pos];

	for (i = pos + 1; i < tList->length; i++)    //ɾ���Ľڵ�λ�ú���������ǰ��
	{
		tList->node[i - 1] = tList->node[i];
	}
	tList->length = tList->length - 1;
	return tmp;
}