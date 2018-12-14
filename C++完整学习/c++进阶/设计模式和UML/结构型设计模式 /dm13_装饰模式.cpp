#include<iostream>
#include<string>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
};

class RunCar :public Car
{
public:
	void grond()
	{
		cout << "可以在陆地上开......." << endl;
	}
	virtual void show()
	{
		grond();
	}
};

class SwimCarDirection :public Car
{
public:
	SwimCarDirection(Car *car)
	{
		m_car = car;
	}
	void swim()
	{
		cout << "可以在水上开........" << endl;
	}
	virtual void show()
	{
		m_car->show();
		swim();           //新增功能swim
	}
private:
	Car * m_car;
};

class FlyCarDirection :public Car
{
public:
	FlyCarDirection(Car *car)
	{
		m_car = car;
	}
	void fly()
	{
		cout << "可以在空中开........" << endl;
	}
	virtual void show()
	{
		m_car->show();
		fly();          //新增功能swim
	}
private:
	Car * m_car;
};
void main131()
{
	Car *myCar = NULL;
	myCar = new RunCar;
	myCar->show();
	cout << "--------\n";

	FlyCarDirection *flyCar = new FlyCarDirection(myCar);
	flyCar->show();
	cout << "--------\n";

	SwimCarDirection *swimCar = new SwimCarDirection(flyCar);
	swimCar->show();

	delete swimCar;
	delete flyCar;
	delete myCar;
}
int main13()
{
	main131();
	system("pause");
	return 0;
}