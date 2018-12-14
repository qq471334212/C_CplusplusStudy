#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"MyVector.cpp"
using namespace std;

//1.Teacher�࣬���Ա��ָ��,���캯����Ҫ �����ڴ�
//2.����������Ҫ�ͷ�pnameָ����ڴ�ռ�
//3.����ǳ��������д�������캯��
//4.��Teacher�������� << ���������

//5.��ģ���������д� int,char,Teacher,*Teacher 

//====��STL��������
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

	Teacher(const Teacher&obj)        //�������캯��
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
		cout << "������������"<<endl;
	}

	//���
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

	//����������װTeacher����ʱ���������������
	friend ostream& operator<<(ostream&out, const Teacher &t)
	{
		out << t.pname << " , " << t.age << endl;
		return out;
	}

	//����������װTeacher*����ʱ���������������
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

//����������װTeacherԪ��
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