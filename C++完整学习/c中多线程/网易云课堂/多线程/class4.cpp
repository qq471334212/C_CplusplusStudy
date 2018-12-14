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
//�������߳�1
void thread_1()
{
	packaged_task<int()>  t;
	{
		//lock_guard<mutex> locker(mu1);
		unique_lock<mutex> locker(mu1);
		cond1.wait(locker, []() {return !task_q.empty(); });   //���task_q��Ϊ�յĻ����ͱ����Ϊ�ն��еĻ���һֱ�ȴ�
		t = move(task_q.front());   //����ȡ����ת�Ƴ���
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
		task_q.push_back(move(t));                 //�����t move�����߳��У������������
		                                           //Ҫȷ��������̵߳�push_back�����̵߳�front�����ȵ��ã�������������˼�һ����������
	}
	cond1.notify_one();           //����ȴ��������߳�
	int value = ret.get();
	cout << value << endl;
	t1.join();

	////packaged_task<int(int)>  t(func1);

	//future<int> ret = t.get_future();  //�첽���ʡ���ȡ��package_task����״̬�������future����
	//int value = ret.get();  //�ȴ�������ɣ���ȡ���

	/*auto t = bind(func1, 6);
	t();*/

	return 0;
}