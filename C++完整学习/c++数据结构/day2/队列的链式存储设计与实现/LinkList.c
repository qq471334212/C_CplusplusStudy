#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LinkList.h"

//����ڲ�ʹ�õĽṹ��
typedef struct _tag_LinkList 
{
	LinkListNode head;  //ͷ�ڵ�
	int length;

}TLinkList;

//������ʽ���Ա�
LinkList* LinkList_Create()
{
	int ret = 0;
	TLinkList *tmp = NULL;
	tmp = (TLinkList *)malloc(sizeof(TLinkList));
	memset(tmp, 0, sizeof(TLinkList));
	tmp->length = 0;
	tmp->head.next = NULL;
	return tmp;
}

//������ʽ���Ա�
void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//�����ʽ������
void LinkList_Clear(LinkList* list)
{
	TLinkList *tList = NULL;
	if (list == NULL)
	{
		return;
	}
	tList = (LinkList*)list;
	//�ָ���ʼ��
	tList->length = 0;
	tList->head.next = NULL;

	return;
}

//��ȡ��ʽ����
int LinkList_Length(LinkList* list)
{
	TLinkList *tList = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tList = (LinkList*)list;

	return tList->length;
}

//��ͷ��������ȽϷ��㣬����
//ָ��λ�ò���ڵ�,����ʱ����������Ľڵ㣬����ǰ��Ľڵ�
//1.ָ��ָ��˭ �Ͱ�˭�ĵ�ַ����ָ��
//2.���������Ĳ����߼� �͸�ֵָ�����֮��Ĺ�ϵ
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int ret = 0;
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Insert() err: %d \n", ret);
		return ret;
	}

	//��ʼ��
	tList = (TLinkList*)list;
	current = &(tList->head);    //�ø�������ǰλ�ã�ָ�����ָ������ͷ��
	
    //��ָ���ͷ�ڵ�λ������Ҫ����Ľڵ�ǰһ��λ��
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

    //�������
	node->next = current->next;
	current->next = node;
	tList->length++;            //�����������+1
	return ret;
}

//��ȡָ��λ�ýڵ�
LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int ret = 0;
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Get() err: %d \n", ret);
		return NULL;
	}

	//��ʼ��
	tList = (TLinkList*)list;
	current = &(tList->head);    //�ø�������ǰλ�ã�ָ�����ָ������ͷ��

								 //��ָ���ͷ�ڵ�λ������Ҫ����Ľڵ�ǰһ��λ��
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;       //����Ӧ�ڵ㷵�ؼ���
}

//ɾ���ö�λ�ýڵ�
//��Ҫ��������ָ�����
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int ret = 0;
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;
	LinkListNode *tmp = NULL;       //�洢Ҫɾ���Ľڵ�
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Delete() err: %d \n", ret);
		return NULL;
	}

	//��ʼ��
	tList = (TLinkList*)list;
	current = &(tList->head);    //�ø�������ǰλ�ã�ָ�����ָ������ͷ��

								 //��ָ���ͷ�ڵ�λ������Ҫ����Ľڵ�ǰһ��λ��
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	tmp = current->next;
	current->next = tmp->next;
	tList->length--;            //ɾ����������-1

	return tmp;                 //��Ҫɾ���Ľڵ㷵�أ���ҵ��������ͷ����ڴ�
}