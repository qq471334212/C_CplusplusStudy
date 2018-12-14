#include<iostream>
#include<string>
#include"dm04_myComplex.h"
using namespace std;

//����ֽ�h cpp���������������ļ�

//��ͨ������������
template<typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<typename T>
void Complex<T>::printCom()
{
	cout << a << " + " << b << "i" << endl;
}

template<typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c)     //д�������棬�������ͺͲ���Ҳ��Ҫ���廯
{
	Complex<T> tmp(a + c.a, b + c.b);
	return tmp;
}

template<typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c)     //д�������棬�������ͺͲ���Ҳ��Ҫ���廯
{
	Complex<T> tmp(a - c.a, b - c.b);
	return tmp;
}


template<typename T>
ostream& operator<<(ostream &out, Complex<T> &c)
{
	out << c.a << " + " << c.b << "i" << endl;
	return out;
}

template<typename T>
istream& operator>>(istream &in, Complex<T> &c)
{
	in >> c.a >> c.b;
	return in;
}

////////////////
//������Ԫ����
//template<typename T>
//Complex<T> Mysub(Complex<T> &c1, Complex<T> &c2)
//{
//	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
//	return tmp;
//}