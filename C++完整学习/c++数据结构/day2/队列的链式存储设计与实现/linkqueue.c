#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkqueue.h"
#include"LinkList.h"

//���еĵײ����ݽṹ��ҵ��ڵ�
typedef struct _tag_LinkQueueNode
{
	LinkListNode node;   //����ڵ�
	void* item;          //����ҵ��ڵ�

}TLinkQueueNode;

//�������� �൱�� �������Ա�
LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

//���ٶ��� �൱�� �������Ա�

//�漰�ڵ��ڴ�����������ڹ��������еĽڵ㶼��malloc������
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);     //����գ�������
	LinkList_Destroy(queue);
}

//��ն��У���Ҫ��ʾ�İ����н�㵯�����ͷ�ÿһ���ڵ�
void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	LinkList_Clear(queue);
}

//���������Ԫ�� �൱�� ���Ա�β�����
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	TLinkQueueNode *tmp = NULL;
	tmp = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func LinkQueue_Append() malloc err:%d\n", ret);
		return ret;
	}
	memset(tmp,0, sizeof(TLinkQueueNode));  //��ʼ�������ڴ渺��
	tmp->item = item;

	//��Ҫ��ջ��item��ҵ��ڵ㣩 ת���� �����LinkListNode�ڵ�
	ret = LinkList_Insert(queue, (LinkListNode*)tmp, LinkList_Length(queue));
	if (ret != 0)
	{
		printf("func LinkList_Insert() err:%d\n", ret);
		if (tmp != NULL)
		{
			free(tmp);        //��ֹ�������ʱ����ڴ�й©
		}
		return ret;
	}
	return ret;
}

//������ɾ��Ԫ�� �൱�� ���Ա�ͷ��ɾ��
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueueNode *tmp = NULL;
	void *ret = NULL;
	tmp = (TLinkQueueNode *)LinkList_Delete(queue, 0);
	if (tmp == NULL)
	{
		printf("func LinkList_Delete() err.\n");
		return NULL;
	}
	else
	{
		ret = tmp->item;
		free(tmp);              //ɾ��֮ǰ����
	}
	return ret;
}

//��ȡ����ͷ��Ԫ�� �൱�� ���Ա��0��λ��
void* LinkQueue_Header(LinkQueue* queue) 
{
	TLinkQueueNode *tmp = NULL;
	void *ret = NULL;
	tmp = (TLinkQueueNode *)LinkList_Get(queue, 0);
	if (tmp == NULL)
	{
		printf("func LinkList_Get() err.\n");
		return NULL;
	}
	ret = tmp->item;
	return ret;
}


int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}
