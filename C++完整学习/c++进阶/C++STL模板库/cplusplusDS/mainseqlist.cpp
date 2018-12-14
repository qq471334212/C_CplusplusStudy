#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//SeqList头文件两次编译会报错，因此引用cpp
#include"SeqList.cpp"
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};
void SeqListPlay()            //展现生命周期
{
	Teacher t1, t2, t3, tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	SeqList<Teacher> list(10);
	list.myInsert(t1, 0);     //句柄在C++中有this指针，不需要了
	list.myInsert(t2, 0);
	list.myInsert(t3, 0);

	//链表遍历
	for (int i = 0; i < list.GetLength(); i++)
	{
		list.GetNode(i, tmp);
		cout << tmp.age << endl;
	}


	//链表销毁
	//while (list.GetLength() > 0)
	//{
	//	list.DeleteNode(0, tmp);
	//	cout << tmp.age << endl;
	//}

	list.clear();
	list.myInsert(t1, 0);     //句柄在C++中有this指针，不需要了
	list.myInsert(t2, 0);
	list.myInsert(t3, 0);

	while (list.GetLength() > 0)
	{
		list.DeleteNode(0, tmp);
		cout << tmp.age << endl;
	}

}

//摸板类SeqList可以装指针，可以装老师变量
//指针形式
void SeqListPlay2()            //展现生命周期
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
	list.myInsert(p1, 0);     //句柄在C++中有this指针，不需要了
	list.myInsert(p2, 0);
	list.myInsert(p3, 0);

	//链表遍历
	for (int i = 0; i < list.GetLength(); i++)
	{
		list.GetNode(i, tmp);
		cout << tmp->age << endl;
	}

	//链表销毁
	while (list.GetLength() > 0)
	{
		list.DeleteNode(0, tmp);
		cout << tmp->age << endl;
	}

}


int main1()
{
	SeqListPlay();
	//SeqListPlay2();
	system("pause");
	return 0;
}