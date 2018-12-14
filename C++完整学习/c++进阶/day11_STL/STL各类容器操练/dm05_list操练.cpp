#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"list"
using namespace std;

void listInit()
{
	list<int> l;
	cout << "list的大小为：" << l.size() << endl;
	//尾部插入元素
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
		//l.push_front(i + 1);
	}
	cout << "list的大小为：" << l.size() << endl;

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//list不能随机访问元素，不支持at（）以及[]下标运算符
	//支持it++，不支持it+5，由链表的特点决定
	it = l.begin();
	it++;
	it++;
	it++;

	l.insert(it, 100);  //在三号位置插入，插入后元素在原来三号位置元素之前

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
}

void listDel()
{
	list<int> l;
	cout << "list的大小为：" << l.size() << endl;
	//尾部插入元素
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
		//l.push_front(i + 1);
	}
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = l.begin();
	list<int>::iterator it1 = l.begin();

	it1++;
	it1++;
	it1++;
	list<int>::iterator it2 = l.erase(it, it1);  //删除一个区间的元素。并返回下一个元素的位置

	cout << *it2 << endl;

	l.remove(5);   //删除所有等于5的元素
	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
}

int main51()
{
	//listInit();
	listDel();
	system("pause");
	return 0;
}

