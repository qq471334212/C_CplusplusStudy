#include<iostream>
#include<string>
using namespace std;

class House1
{
public:
	void setDoor(string door)
	{
		this->m_door = door;
	}
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setWindow(string window)
	{
		this->m_window = window;
	}

	string getDoor()
	{
		cout << m_door << endl;
		return this->m_door;
	}
	string getWall()
	{
		cout << m_wall << endl;
		return this->m_wall;
	}
	string getWindow()
	{
		cout << m_window << endl;
		return this->m_window;
	}
private:
	string m_door;
	string m_wall;
	string m_window;
};

//���̶�
class gcGroup
{
public:
	gcGroup()
	{
		m_h = new House1;
	}
	House1 * getH()
	{
		return m_h;
	}
	void setBuild()
	{
		gcgSetDoor(m_h);
		gcgSetWall(m_h);
		gcgSetWindow(m_h);
	}
	void gcgSetDoor(House1 *h)
	{
		h->setDoor("��");
	}
	void gcgSetWall(House1 *h)
	{
		h->setWall("ǽ");
	}
	void gcgSetWindow(House1 *h)
	{
		h->setWindow("��");
	}
private:
	House1 * m_h;
};

//�ͻ��Լ����췿��
void main101()
{
	House1 *house = new House1;
	house->setDoor("��");
	house->setWall("ǽ");
	house->setWindow("��");

	delete house;
	
}
//���̶��췿��
void main102()
{
	House1 *house = NULL;
	gcGroup *gcg = new gcGroup;
	gcg->setBuild();
	house = gcg->getH();
	house->getDoor();
	house->getWall();
	house->getWindow();

	delete gcg;
	delete house;

}
int main10()
{
	//main101();
	main102();
	system("pause");
	return 0;
}