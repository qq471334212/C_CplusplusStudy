#include<iostream>
#include<string>
using namespace std;

//Current18
//Current220
//Adapter

//�ͻ�����ӿ�
class Current18V
{
public:
	virtual void useCurrent18V() = 0;
};

//ԭ�ӿ�
class Current220V
{
public:
	void useCurrent220V()
	{
		cout << "��ӭʹ��220V��" << endl;
	}
};

class Adapter: public Current18V
{
public:
	Adapter(Current220V *current)
	{
		m_current = current;
	}
	virtual void useCurrent18V()
	{
		cout << "������ʹ������ 220V" << endl;
		m_current->useCurrent220V();
	}
private:
	Current220V * m_current;
};

void main141()
{
	Current220V    *current220V = NULL;
	Adapter        *ad = NULL;

	current220V = new Current220V;
	ad = new Adapter(current220V);

	ad->useCurrent18V();

	delete current220V;
	delete ad;

}
int main14()
{
	main141();
	system("pause");
	return 0;
}