#pragma once

template <typename T>   //ʵ�ַ��ͱ��

class SeqList
{
public:
	SeqList(int capicity);
	~SeqList();

	//��ȡ���Ա���
	int GetLength();

	//���Ա�����
	int GetCapicity();

	//ָ��λ�ò���ڵ�
	int myInsert(T &t, int pos);

	//��ȡָ��λ�ýڵ�
	int GetNode(int pos, T &t);           //�����÷���

	//ɾ���ö�λ�ýڵ�
	int DeleteNode(int pos, T &t);

	int clear();
private:
	int length;
	int capicity;
	T *pArray;      //unsigned int **node;        
				    //�ṹ���׶���ָ�룬ָ������
				    //�ö���ָ��ȽϺ�
};

