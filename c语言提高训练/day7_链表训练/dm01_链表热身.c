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
//	Student s1;                //1.�ṹ��Ƕ�׽ṹ��
//	Student *s2;               //2.�ṹ��Ƕ�׽ṹ��ָ��
//	//Teacher t2;              //3.���ܵݹ�Ƕ���Լ����͵Ľṹ��Ԫ�أ���Ϊȷ�������ڴ�Ĵ�С�����䲻���ڴ�ռ�
//	struct Teacher  *t3;       //4.�ṹ��Ƕ��ָ���Լ����͵�ָ��,�ǿ��Ե�
//}Teacher;

//�������ͱ��ʣ��̶���С�ڴ��ı���

void main01()
{
	//Teacher t1;
	system("pause");
	return;
}