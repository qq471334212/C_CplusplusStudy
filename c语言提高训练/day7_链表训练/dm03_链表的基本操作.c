#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�о����ԣ����ܰ�������Ҫ�õĽṹ��
typedef  struct Node
{
	int data;
	struct Node *next;
}SLIST;

//�������
//1.����һ���������ܵĽṹ��
typedef struct myNode
{
	struct myNode *next;
}myNode;
//2.����洢ҵ�����ݵĽṹ��ȥ��������
typedef struct Teacher
{
	char name[64];
	int  age;
	myNode node;      //�����ַ���Ľṹ���ַƫ����Ϊ64+4=68
}Teacher;

//3.�Ż���ҵ������С����ĵ�ַ���Ľṹ��ĵ�ַ�ص�
typedef struct Teacher1
{
	myNode node;
	char name[64];
	int  age;
}Teacher1;

void testMynode()
{
	Teacher t1, t2, t3;
	t1.node.next = &(t2.node);
	t2.node.next = &(t3.node);
	t3.node.next = NULL;
}

//����api
SLIST * SList_Creat();   //��������
int SList_Print(SLIST *pHead);    //������ӡ����
int SList_NodeInsert(SLIST *pHead, int x, int y);   //��xֵ֮ǰ ����yֵ
int SList_NodeDelete(SLIST *pHead, int x);   //ɾ���ڵ�
int SList_Destroy(SLIST *pHead);   //��������

SLIST * SList_Creat()   
{
	//1.���Ͻ������룬malloc�½ڵ㣬-1Ϊ����
	//2.�½ڵ�������
	//3.���½ڵ��ɵ�ǰ�ڵ㣬��������ָ�����pHead��pCurrent��pM
	int data = 0;
	SLIST *pHead, *pCur, *pTmp;

	//����ͷ�ڵ�
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	printf("please enter you data: ");
	scanf("%d", &data);

	pCur = pHead;               //��ǰ�ڵ��ʼ����ָ��ͷ

	while (data != -1)
	{
		//����ҵ��ڵ�
		pTmp = (SLIST *)malloc(sizeof(SLIST));
		if (pTmp == NULL)
		{
			return NULL;
		}
		pTmp->data = data;
		pTmp->next = NULL;     //��֤β�ڵ�Ϊnull

		pCur->next = pTmp;     //�½ڵ�������
		pCur = pTmp;           //�ѵ�ǰ�ڵ��Ƶ���һ���ڵ㣬����ڵ�β��׷��

		printf("please enter you next data: ");
		scanf("%d", &data);
	}
	return pHead;              //����ͷ�ڵ��ַ
}


int SList_Creat2(SLIST **mypHead)
{
	//1.���Ͻ������룬malloc�½ڵ㣬-1Ϊ����
	//2.�½ڵ�������
	//3.���½ڵ��ɵ�ǰ�ڵ㣬��������ָ�����pHead��pCurrent��pM
	int ret = 0;
	int data = 0;
	SLIST *pHead, *pCur, *pTmp;

	//����ͷ�ڵ�
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SList_Creat2() err: %d", ret);
		goto End;
	}
	pHead->data = 0;
	pHead->next = NULL;

	printf("please enter you data: ");
	scanf("%d", &data);

	pCur = pHead;               //��ǰ�ڵ��ʼ����ָ��ͷ

	while (data != -1)
	{
		//����ҵ��ڵ�
		pTmp = (SLIST *)malloc(sizeof(SLIST));
		if (pTmp == NULL)
		{
			ret = -2;
			printf("func malloc() err: %d", ret);
			goto End;
		}
		pTmp->data = data;
		pTmp->next = NULL;     //��֤β�ڵ�Ϊnull

		pCur->next = pTmp;     //�½ڵ�������
		pCur = pTmp;           //�ѵ�ǰ�ڵ��Ƶ���һ���ڵ㣬����ڵ�β��׷��

		printf("please enter you next data: ");
		scanf("%d", &data);
	}

End:
	if (ret != 0)
	{
		SList_Destroy(pHead);
	}
	else
	{
		*mypHead = pHead;
	}
	return ret;              //����ͷ�ڵ��ַ
}

int SList_Print(SLIST *pHead)    
{
	if (pHead == NULL)
	{
		return -1;
	}
	SLIST *pTmp = NULL;
	pTmp = pHead->next;
	printf("\nbegin \n");
	while (pTmp)
	{
		printf("%d\n", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\nend \n");
	return 0;
}

//�����������ʱע�⵱ǰ�ڵ��λ�ñ�����ǰ���ڵ��λ����
//��˲���Ӧ���������棬����ǰ�棬����ǰ���next�б���Ľڵ�λ�ñ��½ڵ�ռ��
int SList_NodeInsert(SLIST *pHead, int x, int y)   
{
	int iTag = 0;
	SLIST *pCur = NULL, *pTmp = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}

	//����ҵ��ڵ�
	pTmp = (SLIST *)malloc(sizeof(SLIST));
	if (pTmp == NULL)
	{
		return -2;
	}
	pTmp->next = NULL;
	pTmp->data = y;

	pPre = pHead;               //��ǰ�ڵ��ʼ����ָ��ͷ
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == x)
		{	
			iTag = 1;
			break;
		}
	
		pPre = pCur;
		pCur = pCur->next;
	
	}
	//�½ڵ�����ǰ��ڵ�
	pTmp->next = pPre->next;          //û���ҵ�Ҫ�����λ�õĻ�pCurΪNULL��Ҳ����Ҫ��
	pPre->next = pTmp;
	if (iTag == 1)
	{
		printf("\n�ɹ�����ڵ㣡��\n");
	
	}
	else
	{
		printf("\nû���ҵ�Ҫ����Ľڵ㣡��\n");
	}
	return 0;
}

int SList_NodeDelete(SLIST *pHead, int x)
{
	int iTag = 0;
	SLIST *pCur = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}

	pPre = pHead;               //��ǰ�ڵ��ʼ����ָ��ͷ
	pCur = pHead->next;
	while (pCur)
	{
		if (pCur->data == x)
		{
			iTag = 1; 		
			break;
		}

		pPre = pCur;
		pCur = pCur->next;
	}
	

	if (iTag == 1)
	{
		//ɾ������
		pPre->next = pCur->next;
		if (pCur != NULL)
		{
			free(pCur);
		}
		printf("\n�ɹ�ɾ���ڵ㣡��\n");

	}
	else
	{
		printf("\nû���ҵ�Ҫɾ���Ľڵ㣡��\n");
	}
	return 0;
}

//����ɾ���ڵ㣬����ɾ֮ǰҪ����һ������Ȼɾ����ǰһ���ڵ���Ҳ�����һ��Ҫɾ���Ľڵ��λ����
int SList_Destroy(SLIST *pHead)
{
	SLIST *pTmp = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
    
	while (pHead)
	{ 
		pTmp = pHead->next;    //ɾ��һ���ڵ�֮ǰ���Ȼ���˽ڵ�洢����һ���ڵ�ĵ�ַ
		free(pHead);           //ɾ���˽ڵ�
		pHead = pTmp;          //��һ���ڵ��λ�ñ�Ϊͷָ��
	}

	return 0;
}
//����Ҳ��һ�����ڵ���в�����
//��ͷ�ڵ�ָ��ĩβ��Ȼ������ǰ
//���ù�����ҲҪ������һ���ڵ��next��ַ
int SList_Reverse(SLIST *pHead)
{
	if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
	{
		return 0;
	}

	SLIST *p = NULL;  //ǰ��ָ��
	SLIST *q = NULL;  //��ǰָ��
	SLIST *t = NULL;  //�����һ���ڵ�

	//��ʼ��
	/*p = pHead;
	q = pHead->next;*/
	p = pHead->next;
	q = pHead->next->next;

	//һ���ڵ�һ���ڵ�����  ,��������ķ���������
	while (q)
	{
		t = q->next;   //������������
		q->next = p;   //����
		p = q;         //����
		q = t;
	}

	//ͷ�ڵ��β���ڵ� ����NULL
	
	pHead->next->next = NULL;
	pHead->next = p;

	

	return 0;
}
void main()
{
	int ret = 0;
	SLIST *list = NULL;
	
	//list = SList_Creat();
	ret = SList_Creat2(&list);
	if (ret != 0)
	{
		printf("func SList_Creat2() err : %d", ret);
	}


	ret = SList_Print(list);
	if (ret != 0)
	{
		printf("func SList_Print() err : %d", ret);
	}

	ret = SList_NodeInsert(list, 20, 19);
	if (ret != 0)
	{
		printf("func SList_NodeInsert() err : %d", ret);
	}

	ret = SList_Print(list);

	ret = SList_NodeDelete(list, 19);
	if (ret != 0)
	{
		printf("func SList_NodeDelete() err : %d", ret);
	}

	ret = SList_Print(list);

	ret = SList_Reverse(list);
	if (ret != 0)
	{
		printf("func SList_Reverse() err : %d", ret);
	}

	ret = SList_Print(list);

	ret = SList_Destroy(list);
	if (ret != 0)
	{
		printf("func SList_Destroy() err : %d", ret);
	}
	system("pause");
	return;
}