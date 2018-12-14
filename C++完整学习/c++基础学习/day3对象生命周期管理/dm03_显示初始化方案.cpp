#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test3
{
public:
	void init(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

private:
	int a;
	int b;
};

int main03()
{
	Test3 t1;           //C++编译器会提供一个默认的构造函数
	                    //没有拷贝构造函数，也会提供一个默认的拷贝构造函数

	t1.init(1, 2);      //显式的构造函数，当对象定义众多时，赋值非常不方便，因此需要调用构造函数
	Test3 tArray[50];
	tArray[0].init(5, 2);
	//....
	system("pause");
	return 0;
}