#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<fstream>

#include<deque>
#include<functional>
using namespace std;


class LofFile
{
public:
	LofFile()
	{
		//f.open("log.txt");
	}

	void shared_print(string ID, int value)      //shared_print锁住mutex,输出字符串
	{
		//is_open函数也要被同步，否则会被多个线程打开多次
		//{
		//	unique_lock<mutex> locker(m_mutex_open, defer_lock);  //为文件open操作绑定了一个lock
		//	if (!f.is_open())
		//	{
		//		//unique_lock<mutex> locker(m_mutex_open, defer_lock);  //为文件open操作绑定了一个lock
		//		f.open("log.txt");
		//	}
		//}

		call_once(m_flag, [&]() {f.open("log.txt"); });   //这个lamda函数确保open操作只会被一个线程调用一次
		unique_lock<mutex> locker(m_mutex,defer_lock);     //使只有打印这一语句会跟mutex同步，提供了更多弹性
		////....
		//locker.lock();
		cout << "From" << ID << ":" << value << endl;
		//locker.unlock();
		////.....
		//locker.lock();
		//unique_lock<mutex> locker2 = move(locker);
	}

protected:
private:
	mutex m_mutex;
	//mutex m_mutex_open;
	once_flag m_flag;
	ofstream f;            //不能将f返回，或者将f作为参数对象在成员函数中，这样会暴露资源

};

void function_1(LofFile &log)
{
	for (int i = 0; i > -100; i--)
	{
		//cout << "From thread t1" << i << endl;
		//shared_print("From thread t1", i);
		log.shared_print(" thread t1", i);
	}
}

int main()
{
	LofFile log;
	thread t1(function_1, ref(log));   //function_1有一个LofFile参数，所以构造线程要传一个参数
	t1.join();
	for (int i = 0; i < 100; i++)
		//cout << "From main" << i << endl;
		//shared_print("From main", i);
	{
		log.shared_print(" main", i);
		
	}
	

	return 0;
}