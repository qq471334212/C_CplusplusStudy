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
		cout << "����  ��ͷ" << endl;
	}
};

class BodyCarHandle1 :public CarHandle1
{
public:
	virtual void Handle()
	{
		cout << "����  ����" << endl;
	}
};

class TailCarHandle1 :public CarHandle1
{
public:
	virtual void Handle()
	{
		cout << "����  ��β" << endl;
	}
};
int main211()
{
	CarHandle1 *headcarhandle = new HeadCarHandle1;
	CarHandle1 *bodycarhandle = new BodyCarHandle1;
	CarHandle1 *tailcarhandle = new TailCarHandle1;

	//ҵ���߼��ڿͻ���ʵ�֣�������������ģʽ
	headcarhandle->Handle();
	bodycarhandle->Handle();
	tailcarhandle->Handle();

	delete tailcarhandle;
	delete bodycarhandle;
	delete headcarhandle;


	system("pause");
	return 0;
}