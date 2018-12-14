#pragma once
#ifndef __LinkList_H__
#define __LinkList_H__

typedef void LinkList;     //����һ���ṹ������
//typedef struct _tag_LinkListNode LinkListNode;
//struct _tag_LinkListNode
//{
//	LinkListNode *next;
//};

//��������ڵ�����
typedef struct _tag_LinkListNode 
{
	struct _tag_LinkListNode *next;     //�������һ���ڵ��ַ
}LinkListNode;

//������ʽ���Ա�
LinkList* LinkList_Create();

//������ʽ���Ա�
void LinkList_Destroy(LinkList* list);

//�����ʽ������
void LinkList_Clear(LinkList* list);

//��ȡ��ʽ����
int LinkList_Length(LinkList* list);

//ָ��λ�ò���ڵ�
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

//��ȡָ��λ�ýڵ�
LinkListNode* LinkList_Get(LinkList* list, int pos);

//ɾ���ö�λ�ýڵ�
LinkListNode* LinkList_Delete(LinkList* list, int pos);


#endif