#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqstack.h"

void main()
{
	int i = 0;
	int a[10];
	//创建栈
	Stack * stack = NULL; 
	stack = SeqStack_Create(10);
	if (stack == NULL)
	{
		return;
	}

	//压栈
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}

	//栈的容量和大小
	printf("capacity: %d ", SeqStack_Capacity(stack));
	printf("length: %d ", SeqStack_Size(stack));
	printf("top: %d ", *(int *)(SeqStack_Top(stack)));
	
	while (SeqStack_Size(stack) > 0)
	{
		int tmp =*(int*)(SeqStack_Pop(stack));
		printf("tmp: %d", tmp);
	}


	system("pause");
	return;
}