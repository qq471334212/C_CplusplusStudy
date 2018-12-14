#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"baseFunc.h"

int isLeft1(char c)
{
	int ret = 0;
	switch (c)
	{
	case '<':
	case '(':
	case '[':
	case '{':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int isRight1(char c)
{
	int ret = 0;
	switch (c)
	{
	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

