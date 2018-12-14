#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char *name2;
}Teacher;

//浅拷贝
//编译器的等号操作。只会把指针变量的值，从from copy到to，但不会把指针变量所指的内存空间copy过去

//结构体中淘一个 1级指针或者 2级指针

//如果想执行一个深copy，在显示的分配内存！！！！
void copyTeacher(Teacher *to, Teacher *from)
{
	*to = *from;
	//memcpy(to, from, sizeof(Teacher));
	//深拷贝 ，不仅拷贝
	to->name2 = (char *)malloc(100);
	strcpy(to->name2, from->name2);
}

void main01()
{
	Teacher t1;
	Teacher t2;

	strcpy(t1.name, "name1");
	t1.name2 = (char *)malloc(100);
	strcpy(t1.name2, "ssss");

	copyTeacher(&t2, &t1);

	if (t1.name2 != NULL)
	{
		free(t1.name2);
		t1.name2 = NULL;
	}

	if (t2.name2 != NULL)
	{
		free(t1.name2);
		t2.name2 = NULL;
	}
	system("pause");
	return;
}