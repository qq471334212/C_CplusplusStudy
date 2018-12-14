#include<iostream>
using namespace std;

class BankWorker
{
public:
	void save()
	{
		cout << "存款" << endl;
	}
	void moveM()
	{
		cout << "转账" << endl;
	}
	void send()
	{
		cout << "缴费" << endl;
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
		cout << "存款" << endl;
	}
};

class moveMBanker :public AvBankWorker
{
public:
	virtual void dothing()
	{
		cout << "转账" << endl;
	}
};

class AvMoveMBanker :public moveMBanker
{
public:
	virtual void dothing()
	{
		cout << "快速转账" << endl;
	}
};

class AdvAvMoveMBanker :public moveMBanker
{
public:
	virtual void dothing()
	{
		cout << "自动 快速 转账" << endl;
	}
};

class sendBanker :public AvBankWorker
{
public:
	virtual void dothing()
	{
		cout << "缴费" << endl;
	}
};


int mainTest1()
{
	//传统
	BankWorker *bw = new BankWorker;
	bw->moveM();
	bw->save();
	bw->send();

	return 0;
}

//关键
//框架函数
void howDo(AvBankWorker *bw)
{
	bw->dothing();    //有多态发生
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