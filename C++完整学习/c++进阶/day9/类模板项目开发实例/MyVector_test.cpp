#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"MyVector.cpp"
using namespace std;

//1.Teacher类，属性变成指针,构造函数需要 分配内存
//2.析构函数需要释放pname指向的内存空间
//3.避免浅拷贝，重写拷贝构造函数
//4.在Teacher类中增加 << 运算符重载

//5.在模板数组类中存 int,char,Teacher,*Teacher 

//====》STL容器概念
class Teacher
{
public:
	Teacher()
	{
		age = 33;
	
		pname = new char[1];
		strcpy(pname, "");
	}

	Teacher(const char *name,int age)
	{
		int size = strlen(name) + 1;
		this->age = age;
		pname = new char[size];
		strcpy(this->pname, name);
	}

	Teacher(const Teacher&obj)        //拷贝构造函数
	{
		int size = strlen(obj.pname) + 1;
		pname = new char[size];
		pname = obj.pname;
		//strcpy(pname, obj.pname);
		age = obj.age;
	}

	~Teacher()
	{
		if (pname != NULL)
		{
			delete pname;
			pname = NULL;
		}
		cout << "析构函数调用"<<endl;
	}

	//深拷贝
	Teacher& operator=(const Teacher &t)
	{
		if (pname != NULL)
		{
			delete[] pname;
			pname = NULL;
		}
		pname = new char[32];
		pname = t.pname;
		//strcpy(pname, obj.pname);
		age = t.age;
		return *this;
	}

	//数组容器内装Teacher类型时的左移运算符重载
	friend ostream& operator<<(ostream&out, const Teacher &t)
	{
		out << t.pname << " , " << t.age << endl;
		return out;
	}

	//数组容器内装Teacher*类型时的左移运算符重载
	friend ostream& operator<<(ostream&out, const Teacher *t)
	{
		out << t->pname << " , " << t->age << endl;
		return out;
	}

	void printT()
	{
		cout << pname << " , " << age << endl;
	}
private:
	int age;
	//char name[32];
	char *pname;
};

int main()
{
	int i = 0;
	Teacher t1("t1", 31);
	Teacher t2("t2", 32);
	Teacher t3("t3", 33);

	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	MyVector<Teacher*> TArray(3);
	TArray[0] = p1;
	TArray[1] = p2;
	TArray[2] = p3;

	cout << TArray << endl;
	//for (i = 0; i < 3; i++)
	//{
	//	Teacher *tmp = TArray[i];
	//	tmp->printT();
	//}
	system("pause");
	return 0;
}

//数组摸板类装Teacher元素
int main03()
{
	int i = 0;
	Teacher t1("t1", 31);
	Teacher t2 = t1;
	Teacher t3("t3", 33);

	MyVector<Teacher> TArray(3);
	TArray[0] = t1;
	TArray[1] = t2;
	TArray[2] = t3;

	cout << TArray << endl;
	//for (i = 0; i < 3; i++)
	//{
	//	Teacher tmp = TArray[i];
	//	tmp.printT();
	//}
	system("pause");
	return 0;
}

int main02()
{
	int i = 0;
	MyVector<char> myV(4);
	myV[0] = 'a';
	myV[1] = 'b';
	myV[2] = 'c';
	myV[3] = 'd';
	cout << myV;
	system("pause");
	return 0;
}

int main01()
{
	int i = 0;
	MyVector<int> myV(10);
	for (i = 0; i < myV.getLen(); i++)
	{
		myV[i] = i + 1;
		cout << myV[i] << "";
	}
	cout << endl;

	MyVector<int> myV2 = myV;
	for (i = 0; i < myV.getLen(); i++)
	{
		cout << myV2[i] << "";
	}
	cout << endl;

	cout<<myV2<<endl;
	system("pause");
	return 0;
}