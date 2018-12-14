#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

//函数对象实现 数据类型 和 算法 的分离
//plus函数是两个参数的参数列表，可以通过源代码看到
void main21()
{
	/*
	template<class _Ty = void>
	struct plus
	{	// functor for operator+
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator+ to operands
			return (_Left + _Right);
		}
	};*/

	plus<int> intadd;
	int x = 10;
	int y = 20;
	int z = intadd(x, y);
	cout << "z = " << z << endl;

	plus<string> stringadd;
	string s1 = "yanghang";
	string s2 = "zhangzifan";
	string s3 = stringadd(s1, s2);
	cout << "s3 = " << s3 << endl;

	vector<string> v1;
	v1.push_back("aaa");
	v1.push_back("bbb");
	v1.push_back("ddd");
	v1.push_back("ccc");
	v1.push_back("bbb");
	v1.push_back("bbb");

	/*
	template<class _Ty = void>
	struct greater
	{	// functor for operator>
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator> to operands
			return (_Left > _Right);
		}
	};
	*/


	sort(v1.begin(), v1.end(), greater<string>());      //从大到小排列
	                                                    //默认或者less<>从小到大
	for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}

	//要用到函数适配器
	//equal_to有两个参数，left参数来自容器，right参数来自sc
	//重点！！！！===》使用bind2nd函数适配器，将预定义函数对象与第二个参数进行绑定

	//求字符串“ccc”出现的个数
	string sc = "ccc";
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
	cout << "ccc元素的个数：" << num <<endl;
}

class IsGreat
{
public:
	IsGreat(int i)
	{
		m = i;
	}

	bool operator()(int &num)
	{
		return (num > m);
	}
private:
	int m;
};

void main22()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1:" << num1 << endl;

	//通过谓词，求大于2的个数
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << "num2:" << num2 << endl;

	//通过预定义函数对象
	//greater（）有两个参数，左参数来自容器，右参数来自绑定的2
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),2));    //通过适配器为匿名函数对象绑定参数
	cout << "num3:" << num3 << endl;

	//求奇数的个数
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "奇数的个数num4:" << num4 << endl;

	//求偶数的个数
	int num5 = count_if(v1.begin(), v1.end(),not1(bind2nd(modulus<int>(), 2)));
	cout << "偶数的个数num5:" << num5 << endl;
}

int main2()
{
	//main21();
	main22();   //函数适配器综合案例
	system("pause");
	return 0;
}
