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

List Create(int n);
int Is(List L,int m,int n);

int main()
{
	List list;

	int m, n, k;//m是栈的容量，n是输入的长度，k是待检测的个数
	int result;
	result = 0;
	scanf("%d %d %d",&m,&n,&k);
	for (int i =0 ;i<k;i++)
	{
		list = Create(n);
		result = Is(list,m,n);
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

List Create(int n)
{
	List L, t,cycle;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	t = L;
	for (int i=0;i<n;i++)
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

int Is(List L, int m, int n)
{
	int re,vol;
	re = 1;
	vol = 1;
	List L2, t, cycle;
	L2 = (List)malloc(sizeof(struct Node));
	L2->next = NULL;
	t = L2;
	for (int i = 0; i < n; i++)
	{
		List temp;
		temp = (List)malloc(sizeof(struct Node));
		temp->next = NULL;
		temp->number = i+1;
		temp->next = t;
		t->next = temp;
		t = temp;
	}
	cycle = L2;
	L2 = L2->next;
	free(cycle);
	List L1,L3;
	L1 = L;
	L3 = L2;
	while (L1)
	{
		if (!L3)
		{
			L3 = L2;
		}
		List cycle2;
		if (L1->number==L3->number)
		{
			cycle2 = L3->next;
			L3 = cycle2->next;
			free(cycle2);
			L1 = L1->next;
			vol--;
		}
		else if (L1->number<L3->number)
		{
			L3 = L3->next;
			vol++;
		}
		if (vol>m)
		{
			return 0;
		}
	}
	return re;
}
