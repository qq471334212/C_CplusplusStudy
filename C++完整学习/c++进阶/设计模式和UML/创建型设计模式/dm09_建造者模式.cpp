#include<iostream>
#include<string>
using namespace std;

//1. �����������ı�ʾ
class House
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
//������,���󹤳̶�
class Builder
{
public:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;
	virtual House* getHouse() = 0;
private:
};
//���幤�̶�1����Ԣ���̶�
class FlatBuilder:public Builder
{
public:
	FlatBuilder()
	{
		m_flatHouse = new House;
	}
	virtual void buildWall()
	{
		m_flatHouse->setWall("flat wall");
		//m_flatHouse->getWall();
	}
	virtual void buildDoor()
	{
		m_flatHouse->setDoor("flat door");
		//m_flatHouse->getDoor();
	}
	virtual void buildWindow()
	{
		m_flatHouse->setWindow("flat window");
		//m_flatHouse->getWindow();
	}
	virtual House* getHouse()
	{
		return m_flatHouse;
	}
private:
	House * m_flatHouse;
};

//���幤�̶�2���������̶�
class VillaBuilder :public Builder
{
public:
	VillaBuilder()
	{
		m_villaHouse = new House;
	}
	virtual void buildWall()
	{
		m_villaHouse->setWall("villa wall");
		//m_villaHouse->getWall();
	}
	virtual void buildDoor()
	{
		m_villaHouse->setDoor("villa door");
		//m_villaHouse->getDoor();
	}
	virtual void buildWindow()
	{
		m_villaHouse->setWindow("villa window");
		//m_villaHouse->getWindow();
	}
	virtual House* getHouse()
	{
		return m_villaHouse;
	}
private:
	House * m_villaHouse;
};

//���ʦ�����ͼ��ָ�ӹ��̶�
//���̶Ӻ����ʦʵ�ֽ����
class Designer
{
public:
	Designer(Builder *build)
	{
		m_build = build;
	}

	void Construct()
	{
		m_build->buildWall();
		m_build->buildWindow();
		m_build->buildDoor();
	}
private:
	Builder * m_build;
};

//�ͻ��˳���
void mainTest()
{
	//��һ���������̶�
	Builder  *builder = NULL;
	builder = new VillaBuilder;
	Designer *designer = NULL;
	designer = new Designer(builder);
	designer->Construct();
	House    *villaHouse = builder->getHouse();
	villaHouse->getDoor();
	villaHouse->getWall();
	villaHouse->getWindow();

	delete designer;
	delete villaHouse;
	cout << endl;

	//��һ����Ԣ���̶�
	builder = new FlatBuilder;
	designer = new Designer(builder);
	designer->Construct();
	House    *flatHouse = builder->getHouse();
	flatHouse->getDoor();
	flatHouse->getWall();
	flatHouse->getWindow();

	delete designer;
	delete flatHouse;

	delete builder;
}

int main9()
{
	mainTest();
	system("pause");
	return 0;
}