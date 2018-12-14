#define _CRT_SECURE_NO_WARNINGS
#define D_SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"algorithm"
using namespace std;

//string4种初始化方式
void stringInit()
{
	string s1 = "aaaaaaa";
	string s2("bbbb");
	
	string s3 = s2;        //拷贝构造函数
	string s4(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//遍历方式
void stringBianli()
{
	string s1 = "abcdefgh";
	for (size_t i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//2.迭代器
	for (string::iterator it = s1.begin(); it < s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//at(),越界会抛出异常,而[]下标符号则是直接中断程序
	try {
		for (size_t i = 0; i < s1.length() + 3; i++)
		{
			cout << s1.at(i) << " ";
		}
	}
	catch (out_of_range)
	{
		cout << "发生异常" << endl;
	}
}

//字符指针和string类转换
void stringChar()
{
	string s1 = "aaabbbcccddd";
	printf("s1:%s\n", s1.c_str());    //c_str将string转成char * C语言格式


	//拷贝
	char buf1[128] = {0};
	s1.copy(buf1, 6, 3);             //s1的3号位置开始拷贝6个字符到buf1，不会变成C风格字符串
	cout << "buf1 :" << buf1 << endl;
}

//字符串连接
void stringCat()
{
	string s1 = "aaa";
	string s2("bbb");

	s1 = s1 + s2;
	cout << "s1 : " << s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);
	cout << "s3 : " << s3 << endl;
}

//字符串的查找和替换
void stingFindAndReplace()
{
	int cnt = 0;
	string s1 = "wbm hello wbm 111 wbm 222 wbm 333";
	//查找第一次出现wbm的数组下标
	//字符串下标也是从0开始的
	size_t index = s1.find("wbm", 0);
	cout << "index: " << index << endl;

	//统计wbm出现的次数
	//while (index != string::npos)    //npos表示-1，复数位置
	while(index<(s1.length()-3))
	{
		cout << "找到wbm的下标index: " << index << endl;
		cnt++;
		index = s1.find("wbm", index + 1);
	}
	cout << "wbm出现次数为：" << cnt << endl;

	//替换字符
    index = s1.find("wbm", 0);
	while (index<(s1.length() - 3))
	{
		s1.replace(index, 3, "WBM");
		index = s1.find("wbm", index + 1);
	}
	cout << s1 << endl;
}

//删除和插入
void stringDelAndInsert()
{
	string s1 = "hello1,hello2,hello3";
	string::iterator it = find(s1.begin(), s1.end(), 'l');
	if (it != s1.end())
	{
		s1.erase(it);
	}

	cout << "删除l之后的结果： " << s1 <<endl;
	s1.erase(s1.begin(), s1.end());
	cout << "删除全部的结果： " << s1 << "  " << "s1的长度：  " << s1.length() << endl;

	//头插
	string s2 = "BBB";
	s2.insert(0, "AAA");
	cout << "s2头部插入后结果： " << s2 << endl;
	s2.insert(s2.length(), "AAA");
	cout << "s2尾部插入后结果： " << s2 << endl;
}

//string相关算法
void stringAlgorithm()
{
	string s1 = "shdalk";
	//1.函数的入口地址 2.函数对象 3.预定义的函数对象
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << s1 << endl;

	string s2 = "SLAHDLKASHD";
	//1.函数的入口地址 2.函数对象 3.预定义的函数对象
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	cout << s2 << endl;
}


int main()
{
	//stringInit();
	//stringBianli();
	//stringChar();
	//stringCat();
	//stingFindAndReplace();
	//stringDelAndInsert();
	stringAlgorithm();
	system("pause");
	return 0;
}