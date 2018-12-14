#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

template<typename T>
class ShowElemt
{

public:
	ShowElemt()
	{
		n = 0;
	}
	void operator()(T &t)   //���غ������ò�����
	{
		n++;
		cout << t << endl;
	}

	void printN()
	{
		cout << "n = " << n << endl;
	}
private:
	int n;
};

template<typename T>
void FuncShowElemt(T &t)
{
	cout << t << " ";
}

//��ͨ����
void FuncShowElemt2(int &t)
{
	cout << t << " ";
}


//��������Ķ��壬�����������ͨ����������
//
void test1()
{
	int a = 10;
	ShowElemt<int> s1; //����ģ�������
	s1(a);             //��������ģ���ִ�У�ָ��һ������ ===���º���

	FuncShowElemt<int>(a);
	FuncShowElemt2(a);
}

//�����������������  ��ͻ�ƺ�������  �ܱ��ֵ���״̬��Ϣ
//��������ĺô�
void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	//�൱��װ��һ�������º�������
	for_each(v1.begin(), v1.end(), ShowElemt<int>());

	//ͨ���ص�������ʵ������������ߺ�ʵ���ߵķ���
	for_each(v1.begin(), v1.end(), FuncShowElemt2);  

	ShowElemt<int> show1;

	//���������� �������� ��Ҫע�⴫��������û���Ԫ��
	//for_each�㷨�ĺ�������Ĵ���ʱֵ����
	//Ҫע�ⷵ��ֵ
	for_each(v1.begin(), v1.end(), show1);
	show1.printN();   //n����

	cout << "ͨ��for_each�ķ���ֵ�����ô���" << endl;

	show1 = for_each(v1.begin(), v1.end(), show1);;
	show1.printN();
}

template<typename T>
class IsDiv
{
public:
	IsDiv(const T &division)
	{
		this->division = division;
	}
	bool operator()(T &t)
	{
		return(t%division == 0);
	}
private:
	T division;
};

void test3()
{
	vector<int> v1;
	for (int i = 10; i < 33; i++)
	{
		v1.push_back(i);
	}
	int a = 4;
	IsDiv<int> mydiv(a);

	//find_if(v1.begin(), v1.end(), mydiv);
	vector<int>::iterator it;
	it = find_if(v1.begin(), v1.end(), mydiv);    //����ֵ
	if (it == v1.end())
	{
		cout << "������û��Ԫ�ؿ��Ա�4����" << endl;
	}
	else
	{
		cout << "��һ����4������Ԫ��Ϊ��" << *it << endl;
	}
}

//��Ԫ��������Ͷ�Ԫν��
template<typename T>
class SumAdd
{
public:
	T operator()(T &t1, T &t2)
	{
		return t1 + t2;
	}
};

void test4()
{
	vector<int> v1, v2;
	vector<int> v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
	
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
}

bool myCompared(const int &a, const int&b)
{
	   return a < b;   //��С����
}

//��Ԫν��
void test5()
{
	vector<int> v1(10);

	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % 100;
		v1[i] = tmp;
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for_each(v1.begin(), v1.end(), FuncShowElemt2);  //�ص�����
	cout << endl;

	sort(v1.begin(), v1.end(), myCompared);
	for_each(v1.begin(), v1.end(), FuncShowElemt2);  //�ص�����
	cout << endl;

}


struct CompareNoCase
{
	//ע��Ҫ�����������const������ᶪʧ��Ϣ
	//�����Ĳ�����const string���ͣ���str1_��str2_��string����
	bool operator() (const string &s1, const string &s2) const    //��const
	{
		string str1_;
		str1_.resize(s1.size());
		transform(s1.begin(), s1.end(), str1_.begin(), tolower);

		string str2_;
		str2_.resize(s2.size());
		transform(s2.begin(), s2.end(), str2_.begin(), tolower);

		return (str1_ < str2_);    //��С��������
	}
};

void test6()
{
	set<string> set1;
	set1.insert("bbbb");
	set1.insert("cccc");
	set1.insert("aaaa");

	set<string>::iterator it = set1.find("aaAa");    //Ĭ����������ִ�Сд��

	if (it == set1.end())
	{
		cout << "û�в��ҵ�Ŀ�꣡" << endl;
	}
	else
	{
		cout << "���ҵ�Ŀ�꣡" << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("bbbb");
	set2.insert("cccc");
	set2.insert("aaaa");

	set<string, CompareNoCase>::iterator it2 = set2.find("aaAa");    //�����Ԫν�ʣ������ִ�Сд��
	if (it2 == set2.end())
	{
		cout << "�����ִ�Сд, û�в��ҵ�Ŀ�꣡" << endl;
	}
	else
	{
		cout << "�����ִ�Сд, ���ҵ�Ŀ�꣡" << endl;
	}

}
int main1()
{
	//test1();    //���������������
	//test2();    //��������ĺô�����������������ֵ
	//test3();    //һԪν��
	//test4();
    //test5();    //��Ԫ�����Ͷ�Ԫν��
	test6();    //��Ԫν����set�����е�Ӧ��
	system("pause");
	return 0;
}
