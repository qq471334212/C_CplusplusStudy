#include<iostream>
#include<string>
using namespace std;

class People1
{
public:
	People1(string name, int sex, int condi)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
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

	virtual void getPartner(People1 *p) = 0;
protected:
	string	m_name;
	int		m_sex;
	int		m_condi;
};

class male1: public People1
{
public:
	//构造函数继承父类初始化参数列表
	male1(string name, int sex, int condi) :People1(name, sex, condi)
	{
	
	}

	virtual void getPartner(People1 *p)
	{
		if (this->getSex() == p->getSex())
		{
			cout << "我不是同性恋...." << endl;
		}

		if (this->getCondi() == p->getCondi())
		{
			cout << this->getName() << "\t和\t" << p->getName() << "绝配....." << endl;
		}
		else
		{
			cout << this->getName() << "\t和\t" << p->getName() << "不配....." << endl;
		}
	}
private:
};

class female1 : public People1
{
public:
	//构造函数继承父类初始化参数列表
	female1(string name, int sex, int condi) :People1(name, sex, condi)
	{

	}

	virtual void getPartner(People1 *p)
	{
		if (this->getSex() == p->getSex())
		{
			cout << "我不是同性恋...." << endl;
		}

		if (this->getCondi() == p->getCondi())
		{
			cout << this->getName() << "\t和\t" << p->getName() << "绝配....." << endl;
		}
		else
		{
			cout << this->getName() << "\t和\t" << p->getName() << "不配....." << endl;
		}
	}
private:
};

//中介者模式问题抛出
int main231()
{
	//小芳自己找对象,太累，需要找一个媒婆中介者
	People1 *xiaofang = new male1("小芳", 2, 5);

	People1 *zhangsan = new female1("张三", 1, 4);
	People1 *lisi = new female1("李四", 1, 5);

	xiaofang->getPartner(zhangsan);
	xiaofang->getPartner(lisi);

	delete lisi;
	delete zhangsan;
	delete xiaofang;

	system("pause");
	return 0;
}