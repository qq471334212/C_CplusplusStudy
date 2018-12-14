#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
using namespace std;


//二叉链表示法，树的定义
typedef struct BitNode
{
	int data;
	struct BitNode *lchild, *rchild;   //左孩子节点和右孩子节点

}BitNode, *BiTree;

//本质！！！！
//三种遍历的递归访问节点路径都是一样的，只是访问节点的时机不一样，重点！！！！！

//递归中序遍历
void inOrder(BitNode *root)
{
	if (root == NULL)
	{
		return;
	}
	//遍历左子树
	inOrder(root->lchild);
	//遍历根节点
	printf("%d ", root->data);
	//遍历右子树
	inOrder(root->rchild);
}

//非递归中序遍历
/*
1.该节点有左子树，则节点入栈；若无左子树，则将该节点入栈
2.若该节点有右子树，则重复步骤1；若没有（节点访问完毕），根据栈顶指示回退到栈顶节点位置
访问右子树，重复步骤1；若栈为空，遍历结束
*/

//一直向左走，找到中序遍历的起点
BitNode* goLeft(BitNode *T, stack<BitNode *> &s)
{
	if(T==NULL)
	{
		return NULL;
	}
	while (T->lchild)
	{
		s.push(T);         //有左子树，节点入栈
		T = T->lchild;     //当前节点向下移动
	}
	return T;
}
void InOrder2(BitNode *T)
{
	BitNode* t = NULL;            //定义起点节点
	stack<BitNode *> s;          //用STL模板库的stack栈库定义一个栈

	t = goLeft(T, s);
	while (t)
	{
		printf("%d ", t->data);

		//如果t有右子树，重复步骤1
		if (t->rchild != NULL)
		{
			t = goLeft(t->rchild, s);   //右子树中序遍历的起点
		}
		else if (!s.empty())            //若没有（节点访问完毕），根据栈顶指示回退到栈顶节点位置
		{
			t = s.top();                //获取栈顶元素后弹出
			s.pop();
		}
		else                            //若没有（节点访问完毕），并且栈为空,遍历结束
		{
			t = NULL;
		}
	}
}


//#号法创建树
BitNode *CreateBiThrTree()
{
	BitNode *node = NULL;
	BitNode *Lp = NULL;
	BitNode *Rp = NULL;

	char h;
	scanf("%c", &h);

	if (h == '#')
	{
		return  NULL;
	}
	else
    {
		node = (BitNode *)malloc(sizeof(BitNode));
		memset(node, 0, sizeof(BitNode));
		node->data = h;
		Lp = CreateBiThrTree();  //递归构造左右子树
		if (Lp != NULL)
		{
			node->lchild = Lp;
		}
		else
		{
			node->lchild = NULL;
		}
		Rp = CreateBiThrTree();
		if (Rp != NULL)
		{
			node->rchild = Rp;
		}
		else
		{
			node->rchild = NULL;
		}
	}
	return node;
}


BitNode *CreateBiThrTree2()
{
	BitNode *tmp = NULL;

	char h;
	scanf("%c", &h);

	if (h == '#')
	{
		return  NULL;
	}
	else
	{
		tmp = (BitNode *)malloc(sizeof(BitNode));
		if (tmp == NULL)
		{
			return NULL;
		}
		tmp->data = h;
		tmp->lchild = CreateBiThrTree2();
		tmp->rchild = CreateBiThrTree2();
		return tmp;
	}
}

void FreeTree(BitNode *T)
{
	if (T == NULL)
	{
		return;
	}
	if (T->lchild != NULL)
	{
		FreeTree(T->lchild);
		T->lchild = NULL;
	}

	if (T->rchild != NULL)
	{
		FreeTree(T->rchild);
		T->rchild = NULL;
	}

	if (T != NULL)     //销毁完毕
	{
		free(T);
		T = NULL;
	}
}
int main()
{
	BitNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BitNode));
	memset(&t2, 0, sizeof(BitNode));
	memset(&t3, 0, sizeof(BitNode));
	memset(&t4, 0, sizeof(BitNode));
	memset(&t5, 0, sizeof(BitNode));   //节点全部初始化，防止某个节点度小于2，造成野指针
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//结点间建立关系
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	{

		BitNode *p = NULL;
		p = CreateBiThrTree();
	}


	//树的中序遍历
	//printf("inOrder old:");
	//inOrder(&t1);
	//printf("\n");

	//printf("inOrder new:");
	//InOrder2(&t1);
	//printf("\n");



	system("pause");
	return 0;
}