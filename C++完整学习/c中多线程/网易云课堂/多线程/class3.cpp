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

//创建子线程的方式
int main3()
{
	A a;
	thread  t1(a, 6);  //传递a的拷贝给子线程
	thread  t2(ref(a), 6);  //传递a的引用给子线程
	thread  t3(move(a),6);  //将a从主线程传递到子线程，在主线程中a失效
	thread  t4(A(), 6);     //传递临时创建的A对象给子线程

	thread  t5(foo, 6);    //用函数创建
	thread  t6([](int x) {return x * x; }, 6);  ////用lambda函数创建

	thread  t7(&A::f, a, 6, 'w');   //传递a的拷贝的成员函数给子线程
	thread  t8(&A::f, &a, 6, 'w');   //传递a的地址的成员函数给子线程

	async(launch::async, a, 6);
	return 0;
}