#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<functional>
using namespace std;

//map元素的添加/遍历/删除等基本操作
void mapInit()
{
	map<int, string> map1;

	//插入方法1
	map1.insert(pair<int, string>(1, "teacher1"));
	map1.insert(pair<int, string>(2, "teacher2"));

	//插入方法2
	map1.insert(make_pair(3, "teacher3"));

	//插入方法3
	map1.insert(map<int, string>::value_type(4, "teacher4"));

	//插入方法4
	map1[5] = "teacher5";          //类似数组

	//map遍历
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << " " << it->second << endl;
		map1.erase(it);         //erase删除该位置迭代器后自动+1
	}
}

//插入的四种方法
//前三种返回的是pair<T1,T2>类型
//第四种插入，若key已经存在，则对元素进行修改
void mapTest()
{
	map<int, string> map1;

	//插入方法1
	pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "teacher1"));
	map1.insert(pair<int, string>(2, "teacher2"));

	//插入方法2
	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "teacher3"));

	//插入方法3
	pair<map<int, string>::iterator, bool> mypair4 = map1.insert(map<int, string>::value_type(4, "teacher4"));
	if (mypair4.second == true)
	{
		cout << mypair4.first->first << "  " << mypair4.first->second << endl;
	}
	else
	{
		cout << "key4插入失败" << endl;
	}
	pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>::value_type(4, "teacher4"));
	if (mypair5.second == true)
	{
		cout << mypair5.first->first << "  " << mypair5.first->second << endl;
	}
	else
	{
		cout << "key4插入失败" << endl;
	}

	//插入方法4
	map1[5] = "teacher51";          //类似数组
	map1[5] = "teacher52";          //对key为5的进行值修改
	map1[6] = "teacher6";

								   //map遍历
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	//查找
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << it2->first << " " << it2->second << endl;
	}

	//equal_range
	//返回两个迭代器，形成pair
	//第一个迭代器是>=5的位置
	//第二个迭代器是 =5的位置
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5); 
	
	if (mypair.first == map1.end())
	{
		cout << "第一个迭代器>=5 的位置不存在" << endl;
	}
	else
	{
		cout << mypair.first->first << " " << mypair.first->second << endl;
	}

	if (mypair.second == map1.end())
	{
		cout << "第二个迭代器>5 的位置不存在" << endl;
	}
	else
	{
		cout << mypair.second->first << " " << mypair.second->second << endl;
	}
}



int main81()
{
	//mapInit();
	mapTest();
	system("pause");
	return 0;
}