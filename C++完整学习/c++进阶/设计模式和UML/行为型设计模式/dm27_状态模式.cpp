#include<iostream>
#include<string>
#include<list>
using namespace std;

class Worker;

class State
{
public:
	virtual void doSomeThing(Worker *w) = 0;
};

class Worker
{
public:
	Worker();
	int getHour()
	{
		return m_hour;
	}
	void setHour(int hour)    //�ı�״̬
	{
		m_hour = hour;
	}
	State *getCurrentState()
	{
		return m_currentstate;
	}
	void setCurrentState(State *s)
	{
		m_currentstate = s;
	}
	void doSomeThing()
	{
		m_currentstate->doSomeThing(this);
	}
private:
	int m_hour;
	State *m_currentstate;
};
//��״̬1
class State1 :public State
{
public:
	virtual void doSomeThing(Worker *w);
};
//��״̬2
class State2 :public State
{
public:
	virtual void doSomeThing(Worker *w);
};

void State1::doSomeThing(Worker *w)
{
	if (w->getHour() == 7 || w->getHour() == 8)
	{
		cout << "�����緹ʱ��...." << endl;
	}
	else
	{
		delete w->getCurrentState();   //״̬һ�����㣬���٣�ת��״̬��
		w->setCurrentState(new State2);
		w->getCurrentState()->doSomeThing(w);
	}
}

void State2::doSomeThing(Worker *w)
{

	if (w->getHour() == 9 || w->getHour() == 10)
	{
		cout << "���˹���ʱ��...." << endl;
	}
	else
	{
		delete w->getCurrentState();   //״̬�������㣬���٣�Ҫת��״̬���� ���߻ָ�����ʼ��״̬
		w->setCurrentState(new State1);
		cout << "��ǰʱ��� �� " << w->getHour() << "�� \tδ֪״̬" << endl;

	}
}

//��ʼ״̬
Worker::Worker()
{
	m_currentstate = new State1;
}
int main27()
{
	Worker *w1 = new Worker;
	w1->setHour(7);
	w1->doSomeThing();

	w1->setHour(9);
	w1->doSomeThing();

	w1->setHour(11);
	w1->doSomeThing();

	delete w1;

	system("pause");
	return 0;
}