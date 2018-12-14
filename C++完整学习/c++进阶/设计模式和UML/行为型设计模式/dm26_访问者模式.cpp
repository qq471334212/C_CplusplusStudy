#include<iostream>
#include<string>
#include<list>
using namespace std;

class ParkElement;

//Visitor 和 ParkElement两者之间互相关联
class Visitor
{
public:
	virtual void visit(ParkElement* ParkElement) = 0;
};

class ParkElement
{
public:
	virtual void accept(Visitor* visit) = 0;
	virtual string GetName() = 0;
};

class parkA : public ParkElement
{
public:
	virtual void accept(Visitor* v)
	{
		v->visit(this);              //公园接收访问者访问，让访问者做操作
    }
	virtual string GetName()
	{
		return "parkA";
	}
};

class parkB : public ParkElement
{
public:
	virtual void accept(Visitor* v)
	{
		v->visit(this);              //公园接收访问者访问，让访问者做操作
	}
	virtual string GetName()
	{
		return "parkB";
	}
};

//新的一个集合类，包含了公园的各个部分
class parkTotal
{
public:
	parkTotal()
	{
		m_list.clear();
	}
	void setParkElement(ParkElement *pe)
	{
		m_list.push_back(pe);
	}
	virtual void accept(Visitor* v)
	{
		//v->visit(this);              //公园接收管理者访问，访问公园每一个部分
		for (list<ParkElement *>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->accept(v);          //公园A接受访问者...公园B接受访问者......
		}
	}
	virtual string GetName()
	{
		return "parkTotal";
	}
private:
	list<ParkElement *> m_list;       //存储的是公园的各个部分 //让每一个部分都让管理者访问
};

class VisitorA :public Visitor
{
public:
	virtual void visit(ParkElement* parkElement)
	{
		if (parkElement->GetName() == "parkA")
		{
			cout << "清洁工A 完成 公园A区的工作" << endl;
		}
		else
		{
			cout << "清洁工A 走错 工作区域" << endl;
		}
	}
};

class VisitorB :public Visitor
{
public:
	virtual void visit(ParkElement* parkElement)
	{
		if (parkElement->GetName() == "parkB")
		{
			cout << "清洁工B 完成 公园B区的工作" << endl;
		}
		else
		{
			cout << "清洁工B 走错 工作区域" << endl;
		}
	}
};


class ManagerVisitor :public Visitor
{
public:
	virtual void visit(ParkElement* parkElement)
	{
		cout << "管理者 管理 "<< parkElement->GetName() <<" 各个部分的工作" << endl;		
	}

};

void main272()
{
	Visitor *vM = new ManagerVisitor;

	parkTotal *pT = new parkTotal;


	ParkElement *pA = new parkA;
	ParkElement *pB = new parkB;

	pT->setParkElement(pA);
	pT->setParkElement(pB);

	//整个公园 接受 管理者访问
	pT->accept(vM);

	delete pB;
	delete pA;
	delete pT;
	delete vM;
}

void main262()
{
	VisitorA *vA = new VisitorA;
	VisitorB *vB = new VisitorB;

	ParkElement *pA = new parkA;
	ParkElement *pB = new parkB;

	//公园接受访问者
	pA->accept(vA);
	pB->accept(vB);

	delete pB;
	delete pA;
	delete vB;
	delete vA;
}

int main26()
{
	//main261();
	main262();
	system("pause");
	return 0;
}