#include<iostream>
#include<string>
#include<algorithm>  //STL�㷨��ͷ�ļ�

#include <functional>//STL�º�����ͷ�ļ�
using namespace std;

void FunIterator()
{
	string str("abcdefg");
	string::iterator ite;      //����һ�������ĵ�����

	//char *a = str.c_str();
	ite = str.begin();       //begin��������str�׵�ַ
	//ite = str.end();

	//for (size_t i = 0; i < str.size(); i++)   //size_t��ʾunsigned int����
	//{
	//	cout << *ite << " ";
	//	ite++;
	//}

	//for (ite; ite!= str.end(); ite++)  //str.end()���ص���str��β��ַ�ĺ�һλ
	//{
	//	*ite = 'a';
	//	//cout << *ite << " ";
	//}
	str.append(18, 'a');
	ite = str.begin();
	ite[3] = 'w';
	cout << str;

	//for (size_t i = 0; i < str.size(); i++)   //size_t��ʾunsigned int����
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
	//sort(str.begin(), str.end());   //��С����
	sort(str.begin(), str.end(),greater<char>());  //�Ӵ�С���º���������
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