#pragma once
#ifndef _MY_STACK_H_
#define _MY_STACK_H_

typedef void Stack;

//创建栈
Stack *SeqStack_Create(int capacity);

//销毁栈
void SeqStack_Destroy(Stack *stack);

//清空栈
void SeqStack_Clear(Stack *stack);

//入栈
int SeqStack_Push(Stack *stack,void *item);

//出栈
void* SeqStack_Pop(Stack *stack);

//栈顶
void* SeqStack_Top(Stack *stack);

//栈的大小
int SeqStack_Size(Stack *stack);

//栈的容量
int SeqStack_Capacity(Stack *stack);



#endif