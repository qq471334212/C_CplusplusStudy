#include<iostream>
#include<string>
#include<list>
using namespace std;

class SubSystemA
{
public:
	void doThing()
	{
		cout << "SubSystemA  run" << endl;
	}
};

class SubSystemB
{
public:
	void doThing()
	{
		cout << "SubSystemB  run" << endl;
	}
};

class SubSystemC
{
public:
	void doThing()
	{
		cout << "SubSystemC  run" << endl;
	}
};

class Facade
{
public:
	Facade()
	{
		sysA = new SubSystemA;
		sysB = new SubSystemB;
		sysC = new SubSystemC;
	}

	~Facade()
	{
		delete sysA;
		delete sysB;
		delete sysC;
	}

public:
	void doThing()
	{
		sysA->doThing();
		sysB->doThing();
		sysC->doThing();
	}

private:
	SubSystemA *sysA;
	SubSystemB *sysB;
	SubSystemC *sysC;
};

//老式用法
void main171()
{
	SubSystemA *sysA = new SubSystemA;
	SubSystemB *sysB = new SubSystemB;
	SubSystemC *sysC = new SubSystemC;

	sysA->doThing();
	sysB->doThing();
	sysC->doThing();

	delete sysA;
	delete sysB;
	delete sysC;

}

//外观模式

void main172()
{
	Facade *fd = NULL;
	fd = new Facade;

	fd->doThing();
}
int main17()
{
	//main171();
	main172();
	system("pause");
	return 0;
}