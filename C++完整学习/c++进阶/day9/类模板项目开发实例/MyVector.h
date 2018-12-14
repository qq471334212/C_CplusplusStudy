#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class MyVector
{
public:
	MyVector(int size = 0);            //���캯��
	MyVector(const MyVector &obj);     //�������캯��
	~MyVector();

	int getLen();

	T& operator[] (int index);
	//a1=a2=a3;
	MyVector& operator= (const MyVector &obj);

	friend ostream& operator<< <T>(ostream&out, const MyVector &obj);
	friend istream& operator<< <T>(istream&in , const MyVector &obj);
private:
	T * m_space;       //����װ�������ͱ���
	int m_len;
};