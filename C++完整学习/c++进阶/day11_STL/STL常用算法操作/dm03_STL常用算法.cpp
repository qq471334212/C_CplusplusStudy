#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"iterator"  //输出流的头文件
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

//for_each()和transform()常用函数
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


	//for_each()返回的是函数对象
	for_each(v1.begin(), v1.end(), showVector);    //函数对象或者回调函数的入口地址
	cout << endl;
	for_each(v1.begin(), v1.end(), CMyShow());
	cout << endl;

	CMyShow c;
	CMyShow c1 = for_each(v1.begin(), v1.end(), c);  //给c1初始化
	cout << endl;
	c.printNum();           //c和c1是两个不同的对象
	c1.printNum();          //显示调用次数

	c1 = for_each(v1.begin(), v1.end(), c1);          //给c1赋值
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

	//使用回调函数
	transform(v1.begin(), v1.end(), v1.begin(), increase);
	printV(v1);

	//使用预定义函数对象
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	printV(v1);

	//使用函数适配器
	list<int> mylist;
	mylist.resize(v1.size());
	transform(v1.begin(), v1.end(), mylist.begin(), bind2nd(multiplies<int>(),10));
	printL(mylist);

	//transform也可以直接把运算结果输出屏幕
	transform(v1.begin(), v1.end(),ostream_iterator<int>(cout," "), negate<int>());

	//也可以把两个容器的结果通过运算放到第三个容器中
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

	//会报错，因为transform对回调函数对象有要求，需要有返回值
	//transform ==》*_UDest = _Func(*_UFirst);
	//for_each  ==》_Func(*_UFirst);

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

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());    //查找第一个重复出现的位置，并且返回一个迭代器

	if (it == v1.end())
	{
		cout << "未找到重复的元素！" << endl;
	}
	else
	{
		cout << *it << endl;
	}

	int index = distance(v1.begin(), it);       //返回的迭代器是重复元素第一个出现的位置
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
		cout << "找到了7！" << endl;
	}
	else
	{
		cout << "没有找到7！" << endl;
	}
}

//一元谓词
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
		cout << "没有找到7！" << endl;
	}
	else
	{
		cout << "7的个数为: " << num << endl;
	}

	size_t num1 = count_if(v1.begin(), v1.end(), GreaterThree);   //可对自定义数据类型进行条件查找

	if (num1 == 0)
	{
		cout << "没有找到符合条件！" << endl;
	}
	else
	{
		cout << "大于3的个数为: " << num1 << endl;
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

	//查找对应元素的位置
	vector<int>::iterator it = find(v1.begin(), v1.end(),5);
	cout << "*it: " << *it << endl;

	//第一个大于三的位置
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
	student s1("老大", 1);
	student s2("老二", 2);
	student s3("老三", 3);
	student s4("老四", 4);
	vector<student> v1;

	v1.push_back(s4);
	v1.push_back(s1);
	v1.push_back(s3);
	v1.push_back(s2);

	for (vector<student>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		it->printT();
	}
	//自定义类型的排序，实现算法和数据类型的分离
	//通过函数对象的调用
	sort(v1.begin(), v1.end(), CompareStudent);   //无返回值
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

	replace(v1.begin(), v1.end(), 3, 7);          //元素为3的替换为7
	printV(v1);

	replace_if(v1.begin(), v1.end(), great_equal_five, 1);       //大于等于5的都替换为1
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

	//头文件在“numeric”
	int tmp = accumulate(v1.begin(), v1.end(), 100);   //遍历累加之后再加上100
	cout << tmp << endl;

	fill(v1.begin(), v1.end(), 8);     //用8填充遍历的区域
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
	//main33();       //两者比较
	//main34();   //查找相关算法adjacent_find()
	//main35();     //二分查找算法binary_search()
	//main36();       //查找重复的次数count(),以及加条件的查找个数count_if()
	//main37();       //find()和find_if()
	//main38();      //merge()
	//main39();           //sort()自定义数据类型排序
	//main310();            //random_shuffle()随机洗牌 和 倒序reverse()
	//main311();    //copy()拷贝 和 替换replace()/replace_if() 和swap()
	//main312();     //accumulate()遍历计算  和 fill()填充生成函数
	main314();    //集合运算 1.并集 set_union(),2.交集 set_intersection(),3.差集 set_difference()保留第一个序列中存在第二个序列中没有的元素
	system("pause");
	return 0;
}