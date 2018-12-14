#pragma once
//�ڲ���Ԫ��ʱ������������Ӧ��ÿһ��T��������
//��������Ӧ���ܷ���ڵ� ����ڵ� ==�� ˼�����

//��ô������ ===�� linklist ������

template <typename T>   //ʵ�ַ��ͱ��
struct Node
{
	T t;
	Node<T> *next;
	//Node<T> *pre;    //����˫������

};

template <typename T>   //ʵ�ַ��ͱ��

class LinkList
{
public:
	LinkList();
	~LinkList();

	//�����ʽ������
	int clear();

	//��ȡ��ʽ����
	int getlen();

	//ָ��λ�ò���ڵ�
	int Insert(T &t, int pos);

	//��ȡָ��λ�ýڵ�
	int Get(int pos, T &t);

	//ɾ���ö�λ�ýڵ�
	int Del(int pos, T &t);
private:
	Node<T> *head;    //�����ͷ�ڵ�
	int len;
};

