#include "LinkList.h"
#include<iostream>


template <typename T>
LinkList<T>::LinkList()
{
	head = new Node<T>;  //��ʼ����������������ͷ�ڵ����ռ�
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
		tmp = head->next;         //ɾ��ǰҪ���棬�����Ҳ�������ڵ�ĵ�ַ
		delete head;
		head = tmp;
	}
	len = 0;
	head = NULL;
}


//�����ʽ������
template <typename T>
int LinkList<T>::clear()
{
	Node<T> *tmp = NULL;
	while (head != NULL)
	{
		tmp = head->next;         //ɾ��ǰҪ���棬�����Ҳ�������ڵ�ĵ�ַ
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

//��ȡ��ʽ����
template <typename T>
int LinkList<T>::getlen()
{
	return this->len;
}


//ָ��λ�ò���ڵ�
template <typename T>
int LinkList<T>::Insert(T &t, int pos)
{
	Node<T> *current = NULL;
	current = head;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	//�������������ݣ�node�ڵ㲻���ڣ���Ҫmalloc�ڴ�
	Node<T> *node = new Node<T>;
	if (node == NULL)
	{
		return -1;
	}
	node->t = t;    //�����ⲿ����
	node->next = NULL;
	node->next = current->next;
	current->next = node;
	len++;
	return 0;
}


//��ȡָ��λ�ýڵ�
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


//ɾ���ö�λ�ýڵ�
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
	ret = current->next;    //��ɾ����Ԫ��
	t = ret->t;
	current->next = ret->next;
	len--;

	free(ret);     //�����ʱ�򣬴������ڴ�ռ䣬���ɾ��Ҫ�ͷ�

	return 0;
}
