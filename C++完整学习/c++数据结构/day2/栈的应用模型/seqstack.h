#pragma once
#ifndef _MY_STACK_H_
#define _MY_STACK_H_

typedef void Stack;

//����ջ
Stack *SeqStack_Create(int capacity);

//����ջ
void SeqStack_Destroy(Stack *stack);

//���ջ
void SeqStack_Clear(Stack *stack);

//��ջ
int SeqStack_Push(Stack *stack,void *item);

//��ջ
void* SeqStack_Pop(Stack *stack);

//ջ��
void* SeqStack_Top(Stack *stack);

//ջ�Ĵ�С
int SeqStack_Size(Stack *stack);

//ջ������
int SeqStack_Capacity(Stack *stack);



#endif