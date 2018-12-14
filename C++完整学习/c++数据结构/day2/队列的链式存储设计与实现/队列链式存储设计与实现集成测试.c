#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkqueue.h"

void main()
{
	int ret = 0;
	int i = 0;
	int a[10];
	LinkQueue* queue = NULL;
	queue = LinkQueue_Create();
	if (queue == NULL)
	{
		return;
	}
	
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	//¶ÓÁÐÊôÐÔ
	printf("len :%d\n", LinkQueue_Length(queue));
	printf("header :%d\n", *(int *)(LinkQueue_Header(queue)));

	while (LinkQueue_Length(queue) > 0)
	{
		int tmp= *(int *)(LinkQueue_Retrieve(queue));
		printf("tmp: %d", tmp);
	}

	LinkQueue_Destroy(queue);

	system("pause");
	return;
}
