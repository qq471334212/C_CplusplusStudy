#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


template<typename T>
class Complex1
{
	friend Complex1 Mysub(Complex1 &c1, Complex1 &c2)
	{
		Complex1 tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}

public:
	Complex1(T a , T b)
	{
		this->a = a;
		this->b = b;
	}

	//重载复数+号
	Complex1 operator+(Complex1 &c)
	{
		Complex1 tmp(a + c.a, b + c.b);
		return tmp;
	}
	//重载左移输出运算符
	//重载<< ,>> 左移 右移函数只能用友元函数
	//其他运算符重载 都要写成成员函数，不要滥用友元函数
	friend ostream& operator<<(ostream &out, Complex1 &c)
	{
		out << c.a << " + " << c.b << "i" << endl;
		return out;
	}

	void printCom()
	{
		cout << a << " + " << b << "i" << endl;
	}
private:
	T a;
	T b;
};


/*
ostream& operator<<(ostream &out, Complex &c)
{
	out << "a: " << c.a << "  " << "b: " << c.b << endl;
	return out;
}
*/
int main04()
{
	Complex1<int>  c1(1, 2);
	Complex1<int>  c2(3, 4);
	Complex1<int>  c3 = c1 + c2;
	{
		Complex1<int> c4 = Mysub(c1, c2);
		cout << c4;
	}
	cout << c3;
	system("pause");
	return 0;
}