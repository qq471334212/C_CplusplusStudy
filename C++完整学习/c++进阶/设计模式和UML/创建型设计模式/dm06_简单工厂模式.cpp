#include<iostream>
using namespace std;

class Fruit
{
public:
	virtual void sayName() = 0;
private:

};
class Banana :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "�����㽶������������" << endl;
	}
};
class Apple :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "����ƻ��������������" << endl;
	}
};
//����������
class Factory
{
public:
	//���󹤳�
	virtual Fruit * getFruit() = 0;


	//�򵥹���
	//Fruit * create(const char *p)
	//{
	//	if (p == "banana")
	//	{
	//		return new Banana;
	//	}
	//	else if (p == "apple")
	//	{
	//		return new Apple;
	//	}
	//	else
	//	{
	//		cout << "��֧��\n";
	//	}
	//}
};

class AppleFactory :public Factory
{
public:
	virtual Fruit *getFruit()
	{
		return new Apple;
	}
};

class BananaFactory :public Factory
{
public:
	virtual Fruit *getFruit()
	{
		return new Banana;
	}
};

int main6()
{
	//Factory *f = new Factory;
	//Fruit *fruit = NULL;

	//fruit = f->create("banana");
	//fruit->getFruit();

	//delete f;

	Factory *f = NULL;
	Fruit *fruit = NULL;

	f = new AppleFactory;
	fruit = f->getFruit();
	fruit->sayName();

	f = new BananaFactory;
	fruit = f->getFruit();
	fruit->sayName();

	delete f;
	system("pause");
	return 0;
}