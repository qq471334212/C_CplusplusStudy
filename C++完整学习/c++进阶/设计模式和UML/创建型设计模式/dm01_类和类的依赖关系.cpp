#include<iostream>
using namespace std;

//类zhangsan和类car是依赖关系
//依赖（虚线）关系就是一个类指针作另一个类成员函数参数或者返回值
class car
{
public:

};

class zhangsan
{
public:
	void Work(car *c)
	{
	
	}
	car * sailCar()
	{
	
	}
};
//关联（实线）关系，一个类是另一个类的成员变量
class advzhangsan
{
public:
	car * m_car;

};
int main1()
{
	system("pause");
	return 0;
}