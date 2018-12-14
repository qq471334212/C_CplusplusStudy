#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<fstream>
#include<Future>
#include<deque>
#include<condition_variable>
using namespace std;

int func1(int N)
{
	int res = 1;
	for (int i = N; i > 1; i--)
	{
		res *= i;
	}
	cout << "result is: " << res << endl;
	return res;
}

deque<packaged_task<int()>>  task_q;
mutex mu1;
condition_variable cond1;

int main()
{
	thread t1(func1,6);
	//线程休眠方法1
	this_thread::sleep_for(chrono::milliseconds(3));  
	//线程休眠方法2
	chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::milliseconds(4);  //定义一个时间点
	this_thread::sleep_until(tp);
	
	unique_lock<mutex> locker(mu1);
	//locker锁休眠方法1
	locker.try_lock_for(chrono::milliseconds(3));
	//locker锁休眠方法2
	chrono::steady_clock::time_point tp2 = chrono::steady_clock::now() + chrono::milliseconds(4);
	locker.try_lock_until(tp2);

	//条件变量的时间限制
	cond1.wait_for(locker, chrono::milliseconds(3));
	chrono::steady_clock::time_point tp3 = chrono::steady_clock::now() + chrono::milliseconds(4);
	cond1.wait_until(locker, tp3);

	//future的时间限制
	promise<int> p;
	future<int> f = p.get_future();
	f.wait_for(chrono::milliseconds(3));
	chrono::steady_clock::time_point tp4 = chrono::steady_clock::now() + chrono::milliseconds(4);
	f.wait_until(tp4);
	return 0;
}