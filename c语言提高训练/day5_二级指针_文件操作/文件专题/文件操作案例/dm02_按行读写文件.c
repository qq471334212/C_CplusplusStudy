#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main_fputs()
{
	FILE *fp = NULL;
	//char *filename1 = "c:\\1.txt";
	char *filename2 = "E:/22.txt";    //ͳһ�õڶ�����ʽ

	char a[27] = "adsklsjdalkjdlksadlka";
	fp = fopen(filename2, "w+");    //r+�Զ�д��ʽ��,�ļ�����Ҫ���� //w+�Զ�д��ʽ��,�ļ������ڻ��½�

	if (fp == NULL)
	{
		printf("func fopen() err:\n");
		return;
	}
	printf("success open!");
	//for (int i = 0; i < strlen(a); i++)
	//{
	//	fputc(a[i], fp);
	//}
	fputs(a, fp);

	fclose(fp);
}

char * myfgets(char *myp, int max, FILE *fp)
{
	strcpy(myp, "aaaaaaaa");
	return myp;
}

void main_fgets()
{
	FILE *fp = NULL;
	//char *filename1 = "c:\\1.txt";
	char *filename2 = "E:/22.txt";    //ͳһ�õڶ�����ʽ

	char buf[1024];
	fp = fopen(filename2, "r+");    //�Զ�д��ʽ��

	if (fp == NULL)
	{
		printf("func fopen() err:\n");
		return;
	}
	printf("success open!\n");
	while (!feof(fp))    //������ϵ��ļ�������������ļ��������ط�0ֵ�����򷵻�0
	{
		//fgets��\nҲ������ÿ������Զ�����
		//�ڴ��������ڴ��׵�ַ���ڴ泤�ȶ������
		char *p = fgets(buf, 1024, fp);     //�ڴ�ռ��׵�ַbuf��1024Ϊ����ڴ棬��fpָ������ݿ������buf�ڴ�ռ��У�����buf���ڴ��׵�ַ
		if (p == NULL)                      //C�������һ���е�copy���ݵ�buf��ָ�ڴ�ռ��У������c�����ַ���
		{
			goto End;
		}

		printf("%s", buf);
	}
End:
	if (fp != NULL)       //�������رգ��ļ�
	{
		fclose(fp);
	}
	return;
}

void main02()
{
	//main_fputc();
	//main_fgetc();

	//main_fputs();
	main_fgets();

	system("pause");
	return;
}
