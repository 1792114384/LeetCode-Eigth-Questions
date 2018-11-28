#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int myAtoi(char* str)
{ 
	//符号标志位
	int flag = 0;
	//最后的数
	long int sum = 0;
	assert(str);
	//去掉前面的空格
	while (*str == ' ')
	{
		str++;
	}
	//第一个字符为'+',并且保证后面紧跟着的是数字字符
	if (*str == '+' && ('0' <= *(str + 1) && *(str + 1) <= '9'))
	{
		flag = 1;
		str++;
	}
	//第一个字符为'-',并且保证后面紧跟着的是数字字符
	else if (*str == '-' && ('0' <= *(str + 1) && *(str + 1) <= '9'))
	{
		flag = -1;
		str++;
	}

	while (*str)
	{
		//判断是否是数字字符
		if (*str >= '0' && *str <= '9')
		{
			sum = (*str - '0') + sum * 10;
		}
		//只要一个不是，直接退出
		else
		{
			break;
		}
		//及时判断当前数字是否已经超过int的范围
		if (sum > INT_MAX)
		{
			if (flag == -1)
				return INT_MIN;
			else
				return INT_MAX;
		}
		str++;
	}
	
	if (flag == -1)
	{
		return -1 * sum;
	}
	return sum;
}

int main()
{
	char *str = " 987";
	int a = atoi(str);
	printf("%d\n", a);
	a = myAtoi(str);
	printf("%d\n", a);
	system("pause");
	return 0;
}