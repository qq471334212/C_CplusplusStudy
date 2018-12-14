#include<iostream>
#include<list>
using namespace std;

//加密策略
class Strategy
{
public:
	virtual void crypt() = 0;
};

//对称加密，速度快，加密大数据块文件，特点：加密解密密钥都是一样的，但存在安全问题
class Aes:public Strategy
{
public:
	virtual void crypt()
	{
		cout << "use Aes crypt algorithm......." << endl;
	}
};

//非对称加密，速度慢，加密强度高，安全性好，特点：加密密钥和解密密钥不一样 密钥对（公钥 和 私钥）
class Des :public Strategy
{
public:
	virtual void crypt()
	{
		cout << "use Des crypt algorithm......." << endl;
	}
};

class Context
{
public:
	void SetStrategy(Strategy * strategy)
	{
		m_strategy = strategy;
	}

	void myOperator()
	{
		m_strategy->crypt();
	}
private:
	Strategy * m_strategy;
};

int main22()
{
	//1.客户写死业务逻辑
	//Des *des = new Des;
	//des->crypt();
	//delete des;

	//2.客户与策略解耦合
	Strategy *strategy = NULL;

	strategy = new Des;
	Context *context = new Context;
	context->SetStrategy(strategy);
	context->myOperator();

	delete strategy;
	delete context;
	system("pause");
	return 0;
}