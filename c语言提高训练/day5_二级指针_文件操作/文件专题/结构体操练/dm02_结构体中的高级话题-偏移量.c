#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct AdvTeacher
{
	char name[64];   //64
	int age;         //4
	int p;           //4 
	char *pname2;
}AdvTeacher;


void main02()
{
	AdvTeacher t1;
	AdvTeacher *p1 = NULL;
	//strcpy(p1, "dddd");   //���ܸ��ڴ�0��λ�ô�����
	
	p1 - 1;   //û�в����ڴ档������cpu�м��㡣���У����붼û���⣬ָ�����һ��������������
	
	int offsize = (int)&(p1->age);    //ȡ��ַ�������ƫ������p1Ϊ0�� 0��λ�ö�Ӧ����name��64��λ�ö�Ӧage��68λ�ö�Ӧp
	printf("%d \n", offsize);

	system("pause");

	return;
}

void main()
{
	AdvTeacher t1;
	AdvTeacher *p1 = NULL;
	//strcpy(p1, "dddd");   //���ܸ��ڴ�0��λ�ô�����
	p1 = &t1; 
	printf("%d \n", p1);
	//p1 - 1;   //û�в����ڴ档������cpu�м��㡣���У����붼û���⣬ָ�����һ��������������
	//p1 - p1;

	{
		int offsize = (int)&(((AdvTeacher*)0)->age);    //��age����ڽṹ������ƫ����
		printf("%d \n", offsize);
		offsize = (int)&(p1->age);    //��t1->age�ĵ�ַ��p1 0��λ�ö�Ӧ����name��64��λ�ö�Ӧage��68λ�ö�Ӧp
		                                    //��p1��ֵΪt1�ĵ�ַ�󣬴�ʱ��ƫ����Ϊage����ʵ��ַ��������
		printf("%d \n", offsize);
	}
	system("pause");

	return;
}