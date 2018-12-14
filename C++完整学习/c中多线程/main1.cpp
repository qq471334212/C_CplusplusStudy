#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<fstream>
using namespace std;

//方法1
//mutex mu;  //创建互斥对象，解决数据竞争
//           //这样两个线程不会混乱进行
//void shared_print(string msg,int id)
//{
//	lock_guard<mutex> guard(mu);
//	//mu.lock();          //锁住共同资源
//	cout << msg << id << endl;
//	//mu.unlock();        //解锁共同资源 
//}

//方法2
class LofFile1
{
public:
	LofFile1()
	{
		f.open("log.txt");
	}
	
	void shared_print(string ID,int value)      //shared_print锁住mutex,输出字符串
	{	
		//lock(m_mutex, m_mutex2);
		lock_guard<mutex> locker(m_mutex);      //lock_guard构造一个mutex类型的自解锁对象
		//f << "From" << ID << ":" << value << endl;       //结果写入文件中
		//lock_guard<mutex> locker2(m_mutex2, adopt_lock);
		cout << "From" << ID << ":" << value << endl;
	}
	void shared_print2(string ID, int value)      //shared_print锁住mutex,输出字符串
	{
		
		lock_guard<mutex> locker(m_mutex);      //lock_guard构造一个mutex类型的自解锁对象
												//f << "From" << ID << ":" << value << endl;  
	//	lock_guard<mutex> locker2(m_mutex2, adopt_lock);
		cout << "From" << ID << ":" << value << endl;
	}
protected:
private:
	mutex m_mutex;
	//mutex m_mutex2;
	ofstream f;            //不能将f返回，或者将f作为参数对象在成员函数中，这样会暴露资源

};

void function_11(LofFile1 &log)
{
	for (int i = 0; i > -100; i--)
	{
		//cout << "From thread t1" << i << endl;
		//shared_print("From thread t1", i);
		log.shared_print(string(" thread t1"), i);
	}
}

int main2()
{
	LofFile1 log;
	thread t1(function_11,ref(log));   //function_1有一个LofFile参数，所以构造线程要传一个参数
	for (int i = 0; i < 100; i++)
		//cout << "From main" << i << endl;
		//shared_print("From main", i);
		log.shared_print2(string(" main"), i);
	t1.join();

	return 0;
}