#pragma once
#ifndef _MY_DLINKLIST_H_
#define _MY_DLINKLIST_H_

typedef void DLinkList;     //������������

typedef struct _tag_DLinkListNode              //��������ڵ�����
{
	struct _tag_DLinkListNode *next;   //��̽ڵ�
	struct _tag_DLinkListNode *pre;    //ǰ���ڵ� 
}DLinkListNode;

//������ʽ���Ա�
DLinkList* DLinkList_Create();

//������ʽ���Ա�
void DLinkList_Destroy(DLinkList* list);

//�����ʽ������
void DLinkList_Clear(DLinkList* list);

//��ȡ��ʽ����
int DLinkList_Length(DLinkList* list);

//ָ��λ�ò���ڵ�
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

//��ȡָ��λ�ýڵ�
DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

//ɾ���ö�λ�ýڵ�
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);


//��ȵ������������α����api
//�����α�λ��
void DLinkList_Reset(DLinkList* list);

//���α�ָ��ǰһ��λ��
void DLinkList_Pre(DLinkList* list);

//���α�ָ����һ��λ��
void DLinkList_Next(DLinkList* list);

//�α굱ǰλ��
DLinkListNode* DLinkList_Current(DLinkList* list);

//ɾ���α�
void DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);


#endif
