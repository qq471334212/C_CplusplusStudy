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

//工程队
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
		h->setDoor("门");
	}
	void gcgSetWall(House1 *h)
	{
		h->setWall("墙");
	}
	void gcgSetWindow(House1 *h)
	{
		h->setWindow("窗");
	}
private:
	House1 * m_h;
};

//客户自己建造房子
void main101()
{
	House1 *house = new House1;
	house->setDoor("门");
	house->setWall("墙");
	house->setWindow("窗");

	delete house;
	
}
//工程队造房子
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