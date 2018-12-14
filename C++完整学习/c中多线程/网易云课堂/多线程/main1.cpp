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

	int N = fu.get();           //子线程从父线程中获取变量
	for (int i = N; i > 1; i--)
	{
		res *=i;
	}
	cout << "result is: " << res << endl;
	return res;
}

//把子线程中返回的结果传递到父线程中
int main2()
{
	int x;
	/*thread t1(factorial, 4, ref(x));
	t1.join();*/
	promise<int> p;            //promise和future都是模板
	promise<int> p2 = move(p);  
	//promise<int> p2 = p;   //错误
	future<int> fu1= p2.get_future();    //promise和future都只能被move，不能被copy
	shared_future<int> sf = fu1.share();  //当函数要被多个线程执行时，要创建多个promise
	                                      //但是可以用share_future来创建一个可拷贝的future对象
	//...10个线程
	future<int> fu = async(factorial, sf);
	future<int> fu2 = async(factorial, sf);
	future<int> fu3 = async(factorial, sf);
	

	p2.set_value(5);
	//x = fu.get();    //等待子线程结束。获取子线程返回值
	//                 //future类就是从未来获取某个变量的类
	//cout << "Get from child"<< x << endl;


	return 0;

}