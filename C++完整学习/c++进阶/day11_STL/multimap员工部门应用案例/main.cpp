#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
using namespace std;

//multimap����
//1��key���Զ�Ӧ���value ==��Ӧ�÷���
//��˾�����۲�sale��Ա���������������з���development��1����������financial��2����
//��Ա��Ϣ�У����������䣬�绰�����ʵ����
//ͨ��multimap������Ϣ�Ĳ��룬���棬��ʾ
//�ֲ�����ʾԱ����Ϣ

class Person
{
public:
	string name;
	int	   age;
	string tcl;
	double wage;
};

void mainCompany()
{
	Person p1, p2, p3, p4, p5;
	p1.name = "��";
	p1.age = 31;

	p2.name = "��";
	p2.age = 32;

	p3.name = "��";
	p3.age = 33;

	p4.name = "��";
	p4.age = 34;

	p5.name = "��";
	p5.age = 35;
	
	multimap<string, Person> map1;
	map1.insert(make_pair("sale", p1));         //sale����
	map1.insert(make_pair("sale", p2));

	map1.insert(make_pair("development", p3));  //development����
	map1.insert(make_pair("development", p4));
	
	map1.insert(make_pair("financial", p5));    //financial����
	
	for (multimap<string, Person>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
	}
	cout << "��������\n" << endl;

	int developmentNum = map1.count("development");
	cout << "development��������==>" << map1.count("development") << endl;
	multimap<string, Person>::iterator it2 = map1.find("development");
	int tag = 0;
	while (it2 != map1.end() && tag < developmentNum)
	{
		cout << it2->first << " " << it2->second.name << " " << it2->second.age << endl;
		it2++;
		tag++;
	}
}

//��ageΪ32�������޸�Ϊname32
void mainCompany2()
{
	Person p1, p2, p3, p4, p5;
	p1.name = "��";
	p1.age = 31;

	p2.name = "��";
	p2.age = 32;

	p3.name = "��";
	p3.age = 33;

	p4.name = "��";
	p4.age = 34;

	p5.name = "��";
	p5.age = 35;

	multimap<string, Person> map1;
	map1.insert(make_pair("sale", p1));         //sale����
	map1.insert(make_pair("sale", p2));

	map1.insert(make_pair("development", p3));  //development����
	map1.insert(make_pair("development", p4));

	map1.insert(make_pair("financial", p5));    //financial����


	//������ �������� �������޸�
	for (multimap<string, Person>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
		if (it->second.age == 32)
		{
			it->second.name = "name32";
		}
	}
	cout << "��������\n" << endl;

	cout << "�޸ĺ�\n";
	for (multimap<string, Person>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
	}

}

int main()
{
	//mainCompany();
	mainCompany2();
	system("pause");
	return 0;
}