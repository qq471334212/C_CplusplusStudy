#include<iostream>
#include<deque>

using namespace std;

int main()
{

	deque<int> de;
	de.push_front(12);
	de.push_front(13);
	de.push_front(14);

	deque<int>::iterator ite = de.begin();

	for (ite; ite != de.end(); ite++)
	{
		cout << *ite << endl;
	}
}