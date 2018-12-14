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

//享元工厂

//完成 老师节点 存储
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
			map1.erase(it);      //把当前节点 从容器中删除，并且迭代器自动向后一个移
			delete tmp;
    	}
	}
	myPerson* GetCollageTeacher(string id)
	{
		myPerson *tmp = NULL;
		//如果id存在就不new对象，如果不存在，new一个新的对象
		map<string, myPerson*>::iterator it;
		it = map1.find(id);
		if (it == map1.end())   //没有找到这个id
		{
			string tmpname;
			int tmpage;
			cout << "请输入老师的名字：";
			cin >> tmpname;
			cout << "请输入老师的年龄：";
			cin >> tmpage;
		    tmp = new collageTeacher(id, tmpname, tmpage);

			map1.insert(pair<string, myPerson*>(id, tmp));  //将新增老师插入
		}
		else
		{
			tmp = it->second;   //it的第二个元素是 myPerson* 对象
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

	delete fctf;           //定义析构函数，防止内存泄漏
}

int main()
{
	main181();
	system("pause");
	return 0;
}