#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class myArray
{
public:
	myArray(int len);
	~myArray();
	int &operator [](int index);
	int getLen();

	class eSize {
	public:
		eSize(int size)
		{
			m_size = size;
		}
		virtual void printErr()
		{
			cout << "size: " << m_size << " ";
		}
		virtual ~eSize() {}
	protected:             //���Ա�����ʹ��
		int m_size;
	};        //�����쳣
    //�쳣�࣬�ڲ��࣬����
	class eNegative :public eSize{
	public:
		eNegative(int size) :eSize(size)
		{
		
		}

		virtual void printErr()
		{
			cout << "sizeΪ����: " << m_size << " ";
		}
		~eNegative() {}
	};    
	class eZero :public eSize {
	public:
		eZero(int size) :eSize(size)
		{

		}
		virtual void printErr()
		{
			cout << "sizeΪ0: " << m_size << " ";
		}
		~eZero() {}
	};
	class eTooBig :public eSize {
	public:
		eTooBig(int size) :eSize(size)
		{

		}
		virtual void printErr()
		{
			cout << "size����: " << m_size << " ";
		}
		~eTooBig() {}
	};
	class eTooSmall :public eSize {
	public:
		eTooSmall(int size) :eSize(size)
		{

		}
		virtual void printErr()
		{
			cout << "size��С: " << m_size << " ";
		}
		~eTooSmall() {}
	};


private:
	int *m_space;
	int m_len;
};

myArray::myArray(int len) {
	if (len < 0)
	{
		throw eNegative(len);
	}
	else if (len == 0)
	{
		throw eZero(len);
	}
	else if (len > 1000)
	{
		throw eTooBig(len);
	}
	else if (len < 3)
	{
		throw eTooSmall(len);
	}
	m_len = len;
	m_space = new int[len];
}

myArray::~myArray() {
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
	}
	m_len = 0;
}

int &myArray::operator [](int index)
{
	return m_space[index];
}

int myArray::getLen()
{
	return this->m_len;
}

int main42()
{
	int i = 0;
	try {
		myArray a(1);
	}
	catch (myArray::eSize &e)
	{
		e.printErr();           //������̬
	}
	catch (...)
	{
	}
	system("pause");
	return 0;
}

//ÿ���쳣�඼Ҫ�ֱ�д��̫�����ˣ�����ü̳�
int main41()
{
	int i = 0;
	try {
		myArray a(-5);
	}
	catch (myArray::eNegative &e)
	{
		cout << "eNegative �����쳣" << endl;
	}
	catch (myArray::eZero &e)
	{
		cout << "eZero �����쳣" << endl;
	}
	catch (myArray::eTooBig &e)
	{
		cout << "eTooBig �����쳣" << endl;
	}
	catch (myArray::eTooSmall &e)
	{
		cout << "eTooSmall �����쳣" << endl;
	}
	catch (...)
	{
		cout << "���� �����쳣" << endl;
	}
	/*for (i = 0; i < a.getLen(); i++)
	{
		a[i] = i + 1;
		cout << a[i] << " ";
	}*/
	system("pause");
	return 0;
}
