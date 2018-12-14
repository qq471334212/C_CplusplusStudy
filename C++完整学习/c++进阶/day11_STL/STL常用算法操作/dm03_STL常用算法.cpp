#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"iterator"  //�������ͷ�ļ�
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;

void showVector(int &n)
{
	cout << n << " ";
}
int showVector2(int &n)
{
	cout << n << " ";
	return 0;
}

void printV(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printL(list<int> &v)
{
	for (list<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class CMyShow
{
public:
	CMyShow()
	{
		num = 0;
	}
	void operator()(int &a)
	{
		num++;
		cout << a << " ";
	}
	void printNum()
	{
		cout << "num = " << num << endl;
	}
private:
	int num;
};

//for_each()��transform()���ú���
void main31()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);
	/*
	template<class _InIt,
		class _Fn> inline
		_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func)
	{	// perform function for each element [_First, _Last)
		_DEBUG_RANGE(_First, _Last);
		auto _UFirst = _Unchecked(_First);
		const auto _ULast = _Unchecked(_Last);
		for (; _UFirst != _ULast; ++_UFirst)
		{
			_Func(*_UFirst);
		}

		return (_Func);
	}*/


	//for_each()���ص��Ǻ�������
	for_each(v1.begin(), v1.end(), showVector);    //����������߻ص���������ڵ�ַ
	cout << endl;
	for_each(v1.begin(), v1.end(), CMyShow());
	cout << endl;

	CMyShow c;
	CMyShow c1 = for_each(v1.begin(), v1.end(), c);  //��c1��ʼ��
	cout << endl;
	c.printNum();           //c��c1��������ͬ�Ķ���
	c1.printNum();          //��ʾ���ô���

	c1 = for_each(v1.begin(), v1.end(), c1);          //��c1��ֵ
	cout << endl;
	c1.printNum();
}

int increase(int n)
{
	return n + 100;
}

void main32()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);

	/*
	template<class _InIt,
		class _OutIt,
		class _Fn> inline
		_OutIt transform(const _InIt _First, const _InIt _Last, _OutIt _Dest, _Fn _Func)
	{	// transform [_First, _Last) with _Func
		_DEPRECATE_UNCHECKED(transform, _Dest);
		_DEBUG_RANGE(_First, _Last);
		auto _UFirst = _Unchecked(_First);
		const auto _ULast = _Unchecked(_Last);
		auto _UDest = _Unchecked_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
		for (; _UFirst != _ULast; ++_UFirst, (void)++_UDest)
		{
			*_UDest = _Func(*_UFirst);
		}

		return (_Rechecked(_Dest, _UDest));
	}*/

	//ʹ�ûص�����
	transform(v1.begin(), v1.end(), v1.begin(), increase);
	printV(v1);

	//ʹ��Ԥ���庯������
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	printV(v1);

	//ʹ�ú���������
	list<int> mylist;
	mylist.resize(v1.size());
	transform(v1.begin(), v1.end(), mylist.begin(), bind2nd(multiplies<int>(),10));
	printL(mylist);

	//transformҲ����ֱ�Ӱ������������Ļ
	transform(v1.begin(), v1.end(),ostream_iterator<int>(cout," "), negate<int>());

	//Ҳ���԰����������Ľ��ͨ������ŵ�������������
	//transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), increase);

}

void main33()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2 = v1;

	for_each(v1.begin(), v1.end(), showVector);

	//�ᱨ����Ϊtransform�Իص�����������Ҫ����Ҫ�з���ֵ
	//transform ==��*_UDest = _Func(*_UFirst);
	//for_each  ==��_Func(*_UFirst);

	transform(v2.begin(), v2.end(), v2.begin(), showVector2);
}

void main34()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());    //���ҵ�һ���ظ����ֵ�λ�ã����ҷ���һ��������

	if (it == v1.end())
	{
		cout << "δ�ҵ��ظ���Ԫ�أ�" << endl;
	}
	else
	{
		cout << *it << endl;
	}

	int index = distance(v1.begin(), it);       //���صĵ��������ظ�Ԫ�ص�һ�����ֵ�λ��
	cout << index << endl;

}

void main35()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	bool answer = binary_search(v1.begin(), v1.end(), 7);
	if (answer == true)
	{
		cout << "�ҵ���7��" << endl;
	}
	else
	{
		cout << "û���ҵ�7��" << endl;
	}
}

//һԪν��
bool GreaterThree(int num)
{
	return num > 3;
}

void main36()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(7);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(7);

	size_t num = count(v1.begin(), v1.end(), 7);
	if (num == 0)
	{
		cout << "û���ҵ�7��" << endl;
	}
	else
	{
		cout << "7�ĸ���Ϊ: " << num << endl;
	}

	size_t num1 = count_if(v1.begin(), v1.end(), GreaterThree);   //�ɶ��Զ����������ͽ�����������

	if (num1 == 0)
	{
		cout << "û���ҵ�����������" << endl;
	}
	else
	{
		cout << "����3�ĸ���Ϊ: " << num1 << endl;
	}
}

void main37()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);

	//���Ҷ�ӦԪ�ص�λ��
	vector<int>::iterator it = find(v1.begin(), v1.end(),5);
	cout << "*it: " << *it << endl;

	//��һ����������λ��
	vector<int>::iterator it1 = find_if(v1.begin(), v1.end(), GreaterThree);
	cout << "*it1: " << *it1 << endl;
}

void main38()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
}

class student
{
public:

	string name;
	int id;

	student(string _name, int _id)
	{
		name = _name;
		id = _id;
	}

	void printT()
	{
		cout << "name: " << name << " " << "id: " << id << endl;
	}
};
bool CompareStudent(student &s1, student &s2)
{
	return (s1.id < s2.id);
}

void main39()
{
	student s1("�ϴ�", 1);
	student s2("�϶�", 2);
	student s3("����", 3);
	student s4("����", 4);
	vector<student> v1;

	v1.push_back(s4);
	v1.push_back(s1);
	v1.push_back(s3);
	v1.push_back(s2);

	for (vector<student>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		it->printT();
	}
	//�Զ������͵�����ʵ���㷨���������͵ķ���
	//ͨ����������ĵ���
	sort(v1.begin(), v1.end(), CompareStudent);   //�޷���ֵ
	cout << endl;
	for (vector<student>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		it->printT();
	}
}

void main310()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	reverse(v1.begin(), v1.end());
	printV(v1);

	random_shuffle(v1.begin(), v1.end());
	printV(v1);

	string s1 = "abcdefg";
	random_shuffle(s1.begin(), s1.end());
	cout << s1 << endl;
	

}

bool great_equal_five(int num)
{
	return ((num > 5) || (num == 5));
}
void main311()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	printV(v2);

	replace(v1.begin(), v1.end(), 3, 7);          //Ԫ��Ϊ3���滻Ϊ7
	printV(v1);

	replace_if(v1.begin(), v1.end(), great_equal_five, 1);       //���ڵ���5�Ķ��滻Ϊ1
	printV(v1);

	vector<int> v3;
	v3.push_back(2);
	v3.push_back(4);
	v3.push_back(6);
	swap(v1, v3);
	printV(v1);

}

void main312()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	/*
	template<class _InIt,
		class _Ty>
		_NODISCARD inline _Ty accumulate(_InIt _First, const _InIt _Last, _Ty _Val)
	{	// return sum of _Val and all in [_First, _Last)
		return (_STD accumulate(_First, _Last, _Val, plus<>()));
	}*/

	//ͷ�ļ��ڡ�numeric��
	int tmp = accumulate(v1.begin(), v1.end(), 100);   //�����ۼ�֮���ټ���100
	cout << tmp << endl;

	fill(v1.begin(), v1.end(), 8);     //��8������������
	printV(v1);
}

void main314()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);

	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);

}
int main()
{
	
	//main31();   //for_each()  
	//main32();     //transform()
	//main33();       //���߱Ƚ�
	//main34();   //��������㷨adjacent_find()
	//main35();     //���ֲ����㷨binary_search()
	//main36();       //�����ظ��Ĵ���count(),�Լ��������Ĳ��Ҹ���count_if()
	//main37();       //find()��find_if()
	//main38();      //merge()
	//main39();           //sort()�Զ���������������
	//main310();            //random_shuffle()���ϴ�� �� ����reverse()
	//main311();    //copy()���� �� �滻replace()/replace_if() ��swap()
	//main312();     //accumulate()��������  �� fill()������ɺ���
	main314();    //�������� 1.���� set_union(),2.���� set_intersection(),3.� set_difference()������һ�������д��ڵڶ���������û�е�Ԫ��
	system("pause");
	return 0;
}