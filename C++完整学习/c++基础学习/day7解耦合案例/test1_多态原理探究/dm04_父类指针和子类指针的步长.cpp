#include<iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		//print();
	}
	virtual void print()   //���ֽ� ��virtual����һ���麯����
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	//	print();
	}

	void print()
	{
		cout << "���Ƕ���" << endl;
	}
private:
	int b;
};

void HowToPlay(Parent *base)
{
	base->print();            //�ж�̬����
							  //���ֽ�
}
int main()
{
	Child c1;         //����һ�������������������У��ڸ��๹�캯���е����麯��print(),���ܷ�����̬
					  //�����vptrָ���Ƿֲ���ʼ����
	Child *c = NULL;
	Parent *p = NULL;

	Child array[] = { Child(1),Child(2) ,Child(3) };
	p = array;
	c = array;

	p->print();
	c->print();

	p++;
	c++;

	p->print();            //�˴�������Ϊ��������������ڴ�ռ��С��һ�������ָ�벽����һ��
	c->print();

	p++;
	c++;

	p->print();
	c->print();

	system("pause");
	return 0;
}