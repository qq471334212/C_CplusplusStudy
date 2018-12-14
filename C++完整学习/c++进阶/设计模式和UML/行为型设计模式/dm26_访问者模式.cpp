#include<iostream>
#include<string>
#include<list>
using namespace std;

class ParkElement;

//Visitor �� ParkElement����֮�以�����
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
		v->visit(this);              //��԰���շ����߷��ʣ��÷�����������
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
		v->visit(this);              //��԰���շ����߷��ʣ��÷�����������
	}
	virtual string GetName()
	{
		return "parkB";
	}
};

//�µ�һ�������࣬�����˹�԰�ĸ�������
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
		//v->visit(this);              //��԰���չ����߷��ʣ����ʹ�԰ÿһ������
		for (list<ParkElement *>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->accept(v);          //��԰A���ܷ�����...��԰B���ܷ�����......
		}
	}
	virtual string GetName()
	{
		return "parkTotal";
	}
private:
	list<ParkElement *> m_list;       //�洢���ǹ�԰�ĸ������� //��ÿһ�����ֶ��ù����߷���
};

class VisitorA :public Visitor
{
public:
	virtual void visit(ParkElement* parkElement)
	{
		if (parkElement->GetName() == "parkA")
		{
			cout << "��๤A ��� ��԰A���Ĺ���" << endl;
		}
		else
		{
			cout << "��๤A �ߴ� ��������" << endl;
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
			cout << "��๤B ��� ��԰B���Ĺ���" << endl;
		}
		else
		{
			cout << "��๤B �ߴ� ��������" << endl;
		}
	}
};


class ManagerVisitor :public Visitor
{
public:
	virtual void visit(ParkElement* parkElement)
	{
		cout << "������ ���� "<< parkElement->GetName() <<" �������ֵĹ���" << endl;		
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

	//������԰ ���� �����߷���
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

	//��԰���ܷ�����
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