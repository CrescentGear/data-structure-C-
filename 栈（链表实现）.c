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

int main()
{
	List list;
	int n;
	scanf("%d",&n);
	list = Create(n);
	while (list)
	{
		printf("%d",list->number);
		list = list->next;
	}
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
		temp->next = t->next;
		t->next = temp;
	}
	cycle = L;
	L = L->next;
	free(cycle);
	return L;
}
