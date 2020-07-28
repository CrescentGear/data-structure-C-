//未写完（10/25）
//测试点0 sample乱序，一般的Y&N 未通过
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node * List;

struct Node
{
	int number;
	List next;
};

int pop(List S);
void push(int number , List S);
int IsEmpty(List S);
List Input(int N);
List Input1();
int Is(List S,List check,int M);

int main()
{
	int M, N, K;//M是最大容量 N是长度 K是需要检查几个表
	scanf("%d %d %d",&M,&N,&K);
	if (M<0||N<0||K<0)
	{
		return 0;
	}
	int i,result;
	i = 0;
	result = 0;
	List check;
	check = Input1();
	for (i=0;i<K;i++)
	{
		List S1;
		S1 = Input(N);
		result = Is( S1,check,M);
		if (result==1)
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

int IsEmpty(List S)
{
	if (S->next==NULL)
	{
		return 1;
	}
	return 0;
}

int pop(List S)
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

void push(int number , List S)
{
	List temp;
	temp = (List)malloc(sizeof(struct Node));
	temp->number = number;
	temp->next = S->next;
	S->next = temp;
}

List Input(int N)
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
	free(cycle);
	return S;
}

List Input1( )
{
	List S;
	List temp1;
	S = (List)malloc(sizeof(struct Node));
	S->next = NULL;
	return S;
}

int Is(List S1, List check,int M)
{
	int number;
	int number1;
	int number2;
	int count;
	int flag;
	flag = 0;
	count = 1;
	number = 1;
	number2 = 0;
	number1 = 0;
	List S,check1;
	S = S1;
	check1 = check;

	while (S)
	{
		if (!S)
		{
			return 0;
		}
		if (flag==0)
		{
			flag = 1;
			push(1,check1);
		}
		number1 = S->number;
		number2 = pop(check1);
		if (number2==number1)
		{
			S = S->next;
			count--;
		}
		else if(number2<number1)
		{
			push(number2, check1);
			number++;
			push(number, check1);
			count++;
			if (count>M||count<0)
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
