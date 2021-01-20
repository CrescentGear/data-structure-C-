
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_number 1000

void sort(int number1[], int number2[], int n);
int calcu(int n);
int findroot(int n, int layer);

int solve(int number2[], int number3[], int Aleft, int Aright, int root);

int solve(int number2[], int number3[], int Aleft, int Aright, int root)
{
	int n;
	int layer;
	int L;
	int Leftroot, Rightroot;
	n = Aright - Aleft + 1;
	if (n == 0)
		return 0;
	layer = calcu(n);
	L = findroot(n,layer);
	number3[root] = number2[L + Aleft];
	Leftroot = root * 2 + 1;
	Rightroot = Leftroot + 1;
	solve(number2, number3, Aleft, L + Aleft - 1, Leftroot);
	solve(number2, number3, L + Aleft + 1, Aright,Rightroot);
}



int main()
{
	int n, layer;
	int root;
	scanf("%d", &n);
	int number1[max_number];//numbe1是原来输入的数组
	int number2[max_number];//number2排好了顺序
	int number3[max_number];
	sort(number1, number2, n);
	layer = calcu(n);

	solve(number2, number3,0,n-1,0);
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
			printf("%d ", number3[i]);
		else
			printf("%d",number3[i]);
	}
	return 0;
}

void sort(int number1[], int number2[], int n)
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
}

int calcu(int n)
{
	int result;
	result = log10(n + 1) / log10(2);
	return result;
}

int findroot( int n, int layer)
{
	int temp1;
	int temp2; //root //第几个
	int rest;
	if ( n - pow(2, layer) +1 > pow(2 ,layer-1)) // the left tree is full and the right tree is not full yet
	{
		rest =  pow(2 , layer+1) -1-n;
		temp1 = pow(2, layer + 1) / 2;
		temp2 = temp1-1; // temp2 is the root

	}
	else if (n == pow(2 , layer) - 1) // full binary tree
	{
		temp1 = (n - 1)/2;
		temp2 = temp1 ;// temp2 is the root
	}
	else // the left tree is not full 
	{
		rest = n - pow(2 , layer) + 1;
		temp1 = n - rest;
		temp1 = temp1 / 2;
		temp2 = temp1 + rest ; // temp2 is the root
	}
	return temp2;
}

