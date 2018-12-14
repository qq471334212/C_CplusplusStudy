#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqstack.h"
#include"seqlist.h"

//����ջ,�൱�ڴ������Ա�
Stack *SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);;
}

//����ջ���൱���������Ա�
void SeqStack_Destroy(Stack *stack)
{
	SeqList_Destroy(stack);
	return;
}

//���ջ��������������Ա�
void SeqStack_Clear(Stack *stack)
{
	SeqList_Clear(stack);
	return;
}

/**********����ҵ��*************/
//��ջ����ջ��ѹ��Ԫ���൱�������Ա�β������Ԫ��
int SeqStack_Push(Stack *stack, void *item)
{
	int ret = 0;
	ret= SeqList_Insert(stack, item, SeqList_Length(stack));
	return ret;
}


//��ջ������Ԫ���൱�ڲ���������β��Ԫ��
void* SeqStack_Pop(Stack *stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}


//��ȡջ���൱�ڻ�ȡ����β��Ԫ��
void* SeqStack_Top(Stack *stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);

}


//ջ�Ĵ�С,�൱�������ʵ�ʳ���
int SeqStack_Size(Stack *stack)
{
	return SeqList_Length(stack);
}

//ջ���������൱���ı�����
int SeqStack_Capacity(Stack *stack)
{
	return SeqList_Capacity(stack);
}

