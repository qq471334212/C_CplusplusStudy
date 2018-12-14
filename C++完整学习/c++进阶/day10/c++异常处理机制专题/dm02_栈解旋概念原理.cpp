#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Test类构造函数调用" << endl;
	}
	~Test() { cout << "Test类析构函数调用" << endl; }
private:
	int a;
	int b;
};

//void myTest() throw(A,B,C,D)  //只能抛出A,B,C,D类异常以及其子异常
//void myTest() throw()         //不能抛出异常

void myTest()                 //能抛任何异常
{
	Test t1(1, 2), t2(3, 4);
	cout << "myTest....要发生异常" << endl;
	throw 1;       //throw之后，马上就把t1，t2给析构完毕
}

int main12()
{
	try
	{
		myTest();
	}
	catch (int)
	{
		cout << "int 类型异常" << endl;
	}
	catch (...)
	{
		cout << "未知 类型异常" << endl;
	}
	system("pause");
	return 0;
}