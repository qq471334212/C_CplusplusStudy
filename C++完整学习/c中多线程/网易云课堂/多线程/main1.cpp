#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<fstream>
#include<condition_variable>

#include<Future>
using namespace std;

//std::mutex mu;
//std::condition_variable cond;

//int factorial(future<int>&fu)
int factorial(shared_future<int> fu)
{
	int res = 1;

	int N = fu.get();           //���̴߳Ӹ��߳��л�ȡ����
	for (int i = N; i > 1; i--)
	{
		res *=i;
	}
	cout << "result is: " << res << endl;
	return res;
}

//�����߳��з��صĽ�����ݵ����߳���
int main2()
{
	int x;
	/*thread t1(factorial, 4, ref(x));
	t1.join();*/
	promise<int> p;            //promise��future����ģ��
	promise<int> p2 = move(p);  
	//promise<int> p2 = p;   //����
	future<int> fu1= p2.get_future();    //promise��future��ֻ�ܱ�move�����ܱ�copy
	shared_future<int> sf = fu1.share();  //������Ҫ������߳�ִ��ʱ��Ҫ�������promise
	                                      //���ǿ�����share_future������һ���ɿ�����future����
	//...10���߳�
	future<int> fu = async(factorial, sf);
	future<int> fu2 = async(factorial, sf);
	future<int> fu3 = async(factorial, sf);
	

	p2.set_value(5);
	//x = fu.get();    //�ȴ����߳̽�������ȡ���̷߳���ֵ
	//                 //future����Ǵ�δ����ȡĳ����������
	//cout << "Get from child"<< x << endl;


	return 0;

}