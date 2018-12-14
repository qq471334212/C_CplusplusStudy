#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
����ģ�岻�����Զ�����ת��
��ͨ�����ܹ������Զ�����ת��
*/

/*
	1.����ģ���������ͨ����һ��������
	2.C++���������ȿ�����ͨ����
	3.�������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��
	4.����ͨ����ģ������б���﷨�޶�������ͨ��ģ��ƥ��
*/
int Max(int a, int b)
{
	cout << "int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b)
{
	cout << "T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

/*
����ģ����ƣ�
			�����������ǰѺ���ģ�崦��ɿ��Դ����κ����͵ĺ���
			���Ǵ������ǳ���Ա����˹������Ӻ���ģ��ͨ���������Ͳ�����ͬ�ĺ���
			�������������Ժ���ģ����ж��α���
			��һ���������ĵط���ģ����뱾����б���
			�ڶ����ڵ��õĵط��Բ����滻��Ĵ�����б���
*/
template <typename T>
T Max(T a, T b, T c)
{
	cout << "T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);
}

int main()
{
	int a = 1;
	int b = 2;
	cout << Max(a, b) << endl;            //��ģ�庯������ͨ���������ϵ���ʱ������ѡ����ͨ����
	cout << Max<>(a, b) << endl;          //����ʾʹ��ģ�庯��ʱ����ʹ��<>�����б�
	cout << Max(3.0, 4.0) << endl;        //�������ģ��������õ�ƥ�� ʹ�ú���ģ��
	cout << Max(5.0, 6.0, 7.0) << endl;   //����ģ������
	cout << Max('a', 100) << endl;        //������ͨ������������ʽת������


	system("pause");
	return 0;
}