#include<iostream>
using namespace std;
/*
AbFactory     *f = NULL;
myFruit       *fruit = NULL;

f = new myAppleFactory;      //创建苹果工厂
fruit = f->CreateProduct();  //生产苹果
fruit->sayName();*/
class Fruits
{
public:
	virtual void FruitsInit() = 0;

};

class AbstractFactory
{
public:
	virtual Fruits* CreateBanana() = 0;    //一个产品族
	virtual Fruits* CreateApple() = 0;
};


class NorthBanana :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "北方香蕉..........." << endl;
	}
};

class NorthApple :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "北方苹果..........." << endl;
	}
};

class SorthBanana :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "南方香蕉..........." << endl;
	}
};

class SorthApple :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "南方苹果..........." << endl;
	}
};

class NorthFactory :public AbstractFactory
{
public:
	virtual Fruits* CreateBanana()
	{
		return new NorthBanana;
	}
	virtual Fruits* CreateApple()
	{
		return new NorthApple;
	}
};

class SorthFactory :public AbstractFactory
{
public:
	virtual Fruits* CreateBanana()
	{
		return new SorthBanana;
	}
	virtual Fruits* CreateApple()
	{
		return new SorthApple;
	}
};

int main8()
{
	AbstractFactory     *f = NULL;
	Fruits              *fruit = NULL;
	 
	f = new SorthFactory;      //创建南方工厂
	fruit = f->CreateApple();  //生产南方苹果
	fruit->FruitsInit();

	delete fruit;

	fruit = f->CreateBanana();  //生产南方香蕉
	fruit->FruitsInit();

	delete fruit;

	f = new NorthFactory;      //创建北方工厂
	fruit = f->CreateBanana();  //生产北方香蕉
	fruit->FruitsInit();

	delete fruit;


	delete f;
	
	system("pause");
	return 0;
}