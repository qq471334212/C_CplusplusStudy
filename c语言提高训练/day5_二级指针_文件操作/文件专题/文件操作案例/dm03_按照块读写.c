#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ֱ�Ӱ��ڴ�����д�뵽�ļ���
typedef struct Teacher
{
	char name[64];
	int age;

}Teacher;
void main_fwrite()
{
	FILE *fp = NULL;
	char * filename = "E:/3.data";
	int myN = 0;
	Teacher tArray[3];
	//�ṹ�帳ֵ
	for (int i = 0; i < 3; i++)
	{
		sprintf(tArray[i].name, "%d%d%d", i, i, i);
		tArray[i].age = i + 30;
	}
	fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		printf("�����ļ���ʧ�ܣ�\n");
		return;
	}
	for (int  i = 0; i < 3; i++)
	{
		//fwrite����������Ϊд���ٴΣ���һ������Ϊ�ڴ��Ŀ�ʼ���ڶ�������Ϊ���ȣ����ĸ�����Ϊд����ļ�
		//�ڴ�������
		//��������ֵΪʵ��д������ݿ����Ŀ
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);  //��tArray[i]���ڴ��ַ��д��ṹ���С������1�Σ�д�뵽fpָ����ļ���
	
	    //myN���������ж���û��д��
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

void main_fread()
{
	FILE *fp = NULL;
	char * filename = "E:/3.data";
	int myN = 0;
	Teacher tArray[3];
	//�ṹ�帳ֵ

	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("�����ļ���ʧ�ܣ�\n");
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		//fread����������Ϊ�����ٴΣ���һ������Ϊ�ڴ��Ŀ�ʼ���ڶ�������Ϊ���ȣ����ĸ�����Ϊ������ļ�
		//�ڴ�������
		//��������ֵΪʵ�ʶ�������ݿ����Ŀ
		myN = fread(&tArray[i], sizeof(Teacher), 1, fp);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("name:%s  ,age:%d \n", tArray[i].name, tArray[i].age);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

void main()
{
	//main_fwrite();
	main_fread();
	system("pause");
	return;
}
