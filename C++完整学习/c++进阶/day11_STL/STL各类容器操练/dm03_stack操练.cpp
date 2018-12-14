#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
using namespace std;

//ջģ��
//ջ���㷨 �� ���ݽṹ�ķ���
void stackInit()
{
	stack<int> s;
	//��ջ
	for (int i = 0; i < 10; i++)
	{
		s.push(i + 1);
	}

	cout << "ջ�Ĵ�СΪ:" << s.size() << endl;
	//��ջ
	while (!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
}

//Teacher�ڵ�
class Teacher
{
public:
	int age;
	char name[32];

	void printT()
	{
		cout << "age :" << age << endl;
	}
};

void stackStruct()
{
	Teacher *p1, *p2, *p3;
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);

	stack<Teacher*> sp;
	sp.push(p1);
	sp.push(p2);
	sp.push(p3);

	cout << "-----װ��ʦ�ṹ��------" << endl;
	while (!s.empty())
	{
		Teacher tmp = s.top();
		tmp.printT();
		s.pop();
	}

	cout << "-----װ��ʦ�ṹ��ָ��------" << endl;
	while (!sp.empty())
	{
		Teacher *tmp = sp.top();
		tmp->printT();
		sp.pop();
	}
}

int main31()
{
	//stackInit();
	stackStruct();
	system("pause");
	return 0;
}