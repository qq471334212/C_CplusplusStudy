#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
#include"functional"
//#include<vector>
using namespace std;

void test()
{
	priority_queue<int> p1;  //默认情况下 是 最大值优先队列
	priority_queue<int ,vector<int>, less<int>>  p2;  //less是提前预定义好的模板,最大值
	priority_queue<int, vector<int>, greater<int> >  p3;  //less是提前预定义好的仿函数,最小值,greater仿函数在fictional头文件中注意
	
	cout << "最大值优先队列" << endl;
	p1.push(33);
	p1.push(11);
	p1.push(55);
	p1.push(22);

	cout << "队列头部元素： " << p1.top() << endl;
	cout << "队列大小： " << p1.size() << endl;

	while (p1.size() != 0)
	{
		cout << p1.top() << " ";
		p1.pop();
	}

	//测试最小值优先队列
	cout << "最小值优先队列" << endl;
	p3.push(33);
	p3.push(11);
	p3.push(55);
	p3.push(22);

	cout << "队列头部元素： " << p3.top() << endl;
	cout << "队列大小： " << p3.size() << endl;

	while (p3.size() != 0)
	{
		cout << p3.top() << " ";
		p3.pop();
	}
}

int main61()
{
	test();
	system("pause");
	return 0;
}

