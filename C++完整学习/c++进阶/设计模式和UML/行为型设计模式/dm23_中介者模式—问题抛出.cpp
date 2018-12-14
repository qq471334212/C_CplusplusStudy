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
	//���캯���̳и����ʼ�������б�
	male1(string name, int sex, int condi) :People1(name, sex, condi)
	{
	
	}

	virtual void getPartner(People1 *p)
	{
		if (this->getSex() == p->getSex())
		{
			cout << "�Ҳ���ͬ����...." << endl;
		}

		if (this->getCondi() == p->getCondi())
		{
			cout << this->getName() << "\t��\t" << p->getName() << "����....." << endl;
		}
		else
		{
			cout << this->getName() << "\t��\t" << p->getName() << "����....." << endl;
		}
	}
private:
};

class female1 : public People1
{
public:
	//���캯���̳и����ʼ�������б�
	female1(string name, int sex, int condi) :People1(name, sex, condi)
	{

	}

	virtual void getPartner(People1 *p)
	{
		if (this->getSex() == p->getSex())
		{
			cout << "�Ҳ���ͬ����...." << endl;
		}

		if (this->getCondi() == p->getCondi())
		{
			cout << this->getName() << "\t��\t" << p->getName() << "����....." << endl;
		}
		else
		{
			cout << this->getName() << "\t��\t" << p->getName() << "����....." << endl;
		}
	}
private:
};

//�н���ģʽ�����׳�
int main231()
{
	//С���Լ��Ҷ���,̫�ۣ���Ҫ��һ��ý���н���
	People1 *xiaofang = new male1("С��", 2, 5);

	People1 *zhangsan = new female1("����", 1, 4);
	People1 *lisi = new female1("����", 1, 5);

	xiaofang->getPartner(zhangsan);
	xiaofang->getPartner(lisi);

	delete lisi;
	delete zhangsan;
	delete xiaofang;

	system("pause");
	return 0;
}