#include<iostream>
#include<string>
#include<algorithm>  //STL算法的头文件

#include <functional>//STL仿函数的头文件
using namespace std;

void FunIterator()
{
	string str("abcdefg");
	string::iterator ite;      //定义一个容器的迭代器

	//char *a = str.c_str();
	ite = str.begin();       //begin（）返回str首地址
	//ite = str.end();

	//for (size_t i = 0; i < str.size(); i++)   //size_t表示unsigned int类型
	//{
	//	cout << *ite << " ";
	//	ite++;
	//}

	//for (ite; ite!= str.end(); ite++)  //str.end()返回的是str的尾地址的后一位
	//{
	//	*ite = 'a';
	//	//cout << *ite << " ";
	//}
	str.append(18, 'a');
	ite = str.begin();
	ite[3] = 'w';
	cout << str;

	//for (size_t i = 0; i < str.size(); i++)   //size_t表示unsigned int类型
	//{
	//	cout << ite[i] << " ";
	//}

}

void testIterator()
{
	string str("abc");
	string str1("egf");
	//str.append(str1.begin(), str1.begin() + 3);
	str.append(str1.begin(), str1.end());
	cout << str << endl;
	str.erase(str.begin());
	cout << str << endl;
	str.insert(str.begin() + 2, 3, 'Y');
	cout << str << endl;
	str.insert(str.begin() + 2, str1.begin(), str1.end());
	cout << str << endl;
}

void fun(char c)
{
	cout << c;
}
void FunFor()
{
	string str("adhlakhds");
	//for_each(str.begin(), str.end(), fun);
	//sort(str.begin(), str.end());   //从小到大
	sort(str.begin(), str.end(),greater<char>());  //从大到小，仿函数不常用
	cout << str << endl;
	for_each(str.begin(), str.end(),fun);
}
int main()
{
	//FunIterator();
	//testIterator();
	FunFor();
	system("pause");
	return 0;
}