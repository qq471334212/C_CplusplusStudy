#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
using namespace std;

void queueInit()
{
	queue<int> q;
	//入栈
	for (int i = 0; i < 10; i++)
	{
		q.push(i + 1);
	}

	cout << "栈的大小为:" << q.size() << endl;
	//出栈
	while (!q.empty())
	{
		int tmp = q.front();
		cout << tmp << "  ";
		q.pop();
	}
}

//队列算法和数据类型的分离
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

void queueStruct()
{
	Teacher *p1, *p2, *p3;
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);

	while (!q.empty())
	{
		Teacher tmp = q.front();
		tmp.printT();
		q.pop();
	}

	queue<Teacher*> qp;
	qp.push(p1);
	qp.push(p2);
	qp.push(p3);

	while (!qp.empty())
	{
		Teacher* tmp = qp.front();
		tmp->printT();
		qp.pop();
	}

}

int main41()
{
	//queueInit();
	queueStruct();
	system("pause");
	return 0;
}