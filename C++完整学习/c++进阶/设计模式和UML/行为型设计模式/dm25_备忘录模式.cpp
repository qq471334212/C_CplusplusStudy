#include<iostream>
#include<string>
#include<list>
using namespace std;


//Caretaker  ������
//Mememto    ����¼

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

//ԭ����
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

	//����һ������¼
	Mememto *createMemto()
	{
		return new Mememto(m_name, m_age);
	}

	//�ָ�������¼״̬
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

//������
class CareTaker
{
public:
	CareTaker(Mememto *memto)
	{
		this->memto = memto;
	}
	//��ȡ����¼
	Mememto *GetMememto()
	{
		return memto;
	}
	//���ñ���¼
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
	Person2 *p = new Person2("����", 25);
	p->printT();

	//����һ������¼���洢Person2�����һ��״̬
	cout << "--------������״̬-------\n";
	caretaker = new CareTaker(p->createMemto());  //����¼1

	p->SetAge(42);
	p->printT();

	cout << "--------��ԭ��״̬------\n";
	p->SetMememto(caretaker->GetMememto());
	p->printT();

	cout << "-------������״̬2------\n";
	p->SetAge(42);
	p->printT();

	cout << "--------��ԭ��״̬2------\n";
	memto = p->createMemto();   //����¼2
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
	Person2 *p = new Person2("����", 25);
	p->printT();

	//����һ������¼���洢Person2�����һ��״̬
	cout << "--------������״̬-------\n";
	memto = p->createMemto();

	p->SetAge(42);
	p->printT();

	cout << "--------��ԭ��״̬------\n";
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