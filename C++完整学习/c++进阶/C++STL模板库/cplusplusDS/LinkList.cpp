#include "LinkList.h"
#include<iostream>


template <typename T>
LinkList<T>::LinkList()
{
	head = new Node<T>;  //初始化创造链表，给链表头节点分配空间
	if (head == NULL)
	{
		printf("func new() err\n");
	}
	head->next = NULL;
	len = 0;
}

template <typename T>
LinkList<T>::~LinkList()
{
	Node<T> *tmp = NULL;
	while (head != NULL)
	{
		tmp = head->next;         //删除前要缓存，否则找不到后面节点的地址
		delete head;
		head = tmp;
	}
	len = 0;
	head = NULL;
}


//清除链式表数据
template <typename T>
int LinkList<T>::clear()
{
	Node<T> *tmp = NULL;
	while (head != NULL)
	{
		tmp = head->next;         //删除前要缓存，否则找不到后面节点的地址
		delete head;
		head = tmp;
	}
	head = new Node<T>;
	if (head == NULL)
	{
		printf("func new() err\n");
	}
	head->next = NULL;
	len = 0;

	return 0;
}

//获取链式表长度
template <typename T>
int LinkList<T>::getlen()
{
	return this->len;
}


//指定位置插入节点
template <typename T>
int LinkList<T>::Insert(T &t, int pos)
{
	Node<T> *current = NULL;
	current = head;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	//传进来的是数据，node节点不存在，需要malloc内存
	Node<T> *node = new Node<T>;
	if (node == NULL)
	{
		return -1;
	}
	node->t = t;    //缓存外部数据
	node->next = NULL;
	node->next = current->next;
	current->next = node;
	len++;
	return 0;
}


//获取指定位置节点
template <typename T>
int LinkList<T>::Get(int pos, T &t)
{
	Node<T> *current = NULL;
	current = head;
	if (pos < 0)
	{
		return -1;
	}

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	t = current->next->t;

	return 0;
}


//删除置顶位置节点
template <typename T>
int LinkList<T>::Del(int pos, T &t)
{
	Node<T> *current = NULL;
	Node<T> *ret = NULL;
	current = head;
	if (pos < 0)
	{
		return -1;
	}

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	ret = current->next;    //被删除的元素
	t = ret->t;
	current->next = ret->next;
	len--;

	free(ret);     //插入的时候，创建了内存空间，因此删除要释放

	return 0;
}
