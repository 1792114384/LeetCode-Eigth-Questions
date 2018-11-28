#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int myAtoi(char* str)
{ 
	//���ű�־λ
	int flag = 0;
	//������
	long int sum = 0;
	assert(str);
	//ȥ��ǰ��Ŀո�
	while (*str == ' ')
	{
		str++;
	}
	//��һ���ַ�Ϊ'+',���ұ�֤��������ŵ��������ַ�
	if (*str == '+' && ('0' <= *(str + 1) && *(str + 1) <= '9'))
	{
		flag = 1;
		str++;
	}
	//��һ���ַ�Ϊ'-',���ұ�֤��������ŵ��������ַ�
	else if (*str == '-' && ('0' <= *(str + 1) && *(str + 1) <= '9'))
	{
		flag = -1;
		str++;
	}

	while (*str)
	{
		//�ж��Ƿ��������ַ�
		if (*str >= '0' && *str <= '9')
		{
			sum = (*str - '0') + sum * 10;
		}
		//ֻҪһ�����ǣ�ֱ���˳�
		else
		{
			break;
		}
		//��ʱ�жϵ�ǰ�����Ƿ��Ѿ�����int�ķ�Χ
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