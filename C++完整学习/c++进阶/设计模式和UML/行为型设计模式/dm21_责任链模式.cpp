#include<iostream>
#include<list>
using namespace std;

//struct Teacher
//{
//	char name;
//	int age;
//	Teacher* next;
//};

//�쳵����һ��֮��Ҫ�����񴫵ݵ���һ��
class CarHandle
{
public:
	virtual void HandleCar() = 0;
	CarHandle* setNextHandle(CarHandle * handle)
	{
		m_handle=handle;
		return m_handle;
	}
protected:
	CarHandle * m_handle;
};

class HeadCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "����  ��ͷ" << endl;
		//�����공ͷ �Ժ� �����񴫵ݸ� ��һ��������
		if (m_handle != NULL)
		{
			m_handle->HandleCar();      //�൱������ṹ��next��ֵ
		}
	}
};

class BodyCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "����  ����" << endl;
		//�����공�� �Ժ� �����񴫵ݸ� ��һ��������
		if (m_handle != NULL)
		{
			m_handle->HandleCar();         
		}
	}
};

class TailCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "����  ��β" << endl;
		//�����공β �Ժ� �����񴫵ݸ� ��һ��������
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};
int main212()
{
	CarHandle *headcarhandle = new HeadCarHandle;
	CarHandle *bodycarhandle = new BodyCarHandle;
	CarHandle *tailcarhandle = new TailCarHandle;

	//����Ĵ����ϵ,�����߼������Զ���
	headcarhandle->setNextHandle(tailcarhandle);
	tailcarhandle->setNextHandle(bodycarhandle);
	bodycarhandle->setNextHandle(NULL);

	headcarhandle->HandleCar();     //��һ�������߿�ʼ����

	//ҵ���߼��ڿͻ���ʵ�֣�������������ģʽ
	/*headcarhandle->HandleCar();
	bodycarhandle->HandleCar();
	tailcarhandle->HandleCar();*/

	delete tailcarhandle;
	delete bodycarhandle;
	delete headcarhandle;


	system("pause");
	return 0;
}