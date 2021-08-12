//未写完
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MIN -1000
#define MaxSize 100

typedef struct TreeNode* HuffmanTree;
typedef struct HNode* Heap;

struct HNode
{
	HuffmanTree* data;
	int size;
	int capacity;
};

struct TreeNode
{
	int weight;
	HuffmanTree Left,Right;
};

int a[MaxSize];
char codes[65];

bool IsFull(Heap H)
{
	return (H->size == H->capacity);
}
bool IsEmpty(Heap H)
{
	return (H->size==0);
}
Heap BuildHeap(int N) //最小堆初始化
{
	Heap H=(Heap)malloc(sizeof(struct HNode));
	H->data = (HuffmanTree*)malloc((MaxSize+1) * sizeof(struct TreeNode));
	H->size = 0;
	H->capacity = MaxSize;

	return H;
}
void PercDown(Heap H, int k) //下滤调整为最小堆
{
	int Parent, Child;
	HuffmanTree x;
	x = H->data[k];
	for (Parent=k;Parent*2<=H->capacity;Parent=Child )
	{
		Child = Parent * 2;
		if ((Child <H->size) && H->data[Child]->weight > H -> data[Child+1]->weight)
		{
			Child++;
		}
		if (x->weight <= H->data[Child]->weight)
		{
			break;
		}
		else
		H->data[Parent] = H->data[Child];
	}
	H->data[Parent] = x;
}
void BuildMinHeap(Heap H) //构建最小堆
{
	for (int i=H->size/2;i>0;i--)
	{
		PercDown(H,i);
	}
}
bool Insert(Heap H,HuffmanTree X)
{

	int i;
	if (IsFull(H))
		return 0;
	H->size++;
	H->data[H->size] = X;
	for (i=H->size;H->data[i/2]->weight>=X->weight;i/=2)
	{
		H->data[i] = H->data[i/2];
	}
	H->data[i] = X;
	return 1;
}
HuffmanTree DeleteMinHeap(Heap H)
{
	HuffmanTree X;
	int Parent, Child;
	if (IsEmpty(H))
	{
		return NULL;
	}
	HuffmanTree Min = H->data[1];
	H->data[1] = H->data[H->size];
	X = H->data[1];
	H->size--;
	for (Parent=1;Parent*2<=H->size;Parent=Child)
	{
		Child = Parent * 2;
		if ((Child<H->size)&&H->data[Child]->weight > H->data[Child++]->weight)
		{
			Child++;
		}
		if (X->weight<=H->data[Child]->weight)
		{
			break;
		}
		else
		{
			H->data[Parent] = H->data[Child];
		}
	}
	H->data[Parent] = X;
	return Min;
}
HuffmanTree Huffman(Heap H)
{
	int i;
	HuffmanTree T;
	BuildMinHeap(H);
	for (i=1;i<H->size;i++)
	{
		T = (HuffmanTree)malloc(sizeof(struct TreeNode));
		T->Left = DeleteMinHeap(H);
		T->Right = DeleteMinHeap(H);
		T->weight = T->Left->weight + T->Right->weight;
		Insert(H, T);
	}
	T = DeleteMinHeap(H);
	return T;
}

int main()
{
	int N=7;
	//scanf("%d",&N);
	Heap H = BuildHeap(N);
	H->data[0]->Left = NULL;
	H->data[0]->Right = NULL;
	H->data[0]->weight = -5;
	for (int i=0;i<N;i++)
	{
		scanf("%c %d",&codes,&a[i]);
		H->data[i+1]->weight = a[i];
		H->size++;
	}
	BuildMinHeap(H);
	HuffmanTree T = Huffman(H);

	return 0;
}
