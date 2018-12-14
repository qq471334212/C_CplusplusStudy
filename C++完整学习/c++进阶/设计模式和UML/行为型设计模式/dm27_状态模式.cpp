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
	void setHour(int hour)    //改变状态
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
//子状态1
class State1 :public State
{
public:
	virtual void doSomeThing(Worker *w);
};
//子状态2
class State2 :public State
{
public:
	virtual void doSomeThing(Worker *w);
};

void State1::doSomeThing(Worker *w)
{
	if (w->getHour() == 7 || w->getHour() == 8)
	{
		cout << "工人早饭时间...." << endl;
	}
	else
	{
		delete w->getCurrentState();   //状态一不满足，销毁，转到状态二
		w->setCurrentState(new State2);
		w->getCurrentState()->doSomeThing(w);
	}
}

void State2::doSomeThing(Worker *w)
{

	if (w->getHour() == 9 || w->getHour() == 10)
	{
		cout << "工人工作时间...." << endl;
	}
	else
	{
		delete w->getCurrentState();   //状态二不满足，销毁，要转到状态三， 后者恢复到初始化状态
		w->setCurrentState(new State1);
		cout << "当前时间点 ： " << w->getHour() << "点 \t未知状态" << endl;

	}
}

//初始状态
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