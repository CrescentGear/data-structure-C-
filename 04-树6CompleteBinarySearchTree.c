//未写完
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_number 1000

void sort(int number1[],int number2[],int n);
int calcu(int n);
void CBST(int number2[],int number3[],int n,int layer);

int main()
{
	int n,layer;
	scanf("%d",&n);
	int number1[max_number];
	int number2[max_number];
	int number3[max_number];
	sort(number1,number2,n);
	layer = calcu(n);
	CBST(number2, number3, n, layer);
	for (int i=0;i<n;i++)
	{
		printf("%d",number3[i]);
	}
	return 0;
}

void sort(int number1[], int number2[],int n)
{
	int i, j, c;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &number1[i]);
	}
	number2[0] = number1[0];
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (number1[i] < number2[j])
			{
				break;
			}
		}
		if (j != i)
		{
			c = i;
			while (c != j)
			{
				number2[c] = number2[c - 1];
				c--;
			}
		}
		number2[j] = number1[i];
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\t", number2[i]);
	}
}

int calcu(int n)
{
	int result;
	result = log10(n + 1) / log10(2);
	return result;
}

void CBST(int number2[],int number3[],int n,int layer)
{
	if (n-2^layer-1>2^(n+1)) // the left tree is full and the right tree is not null yet
	{
		int rest;
		int temp1;
		int temp2;
		rest = n - 2 ^ layer - 1;
		temp1 = n - rest;
		temp1 = temp1 / 2;
		temp2 = temp1 + rest+1; // temp2 is the root

	}
	else if (n == 2 ^ layer - 1 ) // full binary tree
	{

	}
	else // the left tree is not null 
	{

	}
}
