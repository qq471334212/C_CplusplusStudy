#include<iostream>
#include "SeqList.h"


template <typename T>
SeqList<T>::SeqList(int capicity)
{
	T *pArray = NULL;
	pArray = new T[capicity];    //根据设定容量分配内存
	this->pArray = pArray;
	this->capicity = capicity;
	this->length = 0;
}

template <typename T>
SeqList<T>::~SeqList()
{
	delete[] pArray;
	pArray = NULL;
	length = 0;
	capicity = 0;
}

//获取线性表长度
template <typename T>
int SeqList<T>::GetLength()
{
	return this->length;
}

//线性表容量
template <typename T>
int SeqList<T>::GetCapicity()
{
	return this->capicity;
}

//指定位置插入节点
template <typename T>
int SeqList<T>::myInsert(T &t, int pos)
{
	int ret = 0;
	int i = 0;
	if (pos < 0)
	{
		ret = -1;
		return ret;
	}

	for (i = length; i > pos; i--)   //pos后元素后移
	{
		pArray[i] = pArray[i - 1];
	}

	this->pArray[i] = t;   //STL元素保存是通过 复制的机制实现的，你的类要可以复制才行

	this->length++;
	return ret;
}

//获取指定位置节点
template <typename T>
int SeqList<T>::GetNode(int pos, T &t)
{
	int ret = 0;
	int i = 0;
	if (pos < 0)
	{
		ret = -1;
		return ret;
	}

	t = pArray[pos];
	return ret;
}

//删除置顶位置节点
template <typename T>
int SeqList<T>::DeleteNode(int pos, T &t)
{
	int i = 0;
	int ret = 0;
	if (pos < 0)
	{
		ret = -1;
		return ret;
	}
	t = pArray[pos];

	for (i = pos + 1; i < this->length; i++)   //pos后元素前移
	{
		pArray[i - 1] = pArray[i];
	}
	this->length--;
	return ret;
}