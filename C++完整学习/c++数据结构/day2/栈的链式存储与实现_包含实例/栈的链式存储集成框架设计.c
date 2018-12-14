#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"

void main1()
{
	int i = 0;
	int a[10];

	LinkStack* stack = NULL;
	stack = LinkStack_Create();    //��LinkList��ʽ���Ա���ģ��LinkStack��ʽջ
	if (stack == NULL)
	{
		return;
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}
	//��ȡջ������
	printf("length : %d\n", LinkStack_Size(stack));
	printf("top : %d\n", *(int *)(LinkStack_Top(stack)));

	while (LinkStack_Size(stack) > 0)
	{
		int tmp = *(int *)(LinkStack_Pop(stack));
		printf("tmp : %d\n",tmp);
	}

	LinkStack_Destroy(stack);


	system("pause");
	return;
}