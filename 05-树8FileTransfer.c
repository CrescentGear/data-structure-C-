//25/25
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void input(int number[],int n1, int n2);
int Find(int number[], int n1);
int Find1(int number[],int n1); //Find1使用了路径压缩
void Union(int number[], int root1,int root2);
void check(int number[], int n1, int n2);
int final_check(int number[],int n);

int main()
{
	char a;
	int n1, n2;
	int N;
	int result;
	result = 0;
	scanf("%d",&N);
	int number[N+1];
	for (int i=0;i<N+1;i++)
	{
		number[i] = -1;
	}
	scanf("%c", &a);
	while (a != 'S')
	{
		scanf("%d %d", &n1, &n2);
		switch (a)
		{
		case 'I':
			input(number,n1,n2); 
			break;
		case 'C':
			check(number,n1,n2);
			break;
		}
		scanf("%c", &a);
	}
	result = final_check(number, N);
	if (result == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", result);
	return 0;
}

void input(int number[],int n1,int n2)
{
	Union(number,n1,n2);
}

void check(int number[],int n1,int n2)
{
	int Root1 = Find(number,n1);
	int Root2 = Find(number,n2);
	if (Root1==Root2)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}

int final_check(int number[],int n)
{
	int count;
	count = 0;
	for (int i=1;i<n+1;i++)
	{
		if (number[i]<0)
		{
			count++;
		}
	}
	return count;
}

int Find(int number[],int n1)
{
	for (; number[n1] >= 0; n1 = number[n1]);
	return n1;
}

int Find1(int number[],int n1) //Find1使用了路径压缩
{
	int n2;
	n2 = n1;
	if (number[n1]<0)
	{
		return n1;
	}
	for (; number[n1] >= 0; n1 = number[n1]);
	for (; number[n2]>=0; n2 = number[n2])
	{
		number[n2] = n1;
	}
	return n1;
}


void Union(int number[], int root1, int root2)
{
	int Root1, Root2;
	Root1 = Find(number, root1);
	Root2 = Find(number, root2);
	if (Root1 != Root2)
	{
	if (number[Root1]>number[Root2]) //Root2是大集合
	{
		number[Root2] += number[Root1];
		number[Root1] = Root2;
	}
	else
	{
		number[Root1] += number[Root2];
		number[Root2] = Root1;
	}
	}
}

