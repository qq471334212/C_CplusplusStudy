#include<iostream>
#include<string>
#include<list>
using namespace std;

typedef int Object;    //int类型数据
#define SIZE 5
//MyIterator  Aggregate  ContreteIterator  concreteAggregate

// a  b  c   d
//   △                 //迭代器指针

//迭代器抽象层
class MyIterator
{
public:
	virtual void First() = 0;   //让迭代器指针返回初始位置
	virtual void Next() = 0;    //迭代器向后移动
	virtual bool IsDone() = 0;  //迭代器是否到尾部
	virtual Object CurrentItem() = 0;
private:
};


class Aggregate
{
public:
	virtual MyIterator* CreateIterator() = 0;   //创建迭代器，并把自身传给迭代器
	virtual Object getItem(int index) = 0;
	virtual int getSize() = 0;

};


class ContreteIterator:public MyIterator
{
public:
	ContreteIterator(Aggregate *ag)
	{
		currentIndex = 0;
		this->ag = ag;
	}
	virtual void First()
	{
		currentIndex = 0;
	}
	virtual void Next()
	{
		if (currentIndex < ag->getSize())
		{
			currentIndex++;
		}
	}
	virtual bool IsDone()
	{
		return (currentIndex == ag->getSize());
	}
	virtual Object CurrentItem()
	{
		return ag->getItem(currentIndex);
	}
private:
	int			currentIndex;    //当前迭代器数组下标位置
	Aggregate	*ag;			 //指向容器的指针
};

class ConcreteAggregate :public Aggregate
{
public:
	ConcreteAggregate()
	{
		for (int i = 0; i < SIZE; i++)
		{
			object[i] = i + 10;
		}
	}
	virtual MyIterator* CreateIterator()       //创建时候，让迭代器持有 一个 集合的 指针
	{
		return new ContreteIterator(this);
	}
	virtual Object getItem(int index)
	{
		return object[index];
	}
	virtual int getSize()
	{
		return SIZE;
	}
private:
	Object object[SIZE];
};

int main()
{
	Aggregate	*ag = NULL;
	MyIterator	*it = NULL;

	ag = new ConcreteAggregate;
	it = ag->CreateIterator();     //创建一个迭代器

	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << endl;
	}

	delete it;
	delete ag;

	system("pause");
	return 0;
}