#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"list"
using namespace std;

void listInit()
{
	list<int> l;
	cout << "list�Ĵ�СΪ��" << l.size() << endl;
	//β������Ԫ��
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
		//l.push_front(i + 1);
	}
	cout << "list�Ĵ�СΪ��" << l.size() << endl;

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//list�����������Ԫ�أ���֧��at�����Լ�[]�±������
	//֧��it++����֧��it+5����������ص����
	it = l.begin();
	it++;
	it++;
	it++;

	l.insert(it, 100);  //������λ�ò��룬�����Ԫ����ԭ������λ��Ԫ��֮ǰ

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
}

void listDel()
{
	list<int> l;
	cout << "list�Ĵ�СΪ��" << l.size() << endl;
	//β������Ԫ��
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
	list<int>::iterator it2 = l.erase(it, it1);  //ɾ��һ�������Ԫ�ء���������һ��Ԫ�ص�λ��

	cout << *it2 << endl;

	l.remove(5);   //ɾ�����е���5��Ԫ��
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

