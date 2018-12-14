#include<iostream>
using namespace std;

//static CRITICAL_SECTION cs;
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton���캯��˽�л�" << endl;
	}
public:
	static Singleton *getInstance()
	{
		return m_psl;
	}

	static Singleton *FreeInstance()
	{
		if (m_psl != NULL)                   //��̬�����ǿ�ʱ���ͷ�
		{
			delete m_psl;
			m_psl = NULL;
		}
		return m_psl;
	}
private:
	static Singleton *m_psl;
};
//��̬������ʼ��
Singleton * Singleton::m_psl = new Singleton;
void main53()
{
	//������ȫ�ֱ����д������󣬳����һ���У��Ѿ���ʼִ�й��캯���ˣ��ȸ㶨ȫ�ֱ���
	//Ȼ����ִ��Singleton *p1 = Singleton::getInstance();
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	if (p1 == p2)
	{
		cout << "ͬһ������" << endl;
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