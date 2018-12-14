#include<iostream>
#include<string>
#include"MyVector.h"
using namespace std;

template<typename T>
MyVector<T>::MyVector(int size)           //���캯��
{
	m_space = new T[size];
	m_len = size;
}

template<typename T>
MyVector<T>::MyVector(const MyVector &obj)     //�������캯��
{
	int i = 0;
	//����һ�������С�����ڴ�
	m_len = obj.m_len;   //������С
	m_space = new T[m_len];
	//��������
	for (i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template<typename T>
MyVector<T>::~MyVector()
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
}

template<typename T>
int MyVector<T>::getLen()
{
	return this->m_len;
}

template<typename T>
T& MyVector<T>::operator[] (int index)
{
	return m_space[index];
}

//a3=a2=a1;
//1.�Ȱ�a2���ڴ��ͷŵ�
//2.����a1�Ĵ�С�����ڴ�
//3.��������
template<typename T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T> &obj)
{
	int i = 0;
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
	m_len = obj.m_len;
	m_space = new T[m_len];
	for (i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}
	return *this;           //���ر���
}

template<typename T>
ostream& operator<<(ostream&out, const MyVector<T> &obj)
{
	int i = 0;
	for (i = 0; i < obj.m_len; i++)
	{
		out << obj.m_space[i] ;
	}
	out << endl;
	return out;
}


template<typename T>
istream& operator<<(istream&in , const MyVector<T> &obj)
{
	int i = 0;
	for (i = 0; i < obj.m_len; i++)
	{
		in >> obj.m_space[i];
	}
	return in;
}