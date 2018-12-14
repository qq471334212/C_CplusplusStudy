#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"
#include"LinkList.h"   

#include"baseFunc.h"

int match(char left, char right)
{
	int ret = 0;
	switch (left)
	{
	case '<':
		ret = (right == '>');    //���ƥ�䷵��1�������ƥ�䷵��0
		break;
	case '(':
		ret = (right == ')');    //���ƥ�䷵��1�������ƥ�䷵��0
		break;
	case '[':
		ret = (right == ']');    //���ƥ�䷵��1�������ƥ�䷵��0
		break;
	case '{':
		ret = (right == '}');    //���ƥ�䷵��1�������ƥ�䷵��0
		break;
	case '\'':
		ret = (right == '\'');    //���ƥ�䷵��1�������ƥ�䷵��0
		break;
	case '\"':
		ret = (right == '\"');    //���ƥ�䷵��1�������ƥ�䷵��0
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}



//���ַ���һ��ɨ�裬������ջ����
int scanner(const char *code)
{
	LinkStack* stack = LinkStack_Create();  //ջ�ľ��������һ��ջ
	int ret = 0, i = 0;

	while (code[i] != '\0')
	{
		if (isLeft1(code[i]))
		{
			LinkStack_Push(stack, (void*)(code + i));   //��������ţ�ѹ��ջ��
		}

		if(isRight1(code[i]))
		{
			char *c = (char *)LinkStack_Pop(stack);     //�����ҷ��ţ�����ǰջ��Ԫ������ŵ���������ƥ�䣬��ɹ�����ɨ����һ���ַ���ʧ����ֱ������
			if ((c == NULL) || !match(*c, code[i]))
			{
				printf("%c does not match!\n", code[i]);
				ret = 0;
				break;
			}
		}
		i++;
	}

	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0')) //ɨ��������ջΪ�գ����ʾ�ɹ���ջ�ǿգ����ʾʧ��
	{
		printf("Succeed!\n");
		ret = 1;
	}
	else
	{
		while (LinkStack_Size(stack) > 0)
		{
			char *c = (char *)LinkStack_Pop(stack);
			printf("δƥ��ķ���Ϊ��  %c\n", *c);
		}
		printf("Invalid code\n");
		ret = 0;
	}

	LinkStack_Destroy(stack);
	return ret;
}

void main2()
{
	const char* code = "#include<stdio.h)";
	scanner(code);
	system("pause");
	return;
}