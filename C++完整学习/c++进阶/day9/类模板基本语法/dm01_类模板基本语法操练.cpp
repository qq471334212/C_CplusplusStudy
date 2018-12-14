#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class A
{
public:
	A(T a = 0)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "a : " << a << endl;
	}
protected:
	T a;
};

//从模板类派生时，需要具体化摸板类，C++编译器需要知道父类数据类型具体是什么样子
//==》要知道父类所占的内存大小是多少，只有数据类型固定下来，才知道如何分配内存
class B :public A<int>   //注意点1
{
public:
	B(int a = 10, int b = 20) :A<int>(a) { this->b = b; }   //注意点2.调用父类有参构造函数
	void printB()
	{
		cout << "a : " << a << "  " << "b : " << b << endl;
	}
private:
	int b;
};

//从摸板类派生摸板类
template<typename T>
class C :public A<T>
{
public:
	C(T c, T a) :A<T>(a) {
		this->c = c;
	}
	void printC()
	{
		cout << "c : " << c << endl;
	}
private:
	T c;
};
int main03()
{
	C<int> c1(1, 2);
	c1.printC();
	system("pause");
	return 0;
}

int main02()
{
	B b1(1, 2);
	b1.printB();
	system("pause");
	return 0;
}

//C++编译器要求具体的类，所以必须 要A<int> &a
void useA(A<int> &a)  //类模板做函数参数
{
	a.printA();
}

int main01()
{
	A<int> a1(1);    //类模板需要进行类型具体化
	a1.printA();
	useA(a1);
	system("pause");
	return 0;
}