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

	cout << "ͷ��Ԫ�أ�" << d1.front() << endl;
	cout << "β��Ԫ�أ�" << d1.back()  << endl;
	printD(d1);

	//d1.pop_front();
	//d1.pop_back();
	//printD(d1);

	//���������±�־
	deque<int>::iterator it = find(d1.begin(), d1.end(), 3);          //find()���������ҵ�����ֵ��һ��λ�õĵ�ַ
	if (it != d1.end())    //�ҵ�Ԫ��
	{
		cout << "3���±�Ϊ�� " << distance(d1.begin(), it) << endl;   //distance��ʾ����������֮��ľ���
	}
	else
	{
		cout << "δ�ҵ�Ϊ3��Ԫ��" << endl;
	}
}

int main2()
{
	dequeInit();
	system("pause");
	return 0;
}