#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	virtual Person* clone() = 0;  //����һ��ԭ�Ͷ��󣬶���һ���麯���ӿ�
	virtual void printT() = 0;

};

class CPlusplusPro :public Person
{
public:
	CPlusplusPro()
	{
		m_name = "";
		m_age = 0;
		m_p = NULL;
		setResure("aaa");
	}

	CPlusplusPro(string name, int age)
	{
		m_name = name;
		m_age = age;
		m_p = NULL;
		setResure("aaa");
	}
	void setResure(const char *p)
	{
		if (m_p != NULL)
		{
			delete m_p;
		}
		m_p = new char(strlen(p) + 1);
		strcpy(m_p, p);
	}
	virtual void printT()
	{
		cout << "m_name :" << m_name << "\t" << "m_age :" << m_age << "\t" << "m_p :" << &m_p << endl;
	}
	virtual Person* clone()
	{
		CPlusplusPro *tmp = new CPlusplusPro;
		/*tmp->m_age = this->m_age;
		tmp->m_name = this->m_name;*/
		*tmp = *this;       //ǳ����

		//���
	  /*tmp->m_age = this->m_age;
		tmp->m_name = this->m_name;
		tmp->m_p = new char(strlen(this->m_p) + 1);
		strcpy(tmp->m_p, this->m_p);*/
		return tmp;
	}
private:
	string m_name;
	int m_age;

	char *m_p;   //����ָ����漰���ǳ��������
};

void main111()
{
	Person *c1 = NULL;        //����ָ��ָ���������ʵ�ֶ�̬
	c1=	new CPlusplusPro("����", 32);
	c1->printT();

	Person *c2 = c1->clone();
	c2->printT();

}
int main()
{
	main111();
	system("pause");
	return 0;
}