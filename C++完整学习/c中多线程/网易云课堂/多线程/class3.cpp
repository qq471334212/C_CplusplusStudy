#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<Future>
using namespace std;

class A {
public:
	void f(int x, char c) {}
	int operator()(int N) { return 0; }
};

void foo(int x) {}

//�������̵߳ķ�ʽ
int main3()
{
	A a;
	thread  t1(a, 6);  //����a�Ŀ��������߳�
	thread  t2(ref(a), 6);  //����a�����ø����߳�
	thread  t3(move(a),6);  //��a�����̴߳��ݵ����̣߳������߳���aʧЧ
	thread  t4(A(), 6);     //������ʱ������A��������߳�

	thread  t5(foo, 6);    //�ú�������
	thread  t6([](int x) {return x * x; }, 6);  ////��lambda��������

	thread  t7(&A::f, a, 6, 'w');   //����a�Ŀ����ĳ�Ա���������߳�
	thread  t8(&A::f, &a, 6, 'w');   //����a�ĵ�ַ�ĳ�Ա���������߳�

	async(launch::async, a, 6);
	return 0;
}