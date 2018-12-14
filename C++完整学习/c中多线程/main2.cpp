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

	void shared_print(string ID, int value)      //shared_print��סmutex,����ַ���
	{
		//is_open����ҲҪ��ͬ��������ᱻ����̴߳򿪶��
		//{
		//	unique_lock<mutex> locker(m_mutex_open, defer_lock);  //Ϊ�ļ�open��������һ��lock
		//	if (!f.is_open())
		//	{
		//		//unique_lock<mutex> locker(m_mutex_open, defer_lock);  //Ϊ�ļ�open��������һ��lock
		//		f.open("log.txt");
		//	}
		//}

		call_once(m_flag, [&]() {f.open("log.txt"); });   //���lamda����ȷ��open����ֻ�ᱻһ���̵߳���һ��
		unique_lock<mutex> locker(m_mutex,defer_lock);     //ʹֻ�д�ӡ��һ�����mutexͬ�����ṩ�˸��൯��
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
	ofstream f;            //���ܽ�f���أ����߽�f��Ϊ���������ڳ�Ա�����У������ᱩ¶��Դ

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
	thread t1(function_1, ref(log));   //function_1��һ��LofFile���������Թ����߳�Ҫ��һ������
	t1.join();
	for (int i = 0; i < 100; i++)
		//cout << "From main" << i << endl;
		//shared_print("From main", i);
	{
		log.shared_print(" main", i);
		
	}
	

	return 0;
}