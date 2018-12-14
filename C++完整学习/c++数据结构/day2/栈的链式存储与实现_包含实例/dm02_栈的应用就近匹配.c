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
		ret = (right == '>');    //如果匹配返回1，如果不匹配返回0
		break;
	case '(':
		ret = (right == ')');    //如果匹配返回1，如果不匹配返回0
		break;
	case '[':
		ret = (right == ']');    //如果匹配返回1，如果不匹配返回0
		break;
	case '{':
		ret = (right == '}');    //如果匹配返回1，如果不匹配返回0
		break;
	case '\'':
		ret = (right == '\'');    //如果匹配返回1，如果不匹配返回0
		break;
	case '\"':
		ret = (right == '\"');    //如果匹配返回1，如果不匹配返回0
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}



//对字符串一次扫描，并进行栈操作
int scanner(const char *code)
{
	LinkStack* stack = LinkStack_Create();  //栈的句柄，创建一个栈
	int ret = 0, i = 0;

	while (code[i] != '\0')
	{
		if (isLeft1(code[i]))
		{
			LinkStack_Push(stack, (void*)(code + i));   //遇到左符号，压入栈中
		}

		if(isRight1(code[i]))
		{
			char *c = (char *)LinkStack_Pop(stack);     //遇到右符号，将当前栈顶元素左符号弹出，与其匹配，如成功继续扫描下一个字符，失败则直接跳出
			if ((c == NULL) || !match(*c, code[i]))
			{
				printf("%c does not match!\n", code[i]);
				ret = 0;
				break;
			}
		}
		i++;
	}

	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0')) //扫描结束如果栈为空，则表示成功；栈非空，则表示失败
	{
		printf("Succeed!\n");
		ret = 1;
	}
	else
	{
		while (LinkStack_Size(stack) > 0)
		{
			char *c = (char *)LinkStack_Pop(stack);
			printf("未匹配的符号为：  %c\n", *c);
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