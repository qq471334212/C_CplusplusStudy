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
//创建子线程1
void thread_1()
{
	packaged_task<int()>  t;
	{
		//lock_guard<mutex> locker(mu1);
		unique_lock<mutex> locker(mu1);
		cond1.wait(locker, []() {return !task_q.empty(); });   //如果task_q不为空的话，就被激活；为空队列的话则一直等待
		t = move(task_q.front());   //将获取到的转移出来
	}

	t();
}
int main()
{
	thread t1(thread_1);
	packaged_task<int()>  t(bind(func1, 6));
	future<int> ret = t.get_future();
	
	{
		lock_guard<mutex> locker(mu1);
		task_q.push_back(move(t));                 //必须把t move到子线程中，否则程序会崩溃
		                                           //要确保这个主线程的push_back比子线程的front（）先调用，否则会崩溃，因此加一个条件变量
	}
	cond1.notify_one();           //激活等待条件的线程
	int value = ret.get();
	cout << value << endl;
	t1.join();

	////packaged_task<int(int)>  t(func1);

	//future<int> ret = t.get_future();  //异步访问。获取与package_task共享状态相关联的future对象
	//int value = ret.get();  //等待任务完成，获取结果

	/*auto t = bind(func1, 6);
	t();*/

	return 0;
}