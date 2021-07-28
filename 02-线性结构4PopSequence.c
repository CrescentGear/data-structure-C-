//25/25
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node * List;

struct Node     //链表
{
	int number;
	List next;
};

int pop(List S);
void push(int number , List S);
int IsEmpty(List S);
List Input(int N); //用户的输入
List Input1();     //判断栈的输入
int Is(List S,List check,int M);//判断函数

int main()
{
	int M, N, K;//M是最大容量 N是长度 K是需要检查几个表
	scanf("%d %d %d", &M, &N, &K);
	if (M < 0 || N < 0 || K < 0)    //如果输入的数字为负数，则结束程序
	{
		return 0;
	}
	int i, result;
	i = 0;
	result = 0;
	List check;
	for (i = 0; i < K; i++)  //一一判断输入的数字组是否符合要求
	{
		check = Input1();   //用来做判断的栈
		List S1;
		S1 = Input(N);  //用户的输入
		result = Is(S1, check, M); //判断结果 1为yes 0为no
		if (result == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}

int IsEmpty(List S)     //栈是否为空
{
	if (S->next==NULL)
	{
		return 1;
	}
	return 0;
}

int pop(List S)   //栈的顶部元素输出
{
	if (IsEmpty(S))
	{
		return 0;
	}
	int number;
	List temp;
	temp = S->next;
	number = temp->number;
	S->next = temp->next;
	free(temp);
	return number;
}

void push(int number , List S)  //把元素压入栈顶
{
	List temp;
	temp = (List)malloc(sizeof(struct Node));
	temp->number = number;
	temp->next = S->next;
	S->next = temp;
}

List Input(int N)  //用户的输入
{
	List S;
	List temp1,cycle;
	S = (List)malloc(sizeof(struct Node));
	S->next = NULL;
	temp1 = S;
	int i;
	i = 0;
	for (i=0;i<N;i++)
	{
		int number;
		scanf(" %d",&number);
		List temp;
		temp= (List)malloc(sizeof(struct Node));
		temp->number = number;
		temp->next = NULL;
		temp1->next = temp;
		temp1 = temp1->next;
	}
	cycle = S;
	S = S->next;
	free(cycle);  //回收空的头结点
	return S;
}

List Input1( )//判断栈的输入
{
	List S;
	List temp1;
	S = (List)malloc(sizeof(struct Node));
	S->next = NULL;
	return S;
}

int Is(List S1, List check,int M)  //判断
{
int number;
	int number1;
	int number2;
	int count;
	count = 1;
	number = 1;
	number2 = 0;
	number1 = 0;
	List S, check1;
	S = S1;
	check1 = check;
	push(1, check1);
	while (S)
	{
		if (!S)
		{
			return 0;
		}
		number1 = S->number;  //输入的数字组的元素
		number2 = pop(check1);//栈的元素
		if (number2 == number1)
		{
			S = S->next;
			count--; //数字一样出栈
			if (count == 0)
			{
				count++;
				number++;
				push(number,check1);
			}
		}
		else if (number2 < number1)
		{
			push(number2, check1);
			number++;
			push(number, check1);//数字不一样，把之前的数字入栈，同时压入一个新的数字
			count++;             //已有的数字个数+1
			if (count > M || count < 0) //判断栈的容量是否溢出
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	return 1;
}
