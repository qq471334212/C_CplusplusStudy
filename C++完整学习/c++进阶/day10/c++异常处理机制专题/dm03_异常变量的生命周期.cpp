#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//��ͳ���������
int my_strcpy(char *to, char *from)
{
	if (from == NULL)
	{
		return 1;
	}
	if (to == NULL)
	{
		return 2;
	}
	if (*from == 'a')
	{
		return 3;
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	return 0;
}

//throw int�����쳣
void my_strcpy1(char *to, char *from)
{
	if (from == NULL)
	{
		throw 1;
	}
	if (to == NULL)
	{
		throw 2;
	}
	if (*from == 'a')
	{
		throw 3;
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

//throw char*�����쳣
void my_strcpy2(char *to, char *from)
{
	if (from == NULL)
	{
		throw "func my_strcpy() err: Դbuf����\n";
	}
	if (to == NULL)
	{
		throw "func my_strcpy() err: Ŀ��buf����\n";
	}
	if (*from == 'a')
	{
		throw "func my_strcpy() err: �������̳���\n";
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

class BadSrcType
{
public:
	BadSrcType() { cout << "BadSrcType���캯����" << endl; }
	BadSrcType(const BadSrcType & bst) { cout << "BadSrcType�������캯����" << endl; }
	~BadSrcType() { cout << "BadSrcType����������" << endl; }
};

class BadDecType
{
public:
	BadDecType() { cout << "BadDecType���캯����" << endl; }
	BadDecType(const BadDecType & bdt) { cout << "BadDecType�������캯����" << endl; }
	~BadDecType() { cout << "BadDecType����������" << endl; }
};

class BadProType
{
public:
	BadProType() { cout << "BadProType���캯����" << endl; }
	BadProType(const BadProType & bpt) { cout << "BadProType�������캯����" << endl; }
	~BadProType() { cout << "BadProType����������" << endl; }
};

//���������쳣
void my_strcpy3(char *to, char *from)
{
	if (from == NULL)
	{
		throw BadSrcType();    //�᲻��������������أ�
	}
	if (to == NULL)
	{
		throw BadDecType();
	}
	if (*from == 'a')
	{
		cout << "��ʼBadProType�����쳣....." << endl;
		throw BadProType();
	}

	if (*from == 'b')
	{
		throw &(BadProType());   //�׳���ַ����ָ�����ͱ�����
	}

	if (*from == 'c')
	{
		throw new BadProType;   //�׳���ַ����ָ�����ͱ����񣬲��������������Ұָ�룬����ȫ
	}


	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

int main13()
{
	int ret = 0;
	char buf1[] = "bsadsad";
	char buf2[1024] = { 0 };
	//char *buf2 = NULL;
	/*
	ret = my_strcpy(buf2, buf1);
	if (ret != 0)      //��ͳC���Դ�����
	{
		switch (ret)
		{
		case 1:
			cout << "func my_strcpy() err: Դbuf����" << endl;
			break;
		case 2:
			cout << "func my_strcpy() err: Ŀ��buf����" << endl;
			break;
		case 3:
			cout << "func my_strcpy() err: �������̳���" << endl;
			break;
		default:
			cout << "func my_strcpy() err: δ֪����" << endl;
			break;
		}
	}
	*/


	//C++����int���ͱ���
	//{
	//	try {
	//		//my_strcpy1(buf2, buf1);
	//		my_strcpy2(buf2, buf1);
	//	}
	//	catch (int e)     //����e����д��Ҳ���Բ�м //����int ����
	//	{
	//		cout << e <<"int �����쳣" << endl;
	//	}
	//	catch (const char *c)     //����char *����  //���ָ����ڴ���������׳���ʱ������
	//	{
	//		cout << c << "const char* �����쳣" << endl;
	//	}
	//	catch (...)
	//	{
	//		cout << "δ֪ �����쳣" << endl;
	//	}
	//}


	//����������쳣
	{
		try {
			my_strcpy3(buf2, buf1);
		}
		catch (int e)     //����e����д��Ҳ���Բ�м //����int ����
		{
			cout << e << "int �����쳣" << endl;
		}
		catch (const char *c)     //����char *����  //���ָ����ڴ���������׳���ʱ������
		{
			cout << c << "const char* �����쳣" << endl;
		}
		catch (BadSrcType e)      //�׳�ʱ���ǰ��������󿽱���e������e������������
		{                         //�������ԣ��ǰ��������󿽱���e�������˿������캯��
			cout << "func my_strcpy() err: Դbuf���� BadSrcType�����쳣" << endl;
		}
		catch (BadDecType e)     
		{
			cout << "func my_strcpy() err: Ŀ��buf���� BadDecType�����쳣" << endl;
		}
		/*
		catch (BadProType e)     ����1�������쳣ʱʹ��һ���쳣����������п����������
		{
			cout << "func my_strcpy() err: �������̳��� BadProType�����쳣" << endl;
		}
		*/

		//�����ò�׽����õ�
		//����2��ʹ�����õĻ�����ʹ���׳�ʱ����������
		catch (BadProType &e)
		{
			cout << "func my_strcpy() err: �������̳��� BadProType�����쳣" << endl;
		}

		//����3��ָ����Ժ�����Ԫ��һ��׽�����Ƕ���Ԫ�غ����ò�����дһ��
		catch (BadProType *e)    //�������ϸ���������ƥ��ģ��׳�����Ԫ�أ�����ָ�����ͽ��ղ�����Ҫ�򲶻񵽣����׳�ҲҪ��ָ������
			                     //�������Ѿ��������ˣ��γ�Ұָ�롣���ȶ������Ҫ��̬������������
		{
			cout << "func my_strcpy() err: �������̳��� BadProType�����쳣������ָ������" << endl;
			delete e;
		}
		catch (...)
		{
			cout << "δ֪ �����쳣" << endl;
		}
	}

	system("pause");
	return 0;
}