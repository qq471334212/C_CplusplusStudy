#include<iostream>
#include<string>
#include<list>
using namespace std;

//主体对象，秘书，通知观察者
class Secretary;

//观察者，员工
class PlayersObserver
{
public:
	PlayersObserver(Secretary * secretary)
	{
		this->m_secretary = secretary;
	}
	void updata(string action)
	{
		if (action == "老板来了")
		{
			cout << "老板来了，开始工作了" << endl;
		}
		else if (action == "老板走了")
		{
			cout << "老板走了，开始放松了" << endl;
		}
		else {}
		//cout << "action: " << action << endl;
	}
private:
	Secretary * m_secretary;
};

class Secretary
{
public:
	Secretary() { m_list.clear(); }

	void Notify(string info)
	{
		for (list<PlayersObserver*>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->updata(info);
		}
	}

	void setPlayersObserver(PlayersObserver *p)
	{
		m_list.push_back(p);
	}
private:
	list<PlayersObserver*> m_list;
};

int main24()
{
	Secretary			*secretary = NULL;
	PlayersObserver		*po1 = NULL;
	PlayersObserver		*po2 = NULL;

	secretary = new Secretary;
	po1 = new PlayersObserver(secretary);
	po2 = new PlayersObserver(secretary);

	secretary->setPlayersObserver(po1);
	secretary->setPlayersObserver(po2);

	secretary->Notify("老板来了");

	secretary->Notify("老板走了");

	delete po2;
	delete po1;
	delete secretary;
	system("pause");
	return 0;
}