#include<iostream>
using namespace std;

class Singleton1
{
private:
	Singleton1()
	{
		cout << "Singleton1构造函数私有化" << endl;
	}
public:
	static Singleton1 *getInstance()
	{
		if (m_psl == NULL)                   //静态变量为空时才创建，创建之后不再创建
		{
			m_psl = new Singleton1;
		}
		return m_psl;
	}

	static Singleton1 *FreeInstance()
	{
		if (m_psl != NULL)                   //静态变量非空时才释放
		{
			delete m_psl;
			m_psl = NULL;
		}
		return m_psl;
	}
private:
	static Singleton1 *m_psl;
};
//静态变量初始化
Singleton1 * Singleton1::m_psl = NULL;
void main43()
{

	Singleton1 *p1 = Singleton1::getInstance();
	Singleton1 *p2 = Singleton1::getInstance();
	if (p1 == p2)
	{
		cout << "同一个对象" << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	Singleton1::FreeInstance();
}

int main4()
{
	main43();
	system("pause");
	return 0;
}