#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"
#include"LinkList.h"         //线性链表库

//内部数据类型
typedef struct _tag_LinkStackNode            //链表的业务节点
{
	LinkListNode* node;           //第一个域，第一个元素是链表的节点
	void* item;                   //再包含一个栈的业务节点
}TLinkStackNode;



//创建一个栈相当于创建一个线性链表
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

//处理生命周期
//所有入栈的节点都是malloc出来的

//销毁一个栈相当于销毁一个线性链表
void LinkStack_Destroy(LinkStack *stack)
{
	LinkStack_Clear(stack);    //先释放
	LinkList_Destroy(stack);
	return;
}


//清空一个栈相当于清空一个线性链表
//清空栈的时候  涉及到占元素的生命周期管理
void LinkStack_Clear(LinkStack *stack)
{
	if (stack == NULL)
	{
		return;
	}
	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);          //在这个函数中弹出并释放了节点的内存
	}
	return;
}

//向栈中压入元素 相当于 向线性表头部插入元素
//这里涉及到栈的业务节点item与链表的业务节点node的转换，重点！！！！！
int LinkStack_Push(LinkStack *stack, void *item)
{
	int ret = 0;
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if (tmp == 0)
	{
		ret = -1;
		return ret;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;
	ret = LinkList_Insert(stack, (LinkListNode *)tmp, 0);
	if (ret != 0)
	{
		ret = -2;
		printf("func LinkList_Insert() err: %d\n", ret);
		if (tmp != NULL)
		{
			free(tmp);    //防止内存泄漏
		}
		return ret;
	}
	return ret;
}

//从栈中弹出元素 相当于在线性链表头部删除元素
//然后要把弹出的线性表的业务节点 转换成 栈的业务节点
void* LinkStack_Pop(LinkStack *stack)
{
	void *item = NULL;           //栈的业务节点
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	free(tmp);                //Push的时候分配了内存，因此Pop的时候要释放内存
	return item;
}

//获取栈顶元素相当于获取链表号位置
void* LinkStack_Top(LinkStack *stack)
{

	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}

	return tmp->item;

}

//求栈的大小相当于求线性表的length
int LinkStack_Size(LinkStack *stack)
{
	return LinkList_Length(stack);
}