#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

/*
1.编程实现一下数据输入/输出：
		1、以左对齐的方式输入整数，域宽12
		2、以八进制，十六进制，十进制输出/输入整数
		3、实现浮点数的指数格式和定点格式的输入/输出并指定精度
		4、把字符串读入到字符型数组变量中，从键盘输入，要求输入的串的空格也全部读入，以回车字符结束
		5、按以上流程用流成员函数和操作符各操作一遍
2.编写程序，将两个文件合并为一个文件
3.编写程序，统计一篇英文文章中单词的个数与行数
4.编写程序，将C++源程序每行前加上行号与一个空格
5.编写程序，输出ASCII码值，从20到127的ASCII码自浮标，格式为每行10个
*/

int main411()
{
	long a = 234;
	double b = 2345.67890;
	char c[100];
	cout.width(12);
	cout.fill('*');
	cout.flags(ios_base::left);      //左对齐
	cout << a << endl;

	cout.width(12);
	cout.fill('*');
	cout.flags(ios_base::right);      //左对齐
	cout << a << endl;

	cout.flags(ios::hex);
	cout << 234 << " ";
	cout.flags(ios::dec);
	cout << 234 << " ";
	cout.flags(ios::oct);
	cout << 234 << endl;

	cout.flags(ios::scientific);    //科学计数法
	cout << b << " ";
	cout.flags(ios::fixed);    //科学计数法
	cout << b << endl;
	
	cin.get(c, 99);            //可以读取空格
	cout << c << endl;

	system("pause");
	return 0;
}

int main412()
{
	long a = 234;
	double b = 2345.67890;
	//char c[100];
	cout << setfill('*');
	cout << left << setw(12) << a << endl;
	cout << right << setw(12) << a << endl;
	cout << hex << a << "  " << dec << a << "  " << oct << a << endl;
	cout << scientific << b << "  " << fixed << b << endl;

	system("pause");
	return 0;
}

int main42()
{
	int i = 1;
	char c[1000];
	ifstream ifile1("e:/1.txt");
	ifstream ifile2("e:/2.txt");
	ofstream ofile("e:/3.txt");

	while (!ifile1.eof())   //判断是否到了文件结束符
	{
		ifile1.getline(c, 999);
		ofile << c << endl;      //文件1中读出来，写入到输出文件中
	}

	while (!ifile2.eof())
	{
		ifile2.getline(c, 999);
		ofile << c << endl;      //文件1中读出来，写入到输出文件中
	}


	system("pause");
	return 0;
}

bool isalph(char c)
{
	return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}

int main43()
{
	ifstream ifile1("e:/daily.doc");
	char text[1000] = {0};
	bool inword = true;
	int rows = 0, words = 0;
	int i;
	while (!ifile1.eof())
	{
		ifile1.getline(text, 999);       //bug,读取字符串无效
		cout << text << endl;
		rows++;
		i = 0;
		while (text[i] != 0)
		{
			char ch;
			ch = text[i];
			if (!isalph(ch))
			{
				inword = false;
			}
			else if (isalph(ch) && (inword == false))
			{
				words++;
				inword = true;
			}
			i++;
		}
	}
	cout << "rows : " << rows << endl;
	cout << "words : " << words << endl;
	ifile1.close();

	system("pause");
	return 0;
}

int main44()
{
	int i = 1;
	char c[1000];
	ifstream ifile("e:/1.cpp");
	ofstream ofile("e:/2.cpp");
	while (!ifile.eof())
	{
		ofile << i++ << ": ";
		ifile.getline(c, 999);
		ofile << c << endl;
	}
	ofile.close();
	ifile.close();

	system("pause");
	return 0;
}

int main()
{
	int i = 1, j;
	for (j = 32; j < 127; j++)
	{
		cout << char(j) << " ";
		i++;
		if (i % 10 == 0)
		{
			cout << endl;
		}
	}
	system("pause");
	return 0;
}