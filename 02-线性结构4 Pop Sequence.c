//未写完
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node * List;

struct Node
{
	int number;
	List next;
};

List Create(int n); //队列的创建
int Is(List L, int m, int n);
void AddS(int number,List L); //栈的添加
void PopS( List L); //栈的输出
int main()
{
	List list;

	int m, n, k;//m是栈的容量，n是输入的长度，k是待检测的个数
	int result;
	result = 0;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++)
	{
		list = Create(n);
		result = Is(list, m, n);
		if (result == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

List Create(int n)
{
	List L, t, cycle;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	t = L;
	for (int i = 0; i < n; i++)
	{
		List temp;
		temp = (List)malloc(sizeof(struct Node));
		temp->next = NULL;
		int number;
		scanf("%d", &number);
		temp->number = number;
		t->next = temp;
		t = temp;
	}
	cycle = L;
	L = L->next;
	free(cycle);
	return L;
}

void AddS(int number,List L)
{

	List temp;
	temp = (List)malloc(sizeof(struct Node));
	temp->next = NULL;
	temp->number = number;
	temp->next = L->next;
	L->next = temp;
	printf("%d", L->number);
}

void PopS( List L)
{
	if(L)
	{ 
		List  t, cycle;
		t = L;
		printf("%d", t->number);
		List temp;
		temp = (List)malloc(sizeof(struct Node));
		temp= t->next;
		t->next= temp->next;
		free(temp);
	}
}

int Is(List L, int m, int n)
{
	int re, vol, count;
	re = 1;
	count = 1;
	vol = 0;
	List S, t, l,cycle;
	S = (List)malloc(sizeof(struct Node));
	S->next = NULL;
	l = L;
	t = S;
	while (vol <= n + 1  && l)
	{
		printf("输入:");
		AddS(count, t);
		count++;
		vol++;
		t = t->next;
		while (l->number == t->number)
		{
			printf("输出:");
			l = l->next;
			PopS(t);
			vol--;
			if (vol==0)
			{
				break;
			}
		}

	}
	if (count>0)
	{
		re = 0;
	}
	return re;
}
