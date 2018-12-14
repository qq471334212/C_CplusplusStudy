#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main_fputs()
{
	FILE *fp = NULL;
	//char *filename1 = "c:\\1.txt";
	char *filename2 = "E:/22.txt";    //统一用第二种形式

	char a[27] = "adsklsjdalkjdlksadlka";
	fp = fopen(filename2, "w+");    //r+以读写方式打开,文件必须要存在 //w+以读写方式打开,文件不存在会新建

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
	char *filename2 = "E:/22.txt";    //统一用第二种形式

	char buf[1024];
	fp = fopen(filename2, "r+");    //以读写方式打开

	if (fp == NULL)
	{
		printf("func fopen() err:\n");
		return;
	}
	printf("success open!\n");
	while (!feof(fp))    //检测流上的文件结束符，如果文件结束返回非0值，否则返回0
	{
		//fgets把\n也拷贝到每行最后。自动换行
		//内存打包（把内存首地址和内存长度都打包）
		char *p = fgets(buf, 1024, fp);     //内存空间首地址buf，1024为最大内存，把fp指向的数据拷到这个buf内存空间中，返回buf的内存首地址
		if (p == NULL)                      //C函数库会一行行的copy数据到buf所指内存空间中，并变成c风格的字符串
		{
			goto End;
		}

		printf("%s", buf);
	}
End:
	if (fp != NULL)       //析构（关闭）文件
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
