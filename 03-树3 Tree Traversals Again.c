/*未写完*/
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *List;

struct Node
{
	int data;
	List next;
};

int main()
{
	int n;
	scanf("%d",&n);
	char number[2];
	char type[30][30];
	for (int i=0;i<20;i++)
	{
		scanf(" %s &c",type[i],number);
	}
	/*
	for (int i = 0; i < n*2; i++)
	{
		printf(" %s &c\n", type[i], number[i]);
	}*/
	return 0;
}
