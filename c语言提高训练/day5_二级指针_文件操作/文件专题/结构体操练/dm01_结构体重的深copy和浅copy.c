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

//ǳ����
//�������ĵȺŲ�����ֻ���ָ�������ֵ����from copy��to���������ָ�������ָ���ڴ�ռ�copy��ȥ

//�ṹ������һ�� 1��ָ����� 2��ָ��

//�����ִ��һ����copy������ʾ�ķ����ڴ棡������
void copyTeacher(Teacher *to, Teacher *from)
{
	*to = *from;
	//memcpy(to, from, sizeof(Teacher));
	//��� ����������
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