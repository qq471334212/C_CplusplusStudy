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
	void operator()(string& msg)    //�ԣ�����������
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

	cout << "���̵߳�IDΪ��" << this_thread::get_id() << endl;

	//thread t1((fctor()), move(s));   //move����������s�ַ��������߳��ƶ������̰߳�ȫ�ָ�Ч

	thread t1(fct,ref(s));   //����ַ����s,�����޸ĺ󷵻�
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
	//catch (...)   //��ֹ���߳����쳣������t1�߳��޷�����
	//{
	//	t1.join();
	//	throw;
	//}

	cout << "t1�̵߳�IDΪ��" << t1.get_id() << endl;
	thread t2 = move(t1);    //���̴߳�t1�����ƶ���t2��t1�߳�Ϊ��
	cout << "t2�̵߳�IDΪ��" << t2.get_id() << endl;
	if (t1.joinable())
    {
		t1.join();
    }
	else { cout << "t1 wei NULL" << endl; }

	t2.join();    //t1�̱߳����߳���ִ���꣬��ִ�����߳�
	cout << "form main: " << s << endl;

	cout << thread::hardware_concurrency();          //��ʾ����ж��ٸ��߳̿���ʹ�� , ��ʾ�˸��߳�
	return 0;
}