#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<fstream>
using namespace std;

//����1
//mutex mu;  //����������󣬽�����ݾ���
//           //���������̲߳�����ҽ���
//void shared_print(string msg,int id)
//{
//	lock_guard<mutex> guard(mu);
//	//mu.lock();          //��ס��ͬ��Դ
//	cout << msg << id << endl;
//	//mu.unlock();        //������ͬ��Դ 
//}

//����2
class LofFile1
{
public:
	LofFile1()
	{
		f.open("log.txt");
	}
	
	void shared_print(string ID,int value)      //shared_print��סmutex,����ַ���
	{	
		//lock(m_mutex, m_mutex2);
		lock_guard<mutex> locker(m_mutex);      //lock_guard����һ��mutex���͵��Խ�������
		//f << "From" << ID << ":" << value << endl;       //���д���ļ���
		//lock_guard<mutex> locker2(m_mutex2, adopt_lock);
		cout << "From" << ID << ":" << value << endl;
	}
	void shared_print2(string ID, int value)      //shared_print��סmutex,����ַ���
	{
		
		lock_guard<mutex> locker(m_mutex);      //lock_guard����һ��mutex���͵��Խ�������
												//f << "From" << ID << ":" << value << endl;  
	//	lock_guard<mutex> locker2(m_mutex2, adopt_lock);
		cout << "From" << ID << ":" << value << endl;
	}
protected:
private:
	mutex m_mutex;
	//mutex m_mutex2;
	ofstream f;            //���ܽ�f���أ����߽�f��Ϊ���������ڳ�Ա�����У������ᱩ¶��Դ

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
	thread t1(function_11,ref(log));   //function_1��һ��LofFile���������Թ����߳�Ҫ��һ������
	for (int i = 0; i < 100; i++)
		//cout << "From main" << i << endl;
		//shared_print("From main", i);
		log.shared_print2(string(" main"), i);
	t1.join();

	return 0;
}