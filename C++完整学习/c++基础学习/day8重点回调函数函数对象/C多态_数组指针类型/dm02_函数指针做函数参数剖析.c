#include<stdio.h>

//��������������C++���麯����
int myadd(int a, int b)   //�����ʵ����
{
	printf("func add......\n");
	return a + b;
}

int myadd2(int a, int b)   //����2��ʵ����
{
	printf("func add2......\n");
	return a + b;
}
int myadd3(int a, int b)   //����3��ʵ����
{
	printf("func add3......\n");
	return a + b;
}
int myadd4(int a, int b)   //����4��ʵ����
{
	printf("func add4......\n");
	return a + b;
}

typedef int(*MyTypeFuncAdd)(int a, int b);

//����ָ��
//���
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c = myFuncAdd(5, 6);
	return c;
}
//int (*MyPointerFuncAdd)(int a, int b);   //����һ��ָ��ĳ������ָ��ı�����������Ϊ����
int MainOp2(int(*MyPointerFuncAdd)(int a, int b))   //���������
{
	int c = MyPointerFuncAdd(5, 6);   //��ӵ���
	return c;
}
//��ӵ���
void main()
{
	myadd(1, 2);    //ֱ�ӵ���

	MyTypeFuncAdd myFuncAdd = myadd;
	myFuncAdd(3, 4);
	
	MainOp2(myadd);
	MainOp(myadd);

	//������ʵ���ߺ���������߷ֿ�д��Ȼ��ֱ��д�鷳�����Ǻô��ǣ���
	//��MainOp���û�з����κα仯������£����԰Ѻ����Ĵ�������������������������
	MainOp(myadd2);     //���뺯������ڵ�ַ
	MainOp(myadd3);
	MainOp(myadd4);

	system("pause");
}