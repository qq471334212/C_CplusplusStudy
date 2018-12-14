#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dlinklist.h"

typedef struct Value
{
	DLinkListNode *node;
	int v;
}Value;

void main()
{
	int i = 0;
	DLinkList* list = DLinkList_Create();
	struct Value *pv = NULL;
	struct Value v1, v2, v3, v4, v5;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	//尾插法
	DLinkList_Insert(list, (DLinkListNode *)&v1, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode *)&v2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode *)&v3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode *)&v4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode *)&v5, DLinkList_Length(list));

	//遍历链表
	for (i = 0; i < DLinkList_Length(list); i++)
	{
		pv = (Value *)DLinkList_Get(list, i);
		printf("%d  ", pv->v);
	}

	DLinkList_Delete(list, DLinkList_Length(list) - 1);
	DLinkList_Delete(list, 0);

	printf("\n");

	//遍历链表
	for (i = 0; i < DLinkList_Length(list); i++)
	{
		pv = (Value *)DLinkList_Get(list, i);
		printf("%d  ", pv->v);
	}

	printf("\n");

	DLinkList_Reset(list);
	DLinkList_Next(list);

	pv = (Value *)DLinkList_Current(list);
	printf("%d  ", pv->v);

	DLinkList_DeleteNode(list, (DLinkListNode *)pv);

	pv = (Value *)DLinkList_Current(list);
	printf("%d  ", pv->v);

	DLinkList_Pre(list);
	pv = (Value *)DLinkList_Current(list);
	printf("%d  ", pv->v);

	printf("Length: %d\n", DLinkList_Length(list));

	DLinkList_Destroy(list);
	system("pause");
	return;
}