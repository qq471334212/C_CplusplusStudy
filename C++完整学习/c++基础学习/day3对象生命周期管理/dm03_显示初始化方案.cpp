#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test3
{
public:
	void init(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

private:
	int a;
	int b;
};

int main03()
{
	Test3 t1;           //C++���������ṩһ��Ĭ�ϵĹ��캯��
	                    //û�п������캯����Ҳ���ṩһ��Ĭ�ϵĿ������캯��

	t1.init(1, 2);      //��ʽ�Ĺ��캯�������������ڶ�ʱ����ֵ�ǳ������㣬�����Ҫ���ù��캯��
	Test3 tArray[50];
	tArray[0].init(5, 2);
	//....
	system("pause");
	return 0;
}