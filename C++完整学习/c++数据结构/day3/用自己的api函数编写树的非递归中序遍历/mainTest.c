#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"

//��������ʾ�������Ķ���
typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;   //���ӽڵ���Һ��ӽڵ�

}BitNode, *BiTree;

//���ʣ�������
//���ֱ����ĵݹ���ʽڵ�·������һ���ģ�ֻ�Ƿ��ʽڵ��ʱ����һ�����ص㣡��������

//�ݹ��������
void inOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//����������
	inOrder(root->lchild);
	//�������ڵ�
	printf("%d ", root->data);
	//����������
	inOrder(root->rchild);
}

//�ǵݹ��������
/*
1.�ýڵ�������������ڵ���ջ���������������򽫸ýڵ���ջ
2.���ýڵ��������������ظ�����1����û�У��ڵ������ϣ�������ջ��ָʾ���˵�ջ���ڵ�λ��
�������������ظ�����1����ջΪ�գ���������
*/

//һֱ�����ߣ��ҵ�������������

//��C++��STL stackģ�弰�������Լ�д��linkstack�⺯���滻��
BitNode* goLeft(BitNode *T, LinkStack *s)
{
	if (T == NULL)
	{
		return NULL;
	}
	while (T->lchild)
	{
		//s.push(T);         //�����������ڵ���ջ
		LinkStack_Push(s, (void *)T);
		T = T->lchild;     //��ǰ�ڵ������ƶ�
	}
	return T;
}
void InOrder2(BitNode *T)
{
	BitNode* t = NULL;            //�������ڵ�
	//stack<BitNode *> s;          //��STLģ����stackջ�ⶨ��һ��ջ
	LinkStack *s = LinkStack_Create();

	t = goLeft(T, s);
	while (t)
	{
		printf("%d ", t->data);

		//���t�����������ظ�����1
		if (t->rchild != NULL)
		{
			t = goLeft(t->rchild, s);   //������������������
		}
		//else if (!s.empty())            //��û�У��ڵ������ϣ�������ջ��ָʾ���˵�ջ���ڵ�λ��
		else if (LinkStack_Size(s)>0)
		{
			//t = s.top();                //��ȡջ��Ԫ�غ󵯳�
			//s.pop();
			t = (BitNode *)LinkStack_Pop(s);
		}
		else                            //��û�У��ڵ������ϣ�������ջΪ��,��������
		{
			t = NULL;
		}
	}
}



void main()
{

	BitNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BitNode));
	memset(&t2, 0, sizeof(BitNode));
	memset(&t3, 0, sizeof(BitNode));
	memset(&t4, 0, sizeof(BitNode));
	memset(&t5, 0, sizeof(BitNode));   //�ڵ�ȫ����ʼ������ֹĳ���ڵ��С��2�����Ұָ��
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//���佨����ϵ
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	//�����������
	printf("inOrder old:");
	inOrder(&t1);
	printf("\n");

	printf("inOrder new:");
	InOrder2(&t1);
	printf("\n");

	system("pause");
	return;
}