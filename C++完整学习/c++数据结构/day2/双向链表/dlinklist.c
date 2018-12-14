#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dlinklist.h"

//����ڲ����ݽṹ
typedef struct _tag_DLinkList
{
	DLinkListNode header;    //ͷ�ڵ�
	DLinkListNode *slider;   //�α�
	int length;

}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	if (ret != 0)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}
	return ret;
}

//������ʽ���Ա�
void DLinkList_Destroy(DLinkList* list)
{
	if (list != NULL)
	{
		free(list);
	}
	return;
}

//�����ʽ������
void DLinkList_Clear(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->header.pre = NULL;
		sList->slider = NULL;
	}
	return;
}

//��ȡ��ʽ����
int DLinkList_Length(DLinkList* list)
{
	int length = -1;
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		length = sList->length;
	}
	return length;
}

//ָ��λ�ò���ڵ�
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	int ret = 0, i = 0;
	TDLinkList *sList = (TDLinkList *)list;

	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	{
		//���帨��ָ���������ʼ��
		DLinkListNode *current = (DLinkListNode*)sList;
		DLinkListNode *next = NULL;    //������һ��nextָ��

		for (i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;         //��ǰָ��ָ��Ҫ�����λ��
		}
		next = current->next;

		//����1-2
		current->next = node;
		node->next = next;

		//����3-4
		if (next != NULL)
		{
			next->pre = node;  //����������һ��Ԫ��ʱҪ���⴦��,��next->pre������
		}
		node->pre = current;

		//�����һ��Ԫ�ش���
		if (sList->length == 0)
		{
			sList->slider = node;   //����������һ��Ԫ��ʱ�����α�
		}
		//��0λ�ò��룬��ǰ����ַ��ͷ�ڵ㣬��Ҫ���ڵ�node->pre=null;
		if (current == (DLinkListNode *)sList)
		{
			node->pre = NULL;
		}
		sList->length++;
	}
	return 0;
}


//��ȡָ��λ�ýڵ�
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	int i = 0;
	TDLinkList *sList = (TDLinkList *)list;
	DLinkListNode *current = (DLinkListNode*)sList;
	DLinkListNode *ret = NULL;

	for (i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;         //��ǰָ��ָ��Ҫ�����λ��
	}
	ret = current->next;

	return ret;
}

//ɾ��ָ��λ�ýڵ�
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	int i = 0;
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL || pos < 0)
	{
		return NULL;
	}
	//��������ָ�����
	DLinkListNode *current = (DLinkListNode*)sList;
	DLinkListNode *ret = NULL;
	DLinkListNode *next = NULL;

	for (i = 0; i < pos; i++)
	{
		current = current->next;         //��ǰָ��ָ��Ҫɾ����λ��
	}
	//����ָ�븳ֵ
	ret = current->next;
	next = ret->next;
	//����1
	current->next = next;

	//����2
	if (next != NULL)
	{
		next->pre = current;     //β�ڵ㲻��Ҫ������
		if (current == (DLinkListNode*)sList)  //ͷ�ڵ����
		{
			next->pre = NULL;
		}
	}
	//����α���Ҫɾ����λ�ã���������
	if (sList->slider == ret)
	{
		sList->slider = next;
	}

	sList->length--;
	return ret;
}

//�����α�λ��
void DLinkList_Reset(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL )
	{
		return;
	}
	DLinkListNode *current = (DLinkListNode*)sList;
	sList->slider = current;
	return;
}

//���α�ָ��ǰһ��λ��
void DLinkList_Pre(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		return;
	}
	
	sList->slider = sList->header.pre;
	return;
}

//���α�ָ����һ��λ��
void DLinkList_Next(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		return ;
	}

	sList->slider = sList->header.next;
	return;
}

//�α굱ǰλ��
DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList *sList = (TDLinkList *)list;
	if (sList != NULL)
	{
		return NULL;
	}

	return sList->slider;
}

//ɾ���α�
void DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	return;
}