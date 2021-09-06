#include "stdio.h"
#include "stdlib.h"
#pragma warning(disable:4996)

void Swap(long A[],long i, long j);  //换值
void BubbleSort(long A[], int N);   //冒泡19/25 测试点4，6，8超时   
void SelectionSort(long A[], int N);//选择 25/25                                      总耗时：3722 ms
void InsertSort(long A[], int N);   //插入 25/25                                      总耗时：3167 ms
void ShellSort(long A[], int N);    //希尔 25/25 （使用Sedgewick增量序列）              总耗时：74 ms
void ShellSort1(long A[], int N);   //希尔 25/25 （使用原始希尔排序）                    总耗时：66 ms 
//				      归并 25/25					    总耗时：54 ms
void Merge(long A[], long temp[], int L, int R, int RightEnd);
void MSort(long A[], long temp[], int L, int R);
void MergeSort(long A[], int N);
// 

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

void Swap(long A[],long i, long j)
{
	long temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void BubbleSort(long A[], int N)
{
	for (int i=0;i<N;i++)
	{
		for (int j=1;j<N-i;j++)
		{
			if (A[j-1]>A[j])
			{
				Swap(A,j,j-1);
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
		Swap(A,i,min);
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

void ShellSort(long A[], int N)
{
	//用Sedgewick增量序列
   	int i,j,k;
	int guard;
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
	for (i = 0; Sedgewick[i] >= N; i++);
	guard = i;
		for(i=guard;Sedgewick[i]>0;i++)
		{ 		
			long step = Sedgewick[i];
			for (k=step;k<N;k++)
			{
				long temp = A[k];
				for (j=k;j>=step && temp<A[j-step];j-=step)
				{
					A[j] = A[j - step];
				}
				A[j] = temp;
			}
		}
}
void ShellSort1(long A[], int N)
{
	int i,j,k;

		for(i=N;i>0;i/=2)
		{ 		
			long step = i;
			for (k=step;k<N;k++)
			{
				long temp = A[k];
				for (j=k;j>=step && temp<A[j-step];j-=step)
				{
					A[j] = A[j - step];
				}
				A[j] = temp;
			}
		}
}

void Merge(long A[], long temp[], int L, int R, int RightEnd)
{
	int LeftEnd;
	LeftEnd = R - 1;
	int j = L;
	int i = 0;
	int NumElement = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] > A[R])
		{
			temp[j] = A[R];
			j++;
			R++;
		}
		else
		{
			temp[j] = A[L];
			j++;
			L++;
		}
	}
	while (L <= LeftEnd)
	{
		temp[j] = A[L];
		j++;
		L++;
	}
	while (R <= RightEnd)
	{
		temp[j] = A[R];
		j++;
		R++;
	}
	for (i = 0; i < NumElement; i++, RightEnd--)
	{
		A[RightEnd] = temp[RightEnd];
	}
}

void MSort(long A[], long temp[], int L, int R)
{
	int center;
	center = (L + R) / 2;
	if (L < R)
	{
		MSort(A, temp, L, center);
		MSort(A, temp, center + 1, R);
		Merge(A, temp, L, center + 1, R);
	}
}

void MergeSort(long A[], int N)
{
	long temp[N];
	MSort(A, temp, 0, N - 1);

}
