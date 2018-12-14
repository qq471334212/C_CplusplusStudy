#include<iostream>
#include<string>
using namespace std;

//中介者抽象接口
class Mediator;


class People
{
public:
	People(string name, int sex, int condi, Mediator* m)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
		mediator = m;
	}

	string getName()
	{
		return m_name;
	}

	int getSex()
	{
		return m_sex;
	}

	int getCondi()
	{
		return m_condi;
	}

	virtual void getPartner(People *p) = 0;
protected:
	string		m_name;
	int			m_sex;
	int			m_condi;
	Mediator*   mediator;
};

class Mediator
{
public:
	void getPartner()
	{
		//...

		if (pmale->getSex() == pfemale->getSex())
		{
			cout << "同性 之间不能找对象...." << endl;
		}

		if (pmale->getCondi() == pfemale->getCondi())
		{
			cout << pmale->getName() << "\t和\t" << pfemale->getName() << "绝配....." << endl;
		}
		else
		{
			cout << pmale->getName() << "\t和\t" << pfemale->getName() << "不配....." << endl;
		}

	}

	void setMale(People *male)
	{
		pmale = male;
	}

	void setFemale(People *female)
	{
		pfemale = female;
	}
private:
	People * pmale;
	People * pfemale;
};

class male : public People
{
public:
	//构造函数继承父类初始化参数列表
	male(string name, int sex, int condi, Mediator *m) :People(name, sex, condi, m)
	{

	}
	//传来男人
	virtual void getPartner(People *p)
	{
		mediator->setFemale(p);
		mediator->setMale(this);
		mediator->getPartner();
	}
private:
};

class female : public People
{
public:
	//构造函数继承父类初始化参数列表
	female(string name, int sex, int condi, Mediator *m) :People(name, sex, condi, m)
	{

	}

	virtual void getPartner(People *p)
	{
		mediator->setFemale(this);
		mediator->setMale(p);
		mediator->getPartner();
	}
private:
};

//中介者模式问题抛出
int main23()
{
	//小芳自己找对象,太累，需要找一个媒婆中介者
	Mediator *m = new Mediator;
	People *xiaofang = new male("小芳", 2, 5, m);

	People *zhangsan = new female("张三", 1, 4, m);
	People *lisi = new female("李四", 1, 5, m);

	xiaofang->getPartner(zhangsan);
	xiaofang->getPartner(lisi);

	delete lisi;
	delete zhangsan;
	delete xiaofang;

	system("pause");
	return 0;
}