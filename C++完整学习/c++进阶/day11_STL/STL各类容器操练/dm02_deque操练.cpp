#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<deque>
using namespace std;

void printD(deque<int> &d)
{
	/*for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}*/
	for (deque<int>::iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void dequeInit()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);

	d1.push_front(-1);
	d1.push_front(-3);
	d1.push_front(-5);

	cout << "头部元素：" << d1.front() << endl;
	cout << "尾部元素：" << d1.back()  << endl;
	printD(d1);

	//d1.pop_front();
	//d1.pop_back();
	//printD(d1);

	//查找数组下标志
	deque<int>::iterator it = find(d1.begin(), d1.end(), 3);          //find()函数返回找到该数值第一个位置的地址
	if (it != d1.end())    //找到元素
	{
		cout << "3的下标为： " << distance(d1.begin(), it) << endl;   //distance表示两个迭代器之间的距离
	}
	else
	{
		cout << "未找到为3的元素" << endl;
	}
}

int main2()
{
	dequeInit();
	system("pause");
	return 0;
}