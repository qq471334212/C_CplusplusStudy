#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"vector"      //vector����
#include"algorithm"   //�㷨
using namespace std;

//����װ��������
void test()
{
	vector<int> v1;          //�����ĸ���

	v1.push_back(1);         //���ݸ��ƽ�ȥ
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(-1);

	vector<int>::iterator it = v1.begin();   //�������ĸ���൱��һ��ָ��
	for (it; it < v1.end(); it++)   
	{
		cout << *it << endl;
	}

	//�㷨�͵����������޷�����
	int num1 = count(v1.begin(), v1.end(), 3);    //ͳ��Ԫ��ʱ3�ĸ����м���
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

//����װ����Ԫ��
void test1()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	vector<Teacher> v1;          //�����ĸ���

	v1.push_back(t1);         //���ݸ��ƽ�ȥ
	v1.push_back(t2);
	v1.push_back(t3);

	vector<Teacher>::iterator it = v1.begin();   //�������ĸ���൱��һ��ָ��
	for (it; it < v1.end(); it++)
	{
		(*it).printT();
	}

	/*
	//�㷨�͵����������޷�����
	int num1 = count(v1.begin(), v1.end(), 3);    //ͳ��Ԫ��ʱ3�ĸ����м���
	cout << "num1: " << num1 << endl;
	*/
}

//����װ����ָ��
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
	vector<Teacher*> v1;          //�����ĸ���

	v1.push_back(p1);         //���ƶ����ַ��ȥ
	v1.push_back(p2);
	v1.push_back(p3);

	vector<Teacher*>::iterator it = v1.begin();   //�������ĸ���൱��һ��ָ�룬���Ա�������
	for (it; it < v1.end(); it++)
	{
		(*it)->printT();
	}

	/*
	//�㷨�͵����������޷�����
	int num1 = count(v1.begin(), v1.end(), 3);    //ͳ��Ԫ��ʱ3�ĸ����м���
	cout << "num1: " << num1 << endl;
	*/

	//���⣺�����������  ��ʦ�ڵ�� �������33 �ĸ���
}
int main11()
{
	//test();
	//test1();
	test2();
	system("pause");
	return 0;
}