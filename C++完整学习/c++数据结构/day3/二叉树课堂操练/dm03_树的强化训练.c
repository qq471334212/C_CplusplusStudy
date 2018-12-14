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


void countLeaf2(BitNode *T, int *sum)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			*sum = (*sum) + 1;
		}
		if (T->lchild)
		{
			countLeaf2(T->lchild, sum);
		}
		if (T->rchild)
		{
			countLeaf2(T->rchild, sum);
		}
	}
}

int Depth(BitNode *T)
{
	int depthValue = 0;
	int depthLeft = 0;
	int depthRight = 0;
	if (T == NULL)
	{
		return depthValue;
	}
	
	depthLeft = Depth(T->lchild);   //���������ĸ߶�

	depthRight = Depth(T->rchild);  //���������ĸ߶�

	depthValue = 1 + ((depthLeft > depthRight) ? depthLeft : depthRight);
	return depthValue;
}
BitNode *copyTree(BitNode *T)
{
	BitNode *newNode = NULL;
	BitNode *newLp = NULL;
	BitNode *newRp = NULL;

	if (T == NULL)
	{
		return NULL;
	}

	if (T->lchild != NULL)
	{
		newLp = copyTree(T->lchild);    //copy������
	}
	else
	{
		newLp = NULL;
	}

	if (T->rchild != NULL)
	{
		newRp = copyTree(T->rchild);    //copy������
	}
	else
	{
		newRp = NULL;
	}

	//�����ڴ�ռ�
	newNode = (BitNode *)malloc(sizeof(BitNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->lchild = newLp;
	newNode->rchild = newRp;
	//��ֵ����
	newNode->data = T->data;
	return newNode;
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

	{
		int mysum = 0;
		countLeaf2(&t1, &mysum);
		printf("Ҷ�ӽڵ�ĸ�����%d \n", mysum);
	}

	printf("���ĸ߶�Ϊ��%d\n",Depth(&t1));

	//�����������
	printf("inOrder old:");
	inOrder(&t1);
	printf("\n");

	{
		//������
		BitNode *root = copyTree(&t1);
		printf("inOrder new:");
		inOrder(root);
	}

	system("pause");
	return;
}
