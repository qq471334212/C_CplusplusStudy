#include<iostream>
using namespace std;

//static CRITICAL_SECTION cs;
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton构造函数私有化" << endl;
	}
public:
	static Singleton *getInstance()
	{
		return m_psl;
	}

	static Singleton *FreeInstance()
	{
		if (m_psl != NULL)                   //静态变量非空时才释放
		{
			delete m_psl;
			m_psl = NULL;
		}
		return m_psl;
	}
private:
	static Singleton *m_psl;
};
//静态变量初始化
Singleton * Singleton::m_psl = new Singleton;
void main53()
{
	//由于在全局变量中创建对象，程序刚一运行，已经开始执行构造函数了，先搞定全局变量
	//然后再执行Singleton *p1 = Singleton::getInstance();
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	if (p1 == p2)
	{
		cout << "同一个对象" << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	Singleton::FreeInstance();
}

int main5()
{
	main53();
	system("pause");
	return 0;
}