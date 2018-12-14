#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	virtual Person* clone() = 0;  //返回一个原型对象，定义一个虚函数接口
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
		*tmp = *this;       //浅拷贝

		//深拷贝
	  /*tmp->m_age = this->m_age;
		tmp->m_name = this->m_name;
		tmp->m_p = new char(strlen(this->m_p) + 1);
		strcpy(tmp->m_p, this->m_p);*/
		return tmp;
	}
private:
	string m_name;
	int m_age;

	char *m_p;   //存在指针就涉及深拷贝浅拷贝问题
};

void main111()
{
	Person *c1 = NULL;        //父类指针指向子类对象，实现多态
	c1=	new CPlusplusPro("张三", 32);
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