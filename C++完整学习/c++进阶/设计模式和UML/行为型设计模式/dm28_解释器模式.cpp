#include<iostream>
#include<string>
#include<list>
using namespace std;

//Context1

//Expression

//PlusExpression, MinusExpression

class Context1
{
public:
	Context1(int num)
	{
		this->num = num;
	}
	int GetNum()
	{
		return num;
	}
	int GetRes()
	{
		return res;
	}
	void SetNum(int num)
	{
		this->num = num;
	}
	void SetRes(int res)
	{
		this->res = res;
	}
private:
	int num;    //初始值
	int res;    //结果
};

//解释器接口
class Expression
{
public:
	Expression()
	{
		//m_context = context;
	}
	virtual void interpreter(Context1 * context) = 0;
protected:
	//Context1 * m_context;          //关联一个解释器指针
};

class PlusExpression :public Expression
{
public:
	PlusExpression()
	{
		//this->context = NULL;
	}
	virtual void interpreter(Context1 * context)
	{
		int num = context->GetNum();
		num++;
		context->SetNum(num);
		context->SetRes(num);
	}
private:
	//Context1 * context;
};

class MinusExpression :public Expression
{
public:
	MinusExpression()
	{
		//this->context = context;
	}
	virtual void interpreter(Context1 * context)
	{
		int num = context->GetNum();
		num--;
		context->SetNum(num);
		context->SetRes(num);
	}
private:
	//Context1 * context;
};

int main28()
{
	Expression		*expression = NULL;
	Expression		*expression2 = NULL;
	Context1		*context = NULL;

	context = new Context1(10);
	cout << "num: " << context->GetNum() << endl;
	expression = new PlusExpression;
	expression->interpreter(context);
	cout << "res: " << context->GetRes() << endl;

	expression2 = new MinusExpression;
	expression2->interpreter(context);
	cout << "res: " << context->GetRes() << endl;
	
	delete context;
	delete expression2;
	delete expression;

	system("pause");
	return 0;
}