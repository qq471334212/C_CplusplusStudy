#include<iostream>
#include<list>
using namespace std;

//struct Teacher
//{
//	char name;
//	int age;
//	Teacher* next;
//};

//造车造完一步之后，要把任务传递到下一步
class CarHandle
{
public:
	virtual void HandleCar() = 0;
	CarHandle* setNextHandle(CarHandle * handle)
	{
		m_handle=handle;
		return m_handle;
	}
protected:
	CarHandle * m_handle;
};

class HeadCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "制造  车头" << endl;
		//制造完车头 以后 将任务传递给 下一个处理者
		if (m_handle != NULL)
		{
			m_handle->HandleCar();      //相当于链表结构的next赋值
		}
	}
};

class BodyCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "制造  车身" << endl;
		//制造完车身 以后 将任务传递给 下一个处理者
		if (m_handle != NULL)
		{
			m_handle->HandleCar();         
		}
	}
};

class TailCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "制造  车尾" << endl;
		//制造完车尾 以后 将任务传递给 下一个处理者
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};
int main212()
{
	CarHandle *headcarhandle = new HeadCarHandle;
	CarHandle *bodycarhandle = new BodyCarHandle;
	CarHandle *tailcarhandle = new TailCarHandle;

	//任务的处理关系,处理逻辑可以自定义
	headcarhandle->setNextHandle(tailcarhandle);
	tailcarhandle->setNextHandle(bodycarhandle);
	bodycarhandle->setNextHandle(NULL);

	headcarhandle->HandleCar();     //第一个工作者开始工作

	//业务逻辑在客户端实现，不属于责任链模式
	/*headcarhandle->HandleCar();
	bodycarhandle->HandleCar();
	tailcarhandle->HandleCar();*/

	delete tailcarhandle;
	delete bodycarhandle;
	delete headcarhandle;


	system("pause");
	return 0;
}