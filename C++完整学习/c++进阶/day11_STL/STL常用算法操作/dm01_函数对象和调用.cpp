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
	void operator()(T &t)   //重载函数调用操作符
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

//普通函数
void FuncShowElemt2(int &t)
{
	cout << t << " ";
}


//函数对象的定义，函数对象和普通函数的区别
//
void test1()
{
	int a = 10;
	ShowElemt<int> s1; //函数模板对象定义
	s1(a);             //函数对象的（）执行，指向一个函数 ===》仿函数

	FuncShowElemt<int>(a);
	FuncShowElemt2(a);
}

//函数对象属于类对象  能突破函数概念  能保持调用状态信息
//函数对象的好处
void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	//相当于装入一个匿名仿函数对象
	for_each(v1.begin(), v1.end(), ShowElemt<int>());

	//通过回调函数，实现了任务调用者和实现者的分离
	for_each(v1.begin(), v1.end(), FuncShowElemt2);  

	ShowElemt<int> show1;

	//函数对象作 函数参数 ，要注意传入的是引用还是元素
	//for_each算法的函数对象的传递时值传递
	//要注意返回值
	for_each(v1.begin(), v1.end(), show1);
	show1.printN();   //n不变

	cout << "通过for_each的返回值看调用次数" << endl;

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
	it = find_if(v1.begin(), v1.end(), mydiv);    //返回值
	if (it == v1.end())
	{
		cout << "容器中没有元素可以被4整除" << endl;
	}
	else
	{
		cout << "第一个被4整除的元素为：" << *it << endl;
	}
}

//二元函数对象和二元谓词
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
	   return a < b;   //从小到大
}

//二元谓词
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

	for_each(v1.begin(), v1.end(), FuncShowElemt2);  //回调函数
	cout << endl;

	sort(v1.begin(), v1.end(), myCompared);
	for_each(v1.begin(), v1.end(), FuncShowElemt2);  //回调函数
	cout << endl;

}


struct CompareNoCase
{
	//注意要给函数体加上const，否则会丢失信息
	//传进的参数是const string类型，而str1_和str2_是string类型
	bool operator() (const string &s1, const string &s2) const    //加const
	{
		string str1_;
		str1_.resize(s1.size());
		transform(s1.begin(), s1.end(), str1_.begin(), tolower);

		string str2_;
		str2_.resize(s2.size());
		transform(s2.begin(), s2.end(), str2_.begin(), tolower);

		return (str1_ < str2_);    //从小到大排序
	}
};

void test6()
{
	set<string> set1;
	set1.insert("bbbb");
	set1.insert("cccc");
	set1.insert("aaaa");

	set<string>::iterator it = set1.find("aaAa");    //默认情况下区分大小写的

	if (it == set1.end())
	{
		cout << "没有查找到目标！" << endl;
	}
	else
	{
		cout << "查找到目标！" << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("bbbb");
	set2.insert("cccc");
	set2.insert("aaaa");

	set<string, CompareNoCase>::iterator it2 = set2.find("aaAa");    //加入二元谓词，不区分大小写的
	if (it2 == set2.end())
	{
		cout << "不区分大小写, 没有查找到目标！" << endl;
	}
	else
	{
		cout << "不区分大小写, 查找到目标！" << endl;
	}

}
int main1()
{
	//test1();    //函数对象基本概念
	//test2();    //函数对象的好处，函数对象做返回值
	//test3();    //一元谓词
	//test4();
    //test5();    //二元函数和二元谓词
	test6();    //二元谓词在set集合中的应用
	system("pause");
	return 0;
}
