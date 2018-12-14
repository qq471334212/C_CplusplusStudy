#include<iostream>
using namespace std;
/*
AbFactory     *f = NULL;
myFruit       *fruit = NULL;

f = new myAppleFactory;      //����ƻ������
fruit = f->CreateProduct();  //����ƻ��
fruit->sayName();*/
class Fruits
{
public:
	virtual void FruitsInit() = 0;

};

class AbstractFactory
{
public:
	virtual Fruits* CreateBanana() = 0;    //һ����Ʒ��
	virtual Fruits* CreateApple() = 0;
};


class NorthBanana :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "�����㽶..........." << endl;
	}
};

class NorthApple :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "����ƻ��..........." << endl;
	}
};

class SorthBanana :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "�Ϸ��㽶..........." << endl;
	}
};

class SorthApple :public Fruits
{
public:
	virtual void FruitsInit()
	{
		cout << "�Ϸ�ƻ��..........." << endl;
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
	 
	f = new SorthFactory;      //�����Ϸ�����
	fruit = f->CreateApple();  //�����Ϸ�ƻ��
	fruit->FruitsInit();

	delete fruit;

	fruit = f->CreateBanana();  //�����Ϸ��㽶
	fruit->FruitsInit();

	delete fruit;

	f = new NorthFactory;      //������������
	fruit = f->CreateBanana();  //���������㽶
	fruit->FruitsInit();

	delete fruit;


	delete f;
	
	system("pause");
	return 0;
}