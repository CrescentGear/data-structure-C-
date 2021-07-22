#include "stdio.h"
#include "stdlib.h"
#pragma warning(disable:4996)

void BubbleSort(long A[], int N);   //冒泡19/25 测试点4，6，8超时   
void SelectionSort(long A[], int N);//选择 25/25                总耗时：3722 ms
void InsertSort(long A[], int N);   //插入 25/25                总耗时：3167 ms

int main()
{
	int N;
	scanf("%d",&N);
	long number[N];
	for (int i=0;i<N;i++)
	{
		scanf("%ld",&number[i]);
	}
	BubbleSort(number,N);
	for (int i = 0; i < N-1; i++)
	{
		printf("%ld ",number[i]);
	}
	printf("%ld",number[N-1]);
	return 0;
}

void BubbleSort(long A[], int N)
{
	for (int i=0;i<N;i++)
	{
		for (int j=1;j<N-i;j++)
		{
			long temp;
			if (A[j-1]>A[j])
			{
				temp = A[j-1];
				A[j-1] = A[j];
				A[j] = temp;
			}
		}
	}
}
void SelectionSort(long A[], int N)
{
	for (int i=0;i<N;i++)
	{
		long min = i;
		for (int j=i+1;j<N;j++)
		{
			if (A[min]>A[j])
			{
				min = j;
			}
		}
		long  temp;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}

void InsertSort(long A[], int N)
{
	int j;
	for (int i=0;i<N;i++)
	{
		long min = A[i];
		for ( j=i;j>0&& min<A[j-1];j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = min;
	}
}
