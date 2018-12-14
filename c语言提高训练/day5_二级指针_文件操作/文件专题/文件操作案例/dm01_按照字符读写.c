#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main_fputc()
{
	FILE *fp = NULL;
	//char *filename1 = "c:\\1.txt";
	char *filename2 = "E:/2.txt";    //统一用第二种形式

	char a[27] = "adsklsjdalkjdlksadlka";
	fp = fopen(filename2, "r+");    //以读写方式打开

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
	char *filename2 = "E:/2.txt";    //统一用第二种形式

	char a[27] = "adsklsjdalkjdlksadlka";
	fp = fopen(filename2, "r+");    //以读写方式打开

	if (fp == NULL)
	{
		printf("func fopen() err:\n");
		return;
	}
	printf("success open!"); 
	while (!feof(fp))    //检测流上的文件结束符，如果文件结束返回非0值，否则返回0
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
