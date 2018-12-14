#include<iostream>
#include<string>
using namespace std;
//抽象接口，卖书
class Subject
{
public:
	virtual void sailBook() = 0;
};
//实体店
class RealSubjectBook:public Subject
{
public:
	virtual void sailBook()
	{
		cout << "实体店卖书.........." << endl;
	}
};

//跟RealSubjectBook类关联
//代理在进行被代理目标的工作下，还能额外完成一些功能，例如打折促销，优惠等等
class dangdangProxy :public Subject
{
public:
	virtual void sailBook()
	{
		RealSubjectBook *reb = new RealSubjectBook;
		bookCount();
		reb->sailBook();
		bookCount();
	}

	void bookCount()
	{
		cout << "双十一打折促销卖书" << endl;
	}
private:
	Subject * m_subject;
};

void main121()
{
	Subject *s = NULL;
	s = new dangdangProxy;
	s->sailBook();
	delete s;

}
int main12()
{
	main121();
	system("pause");
	return 0;
}