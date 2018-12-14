#include<iostream>
using namespace std;

class BankWorker
{
public:
	void save()
	{
		cout << "���" << endl;
	}
	void moveM()
	{
		cout << "ת��" << endl;
	}
	void send()
	{
		cout << "�ɷ�" << endl;
	}
};

class AvBankWorker
{
public:
	virtual void dothing() = 0;

};

class saveBanker :public AvBankWorker
{
public:
	virtual void dothing()
	{
		cout << "���" << endl;
	}
};

class moveMBanker :public AvBankWorker
{
public:
	virtual void dothing()
	{
		cout << "ת��" << endl;
	}
};

class AvMoveMBanker :public moveMBanker
{
public:
	virtual void dothing()
	{
		cout << "����ת��" << endl;
	}
};

class AdvAvMoveMBanker :public moveMBanker
{
public:
	virtual void dothing()
	{
		cout << "�Զ� ���� ת��" << endl;
	}
};

class sendBanker :public AvBankWorker
{
public:
	virtual void dothing()
	{
		cout << "�ɷ�" << endl;
	}
};


int mainTest1()
{
	//��ͳ
	BankWorker *bw = new BankWorker;
	bw->moveM();
	bw->save();
	bw->send();

	return 0;
}

//�ؼ�
//��ܺ���
void howDo(AvBankWorker *bw)
{
	bw->dothing();    //�ж�̬����
}

int mainTest2()
{
	AvBankWorker *bw = NULL;
	bw = new moveMBanker;
	bw->dothing();
	delete bw;

	bw = new saveBanker;
	bw->dothing();
	delete bw;

	return 0;
}

int mainTest3()
{
	AvBankWorker *bw = NULL;
	bw = new moveMBanker;
	howDo(bw);
	delete bw;

	bw = new saveBanker;
	howDo(bw);
	delete bw;

	bw = new AvMoveMBanker;
	howDo(bw);
	delete bw;

	return 0;
}

int main2()
{
	//mainTest1();
	//mainTest2();
	mainTest3();
	system("pause");
	return 0;
}