#include<iostream>
#include<string>
using namespace std;

class programmer
{
public:
	virtual void setSal() = 0;

};

class junior_pro:public programmer
{
public:
	junior_pro(string name, string job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void setSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	string name;
	string job;
	int sal;
};

class mid_pro:public programmer
{
public:
	mid_pro(string name, string job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void setSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	string name;
	string job;
	int sal;
};

class adv_pro:public programmer
{
public:
	adv_pro(string name, string job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void setSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	string name;
	string job;
	int sal;
};

class jiagoushi :public programmer
{
public:
	jiagoushi(string name, string job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void setSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	string name;
	string job;
	int sal;
};

void CalProSal(programmer *p)
{
	p->setSal();
}
int main()
{
	mid_pro mp("С��", "�м�", 9600);
	junior_pro jp("С��", "����", 4600);
	adv_pro ap("С��", "�߼�", 15000);


	//ϵͳ��չ
	jiagoushi jg("С��", "�ܹ�ʦ", 15000);
	CalProSal(&mp);
	CalProSal(&jp);
	CalProSal(&ap);
	CalProSal(&jg);
	system("pause");
	return 0;
}