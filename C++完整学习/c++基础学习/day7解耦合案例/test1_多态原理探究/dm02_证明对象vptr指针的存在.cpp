#include<iostream>
using namespace std;

class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}
	void print()   //���ֽ� ��virtual����һ���麯����
	{
		cout << "���ǵ�1" << endl;
	}

private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}
	virtual void print()   //���ֽ� ��virtual����һ���麯����
	{
		cout << "���ǵ�2" << endl;
	}

private:
	int a;
};

int main()
{
	//��Parent2�Ķ���Ĵ�С���Parent1�����С��4����vptrָ��Ĵ�С
	cout << "sizeof Parent1" << sizeof(Parent1) << endl;
	cout << "sizeof Parent2" << sizeof(Parent2) << endl;
	system("pause");
	return 0;
}