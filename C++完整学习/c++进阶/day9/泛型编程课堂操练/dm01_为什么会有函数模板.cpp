#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//函数的业务逻辑一样，但是函数参数类型不一样
void myswap2(int &a, int &b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void myswap1(char &a, char &b)
{
	char c = 0;
	c = a;
	a = b;
	b = c;
}

//让类型参数化，方便程序员进行编码
//泛型编程
//看到template就是告诉C++编译器我要用模板泛型编程了，看到T，不要随便报错
template<typename T>
void myswap(T &a,T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << "函数模板调用" << endl;
}

//多个参数类型
//template<typename T, typename T1>
//void myswap(T &a, T1 &b)

//函数模板的调用
//1.显示类型 调用
//2.自动类型 推导
int main02()
{
	{
		int x = 10;
		int y = 20;
		myswap<int>(x, y);  //第一种方式 函数模板显示类型 调用
		//myswap(x, y);       //第二种方式 自动类型推导
		cout << "x= " << x << "  " << "y= " << y << endl;
	}

	{
		char a = 'x', b = 'y';
		myswap<char>(a, b);
		//myswap(a, b);
		cout << "a= " << a << "  " << "b= " << b << endl;
	}
	return 0;
}

int main01()
{
	int x = 10, y = 20;
	myswap2(x, y);
	cout << "x= " << x << "  " << "y= " << y << endl;
	{
	    char a = 'x', b = 'y';
		myswap1(a, b);
		cout << "a= " << a << "  " << "b= " << b << endl;
	}
	system("pause");
	return 0;
}