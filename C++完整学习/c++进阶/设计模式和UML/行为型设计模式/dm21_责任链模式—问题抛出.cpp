#include<iostream>
#include<list>
using namespace std;

class CarHandle1
{
public:
	virtual void Handle() = 0;
};

class HeadCarHandle1:public CarHandle1
{
public:
	virtual void Handle()
	{
		cout << "制造  车头" << endl;
	}
};

class BodyCarHandle1 :public CarHandle1
{
public:
	virtual void Handle()
	{
		cout << "制造  车身" << endl;
	}
};

class TailCarHandle1 :public CarHandle1
{
public:
	virtual void Handle()
	{
		cout << "制造  车尾" << endl;
	}
};
int main211()
{
	CarHandle1 *headcarhandle = new HeadCarHandle1;
	CarHandle1 *bodycarhandle = new BodyCarHandle1;
	CarHandle1 *tailcarhandle = new TailCarHandle1;

	//业务逻辑在客户端实现，不属于责任链模式
	headcarhandle->Handle();
	bodycarhandle->Handle();
	tailcarhandle->Handle();

	delete tailcarhandle;
	delete bodycarhandle;
	delete headcarhandle;


	system("pause");
	return 0;
}