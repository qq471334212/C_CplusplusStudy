#include<iostream>
#include<string>
#include<list>
using namespace std;

//����������飬֪ͨ�۲���
class Secretary;

//�۲��ߣ�Ա��
class PlayersObserver
{
public:
	PlayersObserver(Secretary * secretary)
	{
		this->m_secretary = secretary;
	}
	void updata(string action)
	{
		if (action == "�ϰ�����")
		{
			cout << "�ϰ����ˣ���ʼ������" << endl;
		}
		else if (action == "�ϰ�����")
		{
			cout << "�ϰ����ˣ���ʼ������" << endl;
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

	secretary->Notify("�ϰ�����");

	secretary->Notify("�ϰ�����");

	delete po2;
	delete po1;
	delete secretary;
	system("pause");
	return 0;
}