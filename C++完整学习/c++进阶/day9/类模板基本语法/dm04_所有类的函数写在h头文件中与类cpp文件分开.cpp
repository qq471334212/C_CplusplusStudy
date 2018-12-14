#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


template<typename T>
class Complex;          //���ǰ������
template<typename T>
Complex<T> Mysub(Complex<T> &c1, Complex<T> &c2);  //��Ԫ����ǰ������

template<typename T>
class Complex
{
	//friend Complex Mysub(Complex &c1, Complex &c2);
	friend Complex Mysub <T>(Complex &c1, Complex &c2);

	friend ostream& operator<< <T> (ostream &out, Complex &c);

public:
	Complex(T a, T b);
	void printCom();
	//���ظ���+��
	Complex operator+(Complex &c);
	Complex operator-(Complex &c);

private:
	T a;
	T b;
};

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
////////////////
//������Ԫ����
template<typename T>
Complex<T> Mysub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}

int main()
{
	Complex<int>  c1(1, 2);
	Complex<int>  c2(3, 4);
	Complex<int>  c3 = c1 + c2;
	{
		Complex<int> c4 = Mysub(c1, c2);
		cout << c4;
	}
	cout << c3;
	system("pause");
	return 0;
}