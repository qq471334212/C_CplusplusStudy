#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//SeqListͷ�ļ����α���ᱨ���������cpp
#include"SeqList.cpp"
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};
void SeqListPlay()            //չ����������
{
	Teacher t1, t2, t3, tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	SeqList<Teacher> list(10);
	list.myInsert(t1, 0);     //�����C++����thisָ�룬����Ҫ��
	list.myInsert(t2, 0);
	list.myInsert(t3, 0);

	//�������
	for (int i = 0; i < list.GetLength(); i++)
	{
		list.GetNode(i, tmp);
		cout << tmp.age << endl;
	}

	//��������
	while (list.GetLength() > 0)
	{
		list.DeleteNode(0, tmp);
		cout << tmp.age << endl;
	}

}

//������SeqList����װָ�룬����װ��ʦ����
//ָ����ʽ
void SeqListPlay2()            //չ����������
{
	Teacher *tmp;
	Teacher t1, t2, t3;
	Teacher *p1, *p2, *p3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	SeqList<Teacher *> list(10);
	list.myInsert(p1, 0);     //�����C++����thisָ�룬����Ҫ��
	list.myInsert(p2, 0);
	list.myInsert(p3, 0);

	//�������
	for (int i = 0; i < list.GetLength(); i++)
	{
		list.GetNode(i, tmp);
		cout << tmp->age << endl;
	}

	//��������
	while (list.GetLength() > 0)
	{
		list.DeleteNode(0, tmp);
		cout << tmp->age << endl;
	}

}


int main()
{
	//SeqListPlay();
	SeqListPlay2();
	system("pause");
	return 0;
}