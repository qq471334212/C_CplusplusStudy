#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main_fputc()
{
	FILE *fp = NULL;
	//char *filename1 = "c:\\1.txt";
	char *filename2 = "E:/2.txt";    //ͳһ�õڶ�����ʽ

	char a[27] = "adsklsjdalkjdlksadlka";
	fp = fopen(filename2, "r+");    //�Զ�д��ʽ��

	if (fp == NULL)
	{
		printf("func fopen() err:\n");
		return;
	}
	printf("success open!");
	for (int i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	fclose(fp);
}

void main_fgetc()
{
	FILE *fp = NULL;
	//char *filename1 = "c:\\1.txt";
	char *filename2 = "E:/2.txt";    //ͳһ�õڶ�����ʽ

	char a[27] = "adsklsjdalkjdlksadlka";
	fp = fopen(filename2, "r+");    //�Զ�д��ʽ��

	if (fp == NULL)
	{
		printf("func fopen() err:\n");
		return;
	}
	printf("success open!"); 
	while (!feof(fp))    //������ϵ��ļ�������������ļ��������ط�0ֵ�����򷵻�0
	{
		char tmp = fgetc(fp);
		printf("%c", tmp);
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
	return;
}

void main1()
{
	//main_fputc();
	main_fgetc();
	system("pause");
	return;
}
