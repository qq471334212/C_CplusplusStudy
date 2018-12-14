#include<iostream>
using namespace std;

class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;

	void make()   //模板函数,决定业务逻辑
	{
		MakeHead();
		MakeBody();
		MakeTail();
	}
};

class Jeep :public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "Jeep Head" << endl;
	}
	virtual void MakeBody()
	{
		cout << "Jeep Body" << endl;
	}
	virtual void MakeTail()
	{
		cout << "Jeep Tail" << endl;
	}
};

class BMW :public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "BMW Head" << endl;
	}
	virtual void MakeBody()
	{
		cout << "BMW Body" << endl;
	}
	virtual void MakeTail()
	{
		cout << "BMW Tail" << endl;
	}
};

class bus :public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "bus Head" << endl;
	}
	virtual void MakeBody()
	{
		cout << "bus Body" << endl;
	}
	virtual void MakeTail()
	{
		cout << "bus Tail" << endl;
	}
};

int main19()
{
	MakeCar *car = NULL;
	car = new bus;
	car->make();

	delete car;

	MakeCar *car2 = NULL;
	car2 = new Jeep;
	car2->make();

	delete car2;

	system("pause");
	return 0;
}