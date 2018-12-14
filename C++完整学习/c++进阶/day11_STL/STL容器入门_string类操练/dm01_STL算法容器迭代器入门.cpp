#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"vector"      //vector容器
#include"algorithm"   //算法
using namespace std;

//容器装基础类型
void test()
{
	vector<int> v1;          //容器的概念

	v1.push_back(1);         //数据复制进去
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(-1);

	vector<int>::iterator it = v1.begin();   //迭代器的概念，相当于一个指针
	for (it; it < v1.end(); it++)   
	{
		cout << *it << endl;
	}

	//算法和迭代器进行无缝连接
	int num1 = count(v1.begin(), v1.end(), 3);    //统计元素时3的个数有几个
	cout << "num1: " << num1 << endl;
}

class Teacher 
{
public:
	int age;
	char name[64];

	void printT()
	{
		cout << "age: " << age << endl;
	}
};

//容器装对象元素
void test1()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	vector<Teacher> v1;          //容器的概念

	v1.push_back(t1);         //数据复制进去
	v1.push_back(t2);
	v1.push_back(t3);

	vector<Teacher>::iterator it = v1.begin();   //迭代器的概念，相当于一个指针
	for (it; it < v1.end(); it++)
	{
		(*it).printT();
	}

	/*
	//算法和迭代器进行无缝连接
	int num1 = count(v1.begin(), v1.end(), 3);    //统计元素时3的个数有几个
	cout << "num1: " << num1 << endl;
	*/
}

//容器装对象指针
void test2()
{
	Teacher *p1, *p2, *p3;
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	vector<Teacher*> v1;          //容器的概念

	v1.push_back(p1);         //复制对象地址进去
	v1.push_back(p2);
	v1.push_back(p3);

	vector<Teacher*>::iterator it = v1.begin();   //迭代器的概念，相当于一个指针，可以遍历容器
	for (it; it < v1.end(); it++)
	{
		(*it)->printT();
	}

	/*
	//算法和迭代器进行无缝连接
	int num1 = count(v1.begin(), v1.end(), 3);    //统计元素时3的个数有几个
	cout << "num1: " << num1 << endl;
	*/

	//问题：如何求容器中  老师节点的 年龄等于33 的个数
}
int main11()
{
	//test();
	//test1();
	test2();
	system("pause");
	return 0;
}