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

List Create(int k);
int Is(List L,int m,int k);

int main()
{
	List list;

	int m, k, n;//m是栈的容量，k是输入的长度，n是待检测的个数
	int result;
	result = 0;
	scanf("%d %d %d",&m,&n,&k);
	for (int i =0 ;i<n;i++)
	{
		list = Create(k);
		result = Is(list,m,k);
		if (result==1)
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

List Create(int k)
{
	List L, t,cycle;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	t = L;
	for (int i=0;i<k;i++)
	{
		List temp;
		temp = (List)malloc(sizeof(struct Node));
		temp->next = NULL;
		int number;
		scanf("%d",&number);
		temp->number = number;
		t->next = temp;
		t = temp;
	}
	cycle = L;
	L = L->next;
	free(cycle);
	return L;
}

int Is(List L, int m, int k)
{
	int re;
	re = 0;

	return re;
}
