#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//直接把内存数据写入到文件中
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
	//结构体赋值
	for (int i = 0; i < 3; i++)
	{
		sprintf(tArray[i].name, "%d%d%d", i, i, i);
		tArray[i].age = i + 30;
	}
	fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		printf("建立文件夹失败！\n");
		return;
	}
	for (int  i = 0; i < 3; i++)
	{
		//fwrite第三个参数为写多少次，第一个参数为内存块的开始，第二个参数为长度，第四个参数为写入的文件
		//内存打包技术
		//函数返回值为实际写入的数据块的数目
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);  //从tArray[i]的内存地址，写入结构体大小的内容1次，写入到fp指向的文件中
	
	    //myN可以用来判断有没有写满
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
	//结构体赋值

	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("建立文件夹失败！\n");
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		//fread第三个参数为读多少次，第一个参数为内存块的开始，第二个参数为长度，第四个参数为毒入的文件
		//内存打包技术
		//函数返回值为实际读入的数据块的数目
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
