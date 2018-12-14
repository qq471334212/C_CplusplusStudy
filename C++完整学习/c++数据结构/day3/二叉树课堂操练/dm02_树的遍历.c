#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//��������ʾ��
typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;   //���ӽڵ���Һ��ӽڵ�

}BitNode, *BiTree;

//���ʣ�������
//���ֱ����ĵݹ���ʽڵ�·������һ���ģ�ֻ�Ƿ��ʽڵ��ʱ����һ�����ص㣡��������
//�������
void preOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//�������ڵ�
	printf("%d ", root->data);
	//����������
	preOrder(root->lchild);
	//����������
	preOrder(root->rchild);
}

//�������
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

//�������
void postOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//����������
	postOrder(root->lchild);
	//����������
	postOrder(root->rchild);
	//�������ڵ�
	printf("%d ", root->data);
}

int sum;          //ȫ�ֱ�����ɲ���
void countLeaf(BitNode *T)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			sum++;
		}
		if (T->lchild)
		{
			countLeaf(T->lchild);
		}
		if (T->rchild)
		{
			countLeaf(T->rchild);
		}
	}
}

void countLeaf2(BitNode *T,int *sum)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			*sum = (*sum) + 1;
		}
		if (T->lchild)
		{
			countLeaf2(T->lchild,sum);
		}
		if (T->rchild)
		{
			countLeaf2(T->rchild,sum);
		}
	}
}

void countLeaf3(BitNode *T, int *sum)
{
	if (T)
	{
		if (T->lchild)
		{
			countLeaf3(T->lchild, sum);
		}
		if (T->lchild == NULL && T->rchild == NULL)   //���жϷ���ǰ�к󶼿��ԣ���Ϊ����·������һ����
		{
			*sum = (*sum) + 1;
		}
		if (T->rchild)
		{
			countLeaf3(T->rchild, sum);
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

	sum = 0;
	countLeaf(&t1);
	printf("Ҷ�ӽڵ�ĸ�����%d \n", sum);

	{
		int mysum = 0;
		countLeaf2(&t1, &mysum);
		printf("Ҷ�ӽڵ�ĸ�����%d \n", mysum);
	}

	{
		int mysum1 = 0;
		countLeaf3(&t1, &mysum1);
		printf("Ҷ�ӽڵ�ĸ�����%d ", mysum1);
	}

	////���ı���
	//printf("��������Ľ�� ��");
	//preOrder(&t1);
	//printf("\n");

	//printf("��������Ľ�� ��");
	//inOrder(&t1);
	//printf("\n");

	//printf("��������Ľ�� ��");
	//postOrder(&t1);
	//printf("\n");


	system("pause");
	return;
}
