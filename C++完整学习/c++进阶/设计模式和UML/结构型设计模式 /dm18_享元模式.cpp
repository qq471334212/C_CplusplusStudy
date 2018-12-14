#include<iostream>
#include<string>
#include<map>
using namespace std;

class myPerson
{
public:
	myPerson(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	virtual void printT() = 0;
protected:
	string m_name;
	int m_age;
};

class collageTeacher :public myPerson
{
public:
	collageTeacher(string id, string name, int age) :myPerson(name, age)
	{
		m_id = id;
	}
	void printT()
	{
		cout << "name: " << m_name << "\t" << "age: " << m_age << "\t" << "id: " << m_id << endl;

	}
private:
	string m_id;
};

//��Ԫ����

//��� ��ʦ�ڵ� �洢
class FlyWeightCTFactory
{
public:
	FlyWeightCTFactory()
	{
		map1.clear();
	}
	~FlyWeightCTFactory()
	{
		while (!map1.empty())
		{
			myPerson *tmp = NULL;
			map<string, myPerson*>::iterator it = map1.begin();
			tmp = it->second;
			map1.erase(it);      //�ѵ�ǰ�ڵ� ��������ɾ�������ҵ������Զ����һ����
			delete tmp;
    	}
	}
	myPerson* GetCollageTeacher(string id)
	{
		myPerson *tmp = NULL;
		//���id���ھͲ�new������������ڣ�newһ���µĶ���
		map<string, myPerson*>::iterator it;
		it = map1.find(id);
		if (it == map1.end())   //û���ҵ����id
		{
			string tmpname;
			int tmpage;
			cout << "��������ʦ�����֣�";
			cin >> tmpname;
			cout << "��������ʦ�����䣺";
			cin >> tmpage;
		    tmp = new collageTeacher(id, tmpname, tmpage);

			map1.insert(pair<string, myPerson*>(id, tmp));  //��������ʦ����
		}
		else
		{
			tmp = it->second;   //it�ĵڶ���Ԫ���� myPerson* ����
		}
		return tmp;
	}
private:
	map<string, myPerson*> map1;
};

void main181()
{
	myPerson *p1 = NULL;
	myPerson *p2 = NULL;
	FlyWeightCTFactory *fctf = NULL;
	fctf = new FlyWeightCTFactory;
	p1 = fctf->GetCollageTeacher("001");
	p1->printT();

	p2 = fctf->GetCollageTeacher("001");
	p2->printT();

	delete fctf;           //����������������ֹ�ڴ�й©
}

int main()
{
	main181();
	system("pause");
	return 0;
}