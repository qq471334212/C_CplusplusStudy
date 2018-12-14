#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class AA
{
public:
	//AA(T a, T b) { this->a = a; this->b = b; m_a++; }
	static T m_a;
private:

	//T a;
	//T b;
};

template<typename T>
T AA<T>::m_a = 0;

int main()
{
	//AA<int> a1(1,1), a2(2,2), a3(3,3);
	AA<int> a1, a2, a3;
	a1.m_a = 10;
	a2.m_a++;
	a3.m_a++;
	cout << AA<int>::m_a << endl;
	{
		AA<char> b1, b2, b3;
		b1.m_a = 'a';
		b2.m_a++;
		b3.m_a++;
		cout << AA<char>::m_a << endl;
	}
	system("pause");
	return 0;
}