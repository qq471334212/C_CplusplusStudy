#include<iostream>
#include<string>
using namespace std;

//�н��߳���ӿ�
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
			cout << "ͬ�� ֮�䲻���Ҷ���...." << endl;
		}

		if (pmale->getCondi() == pfemale->getCondi())
		{
			cout << pmale->getName() << "\t��\t" << pfemale->getName() << "����....." << endl;
		}
		else
		{
			cout << pmale->getName() << "\t��\t" << pfemale->getName() << "����....." << endl;
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
	//���캯���̳и����ʼ�������б�
	male(string name, int sex, int condi, Mediator *m) :People(name, sex, condi, m)
	{

	}
	//��������
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
	//���캯���̳и����ʼ�������б�
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

//�н���ģʽ�����׳�
int main23()
{
	//С���Լ��Ҷ���,̫�ۣ���Ҫ��һ��ý���н���
	Mediator *m = new Mediator;
	People *xiaofang = new male("С��", 2, 5, m);

	People *zhangsan = new female("����", 1, 4, m);
	People *lisi = new female("����", 1, 5, m);

	xiaofang->getPartner(zhangsan);
	xiaofang->getPartner(lisi);

	delete lisi;
	delete zhangsan;
	delete xiaofang;

	system("pause");
	return 0;
}