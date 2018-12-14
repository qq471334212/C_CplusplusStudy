#include<iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()   //动手脚 ，virtual创建一个虚函数表
	{
		cout << "我是爹" << endl;
	}
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}
	void print()
	{
		cout << "我是儿子" << endl;
	}
private:
	int b;
};

void HowToPlay(Parent *base)
{
	base->print();            //有多态发生
							  //动手脚
}
int main()
{
	Parent p1;        //用类定义对象的时候，动手脚，提前布局，对象模型初探
					  //C++编译器会在对象中添加一个vptr指针
	Child c1;
	HowToPlay(&p1);
	HowToPlay(&c1);
	system("pause");
	return 0;
}
