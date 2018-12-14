#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
	char   name[64];
	int    id;

}Student;

//typedef struct Teacher
//{
//	char   name[64];
//	int    id;
//	char   *p;
//	char   **p2;
//	Student s1;                //1.结构体嵌套结构体
//	Student *s2;               //2.结构体嵌套结构体指针
//	//Teacher t2;              //3.不能递归嵌套自己类型的结构体元素，因为确定不了内存的大小，分配不了内存空间
//	struct Teacher  *t3;       //4.结构体嵌套指向自己类型的指针,是可以的
//}Teacher;

//数据类型本质，固定大小内存块的别名

void main01()
{
	//Teacher t1;
	system("pause");
	return;
}