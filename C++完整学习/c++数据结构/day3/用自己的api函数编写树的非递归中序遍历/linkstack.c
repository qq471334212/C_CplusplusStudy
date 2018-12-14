#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"
#include"LinkList.h"         //���������

//�ڲ���������
typedef struct _tag_LinkStackNode            //�����ҵ��ڵ�
{
	LinkListNode* node;           //��һ���򣬵�һ��Ԫ��������Ľڵ�
	void* item;                   //�ٰ���һ��ջ��ҵ��ڵ�
}TLinkStackNode;



//����һ��ջ�൱�ڴ���һ����������
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

//������������
//������ջ�Ľڵ㶼��malloc������

//����һ��ջ�൱������һ����������
void LinkStack_Destroy(LinkStack *stack)
{
	LinkStack_Clear(stack);    //���ͷ�
	LinkList_Destroy(stack);
	return;
}


//���һ��ջ�൱�����һ����������
//���ջ��ʱ��  �漰��ռԪ�ص��������ڹ���
void LinkStack_Clear(LinkStack *stack)
{
	if (stack == NULL)
	{
		return;
	}
	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);          //����������е������ͷ��˽ڵ���ڴ�
	}
	return;
}

//��ջ��ѹ��Ԫ�� �൱�� �����Ա�ͷ������Ԫ��
//�����漰��ջ��ҵ��ڵ�item�������ҵ��ڵ�node��ת�����ص㣡��������
int LinkStack_Push(LinkStack *stack, void *item)
{
	int ret = 0;
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if (tmp == 0)
	{
		ret = -1;
		return ret;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;
	ret = LinkList_Insert(stack, (LinkListNode *)tmp, 0);
	if (ret != 0)
	{
		ret = -2;
		printf("func LinkList_Insert() err: %d\n", ret);
		if (tmp != NULL)
		{
			free(tmp);    //��ֹ�ڴ�й©
		}
		return ret;
	}
	return ret;
}

//��ջ�е���Ԫ�� �൱������������ͷ��ɾ��Ԫ��
//Ȼ��Ҫ�ѵ��������Ա��ҵ��ڵ� ת���� ջ��ҵ��ڵ�
void* LinkStack_Pop(LinkStack *stack)
{
	void *item = NULL;           //ջ��ҵ��ڵ�
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	free(tmp);                //Push��ʱ��������ڴ棬���Pop��ʱ��Ҫ�ͷ��ڴ�
	return item;
}

//��ȡջ��Ԫ���൱�ڻ�ȡ�����λ��
void* LinkStack_Top(LinkStack *stack)
{

	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}

	return tmp->item;

}

//��ջ�Ĵ�С�൱�������Ա��length
int LinkStack_Size(LinkStack *stack)
{
	return LinkList_Length(stack);
}