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
		cout << "我是香蕉。。。。。。" << endl;
	}
};
class myApple :public myFruit
{
public:
	virtual void sayName()
	{
		cout << "我是苹果。。。。。。" << endl;
	}
};
//创建工厂类
class AbFactory
{
public:
	//抽象工厂
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

	f = new myAppleFactory;      //创建苹果工厂
	fruit = f->CreateProduct();  //生产苹果
	fruit->sayName();

	f = new myBananaFactory;
	fruit = f->CreateProduct();
	fruit->sayName();

	delete f;
	delete fruit;
	system("pause");
	return 0;
}