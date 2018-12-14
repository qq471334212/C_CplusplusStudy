#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqqueue.h"
#include"seqlist.h"

void main()
{
	int i = 0;
	int a[10];
	int ret = 0;
	SeqQueue* queue = NULL;
	queue = SeqQueue_Create(10);
	if (queue == NULL)
	{
		return;
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		ret = SeqQueue_Append(queue, &a[i]);
		if (ret != 0)
		{
			printf("func SeqQueue_Append() err.\n");
		}
	}

	//打印队列属性
	printf("len: %d\n", SeqQueue_Length(queue));
	printf("header: %d\n", *((int*)SeqQueue_Header(queue)));
	printf("capacity: %d\n", SeqQueue_Capacity(queue));

	while (SeqQueue_Length(queue) > 0)
	{
		int tmp = *(int*)SeqQueue_Retrieve(queue);
		printf("tmp: %d", tmp);

	}

	SeqQueue_Destroy(queue);

	
	system("pause");
	return;
}
