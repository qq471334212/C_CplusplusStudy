#include<iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		//print();
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
	//	print();
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
	Child c1;         //定义一个子类对象，在这个过程中，在父类构造函数中调用虚函数print(),不能发生多态
					  //子类的vptr指针是分步初始化的
	Child *c = NULL;
	Parent *p = NULL;

	Child array[] = { Child(1),Child(2) ,Child(3) };
	p = array;
	c = array;

	p->print();
	c->print();

	p++;
	c++;

	p->print();            //此处报错，因为父类和子类两者内存空间大小不一样，因此指针步长不一样
	c->print();

	p++;
	c++;

	p->print();
	c->print();

	system("pause");
	return 0;
}