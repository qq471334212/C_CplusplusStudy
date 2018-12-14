#include<iostream>
#include<string>
#include"dm04_myComplex.h"
using namespace std;

//这个又叫h cpp，主程序调用这个文件

//普通函数函数本体
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
Complex<T> Complex<T>::operator+(Complex<T> &c)     //写在类外面，返回类型和参数也都要具体化
{
	Complex<T> tmp(a + c.a, b + c.b);
	return tmp;
}

template<typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c)     //写在类外面，返回类型和参数也都要具体化
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
//滥用友元函数
//template<typename T>
//Complex<T> Mysub(Complex<T> &c1, Complex<T> &c2)
//{
//	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
//	return tmp;
//}