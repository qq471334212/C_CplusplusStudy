#include<iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()   //���ֽ� ��virtual����һ���麯����
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}
	void print()
	{
		cout << "���Ƕ���" << endl;
	}
private:
	int b;
};

void HowToPlay(Parent *base)
{
	base->print();            //�ж�̬����
							  //���ֽ�
}
int main()
{
	Parent p1;        //���ඨ������ʱ�򣬶��ֽţ���ǰ���֣�����ģ�ͳ�̽
					  //C++���������ڶ��������һ��vptrָ��
	Child c1;
	HowToPlay(&p1);
	HowToPlay(&c1);
	system("pause");
	return 0;
}
