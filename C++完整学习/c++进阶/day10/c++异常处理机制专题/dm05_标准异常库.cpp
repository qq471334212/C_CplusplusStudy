#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Teacher5 
{
public:
	Teacher5(int age)
	{
		if (age > 100)
		{
			throw out_of_range("����̫��");
		}
		this->age = age;
	}
private:
	int age;
};

class myException :public exception
{
public:
	myException(const char *p)
	{
		this->m_p = p;
	}

	virtual const char* what()
	{
		cout << "myException :���� " << m_p << endl;
		return m_p;
	}
private:
	const char *m_p;

};

void testMyException()
{
	throw myException("�����쳣");   //�˴����Է�����̬
}

int main()
{
	try
	{
		testMyException();
	}
	catch (myException &e)
	{
		e.what();
	}
	system("pause");
	return 0;
}

int main51()
{
	try
	{
		Teacher5 t1(105);
	}
	catch (out_of_range e)
	{
		cout << e.what() << endl;   //whatͨ�ú���
	}
	catch (...)
	{
		cout << "..." << endl;
	}
	system("pause");
	return 0;
}