#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Test
{
public:
	Test() { a = 1; cout << "�޲ι��캯��" << endl; }
	Test(int x) {
		a = x;
		cout << "�вι��캯��" << a << endl;
	}
	//��ֵ���캯������һ���������������һ�������ʼ��
	Test(const Test &t) {
		cout << "���ƹ��캯��" << t.a << endl;
	}
	void Print()
	{
		cout << a << endl;
	}
	~Test() {
		cout << "��������" << a << endl;
	}
private:
	int a;
};

void objplay()
{
	//�����ʼ���Ͷ���ֵ��������ͬ�ĸ���
	//���캯���ĵ��÷������Զ����ã���������ã�
	//Ҳ������ʾ�ĳ�ʼ��������Ժ���Դ
	Test t1;       //�����޲ι��캯��
	Test t2(2);    //�����вι��캯��������ʽ
	//Test t2=Test(2);  //ֱ�ӵ��ù��캯���������������
	//Test t2 = (4);
	Test t3 = t2;


}

int main02()
{
	objplay();

	system("pause");
	return 0;
}