#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
#include"functional"
//#include<vector>
using namespace std;

void test()
{
	priority_queue<int> p1;  //Ĭ������� �� ���ֵ���ȶ���
	priority_queue<int ,vector<int>, less<int>>  p2;  //less����ǰԤ����õ�ģ��,���ֵ
	priority_queue<int, vector<int>, greater<int> >  p3;  //less����ǰԤ����õķº���,��Сֵ,greater�º�����fictionalͷ�ļ���ע��
	
	cout << "���ֵ���ȶ���" << endl;
	p1.push(33);
	p1.push(11);
	p1.push(55);
	p1.push(22);

	cout << "����ͷ��Ԫ�أ� " << p1.top() << endl;
	cout << "���д�С�� " << p1.size() << endl;

	while (p1.size() != 0)
	{
		cout << p1.top() << " ";
		p1.pop();
	}

	//������Сֵ���ȶ���
	cout << "��Сֵ���ȶ���" << endl;
	p3.push(33);
	p3.push(11);
	p3.push(55);
	p3.push(22);

	cout << "����ͷ��Ԫ�أ� " << p3.top() << endl;
	cout << "���д�С�� " << p3.size() << endl;

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

