#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test4
{
public:
	Test4() { a = 0, b = 0; cout << "�޲ι��캯��" << endl; }
	Test4(int x) {
		a = x;
		b = 0;
		cout << "�вι��캯��" << a << endl;
	}
	Test4(int x,int y) {
		a = x;
		b = y;
		cout << "�вι��캯��2" << a << endl;
	}
	//��ֵ���캯������һ���������������һ�������ʼ��
	Test4(const Test4 &t) {
		this->a = t.a;
		this->b = t.b;
		cout << "���ƹ��캯��" << endl;
	}
	void Print()
	{
		cout << "a: " << a << "b: " << b << endl;
	}
	~Test4() {
		cout << "��������" << a << endl;
	}
private:
	int a;
	int b;
};

//���ƹ��캯��������һ������ȥ��ʼ����һ������
int main()
{
	Test4 t1(1, 2);
	Test4 t0(1, 2);
	//�������캯��4����ʽ
	//��һ��
	Test4 t2 = t1;   //��t1��ʼ��t2
	//�ڶ���
	//Test4 t2(t1);
	t0 = t1;         //��t1��t0��ֵ,���߲�һ��
	system("pause");
	return 0;
}