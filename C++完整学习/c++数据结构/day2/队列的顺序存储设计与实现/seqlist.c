#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"seqlist.h"

//临时代替动态库,到时候可以封装成动态库
//内部操作数据类型，对外部封装
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int **node;        //结构体套二级指针，指针数组
	                            //用二级指针比较好

}TSeqList;

//创建线性表
SeqList* SeqList_Create(int capacity) 
{
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		printf("func SeqList_Create() err: \n");
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));

	tmp->node = (unsigned int **)malloc(sizeof(unsigned int *)*capacity);
	if (tmp->node == NULL)
	{
		printf("func SeqList_Create() malloc err: \n");
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;
}

//销毁线性表
void SeqList_Destroy(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return;
	}

	tList = (TSeqList*)list;
	if (tList->node != NULL)
	{
		free(tList->node);
	}
	free(tList);
	return;
}

//清空线性表数据,回到初始化状态
void SeqList_Clear(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return;
	}

	tList = (TSeqList*)list;
	tList->length = 0;
	return;
}

//获取线性表长度
int SeqList_Length(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return -1;
	}

	tList = (TSeqList*)list;
	return tList->length;
}

//线性表容量
int SeqList_Capacity(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		return -1;
	}

	tList = (TSeqList*)list;
	return tList->capacity;
}

//指定位置插入节点
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int ret = 0;
	int i = 0;
	TSeqList *tList = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return ret;
	}

	tList = (TSeqList*)list;
	//判断线性表是不是已经满了
	if (tList->length >= tList->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() (tList->length >= tList->capacity) err: %d", ret);
		return ret;
	}

	//容错修正，例如果当前容量是10，长度是6，节点（0，1，2，3，4，5）如插入8位置，则将其插入到6位置
	if (pos >= tList->length)
	{
		pos = tList->length;
	}

	//插入位置的后面元素依次后移
	for (i = tList->length; i > pos; i--)
	{
		tList->node[i] = tList->node[i - 1];
	}

	//tList->node[pos] = (unsigned int )node;
	tList->node[i] = node;
	tList->length = tList->length + 1;   //插入后长度+1

	return ret;
}

//获取指定位置节点
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int ret = 0;
	TSeqList *tList = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}
	tList = (SeqList*)list;
	if (pos > tList->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}
	return (SeqListNode *)tList->node[pos];
}

//删除置顶位置节点
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i = 0;
	int ret = 0;
	TSeqList *tList = NULL;
	SeqListNode *tmp = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}
	tList = (SeqList*)list;
	tmp = (SeqListNode *)tList->node[pos];

	for (i = pos + 1; i < tList->length; i++)    //删除的节点位置后面依次向前移
	{
		tList->node[i - 1] = tList->node[i];
	}
	tList->length = tList->length - 1;
	return tmp;
}