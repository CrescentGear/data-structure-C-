/*未写完*/
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;

struct Node
{
	int data;
	List next;
};

struct 
{
	int data;
	int left;
	int right;
}number[10];

struct Queue
{
	List front;
	List rear;
};


int main()
{
	int inputnumber, root;
	List L,t;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	t = L;
	scanf("%d", &inputnumber);
	root = 0;
	for (int i = 0; i < 10; i++)
	{
		number[i].data = -1;
		number[i].left = -1;
		number[i].right = -1;
	}
	for (int i = 0; i < inputnumber; i++)
	{
		char left;
		char right;
		scanf("%c %c", &left, &right);
		if (left != '-')
		{
			number[i].left = left - '0';
			number[left].data = 1;
		}
		if (right != '-')
		{
			number[i].data = right - '0';
			number[right].data = 1;
		}
	}
	for (int i = 0; i < inputnumber; i++)
	{
		if (number[i].data == -1)
		{
			root = i;
		}
	}



	return 0;
}
