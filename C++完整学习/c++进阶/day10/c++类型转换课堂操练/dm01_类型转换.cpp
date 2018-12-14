#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void printBuf(const char *p)
{
	//p[0] = 'a';   //�ᱨ��const���Ա����������޸�

	char *p1 = NULL;
	//ʹ����Ҫ���֪��������ת��ǰ�������
	//const char*����==��char*����
	p1 = const_cast<char *>(p);     //Ҫȷ��p��ָ����ڴ�ռ䣬ȷʵ���޸�
	p1[0] = 'a';    //������
	cout << p << endl;
}
int main()
{
	const char *p = "lakshdlka";  //����ʹ��const_cast�����޸�
	//printBuf(p);                //����
	char buf[] = "shdabxciyasi";
	printBuf(buf);
	system("pause");
	return 0;
}


class Tree
{
public:
};

class Animal
{
public:
	virtual void cry() = 0;

};

class Dog :public Animal
{
public:
	virtual void cry()
	{
		cout << "��wang wang!" << endl;
	}

	void doHome()
	{
		cout << "���ң�" << endl;
	}

};

class Cat :public Animal
{
public:
	virtual void cry()
	{
		cout << "è miao miao!" << endl;
	}

	void doWork()
	{
		cout << "ץ��" << endl;
	}

};

void playObj(Animal *base)
{
	base->cry();    //1.�м̳� 2.���麯����д 3.�и���ָ��ָ��������� ==��������̬
	//��ʶ���������
	//dynamic_cast    ����ʱ����ʶ��
	Dog *pDog = dynamic_cast<Dog*>(base);
	if (pDog != NULL)      //����������Dog����ִ��
	{
		pDog->doHome();
	}

	Cat *pCat = dynamic_cast<Cat*>(base);   //�������==��������� ������������ת��
	if (pCat != NULL)
	{
		pCat->doWork();
	}
}
int main02()
{
	Dog d1;
	Cat c1;

	Animal *pBase = NULL;
	pBase = &d1;
	pBase = static_cast<Animal*>(&d1);   //C++������������ʱ���������ͼ��

	//ǿ������ת��
	pBase = reinterpret_cast<Animal*>(&d1);

	{
		Tree t1;
		//pBase = static_cast<Animal*>(&t1);        //����
		pBase = reinterpret_cast<Animal*>(&t1);

	}

	playObj(&d1);
	playObj(&c1);
	system("pause");
	return 0;
}

int main01()
{
	double dpi = 3.1415926;
	int num1 = (int)dpi;  //C����ת��
	int num2 = static_cast<int>(dpi); //C++��̬����ת��

	//int num3 = dpi;    //��ʽ����ת��������warning������ʹ��static_cast

	char t[10] = "yh";
	int *t1 = NULL;
	//t1 = t;
	//t1 = static_cast<int*>(t);   //����תָ�����ͣ�ʹ��static_cast������������ʱ���������ͼ�飬�д���ᱨ��
	t1 = reinterpret_cast<int*>(t);
	cout << "t: " << t << endl;
	cout << "t1: " << t1 << endl;  //�׵�ַ
	system("pause");
	return 0;
}