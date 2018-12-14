#include<iostream>
using namespace std;

class Singleton1
{
private:
	Singleton1()
	{
		cout << "Singleton1���캯��˽�л�" << endl;
	}
public:
	static Singleton1 *getInstance()
	{
		if (m_psl == NULL)                   //��̬����Ϊ��ʱ�Ŵ���������֮���ٴ���
		{
			m_psl = new Singleton1;
		}
		return m_psl;
	}

	static Singleton1 *FreeInstance()
	{
		if (m_psl != NULL)                   //��̬�����ǿ�ʱ���ͷ�
		{
			delete m_psl;
			m_psl = NULL;
		}
		return m_psl;
	}
private:
	static Singleton1 *m_psl;
};
//��̬������ʼ��
Singleton1 * Singleton1::m_psl = NULL;
void main43()
{

	Singleton1 *p1 = Singleton1::getInstance();
	Singleton1 *p2 = Singleton1::getInstance();
	if (p1 == p2)
	{
		cout << "ͬһ������" << endl;
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