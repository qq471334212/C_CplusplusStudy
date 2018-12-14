#include<iostream>
#include<string>
using namespace std;

int main1()
{
	//string str;
	//cout << str << endl;

	string str1("adhsakjdhla");
	str1.append(4,'1');
	cout << str1;
	//str1.reserve(32);
	/*str1.resize(48);
	cout << str1 << str1.capacity() << endl;*/
	str1.at(1) = 'y';
	cout << str1;

	/*string str2("adadasd",2);
	cout << str2 << " " << str2.empty() << endl;

	string str3("adadasd", 2, 5);
	cout << str3 << " " << str3.empty() << endl;*/

	system("pause");
	return 0;
}