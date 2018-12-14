#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Teacher
{
public:
	Teacher()
	{
		age = 32;
		strcpy(name, "");
	}
	Teacher(int age, const char *_name)
	{
		this->age = age;
		strcpy(name, _name);
	}
	void printT()
	{
		cout << "age: " << age << "  " << "name: " << name << endl;
	}
private:
	int age;
	char name[32];
};

int main31()
{
	const char* fname = "e:/2a.txt";
	ofstream fout(fname,ios::app);   //创建一个输出流,和文件建立关联
	if (!fout)
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	//写文件
	fout << "hello...111" << endl;
	fout << "hello...222" << endl;
	fout.close();           //关闭文件管道

	/*
	//读文件
	ifstream fin(fname);    //创建一个输入流,和文件建立关联
	char ch;
	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();
	*/

	system("pause");
	return 0;
}

int main32()
{
	const char* fname = "e:/2b.data";
	ofstream fout(fname, ios::binary);   //创建一个输出流,和文件建立关联,以二进制方式打开文件
	if (!fout)
	{
		cout << "打开文件失败" << endl;
		return 0;
	}

	Teacher  t1(31, "t1"), t2(32, "t2");
	fout.write((char*)&t1, sizeof(Teacher));
	fout.write((char*)&t2, sizeof(Teacher));
	fout.close();

	ifstream fin(fname, ios::binary);   //创建一个输入流,和文件建立关联,以二进制方式打开文件
	Teacher tmp;

	fin.read((char*)&tmp, sizeof(Teacher));
	tmp.printT();

	fin.read((char*)&tmp, sizeof(Teacher));
	tmp.printT();

	fin.close();

	system("pause");
	return 0;
}