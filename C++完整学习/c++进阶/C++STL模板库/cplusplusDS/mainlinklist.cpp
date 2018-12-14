#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include "LinkList.cpp"
using namespace std;

struct Teacher1
{
	char name[64];
	int age;
};

void main_linklist_play1()
{
	Teacher1 t1, t2, t3, tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	LinkList<Teacher1>  list;
	
	list.Insert(t1, 0);     //�����C++����thisָ�룬����Ҫ��
	list.Insert(t2, 0);
	list.Insert(t3, 0);

	//�������
	for (int i = 0; i < list.getlen(); i++)
	{
		list.Get(i, tmp);
		cout << tmp.age << endl;
	}

	list.clear();

	//list.Insert(t1, 0);     //�����C++����thisָ�룬����Ҫ��
	//list.Insert(t2, 0);
	//list.Insert(t3, 0);

	//��������
	while (list.getlen() > 0)
	{
		list.Del(0, tmp);
		cout << tmp.age << endl;
	}
}

//����ʦԪ��
void main_linklist_play2()
{
	Teacher1 *p1, *p2, *p3, *tmp;
	Teacher1 t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	LinkList<Teacher1 *>  list;

	list.Insert(p1, 0);     //�����C++����thisָ�룬����Ҫ��
	list.Insert(p2, 0);
	list.Insert(p3, 0);

	//�������
	for (int i = 0; i < list.getlen(); i++)
	{
		list.Get(i, tmp);
		cout << tmp->age << endl;
	}

	list.clear();

	list.Insert(p1, 0);     //�����C++����thisָ�룬����Ҫ��
	list.Insert(p2, 0);
	list.Insert(p3, 0);

	//��������
	while (list.getlen() > 0)
	{
		list.Del(0, tmp);
		cout << tmp->age << endl;
	}
}

int main()
{
	//main_linklist_play1();
	main_linklist_play2();
	system("pause");
	return 0;
}