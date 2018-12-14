#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//尾部添加和删除操作
void vectorTest()
{
	vector<int> v1;
	//cout << "capacity: " << v1.capacity() << endl;
	cout << "length: " << v1.size() << endl;


	v1.push_back(1);     //尾部添加元素
	v1.push_back(3);
	v1.push_back(5);
	cout << "length: " << v1.size() << endl;
	cout << "头部元素: " << v1.front() << endl;

	//修改头部元素
	//函数返回值当左值，应当返回一个引用
	v1.front() = 11;   
	v1.back()  = 55;

	cout << "尾部元素：";
	while (v1.size() > 0)
	{
		cout << v1.back() << " "; //获取尾部元素
		v1.pop_back();            //删除尾部元素
		
	}

	//修改头部元素的值
	
}
//vector初始化
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

//vector的遍历
void vectorTest2()
{
	vector<int> v1(10);      //提前分配容量内存
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	printV(v1);
}



//迭代器(正向反向，只读/非只读)
//using iterator = typename _Mybase::iterator;  
//using const_iterator = typename _Mybase::const_iterator;
//using reverse_iterator = _STD reverse_iterator<iterator>;
//using const_reverse_iterator = _STD reverse_iterator<const_iterator>;
void vectorIt()
{
	vector<int> v1(10);      //提前分配容量内存
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "反向遍历" << endl;
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit < v1.rend(); rit++)
	{
		cout << *rit << " ";
	}
}

//删除操作
void vectorDel()
{
	vector<int> v1(10);      //提前分配容量内存
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	//根据位置删除
	v1.erase(v1.begin(), v1.begin() + 3);     //指定区间删除
	printV(v1);

	v1.erase(v1.begin());                     //指定位置删除,要使用迭代器指定位置
	printV(v1);

	//根据元素值来删除
	v1[3] = 5;
	printV(v1);

	for (vector<int>::iterator it = v1.begin(); it < v1.end();)
	{
		if (*it==5)
		{
			it = v1.erase(it);   //erase删除时会让迭代器it自动下移，因此循环中不用it++
			                     //返回的是下一个位置的地址
		}
		else
		{
			it++;
		}
	}
	printV(v1);
}

//插入操作
void vectorInsert()
{
	vector<int> v1(5);      //提前分配容量内存
	for (int i = 0; i < 5; i++)
	{
		v1[i] = i + 1;
	}

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 100);
	printV(v1);
	cout << "容量大小为： " << v1.capacity();
	v1.reserve(10);          //修改vector容器容量大小,不能变小
	printV(v1);
	cout << "容量大小为： " << v1.capacity();
}

//vector容器的api
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