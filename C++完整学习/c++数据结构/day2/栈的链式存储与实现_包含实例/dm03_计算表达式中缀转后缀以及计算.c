#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"
#include"LinkList.h"  

int value(char c)
{
	return (c - '0');
}

int express(int left, int right, char op)
{
	int ret = 0;
	switch (op)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}
	return ret;
}

int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
	return (c == '(');
}


int isRight(char c)
{
	return (c == ')');
}

void output(char c)
{
	if (c != '\0')
	{
		printf("%c", c);
	}
}

int priority(char c)
{
	int ret = 0;          //��ret��С�����������������
	if ((c == '+') || (c == '-'))
	{
		ret = 1;
	}

	if ((c == '*') || (c == '/'))
	{
		ret = 2;    
	}

	return ret;
}

//��׺���ʽת��׺���ʽ
void transform(const char* exp)
{
	int i = 0, cut = 0;;
	int len = strlen(exp);
	char *result = NULL;
	result = (char*)malloc(sizeof(char)*len);
	LinkStack* stack = LinkStack_Create();

	while (exp[i] != '\0')
	{
		if (isNumber(exp[i]))
		{
			output(exp[i]);

		}
		else if (isOperator(exp[i]))
		{
			while (priority(exp[i]) < priority((char)(int)LinkStack_Top(stack)))
			{
				output((char)(int)LinkStack_Pop(stack));

			}
			LinkStack_Push(stack, (void *)(int)exp[i]);
		}
		else if (isLeft(exp[i]))
		{
			LinkStack_Push(stack, (void *)(int)exp[i]);
		}
		else if (isRight(exp[i]))     //����������ţ�whileѭ������ջ����Ԫ�أ�ֱ��ƥ�䵽���������
		{
			while (!isLeft((char)(int)LinkStack_Top(stack)))
			{
				output((char)(int)LinkStack_Pop(stack));

			}
			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!\n");
			break;
		}
		i++;
	}

	while ((LinkStack_Size(stack) > 0) && (exp[i] == '\0'))
	{
		output((char)(int)LinkStack_Pop(stack));

	}
	LinkStack_Destroy(stack);

}

//��׺���ʽ�ļ���
int computer(const char* exp)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0, i = 0;

	while (exp[i] != '\0')
	{
		if (isNumber(exp[i]))
		{
			LinkStack_Push(stack, (void*)value(exp[i]));
		}
		else if (isOperator(exp[i]))
		{
			int right = (int)LinkStack_Pop(stack);
			int left = (int)LinkStack_Pop(stack);
			int result = express(left, right, exp[i]);

			LinkStack_Push(stack, (void*)result);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}
		i++;
	}
	//���ջ��ֻʣһ��Ԫ��ʱ���Ǽ�����
	if ((LinkStack_Size(stack) == 1) && (exp[i] == '\0'))
	{
		ret = (int)LinkStack_Pop(stack);
	}
	else
	{
		printf("Invalid expression!");
	}
	return ret;
}

void main()
{
	transform("8+(3-1)*5");
	printf("\nresult = %d", computer("831-5*+"));
	system("pause");
	return;
}