#include<iostream>
using namespace std;

class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}
	void print()   //动手脚 ，virtual创建一个虚函数表
	{
		cout << "我是爹1" << endl;
	}

private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}
	virtual void print()   //动手脚 ，virtual创建一个虚函数表
	{
		cout << "我是爹2" << endl;
	}

private:
	int a;
};

int main()
{
	//类Parent2的对象的大小会比Parent1对象大小大4，即vptr指针的大小
	cout << "sizeof Parent1" << sizeof(Parent1) << endl;
	cout << "sizeof Parent2" << sizeof(Parent2) << endl;
	system("pause");
	return 0;
}