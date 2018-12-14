#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<fstream>

#include<deque>
#include<functional>
#include<condition_variable>
using namespace std;

//ȫ�ֱ���
deque<int> q;
mutex mu;
condition_variable cond;   //����һ����������
void function_1()
{
	int count = 10;
	while (count > 0)
	{
		unique_lock<mutex> locker(mu);     //�ڷ��ʶ���֮ǰΪmutex�����������������ݾ���
		q.push_front(count);               //Ϊ�������Ԫ��
		locker.unlock();                   //����
		//cond.notify_one();        //����һ���ȴ�����������߳�
		cond.notify_all();        //�������еȴ�����������߳�
		this_thread::sleep_for(chrono::seconds(1));   //chrono����һ�� time library
		count--;
	}
}

void function_2()
{
	int data = 0;
	while (data != 1)
	{
		unique_lock<mutex>  locker(mu);
		cond.wait(locker, []() {return !q.empty(); });  //���߳�2���ߡ����߳�1��notify_one����������ִ��
		                    //��һ��locker��������Ϊwait����������ߣ�������ס��locker�ǲ������ߵ�
		                    //����ڴ˴����ظ��ӽ�����ֻ��ʹ��unique_lock��������lock_guard����
		                    //���һ����lamda������ȷ������q��Ϊ�յ�ʱ���߳�2�ű����Ϊ�յĻ��߳�2һֱ�ȴ�
		                    
		/*	if (!q.empty())
		{*/
			data = q.back();    //ȡ����β��Ԫ�ظ�ֵ��data
			q.pop_back();       //ɾ������β��Ԫ��
			locker.unlock();
			cout << " t2 got a value from t1: " << data << endl;
		//}
		//else
		//{
		//	locker.unlock();      //����Ϊ�ս���������������qһֱ���������ѭ��
		//	//this_thread::sleep_for(chrono::seconds(10));   //�ȴ�10s�У�����ѭ�������������޷�ȷ��ѭ���ȴ�ʱ�������
		//	                                               //��ʱ����Ҫ��������������
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
