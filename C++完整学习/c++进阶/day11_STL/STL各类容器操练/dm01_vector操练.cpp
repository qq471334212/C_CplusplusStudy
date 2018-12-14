#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//β����Ӻ�ɾ������
void vectorTest()
{
	vector<int> v1;
	//cout << "capacity: " << v1.capacity() << endl;
	cout << "length: " << v1.size() << endl;


	v1.push_back(1);     //β�����Ԫ��
	v1.push_back(3);
	v1.push_back(5);
	cout << "length: " << v1.size() << endl;
	cout << "ͷ��Ԫ��: " << v1.front() << endl;

	//�޸�ͷ��Ԫ��
	//��������ֵ����ֵ��Ӧ������һ������
	v1.front() = 11;   
	v1.back()  = 55;

	cout << "β��Ԫ�أ�";
	while (v1.size() > 0)
	{
		cout << v1.back() << " "; //��ȡβ��Ԫ��
		v1.pop_back();            //ɾ��β��Ԫ��
		
	}

	//�޸�ͷ��Ԫ�ص�ֵ
	
}
//vector��ʼ��
void vectorTest1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1;
	vector<int> v3(v1.begin(), v1.begin() + 2);
	vector<int> v4(3, 9);
}

void printV(vector<int> &v)
{
	
	for (size_t i = 0; i < v.size(); i++)
	{
	cout << v[i] << " ";
	}
	cout << endl;
}

//vector�ı���
void vectorTest2()
{
	vector<int> v1(10);      //��ǰ���������ڴ�
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	printV(v1);
}



//������(������ֻ��/��ֻ��)
//using iterator = typename _Mybase::iterator;  
//using const_iterator = typename _Mybase::const_iterator;
//using reverse_iterator = _STD reverse_iterator<iterator>;
//using const_reverse_iterator = _STD reverse_iterator<const_iterator>;
void vectorIt()
{
	vector<int> v1(10);      //��ǰ���������ڴ�
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "�������" << endl;
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit < v1.rend(); rit++)
	{
		cout << *rit << " ";
	}
}

//ɾ������
void vectorDel()
{
	vector<int> v1(10);      //��ǰ���������ڴ�
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	//����λ��ɾ��
	v1.erase(v1.begin(), v1.begin() + 3);     //ָ������ɾ��
	printV(v1);

	v1.erase(v1.begin());                     //ָ��λ��ɾ��,Ҫʹ�õ�����ָ��λ��
	printV(v1);

	//����Ԫ��ֵ��ɾ��
	v1[3] = 5;
	printV(v1);

	for (vector<int>::iterator it = v1.begin(); it < v1.end();)
	{
		if (*it==5)
		{
			it = v1.erase(it);   //eraseɾ��ʱ���õ�����it�Զ����ƣ����ѭ���в���it++
			                     //���ص�����һ��λ�õĵ�ַ
		}
		else
		{
			it++;
		}
	}
	printV(v1);
}

//�������
void vectorInsert()
{
	vector<int> v1(5);      //��ǰ���������ڴ�
	for (int i = 0; i < 5; i++)
	{
		v1[i] = i + 1;
	}

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 100);
	printV(v1);
	cout << "������СΪ�� " << v1.capacity();
	v1.reserve(10);          //�޸�vector����������С,���ܱ�С
	printV(v1);
	cout << "������СΪ�� " << v1.capacity();
}

//vector������api
int main1()
{
	//vectorTest();
	//vectorTest1();
	//vectorTest2();
	//vectorIt();
	//vectorDel();
	vectorInsert();
	system("pause");
	return 0;
}