#include<iostream>
#include "SeqList.h"


template <typename T>
SeqList<T>::SeqList(int capicity)
{
	T *pArray = NULL;
	pArray = new T[capicity];    //�����趨���������ڴ�
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

//��ȡ���Ա���
template <typename T>
int SeqList<T>::GetLength()
{
	return this->length;
}

//���Ա�����
template <typename T>
int SeqList<T>::GetCapicity()
{
	return this->capicity;
}

//ָ��λ�ò���ڵ�
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

	for (i = length; i > pos; i--)   //pos��Ԫ�غ���
	{
		pArray[i] = pArray[i - 1];
	}

	this->pArray[i] = t;   //STLԪ�ر�����ͨ�� ���ƵĻ���ʵ�ֵģ������Ҫ���Ը��Ʋ���

	this->length++;
	return ret;
}

//��ȡָ��λ�ýڵ�
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

//ɾ���ö�λ�ýڵ�
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

	for (i = pos + 1; i < this->length; i++)   //pos��Ԫ��ǰ��
	{
		pArray[i - 1] = pArray[i];
	}
	this->length--;
	return ret;
}

template <typename T>
int SeqList<T>::clear()
{
	this->length = 0;
	return 0;
}