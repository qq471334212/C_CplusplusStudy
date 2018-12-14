#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
using namespace std;

//multimap案例
//1个key可以对应多个value ==》应用分组
//公司有销售部sale（员工两名），技术研发部development（1名），财务部financial（2名）
//人员信息有：姓名，年龄，电话，工资等组成
//通过multimap进行信息的插入，保存，显示
//分部门显示员工信息

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
	p1.name = "王";
	p1.age = 31;

	p2.name = "刘";
	p2.age = 32;

	p3.name = "李";
	p3.age = 33;

	p4.name = "杨";
	p4.age = 34;

	p5.name = "张";
	p5.age = 35;
	
	multimap<string, Person> map1;
	map1.insert(make_pair("sale", p1));         //sale部门
	map1.insert(make_pair("sale", p2));

	map1.insert(make_pair("development", p3));  //development部门
	map1.insert(make_pair("development", p4));
	
	map1.insert(make_pair("financial", p5));    //financial部门
	
	for (multimap<string, Person>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
	}
	cout << "遍历结束\n" << endl;

	int developmentNum = map1.count("development");
	cout << "development部门人数==>" << map1.count("development") << endl;
	multimap<string, Person>::iterator it2 = map1.find("development");
	int tag = 0;
	while (it2 != map1.end() && tag < developmentNum)
	{
		cout << it2->first << " " << it2->second.name << " " << it2->second.age << endl;
		it2++;
		tag++;
	}
}

//把age为32的名字修改为name32
void mainCompany2()
{
	Person p1, p2, p3, p4, p5;
	p1.name = "王";
	p1.age = 31;

	p2.name = "刘";
	p2.age = 32;

	p3.name = "李";
	p3.age = 33;

	p4.name = "杨";
	p4.age = 34;

	p5.name = "张";
	p5.age = 35;

	multimap<string, Person> map1;
	map1.insert(make_pair("sale", p1));         //sale部门
	map1.insert(make_pair("sale", p2));

	map1.insert(make_pair("development", p3));  //development部门
	map1.insert(make_pair("development", p4));

	map1.insert(make_pair("financial", p5));    //financial部门


	//按条件 检索数据 并进行修改
	for (multimap<string, Person>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
		if (it->second.age == 32)
		{
			it->second.name = "name32";
		}
	}
	cout << "遍历结束\n" << endl;

	cout << "修改后\n";
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