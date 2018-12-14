#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<set>
#include<functional>
using namespace std;

//集合，元素唯一，有一定顺序。不可以直接存取，插入元素
//multiset同一元素值可以有多个，其他操作与set一样
//红黑树（平衡二叉树）
//元素顺序默认从小到大
void setInit()
{
	set<int> s;
	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();
		s.insert(tmp);
	}

	s.insert(100);
	s.insert(100);
	s.insert(100);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	while (!s.empty())
	{
		set<int>::iterator it = s.begin();
		cout << *it << " ";

		it = s.erase(s.begin());   //返回删除之后下一个位置的迭代器

	}
}

void setInit2()
{
	set<int> set1;
	set<int, less<int>> set2;

	set<int, greater<int>> set3;    //顺序从大到小
	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();
		set3.insert(tmp);
	}

	for (set<int>::iterator it = set3.begin(); it != set3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



class Student
{
public:
	Student(const char *name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}
public:
	char name[64];
	int age;
};

//仿函数，重载函数调用运算符
class FuncStudent
{
public:
	bool operator() (const Student &left, const Student &right)
	{
		if (left.age < right.age)   //从大到小
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

void setStruct()
{
	set<Student, FuncStudent> set1;
	Student s1("s1", 31);
	Student s2("s2", 22);
	Student s3("s3", 44);
	Student s4("s4", 33);

	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);

	for (set<Student, FuncStudent>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->age << " " << it->name << endl;
	}

}

//如何判断insert函数的返回值
void test1()
{
	Student s1("s1", 31);
	Student s2("s2", 22);
	Student s3("s3", 44);
	Student s4("s4", 33);
	Student s5("s5", 31);

	set<Student, FuncStudent> set1;

	pair<set<Student, FuncStudent>::iterator, bool> pair1 = set1.insert(s1);
	if (pair1.second == true)
	{
		cout << "插入s1成功" << endl;
	}
	else
	{
		cout << "插入s1失败" << endl;
	}
	pair<set<Student, FuncStudent>::iterator, bool> pair5 = set1.insert(s5);
	if (pair5.second == true)
	{
		cout << "插入s5成功" << endl;
	}
	else
	{
		cout << "插入s5失败" << endl;
	}


	set1.insert(s1);
	set1.insert(s2);


	for (set<Student, FuncStudent>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->age << " " << it->name << endl;
	}
}

void test2()
{
	set<int> set1;
	
	for (int i = 0; i < 10; i++)
	{
	
		set1.insert(i + 1);
	}

	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it0 = set1.find(5);
	cout << "it0: " << *it0 << endl;

	int num1 = set1.count(5);   //找元素5的个数
	cout << "num1: " << num1 << endl;

	set<int>::iterator it1 = set1.lower_bound(5);  //大于等于5的迭代器位置
	cout << "it1: " << *it1 << endl;

	set<int>::iterator it2 = set1.lower_bound(5);  //大于等于5的迭代器位置
	cout << "it2: " << *it2 << endl;


}

int main71()
{
	//setInit();
	//setInit2();
	//setStruct();
	//test1();
	test2();
	system("pause");
	return 0;
}
