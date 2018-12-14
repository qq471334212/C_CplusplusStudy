#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqstack.h"
#include"seqlist.h"

//创建栈,相当于创建线性表
Stack *SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);;
}

//销毁栈，相当于销毁线性表
void SeqStack_Destroy(Stack *stack)
{
	SeqList_Destroy(stack);
	return;
}

//清空栈，清空于销毁线性表
void SeqStack_Clear(Stack *stack)
{
	SeqList_Clear(stack);
	return;
}

/**********核心业务*************/
//入栈，向栈中压入元素相当于在线性表尾部插入元素
int SeqStack_Push(Stack *stack, void *item)
{
	int ret = 0;
	ret= SeqList_Insert(stack, item, SeqList_Length(stack));
	return ret;
}


//出栈，弹出元素相当于产出在链表尾部元素
void* SeqStack_Pop(Stack *stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}


//获取栈顶相当于获取链表尾部元素
void* SeqStack_Top(Stack *stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);

}


//栈的大小,相当于链表的实际长度
int SeqStack_Size(Stack *stack)
{
	return SeqList_Length(stack);
}

//栈的容量，相当于聊表容量
int SeqStack_Capacity(Stack *stack)
{
	return SeqList_Capacity(stack);
}

