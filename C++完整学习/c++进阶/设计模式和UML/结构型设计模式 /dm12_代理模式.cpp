#include<iostream>
#include<string>
using namespace std;
//����ӿڣ�����
class Subject
{
public:
	virtual void sailBook() = 0;
};
//ʵ���
class RealSubjectBook:public Subject
{
public:
	virtual void sailBook()
	{
		cout << "ʵ�������.........." << endl;
	}
};

//��RealSubjectBook�����
//�����ڽ��б�����Ŀ��Ĺ����£����ܶ������һЩ���ܣ�������۴������Żݵȵ�
class dangdangProxy :public Subject
{
public:
	virtual void sailBook()
	{
		RealSubjectBook *reb = new RealSubjectBook;
		bookCount();
		reb->sailBook();
		bookCount();
	}

	void bookCount()
	{
		cout << "˫ʮһ���۴�������" << endl;
	}
private:
	Subject * m_subject;
};

void main121()
{
	Subject *s = NULL;
	s = new dangdangProxy;
	s->sailBook();
	delete s;

}
int main12()
{
	main121();
	system("pause");
	return 0;
}