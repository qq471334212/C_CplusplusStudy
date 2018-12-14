#include<iostream>
#include<thread>
#include<string>
using namespace std;

void func()
{
	cout << "www.oxox.work" << endl;
}

class fctor
{
public:
	void operator()(string& msg)    //对（）进行重载
	{
		/*for (int i = 0; i < 1; i++)
		{*/
			cout << "form t1: " << msg << endl;
		//}
		msg = "I love YH";
	}

};
int main1()
{
	fctor fct;
	string s = "I love TAL";

	cout << "主线程的ID为：" << this_thread::get_id() << endl;

	//thread t1((fctor()), move(s));   //move（）函数将s字符串从主线程移动到子线程安全又高效

	thread t1(fct,ref(s));   //按地址传递s,允许修改后返回
	//thread t1(func);
	////t1.join();
	//t1.detach();

	//if (t1.joinable())
	//{
	//	t1.join();
	//}
	//try {
	//	for (int i = 0; i < 1; i++)
	//	{
	//		cout << "form main: " << s << endl;
	//	}
	//}
	//catch (...)   //防止主线程有异常，导致t1线程无法回收
	//{
	//	t1.join();
	//	throw;
	//}

	cout << "t1线程的ID为：" << t1.get_id() << endl;
	thread t2 = move(t1);    //将线程从t1复制移动到t2，t1线程为空
	cout << "t2线程的ID为：" << t2.get_id() << endl;
	if (t1.joinable())
    {
		t1.join();
    }
	else { cout << "t1 wei NULL" << endl; }

	t2.join();    //t1线程比主线程先执行完，再执行主线程
	cout << "form main: " << s << endl;

	cout << thread::hardware_concurrency();          //提示最多有多少个线程可以使用 , 显示八个线程
	return 0;
}