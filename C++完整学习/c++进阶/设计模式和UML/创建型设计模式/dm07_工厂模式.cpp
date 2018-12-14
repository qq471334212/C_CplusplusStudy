#include<iostream>
using namespace std;

class myFruit
{
public:
	virtual void sayName() = 0;
private:

};
class myBanana :public myFruit
{
public:
	virtual void sayName()
	{
		cout << "�����㽶������������" << endl;
	}
};
class myApple :public myFruit
{
public:
	virtual void sayName()
	{
		cout << "����ƻ��������������" << endl;
	}
};
//����������
class AbFactory
{
public:
	//���󹤳�
	virtual myFruit * CreateProduct() = 0;

};

class myAppleFactory :public AbFactory
{
public:
	virtual myFruit *CreateProduct()
	{
		return new myApple;
	}
};

class myBananaFactory :public AbFactory
{
public:
	virtual myFruit *CreateProduct()
	{
		return new myBanana;
	}
};

int main7()
{

	AbFactory     *f = NULL;
	myFruit       *fruit = NULL;

	f = new myAppleFactory;      //����ƻ������
	fruit = f->CreateProduct();  //����ƻ��
	fruit->sayName();

	f = new myBananaFactory;
	fruit = f->CreateProduct();
	fruit->sayName();

	delete f;
	delete fruit;
	system("pause");
	return 0;
}