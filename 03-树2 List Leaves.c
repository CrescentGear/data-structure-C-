/*未写完*/
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree *TList;

struct Tree
{
	int data;
	TList left;
	TList right;
};

struct Number
{
	int data;
	int left;
	int right;
};

struct Queue
{
	TList front;
	TList rear;
};

TList Build(void);

int main()
{
	int inputnumber,root;
	scanf("%d",&inputnumber);
    struct Nnumber number[10];
	root = 0;
	for (int i=0;i<10;i++)
	{
		number[i].data = -1;
		number[i].left = -1;
		number[i].right = -1;
	}
	for (int i=0;i<inputnumber;i++)
	{
		char left;
		char right;
		scanf("%c %c",&left,&right);
		if (left!='-')
		{
			left = left - '0';
			number[left] = 1;
		}
		if (right != '-')
		{
			right = right - '0';
			number[right] = 1;
		}
	}
	for (int i = 0; i < inputnumber; i++)
	{
		if (number[i]==-1)
		{
			root = i;
		}
	}

	return 0;
}
