#include<iostream>
#include<string>
#include<list>
using namespace std;


//Caretaker  管理者
//Mememto    备忘录

class Mememto
{
public:
	Mememto(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string GetName()
	{
		return m_name;
	}
	int GetAge()
	{
		return m_age;
	}
	void SetName(string name)
	{
		m_name = name;
	}
	void SetAge(int age)
	{
		m_age = age;
	}

private:
	string m_name;
	int m_age;

};

//原生者
class Person2
{
public:
	Person2(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string GetName()
	{
		return m_name;
	}
	int GetAge()
	{
		return m_age;
	}
	void SetName(string name)
	{
		m_name = name;
	}
	void SetAge(int age)
	{
		m_age = age;
	}

	//创建一个备忘录
	Mememto *createMemto()
	{
		return new Mememto(m_name, m_age);
	}

	//恢复到备忘录状态
	void SetMememto(Mememto *memto)
	{
		this->m_age = memto->GetAge();
		this->m_name = memto->GetName();
	}

	void printT()
	{
		cout << "m_name" << m_name << "\t" << "m_age" << m_age << endl;
	}
private:
	string m_name;
	int m_age;
};

//管理者
class CareTaker
{
public:
	CareTaker(Mememto *memto)
	{
		this->memto = memto;
	}
	//获取备忘录
	Mememto *GetMememto()
	{
		return memto;
	}
	//设置备忘录
	void SetMememto(Mememto *memto)
	{
		this->memto = memto;
	}
private:
	Mememto * memto;

};

void main252()
{
	CareTaker *caretaker = NULL;
	Mememto *memto = NULL;
	Person2 *p = new Person2("张三", 25);
	p->printT();

	//创建一个备忘录，存储Person2对象的一个状态
	cout << "--------设置新状态-------\n";
	caretaker = new CareTaker(p->createMemto());  //备忘录1

	p->SetAge(42);
	p->printT();

	cout << "--------还原旧状态------\n";
	p->SetMememto(caretaker->GetMememto());
	p->printT();

	cout << "-------设置新状态2------\n";
	p->SetAge(42);
	p->printT();

	cout << "--------还原旧状态2------\n";
	memto = p->createMemto();   //备忘录2
	caretaker->SetMememto(memto);
	p->SetMememto(caretaker->GetMememto());
	p->printT();

	delete memto;
	delete caretaker;
	delete p;
}

void main251()
{
	Mememto *memto = NULL;
	Person2 *p = new Person2("张三", 25);
	p->printT();

	//创建一个备忘录，存储Person2对象的一个状态
	cout << "--------设置新状态-------\n";
	memto = p->createMemto();

	p->SetAge(42);
	p->printT();

	cout << "--------还原旧状态------\n";
	p->SetMememto(memto);
	p->printT();

	delete memto;
	delete p;
}

int main25()
{
	//main251();
	main252();
	system("pause");
	return 0;
}