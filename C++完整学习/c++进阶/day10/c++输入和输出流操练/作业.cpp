#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

/*
1.���ʵ��һ����������/�����
		1���������ķ�ʽ�������������12
		2���԰˽��ƣ�ʮ�����ƣ�ʮ�������/��������
		3��ʵ�ָ�������ָ����ʽ�Ͷ����ʽ������/�����ָ������
		4�����ַ������뵽�ַ�����������У��Ӽ������룬Ҫ������Ĵ��Ŀո�Ҳȫ�����룬�Իس��ַ�����
		5������������������Ա�����Ͳ�����������һ��
2.��д���򣬽������ļ��ϲ�Ϊһ���ļ�
3.��д����ͳ��һƪӢ�������е��ʵĸ���������
4.��д���򣬽�C++Դ����ÿ��ǰ�����к���һ���ո�
5.��д�������ASCII��ֵ����20��127��ASCII���Ը��꣬��ʽΪÿ��10��
*/

int main411()
{
	long a = 234;
	double b = 2345.67890;
	char c[100];
	cout.width(12);
	cout.fill('*');
	cout.flags(ios_base::left);      //�����
	cout << a << endl;

	cout.width(12);
	cout.fill('*');
	cout.flags(ios_base::right);      //�����
	cout << a << endl;

	cout.flags(ios::hex);
	cout << 234 << " ";
	cout.flags(ios::dec);
	cout << 234 << " ";
	cout.flags(ios::oct);
	cout << 234 << endl;

	cout.flags(ios::scientific);    //��ѧ������
	cout << b << " ";
	cout.flags(ios::fixed);    //��ѧ������
	cout << b << endl;
	
	cin.get(c, 99);            //���Զ�ȡ�ո�
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

	while (!ifile1.eof())   //�ж��Ƿ����ļ�������
	{
		ifile1.getline(c, 999);
		ofile << c << endl;      //�ļ�1�ж�������д�뵽����ļ���
	}

	while (!ifile2.eof())
	{
		ifile2.getline(c, 999);
		ofile << c << endl;      //�ļ�1�ж�������д�뵽����ļ���
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
		ifile1.getline(text, 999);       //bug,��ȡ�ַ�����Ч
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