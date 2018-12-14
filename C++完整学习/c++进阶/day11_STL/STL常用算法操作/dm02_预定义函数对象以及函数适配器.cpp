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

//��������ʵ�� �������� �� �㷨 �ķ���
//plus���������������Ĳ����б�����ͨ��Դ���뿴��
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


	sort(v1.begin(), v1.end(), greater<string>());      //�Ӵ�С����
	                                                    //Ĭ�ϻ���less<>��С����
	for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}

	//Ҫ�õ�����������
	//equal_to������������left��������������right��������sc
	//�ص㣡������===��ʹ��bind2nd��������������Ԥ���庯��������ڶ����������а�

	//���ַ�����ccc�����ֵĸ���
	string sc = "ccc";
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
	cout << "cccԪ�صĸ�����" << num <<endl;
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

	//ͨ��ν�ʣ������2�ĸ���
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << "num2:" << num2 << endl;

	//ͨ��Ԥ���庯������
	//greater��������������������������������Ҳ������԰󶨵�2
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),2));    //ͨ��������Ϊ������������󶨲���
	cout << "num3:" << num3 << endl;

	//�������ĸ���
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "�����ĸ���num4:" << num4 << endl;

	//��ż���ĸ���
	int num5 = count_if(v1.begin(), v1.end(),not1(bind2nd(modulus<int>(), 2)));
	cout << "ż���ĸ���num5:" << num5 << endl;
}

int main2()
{
	//main21();
	main22();   //�����������ۺϰ���
	system("pause");
	return 0;
}
