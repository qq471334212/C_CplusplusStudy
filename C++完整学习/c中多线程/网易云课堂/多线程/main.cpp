#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<fstream>

#include<deque>
#include<functional>
#include<condition_variable>
using namespace std;

//全局变量
deque<int> q;
mutex mu;
condition_variable cond;   //定义一个条件变量
void function_1()
{
	int count = 10;
	while (count > 0)
	{
		unique_lock<mutex> locker(mu);     //在访问队列之前为mutex加锁，否则会造成数据竞争
		q.push_front(count);               //为队列添加元素
		locker.unlock();                   //解锁
		//cond.notify_one();        //激活一个等待这个条件的线程
		cond.notify_all();        //激活所有等待这个条件的线程
		this_thread::sleep_for(chrono::seconds(1));   //chrono库是一个 time library
		count--;
	}
}

void function_2()
{
	int data = 0;
	while (data != 1)
	{
		unique_lock<mutex>  locker(mu);
		cond.wait(locker, []() {return !q.empty(); });  //将线程2休眠。等线程1的notify_one把他激活再执行
		                    //有一个locker参数是因为wait会解锁再休眠，否则锁住的locker是不会休眠的
		                    //因此在此处会重复加解锁，只能使用unique_lock，不能用lock_guard！！
		                    //添加一个；lamda函数，确保队列q不为空的时候，线程2才被激活，为空的话线程2一直等待
		                    
		/*	if (!q.empty())
		{*/
			data = q.back();    //取队列尾的元素赋值给data
			q.pop_back();       //删除队列尾的元素
			locker.unlock();
			cout << " t2 got a value from t1: " << data << endl;
		//}
		//else
		//{
		//	locker.unlock();      //队列为空解锁，但是若队列q一直空则会无限循环
		//	//this_thread::sleep_for(chrono::seconds(10));   //等待10s中，减少循环次数，但是无法确定循环等待时间多久最好
		//	                                               //此时就需要条件变量！！！
		//}
	}
}

int main1()
{
	thread t1(function_1);
	thread t2(function_2);
	t1.join();
	t2.join();
	return 0;
}
