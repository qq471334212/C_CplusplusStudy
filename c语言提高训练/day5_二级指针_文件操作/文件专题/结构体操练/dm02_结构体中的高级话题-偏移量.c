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
	//strcpy(p1, "dddd");   //不能给内存0的位置存数据
	
	p1 - 1;   //没有操作内存。就是在cpu中计算。运行，编译都没问题，指针就是一个变量！！！！
	
	int offsize = (int)&(p1->age);    //取地址，求相对偏移量，p1为0， 0的位置对应的是name，64的位置对应age，68位置对应p
	printf("%d \n", offsize);

	system("pause");

	return;
}

void main()
{
	AdvTeacher t1;
	AdvTeacher *p1 = NULL;
	//strcpy(p1, "dddd");   //不能给内存0的位置存数据
	p1 = &t1; 
	printf("%d \n", p1);
	//p1 - 1;   //没有操作内存。就是在cpu中计算。运行，编译都没问题，指针就是一个变量！！！！
	//p1 - p1;

	{
		int offsize = (int)&(((AdvTeacher*)0)->age);    //求age相对于结构体的相对偏移量
		printf("%d \n", offsize);
		offsize = (int)&(p1->age);    //求t1->age的地址，p1 0的位置对应的是name，64的位置对应age，68位置对应p
		                                    //将p1赋值为t1的地址后，此时的偏移量为age的真实地址！！！！
		printf("%d \n", offsize);
	}
	system("pause");

	return;
}