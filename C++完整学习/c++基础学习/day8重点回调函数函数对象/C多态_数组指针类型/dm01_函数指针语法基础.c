#include<stdio.h>

//�������ͻ����﷨����
//����һ����������
//int a[10];

//����һ��ָ����������

//����һ��ָ�� �������͵�ָ�� ��������ָ��

void main1()
{
	int a[10];    //a������������׸�Ԫ�صĵ�ַ��&a���������������ĵ�ַ��a+1��&a+1�Ĳ������ܲ�һ��
	              //�˴�a+1����4����int�����ڴ泤�ȣ�&a+1����40

	{
		//����һ����������
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;

	}

	{
	  //����һ��ָ����������
		typedef int(*PTypeArray)[10];
		PTypeArray myPArray;  //sizeof(int) *10 ����Ϊ40
		myPArray = &a;
		(*myPArray)[0] = 20;
		printf("a[0]:%d \n", a[0]);
	}

	{ 
	 //����һ��ָ�� �������͵�ָ��
		int(*myPointer)[10];   //��һ������,�����ڴ�
		myPointer = &a;
		(*myPointer)[0] = 40;
		printf("a[0]:%d \n", a[0]);
	}
	system("pause");
	return;
}


//����ָ��֪ʶ����

//��ζ���һ����������

//��ζ���һ������ָ������

//��ζ���һ������ָ�� ��ָ��һ����������ڵ�ַ��

int add(int a, int b)
{
	printf("func add......\n");
	return a + b;
}

void main2()
{
	add(1, 2);    //ֱ�ӵ���  //���������Ǻ�������ڵ�ַ
	
	//����һ����������
	{
		typedef int(MyFuncType)(int a, int b);  //������һ������
		MyFuncType *myPointerFunc = NULL;       //������һ��ָ�룬ָ��ĳһ����ĺ���
		myPointerFunc = &add;
		myPointerFunc(3, 4);     //��ӵ���

		myPointerFunc = add;  //Ҳ�ɹ���C�����ƣ�������ʷ�汾
	}

	{
	//����һ������ָ������
		typedef int(*myPointerFuncType)(int a, int b);   //int *a=NULL;
		myPointerFuncType myPointerFunc;   //����һ��ָ��
		myPointerFunc = add;
		myPointerFunc(5, 6);
	}

	//����ָ��
	{
		int(*myPointerFunc)(int a, int b);   //������һ������
		myPointerFunc = add;
		myPointerFunc(7, 8);
	}
	system("pause");
}