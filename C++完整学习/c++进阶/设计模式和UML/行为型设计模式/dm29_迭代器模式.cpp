#include<iostream>
#include<string>
#include<list>
using namespace std;

typedef int Object;    //int��������
#define SIZE 5
//MyIterator  Aggregate  ContreteIterator  concreteAggregate

// a  b  c   d
//   ��                 //������ָ��

//�����������
class MyIterator
{
public:
	virtual void First() = 0;   //�õ�����ָ�뷵�س�ʼλ��
	virtual void Next() = 0;    //����������ƶ�
	virtual bool IsDone() = 0;  //�������Ƿ�β��
	virtual Object CurrentItem() = 0;
private:
};


class Aggregate
{
public:
	virtual MyIterator* CreateIterator() = 0;   //����������������������������
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
	int			currentIndex;    //��ǰ�����������±�λ��
	Aggregate	*ag;			 //ָ��������ָ��
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
	virtual MyIterator* CreateIterator()       //����ʱ���õ��������� һ�� ���ϵ� ָ��
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
	it = ag->CreateIterator();     //����һ��������

	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << endl;
	}

	delete it;
	delete ag;

	system("pause");
	return 0;
}